#include <iostream>
#include <queue>
#include <list>
#include <utility>
#define INF 0x3f3f3f3f
using namespace std;

struct Edge{
	int start,end,weight;
};

class Graph{
	public:
		Graph(int vnum,int ednum);
		void AddEdge(int s,int e,int w);
		void BellmanFord(int start,int target);
	private:
		int vnum,ednum;
		vector<Edge> edge;
};

Graph::Graph(int vnum,int ednum){
	this->vnum = vnum;
	this->ednum = ednum;
	vector<Edge> edge;
}

void Graph::AddEdge(int s,int e,int w){
	Edge ed = {s,e,w};
	edge.push_back(ed);
}

void Graph::BellmanFord(int start,int target){
	vector<int> distance(vnum,INF);
	vector<int> parent(vnum,-1);
	distance[start] = 0;
	
	for(int i=0;i<vnum-1;i++){
		for(int j=0;j<ednum;j++){
			if(distance[edge[j].end]>distance[edge[j].start]+edge[j].weight){
				distance[edge[j].end] = distance[edge[j].start]+edge[j].weight;
				parent[edge[j].end] = edge[j].start;
			}	
		}
	}
	
	for(int j=0;j<ednum;j++){
		if(distance[edge[j].end]>distance[edge[j].start]+edge[j].weight){
			cout << "Negative loop detected!";
			return;
		}
	}
	cout << distance[target];
}

int main(){
	int vnum,ednum,start,target,from,to,weight;
	cin >> vnum >> ednum >> start >> target;
	Graph g(vnum,ednum);
	for(int i=0;i<ednum;i++){
		cin >> from >> to >> weight;
		g.AddEdge(from,to,weight);
	} 
	g.BellmanFord(start,target);
	return 0;
}
