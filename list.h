#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
template <typename T>
struct ListNode {
    T data;
    ListNode* next;

    ListNode() : data(0), next(nullptr) {};
    ListNode(T _data, ListNode *_next) : data(_data), next(_next) {};
};


template <typename T>
class List {
    private:
        ListNode<T>* first;
        int size;
    public:
        List() : first(nullptr), size(0) {};
        ~List() {
            ListNode<T>* ln1 = first;
            ListNode<T>* ln2 = nullptr;
            while(ln1->next) {
                ln2 = ln1->next;
                delete ln1;
                ln1 = ln2;
            }
        };


        T operator[](int i) const {
            if(i > size - 1) {
                std::cerr << "index is larger than the size of list" << std::endl;
                exit(1);
            }

            ListNode<T>* ln = first;
            for(int idx = 0; idx < i; idx++) {
                ln = ln->next;
            }
            return ln->data;
        };


        void push_back(T x) {
            size++;

            if(first == nullptr) {
                first = new ListNode<T>(x, nullptr);
                return;
            }

            ListNode<T>* ln = first;
            while(ln->next) {
                ln = ln->next;
            };
            ln->next = new ListNode<T>(x, nullptr);
        };
        void pop_back() {
            if(first == nullptr) {
                std::cerr << "List is already empty" << std::endl;
                exit(1);
            }
            
            size--;
            if(first->next == nullptr) {
                delete first;
                first = nullptr;
                return;
            };

            ListNode<T>* ln = first;
            ListNode<T>* pre = nullptr;
            while(ln->next) {
                pre = ln;
                ln = ln->next;
            }
            delete ln;
            pre->next = nullptr;
        };
        void insert(int i, T x) {
            if(i > size || i < 0) {
                std::cerr << "index is out of range" << std::endl;
                exit(1);
            }

            size++;
            if(i == 0) {
                first = new ListNode<T>(x, first);
                return;
            }
            else if(i == size) {
                ListNode<T>* ln = first;
                while(ln->next) {
                    ln = ln->next;
                }

                ListNode<T>* insert_node = new ListNode<T>(x, nullptr);
                ln->next = insert_node;
                return;
            }

            ListNode<T>* ln = first;
            ListNode<T>* prev_node = nullptr;
            for(int idx = 0; idx < i; idx++) {
                prev_node = ln;
                ln = ln->next;
            }
            ListNode<T>* insert_node = new ListNode<T>(x, ln);
            prev_node->next = insert_node;
        };
        void erase(int i) {
        };
        void print() {
            int index = 0;
            ListNode<T>* ln = first;
            do {
                if(ln->next) {
                    std::cout << ln->data << " -> ";
                }
                else {
                    std::cout << ln->data;
                }
                ln = ln->next;
            }
            while(ln);
            std::cout << std::endl;
        };
        int getSize() {
            return size;
        };
};
#endif
