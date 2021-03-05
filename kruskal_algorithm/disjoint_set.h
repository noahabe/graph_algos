// a simple implementation of a disjoint set data structure
// with union by rank and path compression heureistics

#include <vector>
#include <algorithm>

class disjoint_set{
private:
	// Note: parent[0] is NOT used.
	std::vector<int> parent; // parent[i] is the parent of node i
				 // if i is the root, i equals parent[i]
	std::vector<int> rank;
	int number_of_sets;
public:
	disjoint_set(int n):rank(n+1,0){
		parent.resize(n+1);
		for (int i = 1;i <= n; ++i)
			parent[i] = i;
		
		number_of_sets = n; 
	}
	void make_set(int i) {
		/* useless*/
		parent[i] = i;
		rank[i] = 0;
	}
	int find_set(int i) {
		if (i != parent[i])
			parent[i] = find_set(parent[i]);
		return parent[i];
	}
	void union_(int i,int j) {
		int i_id = find_set(i);
		int j_id = find_set(j);

		if (i_id == j_id) 
			return;
		if (rank[i_id] > rank[j_id])
			parent[j_id] = i_id;
		else {
			parent[i_id] = j_id;
			if (rank[i_id] == rank[j_id])
				rank[j_id]++;
		}		
		--number_of_sets;
	}
	int size() {
		return number_of_sets;
	}	
	int max_height_of_a_tree(void) {
		std::vector<int> height(parent.size(),0);
		for (int i = 1; i < parent.size(); ++i) {
			int j = i;
			while (j != parent[j]){
				++height[j];	
				j = parent[j];  
			}
		}	
		return *std::max_element(height.begin()+1,height.end());
	}
};


