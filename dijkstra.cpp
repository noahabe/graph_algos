#include "weighted.h"
#include <climits>
#include <queue>

// assumes that the weight of each edge is non-negative.
void dijkstra(WGraph& G, int s,
	std::vector<int>& estimate, 
	std::vector<int>& predecessor) { 

	auto relax = [&](int u, int v, int w) {
		// w is the weight of the edge (u,v)
		if (estimate[u] == INT_MAX)
			return;
		else if (estimate[v] > estimate[u] + w) { 
			estimate[v] = estimate[u] + w;
			predecessor[v] = u;
		}  
	};	
	auto cmp = [&](int v, int u) {
		return estimate[v] > estimate[u];
	}; 
	std::priority_queue<int,std::vector<int>,decltype(cmp)> Q(cmp);
	for_each_vertex(v,G)
		Q.push(v);
	int u;
	while (!Q.empty()) { 
		u = Q.top(); Q.pop();
		for (Edge& e : G[u])
			relax(u,e.dest,e.weight);		
	}
}

int main(void) { 
	WGraph G;
	std::cin >> G;
	int s,v;
	std::cin >> s >> v;
		
	std::vector<int> estimate (G.order()+1,INT_MAX);
	std::vector<int> predecessor (G.order()+1,-1);

	estimate[s] = 0;
	predecessor[s] = -2;
	dijkstra(G,s,estimate,predecessor);
	
	if (estimate[v] == INT_MAX)
		estimate[v] = -1;
	std::cout << estimate[v] << std::endl;
	return 0;
}

