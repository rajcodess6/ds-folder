#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create circular linked list
Node* createList(int n) {
    if (n <= 0) return NULL;

    Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 1; i <= n; i++) {
        newNode = new Node();

        cout << "Enter data for node " << i << ": ";
        cin >> newNode->data;

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    temp->next = head;

    return head;
}

// Function to display circular linked list
void display(Node* head) {
    if (head == NULL) return;

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)" << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = createList(n);

    cout << "Circular Linked List: ";
    display(head);

    return 0;
}