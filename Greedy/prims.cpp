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

// Function to find the minimum spanning tree using Prim's algorithm
int prims(int s) {
    int n = graph.size();
    vector<bool> visited(n, false);
    dis.assign(n+1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Start from the specified vertex
    pq.push(make_pair(0, s));
    int cost = 0;
    dis[s] = 0;
    while (!pq.empty()) {
        auto currentEdge = pq.top();
        pq.pop();
        int u = currentEdge.second;
        int w = currentEdge.first;

        // If the vertex has already been visited, skip it
        if (visited[u]) {
            continue;
        }

        // Mark the current vertex as visited
        visited[u] = true;

        // Add the current edge cost to the minimum spanning tree
        cost += w;

        // Explore all adjacent vertices
        for (auto neighbor : graph[u]) {
            int v = neighbor.second;
            int weight = neighbor.first;
            if(visited[v]) continue;
            if (weight < dis[v]) {
                dis[v] = weight;
                pq.push(make_pair(weight, v));
            }
        }
    }

    return cost;
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

    std::cout<< "cost is : "<< prims(1) <<endl;

    return 0;
}
