/*
	Author: Deepak Duggirala
	Date:	15-08-2015
	Description:Implementation of adjacency list for graphs
*/
#include<iostream>
#include<list>

using namespace std;

class Graph
{
	int V; //No:of vertices
	list<int> *adj; //Pointer to an array containing adjacency lists
	public:
		Graph(int V);  //Constructor
    	void addEdge(int v, int w); //function to add an edge to graph
};

//Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

//Add an edge to the graph
void Graph::addEdge(int v,int e)
{
	adj[v].push_back(e); //add edge e to v's list
}

int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
}
