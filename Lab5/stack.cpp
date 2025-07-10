/** Stack
Name: Muhammad Aqil Rahimi bin Mohamad Rasidi
id: 22011363
Lab G2
**/
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(string name) {
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << name << endl;
    }

    // Pop operation
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        cout << "Popped: " << temp->name << endl;
        top = top->next;
        delete temp;
    }

    // Display stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack stack;

    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Alice");

    cout << "\nInitial Stack:\n";
    stack.display();

    stack.pop();

    cout << "\nAfter Pop:\n";
    stack.display();

    return 0;
}
