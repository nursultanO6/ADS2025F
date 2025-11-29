#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> isRed(n + 1, false);
    while (q--) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            isRed[v] = true;
        } else {
            if (isRed[v]) {
                cout << 0 << endl;
                continue;
            }
            vector<bool> visited(n + 1, false);
            queue<pair<int,int>> qBFS;
            qBFS.push({v, 0});
            visited[v] = true;
            int answer = -1;
            while (!qBFS.empty()) {
                auto [u, dist] = qBFS.front();
                qBFS.pop();
                for (int nei : adj[u]) {
                    if (!visited[nei]) {
                        if (isRed[nei]) {
                            answer = dist + 1;
                            qBFS = queue<pair<int,int>>();
                            break;
                        }
                        visited[nei] = true;
                        qBFS.push({nei, dist + 1});
                    }
                }
            }
            cout << answer << endl;
        }
    }
    return 0;
}
