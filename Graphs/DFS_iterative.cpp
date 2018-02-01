/*
	Author: Deepak Duggirala
	Date:	15-08-2015
	Description:Implementation of DFS(iterative) on adjacency list for graphs
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
    	void DFS_it(int i);
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

//DFS(iterative)
void Graph::DFS_it(int i)
{
	int Visited[V];
	int j;
	//initialization
	for(int j=0;j<V;j++)
		Visited[j]=0;
	list<int> myStack;
	//mark i as visied and push on to the stack
	myStack.push_back(i);
	Visited[i]=1;
	while(!myStack.empty())
	{
		j = myStack.back();
		myStack.pop_back();
		cout<<j<<", ";
		//for every edge (j,k), here k is *it
		for(list<int>::iterator it=adj[j].begin(); it != adj[j].end(); it++)
		{
			if(Visited[*it]==0)
			{
				Visited[*it]=1;
				myStack.push_back(*it);
			}
		}
	}
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
    g.DFS_it(2);
}
