#include <bits/stdc++.h>
using namespace std;

int bfsShortestPath(int startNode, int endNode, vector<vector<int>>& graph) {
    vector<int> distance(21, -1);
    queue<int> q;

    distance[startNode] = 0;
    q.push(startNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (distance[next] == -1) {
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }

    return distance[endNode];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testNumber = 1;

    while (true) {
        vector<vector<int>> graph(21);
        int connectionCount;

        if (!(cin >> connectionCount)) 
            return 0;

        for (int node = 1; node <= 19; node++) {
            if (node != 1)
                cin >> connectionCount;

            for (int i = 0; i < connectionCount; i++) {
                int neighbor;
                cin >> neighbor;

                graph[node].push_back(neighbor);
                graph[neighbor].push_back(node);
            }
        }

        int queries;
        cin >> queries;

        cout << "Test Set #" << testNumber++ << endl;

        while (queries--) {
            int A, B;
            cin >> A >> B;

            int result = bfsShortestPath(A, B, graph);

            cout << setw(2) << A << " to "
                 << setw(2) << B << ": "
                 << result << "\n";
        }

        cout << endl;
    }

    return 0;
}
