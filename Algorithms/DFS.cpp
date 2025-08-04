#include <iostream>
using namespace std;

int v = 5;
int m[10][10] = {{0,1,1,0,0}, {1,0,0,1,1},
        {1,0,0,0,1}, {0,1,0,0,0}, {0,1,1,0,0}};
int visited[10];

void dfs(int m[10][10], int v, int source) {
    visited[source] = 1;
    for (int i = 0; i < v; i++) {
        if (m[source][i] == 1 && visited[i] == 0) {
            cout << i << "\t";
            dfs(m, v, i);
        }
    }
}

int main() {
    int source;
    for (int i = 0; i < v; i++)
        visited[i] = 0;

    cout << "Enter the source vertex: ";
    cin >> source;

    cout << "The DFS Traversal is... \n";
    cout << source << "\t";
    dfs(m, v, source);

    return 0;
}