#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::pair;

// returns true if there is a cycle that is reacheable from v 
bool v_lies_on_a_cycle(vector<vector<int>>& G, int v,std::vector<bool>& visited,
		vector<bool>& uptonow) {

	if (uptonow[v] == true) 
		return true;
	if (!visited[v]) {
		visited[v] = true;	
		uptonow[v] = true;
		for (int adjacent_node : G[v]) {
			if (v_lies_on_a_cycle(G,adjacent_node,visited,uptonow)) 
				return true;
			uptonow[adjacent_node] = false;
		}
	}
	return false;
}

// true if the graph contains a cycle
// false if the graph is acyclic
bool cyclic(vector<vector<int>> &adj) {
	std::vector<bool> visited (adj.size(),false);
	std::vector<bool>  uptonow (adj.size(),false);

	for (int v = 1; v < adj.size(); ++v) { 
		if (!visited[v]) {
			for (int i = 1; i < uptonow.size();++i) 
				uptonow[i] = false;
			/* we say a graph is cyclic if one of 
			   its vertices lie on a cycle */
			if (v_lies_on_a_cycle(adj,v,visited,uptonow))
				return true;
		}
	}	
	return false; // 
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n+1, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
  }
  std::cout << cyclic(adj);
}
