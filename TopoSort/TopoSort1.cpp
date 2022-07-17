#include<bits/stdc++.h>
using namespace std;
vector<int> TopoSort(vector<int> adj[], int nV) {
  vector<int> inDegrees(nV + 1, 0), res;
  for (int i = 1;i <= nV;i++) {
    for (int v : adj[i]) inDegrees[v] += 1;
  }
  queue<int> q;
  for (int i = 1;i <= nV;i++) {
    if (inDegrees[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int fV = q.front();q.pop();
    res.push_back(fV);
    for (int v : adj[fV]) {
      inDegrees[v] -= 1;
      if (inDegrees[v] == 0) q.push(v);
    }
  }
  return res;
}
void addEdge(vector<int> adj[], int v1, int v2) {
  adj[v1].push_back(v2);
}
int main() {
  int n = 6;
  vector<int> adj[n + 1];
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 4);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 5);
  addEdge(adj, 4, 5);
  addEdge(adj, 4, 6);
  addEdge(adj, 5, 6);
  for (int v : TopoSort(adj, n)) {
    cout << v << " ";
  }
  return 0;
}