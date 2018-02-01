/*
	Author: Deepak Duggirala
	Date:	15-08-2015
	Description:Implementation of Breadth First Search on adjacency list for graphs
*/
#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Graph
{
	int V; //No:of vertices
	list<int> *adj; //Pointer to an array containing adjacency lists
	public:
		Graph(int V);  //Constructor
    	void addEdge(int v, int w); //function to add an edge to graph
    	void BFS(int i);//Breadth First search starting from vertex i
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v,int e)
{
	adj[v].push_back(e); //add edge e to v's list
}

void Graph::BFS(int i)
{
	int Visited[V];
	int j;
	//Intialization
	for(j=0;j<V;j++)
		Visited[j]=0;
	list<int> Q;	//Queue
	
	//Start exploration at i
	Visited[i] = 1;
	Q.push_back(i);
	
	//Explore each vertex in Q
	while(!Q.empty())
	{
		//extract and print first element of queue
		j = Q.front();
		cout << j << ", ";
		Q.pop_front();
		//for each (j,k) in edge list
		for(list<int>::iterator it=adj[j].begin(); it != adj[j].end(); it++)
		{
			if(Visited[*it] == 0)
			{
				Visited[*it] = 1;
				Q.push_back(*it);
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
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
}
