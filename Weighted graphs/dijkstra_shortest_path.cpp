/*
	Author: Deepak Duggirala
	Date:	17-08-2015
	Description:Implementation of Dijkstra's shortest path algorithm on adjacency list of graphs
	https://www.topcoder.com/community/data-science/data-science-tutorials/power-up-c-with-the-standard-template-library-part-2/#dijkstra2
*/
#include<iostream>
#include<list>
#include<vector>
#include<limits.h>
#include<queue>

using namespace std;

class Edge
{
	public:
		int to;
		double weight;
		Edge(int v, double weight)
		{
			to = v;
			this->weight = weight;
		}
};

class Node
{
	public:
		int num;
		double distance;
};

class compareNode
{
	public:
	bool operator()(Node &l,Node &r)
	{
		return l.distance > r.distance;
	}
};

class Graph
{
	int V; //No:of vertices
	list<Edge> *adj; //Pointer to an array containing adjacency lists
	double inf;
	bool undirected;
	public:
		Graph(int V,bool undirected);  //Constructor
    	void addEdge(int u, int v,double weight); //function to add an edge to graph
    	void dijkstra_shortest_path(int s);	//find shortest path from s to every other vertex(node)
    	void displayGraph(void);
};

//Constructor
Graph::Graph(int V, bool undirected = false)
{
	this->V = V;
	adj = new list<Edge>[V];
}

//Add an edge to the graph
void Graph::addEdge(int u,int v,double weight=0)
{
	Edge e(v,weight);
	adj[u].push_back(e); //add edge e to u's list
	if(undirected)
	{
		Edge e2(u,weight);
		adj[v].push_back(e2);
	}
}

//Dijkstra's shortest path from vertex s
void Graph::dijkstra_shortest_path(int s)
{
	bool Visited[V];
	double Distance[V];
	
	//infinity is the sum of all edge weights + 1 
	double inf = 0;
	for(int i=0;i<V;i++)
		for(list<Edge>::iterator it=adj[i].begin(); it != adj[i].end(); it++)
		{
			inf+=it->weight;
		}
	inf++;
	//Initialization
	for(int j=0;j<V;j++)
	{
		Visited[j] = false;
		Distance[j] = inf;
	}
	Distance[s]=0;
	//create a source node
	Node src;
	src.num = s;
	src.distance = 0;

	//Build min heap priority queue of all unvisited nodes
	priority_queue<Node ,vector<Node>, compareNode> minPQ;
	minPQ.push(src);
	
	Node u,v;
	while(!minPQ.empty())
	{
		//extract node u with minimum distance which is unvisited
		u = minPQ.top();
		minPQ.pop();
		if(u.distance <= Distance[u.num])
		{
			//mark it as visited
			Visited[u.num] = true;
			cout<<u.num<<", "<<u.distance<<endl;
			//for each edge e = (u,v) in which v is not visited
			for(list<Edge>::iterator e=adj[u.num].begin(); e!=adj[u.num].end();e++)
			{
				if(Visited[e->to] == false)
				{
					if(Distance[e->to] > Distance[u.num] + e->weight)
					{
						Distance[e->to] = Distance[u.num] + e->weight;
						v.num = e->to;
						v.distance = Distance[e->to];						
						minPQ.push(v);
					}
				}
			}
		}
	}
}



int main()
{
	//create an undirected graph with 8 vertices
	Graph g(9,true);
	g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.dijkstra_shortest_path(0);
}
