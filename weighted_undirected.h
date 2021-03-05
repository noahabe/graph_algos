#include <iostream>
#include <vector>

class WUGraph;
std::istream& operator>>(std::istream& is, WUGraph& G);

class WUGraph { 
private:
	std::vector<std::vector<int>> v;
public:
	friend std::istream& operator>>(std::istream& is, WUGraph& G);
	std::vector<int>& operator[](int x) {
		return v[x];
	}
	int order() { return v.size() - 1; } 
};

std::istream& operator>>(std::istream& is, WUGraph& G) {
	int n,m;
	int u1,u2; /* vertices */
	
	is >> n >> m; /* number of vertices, number of edges */
	G.v.resize(n+1);
	for (int _ = 1; _ <= m; ++_) {
		is >> u1 >> u2;
		G.v[u1].push_back(u2);
		G.v[u2].push_back(u1);	
	}	
	return is;
}

#define for_each_vertex(v,G)  for (int v = 1; v <= G.order(); ++v)

