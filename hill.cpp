#include <iostream>
using namespace std;

int heuristic[5] = {10, 8, 6, 4, 2}; // Example heuristic values

void hill_climbing(int graph[5][5], int start, int goal) {
    int current = start;
    bool visited[5] = {false};

    while (current != goal) {
        visited[current] = true;
        cout << current << " ";

        int next = -1, minHeuristic = INT_MAX;

        for (int i = 0; i < 5; i++) {
            if (graph[current][i] && !visited[i] && heuristic[i] < minHeuristic) {
                minHeuristic = heuristic[i];
                next = i;
            }
        }

        if (next == -1) {
            cout << "Stuck at local optimum!" << endl;
            return;
        }
        current = next;
    }
    cout << goal << endl;
}

int main() {
    int graph[5][5] = {{0, 1, 4, 0, 0},
                       {1, 0, 2, 7, 0},
                       {4, 2, 0, 0, 3},
                       {0, 7, 0, 0, 1},
                       {0, 0, 3, 1, 0}};
    hill_climbing(graph, 0, 4);
    return 0;
}
