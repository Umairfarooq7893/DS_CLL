#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Insert at position
void insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node{value, NULL};
    Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(head)\n";
}

// Main
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtPosition(15, 3);

    display();

    return 0;
}