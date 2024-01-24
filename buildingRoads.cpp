#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(int a,map<int,vector<int>> &r,vector<int> &v){
    v[a] = 1;
    for(auto x : r[a]){
        if(!v[x]) dfs(x,r,v);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> heads;
    map<int,vector<int>> roads;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        roads[x].push_back(y);
        roads[y].push_back(x);
    }
    vector<int> visited(n+1,0);
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            dfs(i,roads,visited);
            heads.push_back(i);
        }
    }

    cout<<heads.size()-1<<endl;
    for(int i=0;i<heads.size()-1;i++){
        cout<<heads[i]<<" "<<heads[i+1]<<endl;
    }
    return 0;
}
