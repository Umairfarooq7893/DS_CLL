#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Delete from beginning
void deleteFromBeginning() {
    // If list is empty
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // If only one node exists
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;   // node to delete
    Node* last = head;

    // Finding last node
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;   // move head to next node
    last->next = head;   // maintain circular link
    delete temp;         // delete old head
}

// Delete from end
void deleteFromEnd() {
    // If list is empty
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // If only one node exists
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Traverse to last node
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;  // link second last node to head
    delete temp;        // delete last node
}

// Delete from given position
void deleteFromPosition(int position) {
    // If list is empty
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // Invalid position
    if (position < 1) {
        cout << "Invalid position\n";
        return;
    }

    // Delete first node
    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Traverse to required position
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;

        // If we loop back to head, position is invalid
        if (temp == head) {
            cout << "Position out of range\n";
            return;
        }
    }

    prev->next = temp->next; // bypass the node
    delete temp;             // delete node
}

void display() {
    // If list is empty
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    // Traverse using do-while
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(head)\n";  // indicates circular nature
}

// Main function
int main() {
    // Currently list is empty, so deletions will show messages
    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(2);

    display();

    return 0;
}