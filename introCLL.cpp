#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Manually creating nodes
    Node* head =   new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third =  new Node{30, NULL};
    Node* fourth = new Node{40, NULL};
    Node* fifth =  new Node{50, NULL};

    // Linking in circular form
    head->next = second;
    second->next = third;
    third->next = fourth;
    fifth->next = head;      // circular link

    // Printing
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    return 0;
}