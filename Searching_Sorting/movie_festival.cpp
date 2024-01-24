#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<int, int>& a,
               const pair<int, int>& b)
{
    return (a.second < b.second);
}

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
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),sortbysec);
    int count=0;
    int endTime =0;
    for(auto x : v){
        if(x.first >= endTime){
            count++;
            endTime = x.second;
        }
    }
    cout<<count;
    return 0;
}
