#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
template <typename T>
class Stack {
    private:
        T *data;
        int size;
        int index;
    public:
        Stack(int _size) : size(_size) {
            index = 0;
            data = new T[size];
        };
        ~Stack() {
            delete[] data;
        };


        void push(T x) {
            if(index >= size) {
                std::cerr << "Stack is full" << std::endl;
                exit(1);
            }
            data[index] = x;
            index++;
        };
        T pop() {
            if(index == 0) {
                std::cerr << "No data in stack" << std::endl;
                exit(1);
            }
            index--;
            return data[index];
        };
        void print() {
            for(int i = 0; i < index; i++) {
                if(i < index - 1) {
                    std::cout << data[i] << " ";
                }
                else {
                    std::cout << data[i];
                }
            }
            std::cout << std::endl;
        };
};
#endif
