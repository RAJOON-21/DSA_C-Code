#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int V = 6;

int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = numeric_limits<int>::max();
    int minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printSolution(const vector<int>& dist,int src ) {

    for (int i = 0; i < V; ++i) {
        cout << "Time taken form city "<<src<<" to city "<<i<<" = "<<dist[i]<<endl;
    }
}

void dijkstra(const vector<vector<int>>& graph, int src) {
    vector<int> dist(V, numeric_limits<int>::max());
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!sptSet[v] && graph[u][v] && dist[u] != numeric_limits<int>::max() &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist,src);
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    dijkstra(graph, 5);

    return 0;
}
