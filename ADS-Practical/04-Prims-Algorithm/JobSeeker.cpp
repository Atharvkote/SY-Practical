#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Edge {
public:
    int source, destination, weight;

    Edge(int src, int dest, int w) {
        source = src;
        destination = dest;
        weight = w;
    }

    // Min-Heap comparator
    bool operator>(const Edge &other) const {
        return weight > other.weight;
    }
};

void createGraph(vector<vector<Edge>> &adjacencyList, vector<string> &cityNames, int edges, int vertices) {
    cout << "\nEnter the city names:\n";
    for (int i = 0; i < vertices; i++) {
        cout << "City " << i + 1 << ": ";
        cin >> cityNames[i];
    }

    cout << "\nEnter the roads (edges) in the format: [source] [destination] [distance]\n";
    for (int i = 0; i < edges; i++) {
        string srcCity, destCity;
        int weight;
        cout << "Source: ";
        cin >> srcCity;
        cout << "Destination: ";
        cin >> destCity;
        cout << "Distance: ";
        cin >> weight;

        int src = -1, dest = -1;

        // Find the city indices
        for (int j = 0; j < vertices; j++) {
            if (cityNames[j] == srcCity) src = j;
            if (cityNames[j] == destCity) dest = j;
        }

        if (src == -1 || dest == -1 || src == dest) {
            cout << "Invalid cities. Try again.\n";
            i--;
            continue;
        }

        adjacencyList[src].push_back(Edge(src, dest, weight));
        adjacencyList[dest].push_back(Edge(dest, src, weight));  // Undirected graph
    }
    cout << "\nGraph Created...\n";
}

void PrimsAlgorithm(vector<vector<Edge>> &adjacencyList, vector<string> &cityNames, int vertices, int start) {
    vector<bool> visited(vertices, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;

    vector<int> path;
    int totalCost = 0;

    visited[start] = true;
    path.push_back(start);

    for (const auto &edge : adjacencyList[start]) {
        minHeap.push(edge);
    }

    while (!minHeap.empty() && path.size() < vertices) {
        Edge current = minHeap.top();
        minHeap.pop();

        if (!visited[current.destination]) {
            visited[current.destination] = true;
            path.push_back(current.destination);
            totalCost += current.weight;

            for (const auto &edge : adjacencyList[current.destination]) {
                if (!visited[edge.destination]) {
                    minHeap.push(edge);
                }
            }
        }
    }

    for (const auto &edge : adjacencyList[path.back()]) {
        if (edge.destination == start) {
            totalCost += edge.weight;
            path.push_back(start);
            break;
        }
    }

    cout << "\nOptimal Interview Route (TSP using Prim's Algorithm):\n";
    for (size_t i = 0; i < path.size(); i++) {
        cout << cityNames[path[i]];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << "\n\nTotal Travel Distance: " << totalCost << " km\n";
}

int main() {
    int vertices, edges;
    string startCity;

    cout << "Number of Interview Locations (Vertices): ";
    cin >> vertices;
    cout << "Number of Roads (Edges): ";
    cin >> edges;

    vector<vector<Edge>> adjacencyList(vertices);
    vector<string> cityNames(vertices);

    createGraph(adjacencyList, cityNames, edges, vertices);

    cout << "\nEnter your starting city: ";
    cin >> startCity;

    int start = -1;
    for (int i = 0; i < vertices; i++) {
        if (cityNames[i] == startCity) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        cout << "Invalid starting city. Exiting.\n";
        return 0;
    }

    PrimsAlgorithm(adjacencyList, cityNames, vertices, start);

    return 0;
}
