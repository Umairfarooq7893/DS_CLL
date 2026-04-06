#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Creating circular linked list manually
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    head->next = second;
    second->next = third;
    third->next = head;   // circular link

    // Traversal
    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "head";

    return 0;
}