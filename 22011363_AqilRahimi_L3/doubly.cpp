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
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void display_list() {
        cout << "nullptr";
        Node* curr = head;
        while (curr != nullptr) {
            cout << " <-> " << curr->name;
            curr = curr->next;
        }
        cout << " <-> nullptr" << endl;
    }

    void delete_value(string name) {
        if (head == nullptr) return;

        Node* curr = head;

        while (curr != nullptr) {
            if (curr->name == name) {
                if (curr == head) {
                    head = curr->next;
                    if (head != nullptr) head->prev = nullptr;
                    else tail = nullptr; // list becomes empty
                } else if (curr == tail) {
                    tail = curr->prev;
                    tail->next = nullptr;
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

    DoublyLinkedList std_list;

    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    cout << "Initial list:" << endl;
    std_list.display_list();

    std_list.delete_value("Ahmed");

    cout << "\nAfter deletion:" << endl;
    std_list.display_list();

    return 0;
}
