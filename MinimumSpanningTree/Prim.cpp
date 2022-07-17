#include<bits/stdc++.h>
using namespace std;
struct Edge {
  int v1, v2, w;
  Edge(int _v1, int _v2, int _w) {
    v1 = _v1;
    v2 = _v2;
    w = _w;
  }
};
struct Compare {
  bool operator()(Edge e1, Edge e2) {
    return e1.w > e2.w;
  }
};
vector<Edge> Prim(vector<Edge> adj[], int nV) {
  vector<Edge> res;
  vector<int> dis(nV + 1, 1e9);
  vector<bool> visited(nV + 1, false);
  priority_queue<Edge, vector<Edge>, Compare> pq;
  pq.push(Edge(1, 1, 0));
  dis[1] = 0;
  while (!pq.empty()) {
    Edge eTop = pq.top(); pq.pop();
    int vTop = eTop.v2;
    if (visited[eTop.v2]) continue;
    visited[eTop.v2] = true;
    for (Edge e : adj[vTop]) {
      if (visited[e.v2] && dis[e.v2] <= eTop.w) continue;
      dis[e.v2] = eTop.w;
      pq.push(e);
    }
    if (vTop != 1) {
      res.push_back(eTop);
      if (res.size() == nV - 1) break;
    }
  }
  return res;
}
void addEdge(vector<Edge> adj[], int v1, int v2, int w) {
  adj[v1].push_back(Edge(v1, v2, w));
  adj[v2].push_back(Edge(v2, v1, w));
}
int main() {
  int n, m, v1, v2, w;
  cin >> n >> m;
  vector<Edge> adj[n + 1];
  for (int i = 0;i < m;i++) {
    cin >> v1 >> v2 >> w;
    addEdge(adj, v1, v2, w);
  }
  long long res = 0;
  for (Edge e : Prim(adj, n)) {
    res += e.w;
  }
  cout << res << endl;
  return 0;
}