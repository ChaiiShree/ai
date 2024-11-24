#include <iostream>
using namespace std;

void dfs(int graph[5][5], bool visited[], int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < 5; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

int main() {
    int graph[5][5] = {{0, 1, 0, 1, 0},
                       {1, 0, 1, 1, 0},
                       {0, 1, 0, 0, 1},
                       {1, 1, 0, 0, 1},
                       {0, 0, 1, 1, 0}};
    bool visited[5] = {false};
    dfs(graph, visited, 0);
    return 0;
}
