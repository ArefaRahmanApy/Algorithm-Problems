#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int l;
        cin >> l;

        vector<vector<int>> graph(n);
        vector<int> color(n, -1); // -1 = uncolored

        for (int i = 0; i < l; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> q;
        bool Bicoloring = true;

        color[0] = 0;
        q.push(0);

        while (!q.empty() && Bicoloring) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    Bicoloring = false;
                    break;
                }
            }
        }

        if (Bicoloring)
            cout << "Bicoloring ." << endl;
        else
            cout << "Not Bicoloring  ." << endl;
    }
}
