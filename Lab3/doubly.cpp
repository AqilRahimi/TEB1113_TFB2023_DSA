/** doubly linked list
Name: Muhammad Aqil Rahimi bin Mohamad Rasidi
id: 22011363
lab G2
**/
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void display_forward() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name;
            if (currNode->next != nullptr) cout << " -> ";
            currNode = currNode->next;
        }
        cout << endl;
    }

    void display_backward() {
        Node* currNode = tail;
        while (currNode != nullptr) {
            cout << currNode->name;
            if (currNode->prev != nullptr) cout << " <- ";
            currNode = currNode->prev;
        }
        cout << endl;
    }

    void delete_value(string name) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->name == name) {
                if (curr == head) {
                    head = curr->next;
                    if (head != nullptr) head->prev = nullptr;
                } else if (curr == tail) {
                    tail = curr->prev;
                    if (tail != nullptr) tail->next = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alice");

    LinkedList std_list;

    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    cout << "Forward: ";
    std_list.display_forward();

    cout << "Backward: ";
    std_list.display_backward();

    std_list.delete_value("Ahmed");

    cout << "\nAfter deleting 'Ahmed':\n";

    cout << "Forward: ";
    std_list.display_forward();

    cout << "Backward: ";
    std_list.display_backward();

    return 0;
}
