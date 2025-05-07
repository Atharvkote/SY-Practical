#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

class OBST
{
public:
    Node *obst_root;
    int key[10];
    int success[10];
    int failure[11];
    int cost[11][11];
    int weight[11][11];
    int root[11][11];
    int number_of_keys;

    OBST()
    {
        cout << "Enter Number of Keys: ";
        cin >> number_of_keys;

        cout << "Enter keys (sorted):\n";
        for (int i = 0; i < number_of_keys; i++)
        {
            cout << "Key[" << i << "]: ";
            cin >> key[i];
        }

        cout << "Enter success probabilities P[i] (for each key):\n";
        for (int i = 0; i < number_of_keys; i++)
        {
            cout << "P[" << i << "]: ";
            cin >> success[i];
        }

        cout << "Enter failure probabilities Q[i] (n+1 values):\n";
        for (int i = 0; i <= number_of_keys; i++)
        {
            cout << "Q[" << i << "]: ";
            cin >> failure[i];
        }

        for (int i = 0; i <= number_of_keys; i++)
        {
            for (int j = 0; j <= number_of_keys; j++)
            {
                cost[i][j] = 0;
                weight[i][j] = 0;
                root[i][j] = 0;
            }
        }
    }

    void calculate_weight()
    {
        for (int i = 0; i <= number_of_keys; i++)
        {
            for (int j = i; j <= number_of_keys; j++)
            {
                if (i == j)
                    weight[i][j] = failure[i];
                else
                    weight[i][j] = weight[i][j - 1] + success[j - 1] + failure[j];
            }
        }
    }

    void calculate_cost()
    {
        for (int i = 0; i <= number_of_keys; i++)
        {
            cost[i][i] = failure[i];
        }

        for (int length = 1; length <= number_of_keys; length++)
        {
            for (int i = 0; i <= number_of_keys - length; i++)
            {
                int j = i + length;
                cost[i][j] = INT_MAX;

                for (int r = i + 1; r <= j; r++)
                {
                    int temp = cost[i][r - 1] + cost[r][j] + weight[i][j];
                    if (temp < cost[i][j])
                    {
                        cost[i][j] = temp;
                        root[i][j] = r;
                    }
                }
            }
        }
    }

    Node *obst_constructor(int i, int j)
    {
        if (i > j || root[i][j] == 0)
            return nullptr;

        int r = root[i][j];
        Node *node = new Node(key[r - 1]);

        node->left = obst_constructor(i, r - 1);
        node->right = obst_constructor(r + 1, j);

        return node;
    }

    Node *construct_tree()
    {
        obst_root = obst_constructor(0, number_of_keys);
        //    cout << "\nOptimal BST Root Key: " << obst_root->key << endl;
        return obst_root;
    }

    void preorder(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->key << " ,";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->key << " ,";
        inorder(root->right);
    }
    void postorder(Node *root)
    {
        if (root == nullptr)
            return;
        postorder(root->left);
        cout << root->key << " ,";
        postorder(root->right);
    }

    void display()
    {
        cout << "\nCost Matrix:\n";
        for (int i = 0; i <= number_of_keys; i++)
        {
            cout << "Case :: j - i = " << i << " :::: ";
            for (int j = 0; j <= number_of_keys; j++)
                if (cost[i][j] != 0 && cost[i][j] != INT_MAX)
                    cout << "C[" << i << "]" << "[" << j << "] :: " << cost[i][j] << " ,";
            cout << endl;
        }

        cout << "\nRoot Matrix:\n";
        for (int i = 0; i <= number_of_keys; i++)
        {
            cout << "Case :: j - i = " << i << " :::: ";
            for (int j = 0; j <= number_of_keys; j++)
                if (root[i][j] != 0 && root[i][j] != INT_MAX)
                    cout << "R[" << i << "]" << "[" << j << "] :: " << root[i][j] << " ,";
            cout << endl;
        }

        cout << "\nWeight Matrix:\n";
        for (int i = 0; i <= number_of_keys; i++)
        {
            cout << "Case :: j - i = " << i << " :::: ";
            for (int j = 0; j <= number_of_keys; j++)
                if (weight[i][j] != 0 && weight[i][j] != INT_MAX)
                    cout << "W[" << i << "]" << "[" << j << "] :: " << weight[i][j] << " ,";
            cout << endl;
        }
    }
};

int main()
{
    OBST tree;
    tree.calculate_weight();
    tree.calculate_cost();
    tree.display();
    tree.construct_tree();
    cout << "\nPreorder Traversal of the Optimal BST ::: [ ";
    tree.preorder(tree.obst_root);
    cout << " ]\n";
    cout << "\nInorder Traversal of the Optimal BST  ::: [ ";
    tree.inorder(tree.obst_root);
    cout << " ]\n";
    cout << "\nPostorder Traversal of the Optimal BST ::: [ ";
    tree.postorder(tree.obst_root);
    cout << " ]\n";
    return 0;
}
