#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,sum;
    cin>>n>>sum;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x;
        cin>>x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(),v.end());
    int start=0;
    int end=n-1;
    while(start < end){
        if(v[start].first + v[end].first > sum) end--;
        else if(v[start].first + v[end].first < sum) start++;
        else break;
    }
    if(start>=end) cout<<"IMPOSSIBLE";
    else cout<<v[start].second+1<<" "<<v[end].second+1;
    return 0;
}
