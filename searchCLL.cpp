#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void search(Node* head, int key) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;  // start from head
    int pos = 1;

    do {
        if (temp->data == key) {
            cout << "Element found at position " << pos;
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != head);

    cout << "Element not found";
}

int main() {
   
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};

    head->next = second;
    second->next = third;
    third->next = head;   // circular link


    search(head, 20);

    return 0;
}