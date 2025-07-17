#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
using namespace std;
struct Queue {
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;
    Queue() {
        front = rear = nullptr;
    }
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return val;
    }
    int peek() {
        if (front == nullptr) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
    ~Queue() {
        clear();
    }
};

#endif 
