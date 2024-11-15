#include <iostream>
using namespace std;



class SinglyLinkedList {
    class Node {
                public:
                     int index;
                     Node* next;

                     Node(int val){
                            this -> index = val;
                            this -> next = NULL;
                     }
    };


private:
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    // Create linked list
    void create() {
        int val;
        char ans = 'y';
        Node* temp = NULL;

        do {
            cout << "Enter the element: ";
            cin >> val;
            Node* newNode = new Node(val);

            if (head == NULL) {
                head = newNode;
            } else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }

            cout << "Do you want to enter more elements? (y/n): ";
            cin >> ans;
        } while (ans == 'y' || ans == 'Y');

        cout << "Linked list created." << endl;
    }

    // Display linked list
    void display() const {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->index << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Insert at head
    void insert_head() {
        int val;
        cout << "Enter the element you want to insert at the head: ";
        cin >> val;
        Node* newNode = new Node(val);
        
        newNode->next = head;
        head = newNode;

        cout << "Node inserted at the head." << endl;
    }

    // Insert at last
    void insert_last() {
        int val;
        cout << "Enter the element you want to insert at the end: ";
        cin >> val;
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Node inserted at the end." << endl;
    }

    // Insert after a specific node
    void insert_after() {
        int val, key;
        cout << "Enter the element you want to insert: ";
        cin >> val;
        Node* newNode = new Node(val);

        cout << "Enter the element after which you want to insert: ";
        cin >> key;

        Node* temp = head;
        while (temp != NULL && temp->index != key) {
            temp = temp->next;
        }

        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Node inserted after " << key << "." << endl;
        } else {
            cout << "Element " << key << " not found in the list." << endl;
            delete newNode;
        }
    }

    // Delete first node
    void delete_first() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "First node deleted." << endl;
    }

    // Delete last node
    void delete_last() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == NULL) { // Only one node
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            Node* prev = NULL;
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }
        cout << "Last node deleted." << endl;
    }

    // Delete node after a specific key
    void delete_after(int key) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->index != key) {
            temp = temp->next;
        }

        if (temp != NULL && temp->next != NULL) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            cout << "Node deleted after " << key << "." << endl;
        } else {
            cout << "Element " << key << " not found in the list or it has no next node." << endl;
        }
    }
};

int main() {
    SinglyLinkedList sll;
    
}