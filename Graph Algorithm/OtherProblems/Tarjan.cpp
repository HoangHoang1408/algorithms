#include<bits/stdc++.h>
#define vi vector<int> 
#define vb vector<bool> 
using namespace std;

struct Edge {
  int v1, v2;
  Edge(int _v1, int _v2) {
    v1 = _v1;
    v2 = _v2;
  }
};

struct GraphInfo {
  vi lowVals, disc;
  GraphInfo(vi lowVals, vi disc) {
    this->lowVals = lowVals;
    this->disc = disc;
  }
};

void addEdge(vector<vi>& adj, int v1, int v2) {
  adj[v1].push_back(v2);
}

void discoverWithDFS(int sV, int pV, int& count, vector<vi> adj, stack<int>& stk, vb& inStack, vi& disc, vi& lowVals) {
  count += 1;
  disc[sV] = lowVals[sV] = count;
  stk.push(sV);
  for (int v : adj[sV]) {
    if (v == pV) continue;
    if (disc[v] == -1) {
      inStack[v] = true;
      discoverWithDFS(v, sV, count, adj, stk, inStack, disc, lowVals);
      inStack[v] = false;
      lowVals[sV] = min(lowVals[sV], lowVals[v]);
    }
    else if (inStack[v]) {
      lowVals[sV] = min(lowVals[sV], disc[v]);
    }
  }
  if (lowVals[sV] != disc[sV]) return;
  while (true) {
    int top = stk.top();
    cout << top << " ";
    stk.pop();
    if (top == sV) break;
  }
  cout << endl;
}

void Tarjan(vector<vi> adj) {
  int nV = adj.size() - 1, count = 0;
  vi disc(nV + 1, -1), lowVals(nV);
  vb inStack(nV + 1, false);
  stack<int> stk;
  for (int i = 1;i <= nV;i++) {
    if (disc[i] != -1) continue;
    inStack[i] = true;
    discoverWithDFS(i, -1, count, adj, stk, inStack, disc, lowVals);
    inStack[i] = false;
  }
}
void printGraphInfo(GraphInfo gi) {
  cout << "Disc:\n";
  for (int val : gi.disc)cout << val << " ";
  cout << endl;
  cout << "Low vals:\n";
  for (int val : gi.lowVals)cout << val << " ";
  cout << endl;
}

int main() {
  int nV = 5;
  vector<vi> adj(nV + 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 3, 2);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 5);
  addEdge(adj, 5, 3);
  Tarjan(adj);
  return 0;
}