#include <bits/stdc++.h>
using namespace std;

int dr[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dc[8] = { 1, -1,  1, -1, 2, -2,  2, -2 };

pair<int,int> convert(string s) {
    int col = s[0] - 'a';
    int row = s[1] - '1';
    return {row, col};
}

int knight_moves(int sr, int sc, int er, int ec)
{
    const int N = 8;

    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int,int>> q;

    dist[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int r = cur.first;
        int c = cur.second;

        if (r == er && c == ec)
            return dist[r][c];

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < N && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;

    while (cin >> s1 >> s2) {

        auto start = convert(s1);
        auto endp = convert(s2);

        int sr = start.first,  sc = start.second;
        int er = endp.first,   ec = endp.second;

        int steps = knight_moves(sr, sc, er, ec);

        cout << "To get from " << s1 << " to " << s2
             << " takes " << steps << " knight moves.\n";
    }

    return 0;
}
