#include <iostream>
#include <queue>
#include <list>
#include <utility>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> pai;

class Graph{
	public:
		Graph(int V);
		void AddEdge(int s,int e,int w);
		void Prim();
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
	lis[e].push_back(make_pair(s,w));
}

void Graph::Prim(){
	priority_queue<pai,vector<pai>,greater<pai> > pq;
	vector<int> parent(vnum,-1);
	vector<int> key(vnum,INF);
	vector<bool> visited(vnum,false);
	
	pq.push(make_pair(0,0));
	key[0] = 0;
	
	while(!pq.empty()){
		int p = pq.top().second;
		pq.pop();
		
		list<pair<int,int>>::iterator it;
		for(it=lis[p].begin();it!=lis[p].end();it++){
			int vertex = (*it).first;
			int weight = (*it).second;
			if(visited[vertex]==1){
				continue;
			}
			if(weight<key[vertex]){
				parent[vertex] = p;
				key[vertex] = weight;
				pq.push(make_pair(key[vertex],vertex));
			}
		}
		visited[p] = true;
	} 
	int cost=0;
	for(int i=0;i<vnum;i++){
		cost += key[i];
	}
	cout << cost;
}

int main(){
	int vnum,ednum,start,end,weight;
	cin >> vnum >> ednum;
	Graph g(vnum);
	for(int i=0;i<ednum;i++){
		cin >> start >> end >> weight;
		g.AddEdge(start,end,weight);
	}
	g.Prim();
	return 0;
}
