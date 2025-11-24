#include <bits/stdc++.h>
using namespace std;

struct Edge {
    long long from;
    long long to;
    long long weight;
};

bool detectNegativeCycle(long long numNodes, const vector<Edge>& edges) {
    const long long INF = LLONG_MAX;
    vector<long long> distance(numNodes, INF);
    distance[0] = 0;

    for (long long i = 0; i < numNodes - 1; i++) {
        for (const auto& edge : edges) {
            if (distance[edge.from] != INF && distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges) {
        if (distance[edge.from] != INF && distance[edge.from] + edge.weight < distance[edge.to]) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long testCases;
    cin >> testCases;

    while (testCases--) {
        long long numNodes, numEdges;
        cin >> numNodes >> numEdges;

        vector<Edge> edges(numEdges);
        for (long long i = 0; i < numEdges; i++) {
            cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        }

        if (detectNegativeCycle(numNodes, edges))
            cout << "possible"<<endl;
        else
            cout << "not possible"<<endl;
    }

    return 0;
}
