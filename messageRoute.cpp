#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges,int s,int t){
    // create adjList;
    queue<int> q;
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    parent[s]=-1;
    parent[t] =-1;
    q.push(s);
    visited[s]=true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }

    vector<int> ans;
    if(parent[t]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return ans;
    }
    int currentNode = t;
    while(currentNode!=-1){
        ans.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{   
    int n,m;
    cin>>n>>m;
    vector<int> path;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back(make_pair(x,y));
    }
    path = shortestPath(edges,1,n);
    if(path.size()) cout<<path.size()<<endl;
    for(auto x : path){
        cout<<x<<" ";
    }
    return 0;
}
