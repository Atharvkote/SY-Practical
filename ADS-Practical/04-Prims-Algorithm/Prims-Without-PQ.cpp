#include<iostream>
#include<climits>
#include<string>
#include<vector>
using namespace std;
class prims
{
public:
    int mat[20][20];
    int V, e, ver1, ver2 , cost;
    vector<string> start;
    vector<int> Final;
    vector<pair<string, string>> mstEdges;
    vector<int> mstWeights;

    prims(int vertices , int cst)
    {
        V = vertices;
        cost = cst;
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                mat[i][j] = 0;
            }
        }

        for(int i = 0; i < V; i++)
        {
            string vertex;
            cout << "Enter the city " << i + 1 << " : ";
            cin >> vertex;
            start.push_back(vertex);
            Final.push_back(-1);
        }
    }

    void addEdge(string a, string b, int w)
    {
        for(int i = 0; i < V; i++)
        {
            if(a == start[i]) ver1 = i;
            if(b == start[i]) ver2 = i;
        }
        mat[ver1][ver2] = w;
        mat[ver2][ver1] = w;
    }

    void displayAdjList()
    {
        cout << "\nAdjacency List:\n";
        for(int i = 0; i < V; i++)
        {
            cout << start[i] << " -> ";
            for(int j = 0; j < V; j++)
            {
                if(mat[i][j] != 0)
                {
                    cout << "(" << start[j] << ", " << mat[i][j] << ") ";
                }
            }
            cout << endl;
        }
    }

    void prim()
    {
        Final[0] = 1;
        
        int min, u = 0, v = 0;

        for(int k = 0; k < V - 1; k++)
        {
            min = INT_MAX;

            for(int i = 0; i < V; i++)
            {
                if(Final[i] == 1)
                {
                    for(int j = 0; j < V; j++)
                    {
                        if(mat[i][j] != 0 && Final[j] == -1 && mat[i][j] < min)
                        {
                            min = mat[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }

            Final[v] = 1;
            mstEdges.push_back({start[u], start[v]});
            mstWeights.push_back(min);
        }

        cout << "\nConnections between cities :\n";
        int totalWeight = 0;
        for(int i = 0; i < mstEdges.size(); i++)
        {
            cout << mstEdges[i].first << " <-> " << mstEdges[i].second 
                 << " Distance of " << mstWeights[i] <<" KM "<< endl;
            totalWeight += mstWeights[i];
        }
        cout << "Total Distance for road construction in KM " << totalWeight << endl;
        cout << "Total cost for construction (in lakhs) : " << totalWeight*cost << endl;
        
        
        
    }
};

int main()
{
    int v, e ,cst;
    cout << "Enter the no. of cities : ";
    cin >> v;
    cout << "Enter the no. of roads : ";
    cin >> e;
    cout << "Enter cost of construction per KM (in lakhs) : ";
    cin >> cst;

    prims graph(v , cst);

    for(int i = 0; i < e; i++)
    {
        string a, b;
        int w;
        cout << "Enter edge " << i + 1 << " (format: city-1 city-2 distance): ";
        cin >> a >> b >> w;
        graph.addEdge(a, b, w);
    }

    //graph.displayAdjList();
    graph.prim();

    return 0;
}