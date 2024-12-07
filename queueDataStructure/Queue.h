#pragma once
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class Queue {
    Node<T>* first;
    Node<T>* last;
    int count; // To keep track of the number of elements

public:
    Queue() {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    void enqueue(T elem) {
        Node<T>* newNode = new Node<T>(elem);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
            count++;
            return;
        }
        last->next = newNode;
        last = newNode;
        count++;
    }

    T dequeue() {
        if (first == nullptr) {
            throw std::underflow_error("Queue is empty - cannot remove element");
        }
        T tempVal = first->data;
        if (first->next == nullptr) {
            delete first;
            first = nullptr;
            last = nullptr;
            count--;
            return tempVal;
        }
        Node<T>* oldFirst = first;
        first = first->next;
        delete oldFirst;
        count--;
        return tempVal;
    }

    int numberOfElements() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }
};