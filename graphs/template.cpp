#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb push_back

struct Edge {
	int src, dest;
}

class Graph {
public:
	vector<vi> adjList;
	Graph(vector<Edge> const &edges, int N, bool undirected = 1) {
		adjList.resize(N);
		for(auto &edge: edges) {
			adjList[edge.src].pb(edge.dest);
			if(undirected) {
				adjList[edge.dest].pb(edge.src);
			}
		}
	}
}

int32_t main() {
	// vector<Edge> edges = {{a, b}, {c, d}};
	// Graph graph(edges, N);
}