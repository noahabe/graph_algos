// based on the algorithm gived in CLRS
#include "weighted.h"
#include <climits>

bool bellmanford(WGraph& G,int s,
	std::vector<int>& estimate, 
	std::vector<int>& predecessor) { 
	
	auto relax = [&](int u, int v, int w) {
		// w is the weight of the edge (u,v)
		if (estimate[v] > estimate[u] + w) { 
			estimate[v] = estimate[u] + w;
			predecessor[v] = u;
		}  
	};	
	
	for (int i = 1; i <= G.order()-1; ++i) { 
		for_each_vertex(v,G) {  
			for (Edge& e : G[v]) {  
				if (estimate[v] == INT_MAX)
					continue;
				else
					relax(v,e.dest,e.weight);
			}
		}
	}
	for_each_vertex(v,G) { 
		if (estimate[v] == INT_MAX) 
			continue;
		for (Edge& e : G[v]){ 
			if (estimate[e.dest] > estimate[v] + e.weight)
				return false; // the graph contains a negative cycle
		}	
	}
	return true;
} 

void print(std::vector<int>& v) { 
	for (int b:v)
		std::cout << b << " ";
	std::cout << std::endl;
}

int main(void) { 
	WGraph G;
	std::cin >> G;
	int s, v;
	std::cin >> s >> v;
	
	std::vector<int> estimate (G.order()+1,INT_MAX);
	std::vector<int> predecessor (G.order()+1,-1);

	estimate[s] = 0;
	predecessor[s] = -2;

	bool negative_cycle = !bellmanford(G,s,estimate,predecessor);	
	if (negative_cycle) { 
		std::cout << "the graph contains a negative cycle, hence no solution"
			<< std::endl;
		return 2;
	}
	std::cout << estimate[v] << std::endl;
	
}
 
