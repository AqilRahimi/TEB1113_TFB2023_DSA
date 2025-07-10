/** Queue using Array
Name: Muhammad Aqil Rahimi bin Mohamad Rasidi
ID: 22011363
Lab G2
**/
#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    string* queue;

public:
    Queue(int size) {
        capacity = size;
        queue = new string[capacity];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << name << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        queue[rear] = name;
        cout << name << " enqueued to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << queue[front] << " dequeued from queue.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);  // Queue size 5

    q.enqueue("Ali");
    q.enqueue("Ahmed");
    q.enqueue("Alice");

    cout << endl;
    q.display();
    q.dequeue();
    q.display();

    return 0;
}
