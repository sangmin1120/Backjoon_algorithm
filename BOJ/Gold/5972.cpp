/**
 * 택배 배송
 * BFS (G5)
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> graph[50001];
int dist[50001];

void solution() {

    queue<int> q;
    int s = 1;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto g : graph[cur]) {
            int next = g.first;
            int w = g.second + dist[cur];

            if (w < dist[next]) {
                dist[next] = w;
                q.push(next);
            }
        }
    }

    cout << dist[n] << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //input
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    fill(dist,dist+n+1,INT_MAX);

    solution();

    return 0;
}
