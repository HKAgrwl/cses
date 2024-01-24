#include <iostream>
#include <vector>
#include <limits>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>v[i];
    }
    long long int ans=INT_MIN;
    long long int sum=0;
    for(auto x: v){
        sum+=x;
        if(sum>ans) ans=sum;
        if(sum<0) sum=0;
    }
    cout<<ans;
    return 0;
}
