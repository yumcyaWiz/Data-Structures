#include <iostream>
#include "stack.h"


int main() {
    Stack<int> stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
}
