#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef pair<int,int> pairr;

void addEdge(vector<pair<int,int>> arr[], int st, int en, int wt){
    arr[st].push_back(make_pair(en,wt));
    arr[en].push_back(make_pair(st,wt));
}

void dijkstra(vector<pair<int,int>> adj[], int v){
    vector<int> dist(v,INT_MAX);
    int st=0;
    dist[st]=0;
    priority_queue<pairr,vector<pairr>, greater<pairr>> pq;

    pq.push(make_pair(0,st));

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        for(auto &x : adj[u]){
            int v=x.first;
            int wt=x.second;

            if(dist[u] + wt < dist[v]){
                dist[v]=dist[u] + wt;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    cout << " Shortest distance to each from start " << st << endl;
    for(int i=0;i<v;i++){
        cout << i << " " << dist[i] << "\n";
    }
}
int main(){
    int v=9;
    vector<pair<int,int>> adj[v];

    addEdge(adj,0,1,4);
    addEdge(adj,0,7,8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    dijkstra(adj,v);

    return 0;
}
