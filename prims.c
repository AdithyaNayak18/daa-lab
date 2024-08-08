#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pairr;

void addEdge(vector<pair<int,int>> adj[], int a, int b, int wt){
    adj[a].push_back(make_pair(b,wt));
    adj[b].push_back(make_pair(a,wt));
}
void primMST(vector<pair<int,int>> adj[], int v){
    
    vector<int> key(v,INT_MAX);
    vector<int> parent(v,-1);
    vector<bool> inMST(v,false);
    priority_queue<pairr,vector<pairr>,greater<pairr>> pq;
    
    int start=0;
    key[start]=0;
    pq.push(make_pair(0,start));
    
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        inMST[u]=true;
        
        for(auto &x : adj[u]){
            int v=x.first;
            int wt=x.second;
            
            if(!inMST[v] && (key[v] > key[u]+wt)){
                key[v]=wt;
                parent[v]=u;
                pq.push(make_pair(key[v],v));
            }
        }
    }
    for(int i=1;i<v;i++){
        cout<< parent[i] << " - " << i << "\t" << key[i] << endl;
    }
    
}
int main(){
    int v=5;
    vector<pair<int,int>> adj[v];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);

    primMST(adj, v);

    return 0;
}
