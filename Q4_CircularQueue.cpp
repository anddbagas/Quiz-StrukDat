#include <iostream>
using namespace std;

const int MAX = 5;
int arr[MAX];
int frontIdx = -1;
int rearIdx = -1;

bool isFull() {
    return ((rearIdx + 1) % MAX == frontIdx);
}

bool isEmpty() {
    return (frontIdx == -1);
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Circular Queue Overflow! Cannot insert " << value << "." << endl;
        return;
    }
    if (isEmpty()) {
        frontIdx = 0;
    }
    rearIdx = (rearIdx + 1) % MAX;
    arr[rearIdx] = value;
    cout << "Enqueued: " << value << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Circular Queue Underflow! Queue is empty." << endl;
        return;
    }
    cout << "Dequeued: " << arr[frontIdx] << endl;
    
    if (frontIdx == rearIdx) {
        frontIdx = -1;
        rearIdx = -1;
    } else {
        frontIdx = (frontIdx + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    int i = frontIdx;
    while (true) {
        cout << arr[i] << " ";
        if (i == rearIdx) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    cout << "=== RUNNING 10-STEP MANDATORY TEST ===" << endl;

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    dequeue();
    dequeue();

    enqueue(60);
    enqueue(70);

    cout << "\nFinal Output:" << endl;
    display();

    return 0;
}