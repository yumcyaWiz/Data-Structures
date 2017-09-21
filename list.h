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
        };
        void insert(int i) {
        };
        void erase(int i) {
        };
};
#endif
