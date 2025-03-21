#include <iostream>

using namespace std;

class Graph {
    int n;  
    int adjMat[10][10];  
    int adjList[10][10]; 
    int listSize[10];    

public:
    Graph(int size) {
        n = size;
        for (int i = 0; i < n; i++) {
            listSize[i] = 0;
            for (int j = 0; j < n; j++) {
                adjMat[i][j] = 0;
                adjList[i][j] = -1; 
            }
        }
    }

    void addEdge(int u, int v) {
        if (u >= n || v >= n || u < 0 || v < 0) {
            cout << "Invalid Edge!" << endl;
            return;
        }
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; 
        adjList[u][listSize[u]++] = v;
        adjList[v][listSize[v]++] = u;
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayList() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int j = 0; j < listSize[i]; j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size, choice, u, v;
    cout << "Enter number of nodes: ";
    cin >> size;
    
    Graph g(size);

    do {
        cout << "\nGraph Menu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Display Adjacency List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.addEdge(u, v);
                break;
            case 2:
                g.displayMatrix();
                break;
            case 3:
                g.displayList();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}