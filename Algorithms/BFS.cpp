#include <iostream>
using namespace std;

void bfs(int V, vector<vector<int>>& adj, int src) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    bfs(V, adj, 0);
    return 0;
}
