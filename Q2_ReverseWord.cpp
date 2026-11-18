#include <iostream>
using namespace std;

const int MAX = 100;
char charStack[MAX];
int top = -1;

void push(char x) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    charStack[++top] = x;
}

char pop() {
    if (top < 0) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    return charStack[top--];
}

int main() {
    char word[MAX];

    cout << "Enter a word: ";
    cin >> word;

    cout << "Original word: " << word << endl;

    for (int i = 0; word[i] != '\0'; i++) {
        push(word[i]);
    }

    cout << "Reversed word: ";
    while (top >= 0) {
        cout << pop();
    }
    cout << endl;

    return 0;
}