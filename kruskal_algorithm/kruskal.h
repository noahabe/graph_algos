#include "disjoint_set.h"
#include "weighted_undirected.h"
#include <algorithm>

/* Assumes that G is a connected graph */
std::vector<Edge> mst_kruskal(WUGraph& G) {
	std::vector<Edge> all_edges (G.get_all_edges());
	std::vector<Edge> spanning_tree;
	spanning_tree.reserve(G.order()-1);
	std::sort(all_edges.begin(),all_edges.end());

	disjoint_set D (G.order()); 
	int e = -1;
	while (spanning_tree.size() < G.order()-1) { 
		++e;	
		if (D.find_set(all_edges[e].vertex1) == 
			D.find_set(all_edges[e].vertex2))
			continue;
		spanning_tree.push_back(all_edges[e]);	
	}	
	return spanning_tree;
}

