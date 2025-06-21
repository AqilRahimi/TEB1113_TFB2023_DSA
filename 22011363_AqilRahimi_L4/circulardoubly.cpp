/** circular doubly linked list
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
            head->next = head;
            head->prev = head;
        } else {
            tail->next = node;
            node->prev = tail;
            node->next = head;
            head->prev = node;
            tail = node;
        }
    }

    void display_forward() {
        if (head == nullptr) return;

        Node* curr = head;
        do {
            cout << curr->name << " -> ";
            curr = curr->next;
        } while (curr != head);
        cout << head->name << " (back to start)" << endl;
    }


    void display_backward() {
    if (tail == nullptr) return;

    Node* curr = tail;
    do {
        cout << curr->name << " <- ";
        curr = curr->prev;
    } while (curr != tail);
    cout << tail->name << " (back to end)" << endl;
    }

    void delete_value(string name) {
        if (head == nullptr) return;

        Node* curr = head;
        do {
            if (curr->name == name) {
                // Only one node in the list
                if (curr == head && curr == tail) {
                    delete curr;
                    head = nullptr;
                    tail = nullptr;
                    return;
                }

                // Deleting head
                if (curr == head) {
                    head = head->next;
                    tail->next = head;
                    head->prev = tail;
                }
                // Deleting tail
                else if (curr == tail) {
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                }
                // Deleting middle node
                else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }

                delete curr;
                return;
            }
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

    cout << "Forward: ";
    std_list.display_forward();

    cout << "Backward: ";
    std_list.display_backward();

    std_list.delete_value("Ahmed");

    cout << "\nAfter deleting 'Ahmed':" << endl;

    cout << "Forward: ";
    std_list.display_forward();

    cout << "Backward: ";
    std_list.display_backward();

    return 0;
}
