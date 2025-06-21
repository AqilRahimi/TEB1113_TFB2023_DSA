/** singly linked list
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

    Node(string name) {
        this->name = name;
        this->next = nullptr;
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
            tail = node;
        }
    }

    void display_list() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " -> ";
            currNode = currNode->next;
        }
        cout << "nullptr" << endl;
    }

    void delete_value(string name) {
        if (head == nullptr) return;

        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            if (curr->next->name == name) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                if (temp == tail) {
                    tail = curr;
                }
                delete temp;
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

    cout << "Initial list:\n";
    std_list.display_list();

    std_list.delete_value("Ahmed");

    cout << "\nAfter deletion:\n";
    std_list.display_list();

    return 0;
}
