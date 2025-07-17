#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
using namespace std;
struct Stack {
    struct Node {
        int data;
        Node* next;
    };
    Node* top;  
    Stack() {
        top = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void display() {
        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void clear() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    ~Stack() {
        clear();
    }
};
#endif
