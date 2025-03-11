#include <iostream>
using namespace std;

class Node
{
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

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree()
    {
        this->root = nullptr;
    }

    void InsertNode(Node *&root, int val)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }
        if (val < root->data)
        {
            InsertNode(root->left, val);
        }
        else if (val > root->data)
        {
            InsertNode(root->right, val);
        }
    }

    void CreateBST()
    {
        int choice;
        cout << "Creating a Binary Search Tree... \n:: Enter Data Of Root Node : ";
        int rootData;
        cin >> rootData;
        root = new Node(rootData);

        do
        {
            int val;
            cout << "Enter Data : ";
            cin >> val;
            InsertNode(root, val);
            cout << "Do you want to continue inserting?\n[ PRESS 0 ] : To Continue \n[ PRESS 1 ] : To Exit\n";
            cin >> choice;
        } while (choice == 0);
    }

    Node *RecursiveSearch(Node *root, int key)
    {
        if (root == nullptr)
        {
            cout << "Key Not Found in Tree\n";
            return nullptr;
        }

        if (root->data == key)
        {
            cout << "Key Found in Tree\n";
            return root;
        }

        return key < root->data ? RecursiveSearch(root->left, key) : RecursiveSearch(root->right, key);
    }

    Node *IterativeSearch(Node *root, int key)
    {
        while (root != nullptr)
        {
            if (root->data == key)
            {
                cout << "Key Found in Tree\n";
                return root;
            }
            root = key < root->data ? root->left : root->right;
        }
        cout << "Key Not Found in Tree\n";
        return nullptr;
    }

    void PreOrder(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->data << " ,";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void InOrder(Node *root)
    {
        if (root == nullptr)
            return;
        InOrder(root->left);
        cout << root->data << " ,";
        InOrder(root->right);
    }

    void PostOrder(Node *root)
    {
        if (root == nullptr)
            return;
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ,";
    }

    void displayBinaryTree()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty. No traversals available.\n";
            return;
        }

        int choice;
        cout << "\nTree Traversals :\n";
        cout << "[ PRESS 1 ] : PreOrder Traversal..\n";
        cout << "[ PRESS 2 ] : InOrder Traversal..\n";
        cout << "[ PRESS 3 ] : PostOrder Traversal..\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "PreOrder Sequence : [";
            PreOrder(root);
            cout << " ]\n";
            break;
        case 2:
            cout << "InOrder Sequence : [ ";
            InOrder(root);
            cout << " ]\n";
            break;
        case 3:
            cout << "PostOrder Sequence : [";
            PostOrder(root);
            cout << " ]\n";
            break;
        default:
            cout << "Invalid Choice...\n";
            break;
        }
    }

    void searchBST()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty. Create a tree first!\n";
            return;
        }

        int key, searchChoice;
        cout << "Enter key to search: ";
        cin >> key;
        cout << "Choose search method:\n";
        cout << "[1] Recursive Search\n";
        cout << "[2] Iterative Search\n";
        cin >> searchChoice;

        Node *result = nullptr;
        if (searchChoice == 1)
        {
            result = RecursiveSearch(root, key);
        }
        else if (searchChoice == 2)
        {
            result = IterativeSearch(root, key);
        }
        else
        {
            cout << "Invalid search choice!\n";
        }

        if (result)
        {
            cout << "Key " << key << " found at node with address: " << result << "\n";
        }
    }
};

int main()
{
    BinarySearchTree tree;
    int choice;

    do
    {
        cout << "\nBinary Tree Menu:\n";
        cout << "[1] Create Binary Tree\n";
        cout << "[2] Insert Node\n";
        cout << "[3] Display Tree Traversals\n";
        cout << "[4] Search for a Key\n";
        cout << "[5] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tree.CreateBST();
            break;
        case 2:
            if (tree.root == nullptr)
            {
                cout << "Tree is empty. Create a tree first!\n";
            }
            else
            {
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                tree.InsertNode(tree.root, val);
            }
            break;
        case 3:
            tree.displayBinaryTree();
            break;
        case 4:
            tree.searchBST();
            break;
        case 5:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
