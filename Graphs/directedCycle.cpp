/*
	Author: Deepak Duggirala
	Date:	16-08-2015
	Description:Detection of cycles in (adjacency list) directed graphs
*/
#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph
{
	int V; //No:of vertices
	list<int> *adj; //Pointer to an array containing adjacency lists
	int *pre,*post;//pre and post counters
	int count;
	vector<int> nonTreeEdges;
	public:
		Graph(int V);  //Constructor
    	void addEdge(int v, int w); //function to add an edge to graph
    	void DFS(int i);
    private:
    	//DFS recursion function called by DFS
    	void DFS_rec(int i,int* Visited);
};

//Constructor
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	pre = new int [V];
	post = new int [V];
	for(int i=0;i<V;i++)
	{
		pre[i]=0;
		post[i]=0;
	}
	count=1;
}

//Add an edge to the graph
void Graph::addEdge(int v,int e)
{
	adj[v].push_back(e); //add edge e to v's list
}

//Depth First Search
void Graph::DFS(int i)
{
	int Visited[V];
	int u,v;
	for(int j=0;j<V;j++)
		Visited[j]=0;
	DFS_rec(i, Visited);
	
	//print non tree edges
	cout<<"back edges"<<endl;
	for(int j=0;j<nonTreeEdges.size();j=j+2)
	{
		u = nonTreeEdges[j];
		v = nonTreeEdges[j+1];
		
		if(pre[v] <= pre[u] && post[u]<=post[v])
			cout<<u<<", "<<v<<endl;
	}
}

void Graph::DFS_rec(int i, int* Visited)
{
	//Mark i as visited
	Visited[i] = 1;
	//pre count
	pre[i] = count;
	count++;
	cout << i << ", ";
	//Explore each neighbor of i recursively
	for(list<int>::iterator it=adj[i].begin(); it != adj[i].end(); it++)
	{
		if(Visited[*it] == 0)
		{
			DFS_rec(*it,Visited);
		}
		else
		{
			nonTreeEdges.push_back(i);
			nonTreeEdges.push_back(*it);
		}
	}
	//post count
	post[i]=count;
	count++;
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
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
}
