#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto it : adj[node]) {
                int nbr = it.first;
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (auto it : adj[node]) {
            int nbr = it.first;
            if (!visited[nbr]) dfsHelper(nbr, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        dfsHelper(start, visited);
        cout << endl;
    }

    void Dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int nextNode = it.first;
                int edgeWeight = it.second;

                if (dist[node] + edgeWeight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + edgeWeight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        cout << "Dijkstra Shortest Distances:\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }

    void Prim() {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);

        key[0] = 0;

        for (int i = 0; i < V - 1; i++) {
            int minKey = INT_MAX, u = -1;

            for (int v = 0; v < V; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            inMST[u] = true;

            for (auto it : adj[u]) {
                int v = it.first;
                int w = it.second;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        cout << "Prim's MST:\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << endl;
        }
    }
};

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u != v) {
            if (rank[u] < rank[v]) parent[u] = v;
            else if (rank[u] > rank[v]) parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
};

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void Kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    DisjointSet ds(V);

    cout << "Kruskal's MST:\n";
    for (auto e : edges) {
        int pu = ds.findParent(e.u);
        int pv = ds.findParent(e.v);

        if (pu != pv) {
            cout << e.u << " - " << e.v << " (weight " << e.w << ")\n";
            ds.unionSet(pu, pv);
        }
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);

    cout << "\n--- BFS ---\n";
    g.BFS(0);

    cout << "\n--- DFS ---\n";
    g.DFS(0);

    cout << "\n--- Dijkstra ---\n";
    g.Dijkstra(0);

    cout << "\n--- Prim ---\n";
    g.Prim();

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3}
    };

    cout << "\n--- Kruskal ---\n";
    Kruskal(5, edges);

    return 0;
}

