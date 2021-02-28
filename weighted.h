#include <iostream>
#include <vector>

// WGraph for Weighted Graph

class WGraph;
std::istream& operator>>(std::istream& is, WGraph& G);

// recall that the edge is a directed edge.
struct Edge {
	int dest; // the destination of the edge
	int weight;
	Edge(int d, int w)
	:dest(d),weight(w) 
	{}
};


class WGraph { 
public:
	std::vector<std::vector<Edge>> v;
	std::vector<Edge>& operator[](int x) {
		return v[x];
	}
	int order() { return v.size()-1; }
};

std::istream& operator>>(std::istream& is, WGraph& G) {
	int n,m;
	int u1,u2; /* vertices */
	int w; // the weight of the edge (u1,u2)
	
	is >> n >> m; /* number of vertices, number of edges */
	G.v.resize(n+1);
	for (int _ = 1; _ <= m; ++_) {
		is >> u1 >> u2 >> w;
		G[u1].emplace_back(u2,w);
	}	
	return is;
}

#define for_each_vertex(v,G)  for (int v = 1; v <= G.order(); ++v)

std::ostream& operator<<(std::ostream& os,WGraph& H) {
	for_each_vertex(u,H) {
		os << "vertex: " << u << " | ";
		
		for (const Edge& v : H[u]) {
			os << v.dest << " ";	
		}
		os << std::endl;
	}
	return os;
}

WGraph Transpose(WGraph& G){
	WGraph retval;
	retval.v.resize(G.order()+1);
	for_each_vertex(v,G) {
		for (const Edge& e : G[v]) {
			retval[e.dest].emplace_back(v,e.weight);
		}	
	}
	return retval;
}

