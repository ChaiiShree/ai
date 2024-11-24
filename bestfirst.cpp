#include <iostream>
#include <set>
using namespace std;

int heuristic[5] = {10, 8, 6, 4, 2}; // Example heuristic values

void best_first_search(int graph[5][5], int start, int goal) {
    bool visited[5] = {false};
    set<pair<int, int>> pq;
    pq.insert({heuristic[start], start});

    while (!pq.empty()) {
        int current = pq.begin()->second;
        pq.erase(pq.begin());

        if (visited[current]) continue;
        visited[current] = true;

        cout << current << " ";
        if (current == goal) return;

        for (int i = 0; i < 5; i++) {
            if (graph[current][i] && !visited[i]) {
                pq.insert({heuristic[i], i});
            }
        }
    }
}

int main() {
    int graph[5][5] = {{0, 1, 4, 0, 0},
                       {1, 0, 2, 7, 0},
                       {4, 2, 0, 0, 3},
                       {0, 7, 0, 0, 1},
                       {0, 0, 3, 1, 0}};
    best_first_search(graph, 0, 4);
    return 0;
}
