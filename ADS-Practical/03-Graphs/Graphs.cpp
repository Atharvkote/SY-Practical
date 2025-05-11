#include <iostream>
#include <vector>

using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
};

class Graph {
private:
    int matrix[100][100];  
    vector<vector<Edge>> adj_list;
    int n;

public:
    Graph(int n) {
        this->n = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
        adj_list = vector<vector<Edge>>(n);
    }

    void add_edge(int src, int dest, int wt) {
        matrix[src][dest] = wt;
        matrix[dest][src] = wt;
        adj_list[src].push_back(Edge(src, dest, wt));
        adj_list[dest].push_back(Edge(dest, src, wt));
    }

    void print_matrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void print_list() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < n; ++i) {
            cout << i << " -> ";
            for (int j = 0; j < adj_list[i].size(); ++j) {
                Edge e = adj_list[i][j];
                cout << "(" << e.dest << ", wt=" << e.weight << ") ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int choice;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Graph g(n);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Display Adjacency List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int src, dest, wt;
                cout << "Enter source, destination, weight: ";
                cin >> src >> dest >> wt;
                if (src >= n || dest >= n || src < 0 || dest < 0) {
                    cout << "Invalid nodes!\n";
                } else {
                    g.add_edge(src, dest, wt);
                }
                break;
            }
            case 2:
                g.print_matrix();
                break;
            case 3:
                g.print_list();
                break;
            case 4:
                cout << "Exiting.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
