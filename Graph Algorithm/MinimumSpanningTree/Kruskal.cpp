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
class DisjoinSet {
  vector<int> parrents;
public:
  DisjoinSet(int n) {
    parrents.resize(n + 1);
    for (int i = 1;i <= n;i++) parrents[i] = i;
  }
  void unite(int x1, int x2) {
    parrents[find(x1)] = find(x2);
  }
  int find(int x) {
    if (parrents[x] == x) return x;
    parrents[x] = find(parrents[x]);
    return parrents[x];
  }
};
vector<Edge> Kruskal(int nV, vector<Edge> edges) {
  vector<Edge> res;
  DisjoinSet djs(edges.size() + 1);
  sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) {
    return e1.w < e2.w;
       });
  for (Edge e : edges) {
    if (djs.find(e.v1) == djs.find(e.v2)) continue;
    res.push_back(e);
    djs.unite(e.v1, e.v2);
    if (res.size() == nV - 1) break;
  }
  return res;
}
int main() {
  int n, m, v1, v2, w;
  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0;i < m;i++) {
    cin >> v1 >> v2 >> w;
    edges.push_back(Edge(v1, v2, w));
  }
  long long res = 0;
  for (Edge e : Kruskal(n, edges)) res += e.w;
  cout << res << endl;
  return 0;
}