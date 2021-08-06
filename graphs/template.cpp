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
};

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
};

void bfs(Graph const &graph, int beg, vector<bool>& check) {
	check[beg] = 1;
	queue<int> q;
	q.push(beg);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		for(auto &x: graph.adjList[curr]) {
			if(!check[x]) {
				check[x] = 1;
				q.push(x);
			}
		}
	}
}

void dfs(Graph const &graph, int beg, vector<bool>& check) {
	check[beg] = 1;
	for(auto &x: graph.adjList[beg]) {
		if(!check[x]) {
			dfs(graph, x, check);
		}
	}
}

int32_t main() {
	// int N = 6;  ->  Max size of nodes
	// vector<Edge> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {2, 5}};
	// Graph graph(edges, N);  ->  Construct the graph
	// vector<bool> check(2*N, 0);  ->  check if a node has been visited
	// //bfs(graph, 1, check);  ->  breadth first search
	//dfs(graph, 1, check);  ->  depth first search



}