#include <iostream>
using namespace std;

const int MAX = 5;
int arr[MAX];
int top = -1;

void push(int x) {
    if (top >= MAX - 1) {
        cout << "Stack is full!" << endl;
        return;
    }
    arr[++top] = x;
    cout << x << " inserted successfully." << endl;
}

void pop() {
    if (top < 0) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << arr[top--] << " removed successfully" << endl;
}

void peek() {
    if (top < 0) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Top element: " << arr[top] << endl;
}

void display() {
    if (top < 0) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice = 0;
    int x;

    while (choice != 5) {
        cout << "\n==== STACK MENU ====" << endl;
        cout << "1. Push    2. Pop  3. Peek" << endl;
        cout << "4. Display     5. Exit" << endl;
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Goodbye!.." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}