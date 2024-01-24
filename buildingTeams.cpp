#include <iostream>
#include <unordered_map>
#include<map>
#include <vector>
#include <set>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

bool flag=false;

bool checkbfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,map<int,int> &colors,int x){
    queue<int> q;
    q.push(x);
    colors[x] = 1;
    visited[x] = true;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto x: adjList[frontNode]){
            if(!visited[x]){
                colors[x] = 1-colors[frontNode];
                visited[x] = true;
                q.push(x);
            }
            if(colors[x] == colors[frontNode]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    map<int,int> colors;
    unordered_map<int,bool> visited;
    unordered_map<int,set<int>> adj;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            if(!checkbfs(adj,visited,colors,i)){
                flag = true;
                break;
            }
        }
    }
    if(flag) cout<<"IMPOSSIBLE";
    else{
        for(auto x:colors){
            cout<<x.second+1<<" ";
        }
    }
    return 0;
}
