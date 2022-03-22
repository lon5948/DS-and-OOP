#include <iostream>
#include <algorithm>
using namespace std;

struct Edge{
    int start,end,weight;
    Edge(){};
    Edge(int u,int v,int w):start(u),end(v),weight(w){};
};

bool Compare(struct Edge,struct Edge);
int Findset(int*,int);
void Union(int*,int,int);
void Kruskal(int*,int,int);

int main(){
    int vnum,ednum;
    cin >> vnum >> ednum;
    int subset[vnum];
    Kruskal(subset,vnum,ednum);    
    return 0;
} 

bool Compare(Edge a,Edge b){
    return a.weight < b.weight;
}

int Findset(int *subset,int i){
    while(subset[i]!=i){
        i = subset[i];
    }
    return i;
}

void Union(int *subset,int a,int b){
    int aroot,broot;
    aroot = Findset(subset,a);
    broot = Findset(subset,b);
    subset[aroot] = broot;
}

void Kruskal(int *subset,int vnum,int ednum){
    int cost=0;
    struct Edge edge[ednum];
    for(int i=0;i<vnum;i++){
        subset[i] = i;
    }
    
    for(int i=0;i<ednum;i++){
        cin >> edge[i].start >> edge[i].end >> edge[i].weight;
    }
    
    sort(edge,edge+ednum,Compare);
    
    int i,j;
    for(i=0,j=0;i<vnum-1 && j<ednum ;i++){
        while(Findset(subset,edge[j].start)==Findset(subset,edge[j].end)){
            j++;
        }
        Union(subset,edge[j].start,edge[j].end);
        cost += edge[j].weight;
    }
    cout << cost;
}
