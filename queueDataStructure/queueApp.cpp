#include <iostream>
#include "Queue.h"
#include <string>

int main() {
    Queue<std::string> q1;
    std::cout << q1.numberOfElements() << std::endl;
    if (q1.isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    }
    q1.enqueue("first");
    q1.enqueue("second");
    std::cout << q1.numberOfElements() << std::endl;
    std::cout << q1.dequeue() << std::endl;
    std::cout << q1.numberOfElements() << std::endl;
    if (q1.isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    }
}