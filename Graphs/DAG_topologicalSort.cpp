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
	list<int> source;
	int *indegree;
	public:
		Graph(int V);  //Constructor
    	void addEdge(int v, int w); //function to add an edge to graph
    	void topologicalSort(void);
};

//Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	indegree = new int [V];
	for(int j=0;j<V;j++)
	{
		indegree[j]=0;
	}
	
}

//Add an edge to the graph
void Graph::addEdge(int v,int e)
{
	adj[v].push_back(e); //add edge e to v's list
	indegree[e]++;
}


//Topological Sort
void Graph::topologicalSort(void)
{
	int s;
	for(int j=0;j<V;j++)
	{
		if(indegree[j]==0)
		{
			source.push_back(j);
		}
	}
	
	while(!source.empty())
	{
		s = source.front();
		cout<<s<<", ";
		source.pop_front();
		for(list<int>::iterator it=adj[s].begin(); it != adj[s].end(); it++)
		{
			indegree[*it]--;
			if(indegree[*it] == 0)
			{
				source.push_back(*it);
			}
		}
	}
}

int main()
{
	Graph g(8);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.topologicalSort();
}
