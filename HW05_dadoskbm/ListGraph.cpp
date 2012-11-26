#include "ListGraph.h"
#include <iostream>

using namespace std;

/*
Initializes the list matrix to fit the number of nodes. 
Params:
  num_nodes: Number of nodes to be placed in a graph
*/
ListGraph::ListGraph(int num_nodes)
{
	num_edges = 0;
	if(num_nodes > 0)
	{
		edgeList = vector<EList>(num_nodes);
	}
	else
		cout << "num_nodes must be greater than 0!" << endl;

}

ListGraph::~ListGraph() {}

/*
   * Add a weighted, undirected edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	if(u >= 0 && u < edgeList.size() && v >= 0 && v < edgeList.size()
		&& u != v && weight > 0)
	{
		edgeList[u].push_back(NWPair(v,weight));
		edgeList[v].push_back(NWPair(u,weight));
		num_edges++;
	}
	else
		cout << "Bad edge" << endl;
}

/*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   */
  EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
  {
	  EList neighbors = edgeList[u];
	  for(EList::iterator iter = neighbors.begin(); iter != neighbors.end(); iter++)
	  {
		  if(iter->first == v)
			  return iter->second;
	  }
	  return 0;

  }

  /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
   *
   * Preconditions: u is a legal label.
   */
  std::list<NWPair> ListGraph::getAdj(NodeID u) const
  {
	  if(u >= 0 && u < edgeList.size())
	  {
		  return edgeList[u];
	  }
	  else
		cout << "Illegal label passed to getAdj" << endl;
  }

  /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
  unsigned ListGraph::degree(NodeID u) const
  {
	  if(u >= 0 && u < edgeList.size())
	  {
		  return edgeList[u].size();
	  }
	  else
		 cout << "Illegal label passed to degree" << endl;
  }

  /*
   * Return the number of nodes in the graph.
   */
  unsigned ListGraph::size() const
  {
	  return edgeList.size();
  }

  /* 
   * Return the number of edges in the graph.
   */
  unsigned ListGraph::numEdges() const
  {
	  return num_edges;
  }