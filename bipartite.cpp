#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

class Graph;
std::istream& operator>>(std::istream& is, Graph& G);

class Graph { 
public:
	std::vector<std::vector<int>> v;
	friend std::istream& operator>>(std::istream& is, Graph& G);
	std::vector<int>& operator[](int x) {
		return v[x];
	}
	int order() { return v.size() - 1; } 
};

std::istream& operator>>(std::istream& is, Graph& G) {
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

const int IT_IS_BIPARTITE = 1;
const int NOT_BIPARTITE   = 0;

enum class COLOR{
	BLACK,
	YELLOW,
	NOT_YET_ASSIGNED
};

int bfs(Graph& G, int u,std::vector<COLOR>& color) {
	color[u] = COLOR::BLACK;
	std::queue<int> Q;
	
	Q.push(u);
	while (!Q.empty()) { 
		int v = Q.front(); Q.pop();
		for (int i : G[v]) {
			if (color[i] == COLOR::NOT_YET_ASSIGNED) {
				// color the vertex i the opposite
				// of the color of v
				switch (color[v]) {
				case COLOR::BLACK:
					color[i] = COLOR::YELLOW;
					break;
				case COLOR::YELLOW:
					color[i] = COLOR::BLACK;
					break;
				case COLOR::NOT_YET_ASSIGNED:
					std::cerr << "IMPOSSIBLE" << std::endl;
					abort();
					break;
				}
				Q.push(i);
			}
			else if (color[i] == color[v]) {
				return NOT_BIPARTITE; 
			}
		}
	}	
	return IT_IS_BIPARTITE; 
}


int bipartite(Graph& G) {
	// a graph is bipartite if all of its components are bipartite!!
	std::vector<COLOR> color (G.v.size(),COLOR::NOT_YET_ASSIGNED);
	for_each_vertex(v,G) {
		if (color[v] == COLOR::NOT_YET_ASSIGNED) {
			if(bfs(G,v,color) == NOT_BIPARTITE) 
				return NOT_BIPARTITE;
		}
	}	
	return IT_IS_BIPARTITE; 
}

int main(void) {
	Graph G;
	std::cin >> G;
	std::cout << bipartite(G) << std::endl;
}

