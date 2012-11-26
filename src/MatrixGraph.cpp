#include "MatrixGraph.h"
#include <iostream>

#define NOEDGE -1

using namespace std;
/*
Initializes the adjacency matrix to fit num_nodes elements. All slots
are initially set to the dummy value, which indicates that there is no edge
between the two items.
Params:
  num_nodes: Number of nodes to be placed in a graph
*/
MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	num_edges = 0;
	M = vector<vector<EdgeWeight>>(num_nodes);
	//Initialize inner vectors, set all values to NOEDGE
	for(int i = 0; i < num_nodes; i++)
	{
		M[i] = vector<EdgeWeight>(num_nodes);
		for(int j = 0; j < num_nodes; j++)
			M[i][j] = NOEDGE;
	}

}

MatrixGraph::~MatrixGraph() {}

/*
   * Add a weighted, undirected edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	if(u >= 0 && u < M.size() && v >= 0 && v < M.size()
		&& u != v && M[u][v] == NOEDGE && weight > 0)
	{
		M[u][v] = weight;
		M[v][u] = weight;
		num_edges++;
	}
	else
		cout <<"Bad edge." << endl;
}

/*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   */
  EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
  {
	  EdgeWeight edge = M[u][v];
	  return edge == NOEDGE ? 0 : edge;
  }

  /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
   *
   * Preconditions: u is a legal label.
   */
  std::list<NWPair> MatrixGraph::getAdj(NodeID u) const
  {
	  list<NWPair> result;
	  if(u >= 0 && u < M.size())
	  {
		  for(int i = 0; i < M[u].size(); i++)
		  {
			  if(M[u][i] != NOEDGE)
				  result.push_back(NWPair(i, M[u][i]));
		  }
	  }
	  else
		throw exception("Illegal label passed to getAdj");

	  return result;
  }

  /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
  unsigned MatrixGraph::degree(NodeID u) const
  {
	  unsigned int deg = 0;
	  if(u >= 0 && u < M.size())
	  {
		  for(int i = 0; i < M[u].size(); i++)
		  {
			  if(M[u][i] != NOEDGE)
				  deg++;
		  }
	  }
	  else
		 throw exception("Illegal label passed to getAdj");

	  return deg;
  }

  /*
   * Return the number of nodes in the graph.
   */
  unsigned MatrixGraph::size() const
  {
	  return M.size();
  }

  /* 
   * Return the number of edges in the graph.
   */
  unsigned MatrixGraph::numEdges() const
  {
	  return num_edges;
  }