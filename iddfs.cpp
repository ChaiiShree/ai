#include <iostream>
using namespace std;

bool dls(int graph[5][5], bool visited[], int node, int depth) {
    if (depth == 0) return false;
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < 5; i++) {
        if (graph[node][i] && !visited[i]) {
            if (dls(graph, visited, i, depth - 1)) return true;
        }
    }
    return false;
}

void iddfs(int graph[5][5], int start, int maxDepth) {
    for (int depth = 1; depth <= maxDepth; depth++) {
        bool visited[5] = {false};
        if (dls(graph, visited, start, depth)) break;
    }
}

int main() {
    int graph[5][5] = {{0, 1, 0, 1, 0},
                       {1, 0, 1, 1, 0},
                       {0, 1, 0, 0, 1},
                       {1, 1, 0, 0, 1},
                       {0, 0, 1, 1, 0}};
    iddfs(graph, 0, 3);
    return 0;
}
