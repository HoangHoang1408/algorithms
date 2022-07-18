#include<bits/stdc++.h>
#define vi vector<int> 
#define vb vector<bool>
using namespace std;
// graph info for undirected graph
void addEdge(int v1, int v2, vi adj[]) {
  adj[v1].push_back(v2);
  adj[v2].push_back(v1);
}

struct Edge {
  int v1, v2;
  Edge(int a, int b) {
    v1 = a;v2 = b;
  }
};

struct GraphInfo {
  vi disc, lowVals, articulationPoints;
  vector<Edge> bridges;
  GraphInfo(vi disc, vi lowVals, vector<Edge> bridges, vi articulationPoints) {
    this->disc = disc;
    this->lowVals = lowVals;
    this->bridges = bridges;
    this->articulationPoints = articulationPoints;
  }
};

void DiscoverWithDFS(int sV, int pV, vi adj[], int& count, vi& disc, vi& lowVals, vi& articulationPoints, vector<Edge>& bridges) {
  count += 1;
  disc[sV] = lowVals[sV] = count;
  for (int v : adj[sV]) {
    if (pV == v) continue;
    if (disc[v] == -1) {
      DiscoverWithDFS(v, sV, adj, count, disc, lowVals, articulationPoints, bridges);
      lowVals[sV] = min(lowVals[sV], lowVals[v]);
      if (lowVals[v] >= disc[sV] && disc[sV] != 1) articulationPoints.push_back(sV);
      if (lowVals[v] > disc[sV]) bridges.push_back(Edge(sV, v));
    }
    else lowVals[sV] = min(lowVals[sV], disc[v]);
  }
}

GraphInfo discoverGraph(vi adj[], int nV) {
  vi disc(nV + 1, -1), lowVals(nV + 1), articulationPoints;
  vector<Edge> bridges;
  int count = 0;
  for (int v = 1;v <= nV;v++) {
    if (disc[v] != -1) continue;
    DiscoverWithDFS(v, -1, adj, count, disc, lowVals, articulationPoints, bridges);
  }
  copy(disc.begin() + 1, disc.end(), disc.begin());
  copy(lowVals.begin() + 1, lowVals.end(), lowVals.begin());
  disc.resize(nV);
  lowVals.resize(nV);
  return GraphInfo(disc, lowVals, bridges, articulationPoints);
}

void printGraphInfo(GraphInfo info) {
  cout << "Disc vals:\n";
  for (int val : info.disc) cout << val << " ";
  cout << endl;
  cout << "Low vals:\n";
  for (int val : info.lowVals) cout << val << " ";
  cout << endl;
  cout << "Articulation points:\n";
  for (int val : info.articulationPoints) cout << val << " ";
  cout << endl;
  cout << "Bridges:\n";
  for (Edge e : info.bridges) cout << e.v1 << " " << e.v2 << endl;
}

int main() {
  int nV = 11;
  vi adj[nV + 1];
  addEdge(1, 2, adj);
  addEdge(1, 3, adj);
  addEdge(2, 3, adj);
  addEdge(3, 4, adj);
  addEdge(4, 6, adj);
  addEdge(4, 9, adj);
  addEdge(5, 6, adj);
  addEdge(6, 7, adj);
  addEdge(6, 9, adj);
  addEdge(9, 7, adj);
  addEdge(7, 10, adj);
  addEdge(5, 8, adj);
  addEdge(5, 11, adj);
  addEdge(8, 11, adj);
  printGraphInfo(discoverGraph(adj, nV));
  return 0;
}