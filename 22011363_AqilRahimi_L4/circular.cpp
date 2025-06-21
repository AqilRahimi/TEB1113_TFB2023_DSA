/** circular linked list
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
            head = tail = node;
            node->next = head; // circular link
        } else {
            tail->next = node;
            node->next = head; // keep it circular
            tail = node;
        }
    }

    void display_list() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << curr->name << " -> ";
            curr = curr->next;
        } while (curr != head);

        cout << head->name << endl;
    }

    void delete_value(string name) {
        if (head == nullptr) return;

        Node* curr = head;
        Node* prev = tail;

        do {
            if (curr->name == name) {
                if (curr == head) {
                    if (head == tail) {
                        delete head;
                        head = tail = nullptr;
                        return;
                    } else {
                        head = head->next;
                        tail->next = head;
                        delete curr;
                        return;
                    }
                } else {
                    prev->next = curr->next;
                    if (curr == tail) {
                        tail = prev;
                    }
                    delete curr;
                    return;
                }
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
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
