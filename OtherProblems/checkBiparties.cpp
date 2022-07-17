#include<bits/stdc++.h>
using namespace std;
void checkBiparties(int cV, vector<int> adj[], vector<int>& side, bool& res) {
  for (int v : adj[cV]) {
    if (side[v] == -1) {
      side[v] = 1 - side[cV];
      checkBiparties(v, adj, side, res);
    }
    else if (side[v] == side[cV]) {
      res = false;
      return;
    }
  }
}
void addEdge(vector<int> adj[], int v1, int v2) {
  adj[v1].push_back(v2);
  adj[v2].push_back(v1);
}

int main() {
  int nV, nE;cin >> nV >> nE;
  vector<int> side(nV + 1, -1), adj[nV + 1];
  int v1, v2;
  for (int i = 1;i <= nE;i++) {
    cin >> v1 >> v2;
    addEdge(adj, v1, v2);
  }
  bool res = true;
  for (int i = 1;i <= nV;i++) {
    if (!res || side[i] != -1) continue;
    side[i] = 0;
    checkBiparties(i, adj, side, res);
  }
  cout << res << endl;
  return 0;
}