/* WUGraph - Weighted Undirected Graph */

#include <iostream>
#include <vector>

class WUGraph;
std::istream& operator>>(std::istream& is, WUGraph& G);

struct Edge {
	int vertex1;
	int vertex2;
	int weight;
	
	Edge(int s,int d,int w)
	:vertex1(s),vertex2(d),weight(w)
	{}	

	bool operator<(Edge& rhs) { 
		return this->weight < rhs.weight;
	}
};

class WUGraph { 
private:
	std::vector<std::vector<Edge>> v;
	std::vector<Edge> alledges;
public:
	friend std::istream& operator>>(std::istream& is, WUGraph& G);
	std::vector<Edge>& operator[](int x) {
		return v[x];
	}
	int order() { return v.size() - 1; } 
	std::vector<Edge> get_all_edges(); 
};

#define for_each_vertex(v,G)  for (int v = 1; v <= G.order(); ++v)

std::vector<Edge> WUGraph::get_all_edges() {
	/*std::vector<Edge> retval;
	retval.reserve(this->order()/2); // this is just my herueistics
	for_each_vertex(u,(*this))
		for (Edge& e:v[u])
			retval.push_back(e);
	return retval;*/
	return this->alledges;	
}

std::istream& operator>>(std::istream& is, WUGraph& G) {
	int n,m;
	int u1,u2,w; /* vertices & weight */
	
	is >> n >> m; /* number of vertices, number of edges */
	G.v.resize(n+1);
	for (int _ = 1; _ <= m; ++_) {
		is >> u1 >> u2 >> w;
		G.v[u1].emplace_back(u1,u2,w);
		G.v[u2].emplace_back(u1,u2,w);	
		G.alledges.emplace_back(u1,u2,w);
	}	
	return is;
}


