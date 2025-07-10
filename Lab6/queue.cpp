/** Queue 
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

class Queue {
public:
    Node* head;
    Node* tail;

    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;  // Queue becomes empty
        }
    }

    void display() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " -> ";
            currNode = currNode->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    Queue q;

    q.enqueue(node1);
    q.enqueue(node2);
    q.enqueue(node3);

    cout << "Initial Queue:\n";
    q.display();

    cout << "\nDequeuing one item...\n";
    q.dequeue();

    cout << "\nQueue after one dequeue:\n";
    q.display();

    return 0;
}
