#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cassert>

using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

vector<int> dijkstra(int n, int src, const vector<vector<pii>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 4;
    vector<vector<pii>> adj(n);
    adj[0].push_back({4, 1});
    adj[0].push_back({1, 2});
    adj[2].push_back({2, 1});
    adj[1].push_back({1, 3});

    vector<int> d = dijkstra(n, 0, adj);
    assert(d[3] == 4);
    cout << "Dijkstra shortest path verified." << endl;
    return 0;
}

// Updated: 2018-08-20 - feat(graphs): Dijkstra shortest path using std::priority_queue
