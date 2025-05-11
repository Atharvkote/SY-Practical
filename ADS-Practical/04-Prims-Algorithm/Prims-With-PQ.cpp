#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Edge
{
public:
    int source, destination, weight;

    Edge(int src, int dest, int w)
    {
        source = src;
        destination = dest;
        weight = w;
    }

    // PQ Comparator
    bool operator>(const Edge &other) const
    {
        return weight > other.weight;
    }
};

void createGraph(vector<vector<Edge>> &adjacencyList, int edges, int vertices)
{
    cout << "\nEnter the edges in the format: source destination weight\n";
    for (int i = 0; i < edges; i++)
    {
        int src, dest, weight;
        cout << "Source: ";
        cin >> src;
        cout << "Destination: ";
        cin >> dest;
        cout << "Weight: ";
        cin >> weight;

    
        if (src < 1 || src > vertices || dest < 1 || dest > vertices)
        {
            cout << "Invalid edge! Please enter vertices between 1 and " << vertices << endl;
            i--;  
            continue;
        }

        adjacencyList[src].push_back(Edge(src, dest, weight));
        adjacencyList[dest].push_back(Edge(dest, src, weight));   // Un-driected graPh
    }
    cout << "\nGraph Created...\n";
}

void primsAlgorithm(vector<vector<Edge>> &adjacencyList, int vertices)
{
    vector<bool> visited(vertices + 1, false);    
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;

    visited[1] = true;

    // Push all edges from vertex 1
    for (const auto &edge : adjacencyList[1])
    {
        minHeap.push(edge);
    }

    int minWeight = 0;
    vector<Edge> mst;

    while (!minHeap.empty() && mst.size() < vertices - 1)
    {
        Edge current = minHeap.top();
        minHeap.pop();

        int dest = current.destination;
        int weight = current.weight;

        if (!visited[dest])
        {
            visited[dest] = true;
            minWeight += weight;
            mst.push_back(current);

            for (const auto &edge : adjacencyList[dest])
            {
                if (!visited[edge.destination])
                {
                    minHeap.push(edge);
                }
            }
        }
    }

    cout << "\nMinimum Spanning Tree (MST) Edges:\n";
    for (const auto &edge : mst)
    {
        cout << edge.source << " - " << edge.destination << " (Weight: " << edge.weight << ")\n";
    }

    cout << "\nMinimum cost of the spanning tree: " << minWeight << endl;
}

int main()
{
    int vertices, edges;
    cout << "Number of Vertices: ";
    cin >> vertices;
    cout << "Number of Edges: ";
    cin >> edges;

    vector<vector<Edge>> adjacencyList(vertices + 1);  // 1-based indexing
    createGraph(adjacencyList, edges, vertices);
    primsAlgorithm(adjacencyList, vertices);

    return 0;
}
