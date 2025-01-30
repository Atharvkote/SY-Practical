#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    Node *root;
    Node *current;

    BinaryTree(){
        this->root = nullptr;
        this->current = nullptr;
    }

    void insertNode(Node *newNode , Node *root) {
         char choice;
         cout << "[ PRESS L ] : To Insert at Left of [ " << root->data << " ]\n[ PRESS R ] : To Insert at Right of [ " << root->data << " ]\n";
         cin >> choice;

        if (choice == 'L' || choice == 'l'){
             if (root->left != NULL){
                root = root->left;
                insertNode(newNode, root);  // Recursive Call Till Left is NULL
            }
        else{ root->left = newNode; }
        }
     
        if (choice == 'R' || choice == 'r'){
             if (root->right != NULL){
                 root = root->right;
                 insertNode(newNode, root); // Recursive Call Till Right is NULL
            }
        else{ root->right = newNode; }
        }
    }
    void deleteNode() {}

    void PreOrder(Node *root){
        if(root == nullptr){ return; }
        cout << root->data <<" ,";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void InOrder(Node *root){
        if(root == nullptr){ return; }
        InOrder(root->left);
        cout << root->data <<" ,";
        InOrder(root->right);
    }

    void PostOrder(Node *root){
        if(root == nullptr){ return; }
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data <<" ,";
    }

    void displayBinaryTree() {
        int choice;
        cout << "\nTree Traversals :\n[ PRESS 1 ] : PreOrder Traversal..\n[ PRESS 2 ] : InOrder Traversal..\n[ PRESS 3 ] : PostOrder Traversal..\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "PreOrder Sequence : [";
            PreOrder(root);
            cout <<" ]\n";
            break;
        case 2:
            cout << "InOrder Sequence : [ ";
            InOrder(root);
            cout <<" ]\n";
            break;
        case 3:
            cout << "PostOrder Sequence : [";
            PostOrder(root);
            cout <<" ]\n";
            break;
        
        default:
            cout << "Invalid Choice...";
            break;
        }
    }
    void createBinaryTree()
    {
        int val,choice;
        root = nullptr; // resetting root

        do{
            cout << "Enter data for node :";
            cin >> val;
            Node *newNode = new Node(val);
            if (root == NULL){ root = newNode; }
            else{ insertNode(newNode, root); }
            cout << "[ PRESS 1 ] : To Continue..\n[ PRESS 0 ] : To Exit..\n";
            cin >> choice;
        } while (choice == 1);
    }

    void insertNewNode() {
        if (root == nullptr) {
            cout << "Tree is empty. Create a tree first.\n";
            return;
        }
        int val;
        cout << "Enter data for new node: ";
        cin >> val;
        Node *newNode = new Node(val);
        insertNode(newNode, root);
    }
};

int main(){
    BinaryTree tree;
    int choice;
    do {
        cout << "\nBinary Tree Menu:\n";
        cout << "[1] Create Binary Tree\n";
        cout << "[2] Insert Node\n";
        cout << "[3] Display Tree Traversals\n";
        cout << "[4] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                tree.createBinaryTree();
                break;
            case 2:
                tree.insertNewNode();
                break;
            case 3:
                tree.displayBinaryTree();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}
