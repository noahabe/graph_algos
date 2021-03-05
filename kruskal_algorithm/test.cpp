#include "kruskal.h"

int main(void) { 
	WUGraph G;
	std::cin >> G;
	std::vector<Edge> spanning_tree (mst_kruskal(G));
	for (Edge e : spanning_tree) 
		std::cout << " ("<<e.vertex1
			<< ","<<e.vertex2
			<< ","<<e.weight
			<< ")\n" ;
	return 0;
}
