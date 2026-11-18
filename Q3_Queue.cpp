#include <iostream>
using namespace std;

const int MAX = 5;
int arr[MAX];
int frontIdx = -1;
int rearIdx = -1;

void enqueue(int value) {
    if (rearIdx >= MAX - 1) {
        cout << "Queue Overflow! Cannot insert " << value << "." << endl;
        return;
    }
    if (frontIdx == -1) {
        frontIdx = 0;
    }
    arr[++rearIdx] = value;
    cout << value << " inserted successfully." << endl;
}

void dequeue() {
    if (frontIdx == -1 || frontIdx > rearIdx) {
        cout << "Queue Underflow! Queue is empty." << endl;
        return;
    }
    cout << arr[frontIdx++] << " removed successfully." << endl;
    
    if (frontIdx > rearIdx) {
        frontIdx = -1;
        rearIdx = -1;
    }
}

void front() {
    if (frontIdx == -1 || frontIdx > rearIdx) {
        cout << "Queue is empty! No front element." << endl;
        return;
    }
    cout << "Front element: " << arr[frontIdx] << endl;
}

void display() {
    if (frontIdx == -1 || frontIdx > rearIdx) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = frontIdx; i <= rearIdx; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice = 0;
    int value;

    while (choice != 5) {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                front();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-5." << endl;
        }
    }

    return 0;
}