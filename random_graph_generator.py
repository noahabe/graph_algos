import random
import argparse
import sys

UNDIRECTED = 1
DIRECTED   = 2
WEIGHTED   = 3  

def generate(kind_of_graph)->list: 
	# n is the number of vertices
	n = random.randint(1,1000)

	#m is number of edges
	if kind_of_graph == UNDIRECTED:
		m = random.randint(1,int(n*(n-1)/2))
	else: #directed or weighted 
		m = random.randint(1,int(n*(n-1)))

	edges = list()  
	# the graph that is going to be generated is a simple graph
	# i.e. no self loops and
	#      no multiple edges b/n two vertices  
	while len(edges) <= m: 	
		u = random.randint(1,n)
		v = random.randint(1,n)

		# self loops are not allowed
		if u == v:
			continue

		# check for multiple edges 
		if kind_of_graph == UNDIRECTED:
			if (u,v) in edges or (v,u) in edges:
				continue
			else:
				edges.append((u,v))

		elif kind_of_graph == DIRECTED: 
			if (u,v) in edges:
				continue
			else:
				edges.append((u,v))
			
		elif kind_of_graph == WEIGHTED: 
			for e in edges:
				if e[0] == u and e[1] == v:
					break
			else:
				#the thrid corrdinate if you will is the weight of the 
				#edge u to v 
				edges.append((u,v,random.randint(1,100)))	
				continue	
	return (n,m,edges)
	
if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='choose what kind of graph to generate')
	parser.add_argument(
		action='store',
		type=str,
		dest='kind_of_graph',
		default='undirected',
		help='specify what kind of graph you want to generate. [undirected][directed][weighted]')
	values = parser.parse_args()
	option = None
	if values == "undirected":
		option = UNDIRECTED
	elif values == "directed":
		option = DIRECTED
	elif values == "weighted":
		option = WEIGHTED	
	else:
		sys.exit("[-] Unknown parameter passed")
	print(generate(option))
