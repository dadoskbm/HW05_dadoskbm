#include "GraphAlgs.h"

#include <iostream>
using namespace std;

/*
 * Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that 
 * vists every node exactly once (with exception of the first node, which is repeated as the 
 * last node in the cycle.)
 * 
 * Return value: Return a pair, with the first element being a vector of length n listing the 
 *  order of the nodes in the cycle (do NOT list the start node twice), and the second element
 *  being the length of that path (do NOT forget to include the edge from the last node back to
 *  the start node in the total length.
 *
 * Preconditions: 
 *     G is undirected.
 *     Every pair of nodes u,v  (u != v) has an edge connecting the of weight > 0.
 */
vector<NodeID> bestTour;
double bestTourLen = 0;
Graph* graphRef;


void swap(vector<NodeID> &arr, int index1, int index2)
{
	NodeID temp = arr[index2];
	arr[index2] = arr[index1];
	arr[index1] = temp;
}

//Recursive algorithm
void tour(vector<NodeID> arr,int total, int startPlace = 0)
{
	
	if(total - startPlace == 1)
	{
		double tourLen = 0;
		for(int i = 0; i < total - 1; i++)
		{
			double edgeLength = graphRef->weight(arr[i], arr[i + 1]);
			if(edgeLength == 0) 
				return;
			else
				tourLen += edgeLength;
		}
		if(graphRef->weight(arr[total - 1], arr[0]) == 0) return;

		tourLen += graphRef->weight(arr[total - 1], arr[0]);

		//Check to see if it's better.
		if(bestTourLen == 0 || tourLen < bestTourLen)
		{
			bestTourLen = tourLen;
			bestTour = arr;
		}
	}
	else	
	{
		double tourLen = 0;
		for(int i = 0; i < startPlace - 1; i++)
		{
			tourLen += graphRef->weight(arr[i], arr[i + 1]);
		}
		if(bestTourLen != 0 && tourLen > bestTourLen)
			return;
		for(int i = startPlace; i < total; i++)
		{
			swap(arr, startPlace, i);
			tour(arr, total, startPlace + 1);
			swap(arr, startPlace, i);
		}
	}

}

pair<vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	graphRef = G;
	vector<NodeID> order = vector<NodeID>(G->size());
	for(int i = 0; i < G->size(); i++)
		order[i] = i;
	tour(order, G->size());
	return pair<vector<NodeID>, double>(bestTour, bestTourLen);
}