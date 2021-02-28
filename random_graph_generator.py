import random
import argparse

UNDIRECTED = 1
DIRECTED   = 2
WEIGHTED   = 3  

def generate(kind_of_graph): 

	#the number of vertices
	n = random.randint(1,1000)

	#the number of edges
	m = random.randint(1,1000)



if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='choose what kind of graph to generate')
	parser.add_argument(
		action='store',
		type=str,
		dest='kind_of_graph',
		default='undirected',
		help='specify what kind of graph you want to generate. [undirected][directed][weighted]')
	values = parser.parse_args()
	print(values.kind_of_graph)
	
