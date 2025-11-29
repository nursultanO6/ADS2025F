#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : g[v]) {
            if (!visited[to]) {
                visited[to] = true;
                q.push(to);
            }
        }
    }

    if (visited[f])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
