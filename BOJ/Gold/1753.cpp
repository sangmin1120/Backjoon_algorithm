/**
 * 최단 경로: 가중치 10 이하 자연수, 우선 순위 큐
 * Dijkstra (G4)
 */
#include <bits/stdc++.h>
using namespace std;

// init
int count_v, count_e; // 정점 수, 엣지 수
int start_v; // 시작 정점
vector<vector<pair<int,int>>> graph(20001); // v1 -> v2, w
int dist[20001];

void solution() {

    priority_queue<pair<int,int>> pq; // -(w),v
    pq.push({0,start_v});
    dist[start_v]=0;

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int w = -cur.first;
        int v = cur.second;

        for (auto target : graph[v]) {
            int target_v = target.first;
            int target_w = target.second;

            if (dist[target_v] > w+target_w) {
                dist[target_v] = w+target_w;
                pq.push({-dist[target_v], target_v});
            }
        }
    }

    // print
    for (int i=1;i<=count_v;i++) {
        if (dist[i] == INT_MAX)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> count_v >> count_e;
    cin >> start_v;

    fill(dist,dist+count_v+1,INT_MAX);
    for (int i=0;i<count_e;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        graph[a].push_back({b,w});
    }

    solution();

    return 0;
}
