#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct edge {
    int u, v;
};

int cube(int a) {
    return a * a * a;
}

int main() {
    int set_Count = 1;
    int n;

    while (cin >> n) {

        vector<int> busyness(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> busyness[i];

        int red;
        cin >> red;
        vector<edge> edges(red);

        for (int i = 0; i < red; ++i)
            cin >> edges[i].u >> edges[i].v;

        
        int q;
        cin >> q;
        vector<int> queries(q);

        for (int i = 0; i < q; ++i)
            cin >> queries[i];

        vector<int> distance(n + 1, INF);
        distance[1] = 0;

        for (int i = 1; i < n; ++i) {
            for (const auto& e : edges) {
                int u = e.u;
                int v = e.v;

                int cost = cube(busyness[v] - busyness[u]);

                if (distance[u] != INF && distance[u] + cost < distance[v]) {
                    distance[v] = distance[u] + cost;
                }
            }
        }

        cout << "Set " << set_Count++ << endl;
        for (int target : queries) {
            if (target < 1 || target > n || distance[target] == INF || distance[target] < 3)
                cout << "? " <<endl;
            else
                cout << distance[target] << endl;
        }
    }
}
