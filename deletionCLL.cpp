
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    delete temp;
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    delete temp;
}
// Delete from position
void deleteFromPosition(int position) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (position < 1) {
        cout << "Invalid position\n";
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;

        if (temp == head) {
            cout << "Position out of range\n";
            return;
        }
    }

    prev->next = temp->next;
    delete temp;
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
    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(2);
    display();

    return 0;
}