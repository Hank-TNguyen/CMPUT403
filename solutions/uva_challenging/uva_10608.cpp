/* UVa problem: 10608
 *
 * Topic: Data structure
 *
 * Level: challenging
 *
 * Brief problem description:
 *
 *   Given a graph, find the largest connected components
 *
 * Solution Summary:
 *
 *   Graph - connected components
 *
 * Used Resources:
 *
 *   https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * Hung Nguyen
 */


#include <iostream>
#include <list>
using namespace std;

class Graph {
    // No. of vertices
    long long V;

    long long max_len;
    // Pointer to an array containing adjacency lists
    list<long long> *adj;
    list<long long> *connected;
    // A function used by DFS
    void DFSUtil(long long v, bool visited[], long long w);
public:
    Graph(long long  V);   // Constructor
    void addEdge(long long v, long long w);
    void connectedComponents();
};

void Graph::connectedComponents() {
    max_len = 0;
    bool *visited = new bool[V];
    for (long long v = 0; v < V; v++)
        visited[v] = false;

    for (long long v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited, v);

            long long count = 0;

            list<long long>::iterator i;
            for(i = connected[v].begin(); i != connected[v].end(); ++i)
                count++;

            max_len = max(max_len, count);
        }
    }
    cout << max_len << endl;
}

void Graph::DFSUtil(long long v, bool visited[], long long w) {
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    connected[w].push_back(v);
    list<long long>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited, w);
}

Graph::Graph(long long V) {
    this->V = V;
    adj = new list<long long>[V];
    connected = new list<long long>[V];
}

void Graph::addEdge(long long v, long long w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main() {

    int T;

    cin >> T;

    while (T--) {
        long long N, M;
        cin >> N >> M;
        Graph g(N + 1);
        while (M--) {
            long long f1, f2;
            cin >> f1 >> f2;

            g.addEdge(f1, f2);
        }

        g.connectedComponents();
    }
    return 0;
}