/**
 * 최소비용 구하기 2
 * 다익스트라 (G3)
 */
#include <bits/stdc++.h>
using namespace std;

// init
int n,m; // n 개 도시, m 개 버스
int s,e;
vector<pair<int,int>> graph[1001];
int dist[1001];
int pre[1001];

void solution() {

    priority_queue<pair<int,int>> pq;
    pq.push({0,s});
    dist[s]=0;
    pre[s]=s;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int v = cur.second;
        int w = -cur.first;

        if (dist[v]<w)  continue;

        for (auto g : graph[v]) {
            int next = g.first;
            int cost = g.second + w;
            if (cost < dist[next]) {
                dist[next] = cost;
                pq.push({-cost,next});
                pre[next]=v;
            }
        }
    }

    // path 확인
    int cur = e;
    vector<int> path;
    while (cur!=s) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(s);
    reverse(path.begin(),path.end());

    // print
    cout << dist[e] << '\n';
    cout << path.size() << '\n';
    for (auto p : path)
        cout << p << ' ';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    fill(dist,dist+n+1,INT_MAX);
    cin >> s >> e;

    solution();

    return 0;
}