#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;
using pii = std::pair<int, int>;
const int INF = 1e9+7;
const int N = 1e7 + 7;

// Define a pair for representing edges (weight, destination vertex)
std::vector<std::vector<pii>> graph(N);
std::vector<int> dis;

// Function to find the sssp using dijkstra's algorithm
void dijkstra(int s) {
    int n = graph.size();
    dis.assign(n+1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Start from the specified vertex
    pq.push(make_pair(0, s));
    dis[s] = 0;
    while (!pq.empty()) {
        auto currentEdge = pq.top();
        pq.pop();
        int u = currentEdge.second;
        int w = currentEdge.first;

        // If the vertex has already been visited, skip it
        if (dis[u] != w) continue;

        // Explore all adjacent vertices
        for (auto neighbor : graph[u]) {
            int v = neighbor.second;
            int weight = neighbor.first;
            if (dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;

    // Read the edges and their weights
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(weight, v));
        graph[v].push_back(make_pair(weight, u)); // For undirected graph
    }

    dijkstra(1);
    std::cout<< "shortest path from 1->6 is: " << dis[6];
    return 0;
}
