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

    int NumberOfNode(Node *root){
        if(root == nullptr){ return 0; }
        
        int leftCount = NumberOfNode(root->left);
        int rightCount = NumberOfNode(root->right);
        
        return leftCount + rightCount + 1;
    }

    int heightOfTree(Node *root){
        if(root == nullptr){ return 0; }
        
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        
        return max(leftHeight , rightHeight) + 1;
    }

    void getRoot(){ cout << "Root : " << root->data << endl;}

    void getLeafNode(Node* root){
        if(root->left == nullptr && root->right == nullptr){
            cout << root->data <<" ,";
        }
        if(root == nullptr){ return; }
        getLeafNode(root->left);
        getLeafNode(root->right);
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
        cout << "[4] Get Number Of Nodes\n";
        cout << "[5] Get Height of the Tree\n";
        cout << "[6] Get Root\n";
        cout << "[7] Leaf Leave Node\n";
        cout << "[8] Exit\n";
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
            int number;
                 number = tree.NumberOfNode(tree.root);
                cout << "Number Of Node : "<< number;
                break;
            case 5:
            int height;
                height = tree.heightOfTree(tree.root);
                cout << "Number Of Node : "<< height;
                break;
            case 6:
                tree.getRoot();
                break;
            case 7:
                tree.getLeafNode(tree.root);
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 8);
    return 0;
}
