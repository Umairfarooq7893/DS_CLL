#include <iostream>
using namespace std;


struct Node {
    int data; 
    Node* next; 
};

Node* head = NULL;

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();  // create new node
    newNode->data = value;

    // If list is empty, point node to itself
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    // Traverse to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert new node before head
    newNode->next = head;
    temp->next = newNode;
    head = newNode;   // update head
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = new Node{value, NULL};

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    // Traverse to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert new node at end
    temp->next = newNode;
    newNode->next = head;
}

// Insert at specific position
void insertAtPosition(int value, int position) {
    // Invalid position
    if (position < 1) {
        cout << "Invalid position\n";
        return;
    }

    // Insert at beginning
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node{value, NULL};
    Node* temp = head;

    // Traverse to (position-1) node
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;

        // If we loop back to head, position is out of range
        if (temp == head) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }
    }

    // Insert node in between
    newNode->next = temp->next;
    temp->next = newNode;
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

    cout << "(head)\n";  // indicates circular link
}

// Main function
int main() {
    insertAtEnd(10); 
    insertAtEnd(20);      
    insertAtBeginning(5); 
    insertAtPosition(15, 3); 

    display();

    return 0;
}