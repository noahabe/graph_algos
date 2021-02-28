#include <iostream>
#include <vector>

class DiGraph;
std::istream& operator>>(std::istream& is, DiGraph& G);

class DiGraph { 
public:
	std::vector<std::vector<int>> v;
	std::vector<int>& operator[](int x) {
		return v[x];
	}
	int order() { return v.size()-1; }
};

std::istream& operator>>(std::istream& is, DiGraph& G) {
	int n,m;
	int u1,u2; /* vertices */
	
	is >> n >> m; /* number of vertices, number of edges */
	G.v.resize(n+1);
	for (int _ = 1; _ <= m; ++_) {
		is >> u1 >> u2;
		G[u1].push_back(u2);
	}	
	return is;
}

#define for_each_vertex(v,G)  for (int v = 1; v <= G.order(); ++v)

std::ostream& operator<<(std::ostream& os,DiGraph& H) {
	for_each_vertex(u,H) {
		os << "vertex: " << u << " | ";
		
		for (int v : H[u]) {
			os << v << " ";	
		}
		os << std::endl;
	}
	return os;
}

DiGraph Transpose(DiGraph& G){
	DiGraph retval;
	retval.v.resize(G.order()+1);
	for_each_vertex(v,G) {
		for (int u : G[v]) {
			retval[u].push_back(v);
		}	
	}
	return retval;
}

