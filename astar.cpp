#include <iostream>
#include <set>
#include <climits>
using namespace std;

int heuristic[5] = {10, 8, 6, 4, 2}; // Example heuristic values

void a_star(int graph[5][5], int start, int goal) {
    int cost[5] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    cost[start] = 0;

    set<pair<int, int>> openSet;
    openSet.insert({heuristic[start], start});

    while (!openSet.empty()) {
        int current = openSet.begin()->second;
        openSet.erase(openSet.begin());

        if (current == goal) {
            cout << "Goal reached with cost: " << cost[goal] << endl;
            return;
        }

        for (int i = 0; i < 5; i++) {
            if (graph[current][i]) {
                int newCost = cost[current] + graph[current][i];
                if (newCost < cost[i]) {
                    cost[i] = newCost;
                    openSet.insert({newCost + heuristic[i], i});
                }
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
    a_star(graph, 0, 4);
    return 0;
}
