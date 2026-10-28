#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(int start, vector<int> adj[], int n) {
    bool visited[100] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";
        for (int neighbour : adj[vertex]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
int main() {
    int n, e, u, v, start;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<int> adj[100];
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter starting vertex: ";
    cin >> start;
    BFS(start, adj, n);
    return 0;
}