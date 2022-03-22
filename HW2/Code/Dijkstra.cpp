#include <iostream>
#include <queue>
#include <list>
#include <utility>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> pai;

class Graph{
	public:
		Graph(int vnum);
		void AddEdge(int s,int e,int w);
		void Dijkastra(int start,int target);
	private:
		int vnum;
		list<pai> *lis;
};

Graph::Graph(int vnum){
	this->vnum = vnum;
	lis = new list<pai>[this->vnum];
}

void Graph::AddEdge(int s,int e,int w){
	lis[s].push_back(make_pair(e,w));
}

void Graph::Dijkastra(int start,int target){
	priority_queue<pai,vector<pai>,greater<pai>> pq;
	vector<int> distance(vnum,INF);
	vector<int> parent(vnum,-1);
	distance[start] = 0;
	pq.push(make_pair(0,start));
	
	while(!pq.empty()){
		int p = pq.top().second;
		pq.pop();
		
		list<pai>::iterator it;
		for(it=lis[p].begin();it!=lis[p].end();it++){
			int vertex = (*it).first;
			int weight = (*it).second;
			
			if(distance[vertex]>distance[p]+weight){
				parent[vertex] = p;
				distance[vertex] = distance[p]+weight;
				pq.push(make_pair(distance[vertex],vertex));
			}
		}
	}
	cout << distance[target] << endl; 
}

int main(){
	int vnum,ednum,start,target,from,to,weight;
	cin >> vnum >> ednum >> start >> target;
	Graph g(vnum);
	for(int i=0;i<ednum;i++){
		cin >> from >> to >> weight;
		g.AddEdge(from,to,weight);
	} 
	g.Dijkastra(start,target);
	return 0;
}
