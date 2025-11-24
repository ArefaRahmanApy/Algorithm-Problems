#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

struct Edge {
    int to;
    int weight;
};

int find_Second_ShortestPath() {
    int N, R;
    if (!(cin >> N >> R)) return -1;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < R; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> shortest(N + 1, INF);
    vector<int> second_Shortest(N + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    shortest[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [current_Distance, u] = pq.top();
        pq.pop();

        if (current_Distance > second_Shortest[u])
            continue;

        for (auto e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            int newDistance = current_Distance + w;

            if (newDistance < shortest[v]) {
                second_Shortest[v] = shortest[v];
                shortest[v] = newDistance;
                pq.push({shortest[v], v});
            } else if (newDistance > shortest[v] && newDistance < second_Shortest[v]) {
                second_Shortest[v] = newDistance;
                pq.push({second_Shortest[v], v});
            }
        }
    }

    return (second_Shortest[N] == INF ? -1 : second_Shortest[N]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int result = find_Second_ShortestPath();
        if (result != -1)
            cout << "Case " << caseNum << ": " << result << "\n";
        else
            cout << "Case " << caseNum << ": No second shortest path\n";
    }

    return 0;
}

