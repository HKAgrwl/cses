#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,1));
        v.push_back(make_pair(y,-1));
    }
    sort(v.begin(),v.end());
    int ans=0;
    int sum=0;
    for(auto x : v){
        sum+=x.second;
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
