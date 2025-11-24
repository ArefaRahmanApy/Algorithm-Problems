#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Wormhole {
    int start;
    int end;
    int time;
};

int bellman_ford(int x, int y, const vector<Wormhole>& wormholes) {
    vector<ll> distance(x, INF);
    distance[0] = 0;
    for (int i = 0; i <x-1; ++i) {
        bool relaxedin_pass = false;
        for (const auto& w : wormholes) {
            if (distance[w.start] != INF) {
                if (distance[w.start] + w.time < distance[w.end]) {
                    distance[w.end] = distance[w.start] + w.time;
                    relaxedin_pass = true;
                }
            }
        }
        if (!relaxedin_pass){  
        break;
        }
    }
    for (const auto& w : wormholes) {
        if (distance[w.start] != INF) {
            if (distance[w.start] + w.time < distance[w.end]) {
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    int x,y;
    if (!(cin >>x>>y)) {
        return;
    }

    vector<Wormhole> wormholes;
    for (int i = 0; i < y; ++i) {
        int n, m, t;
        cin >> n >> m  >> t;
        wormholes.push_back({n, m, t});
    }
    if (bellman_ford(x, y, wormholes) == 1) {
        cout << "possible" << endl;
    } else {
        cout << "not possible" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    if (!(cin >>c)){
        return 0;
    }
    while (c--) {
        solve();
    }
}
