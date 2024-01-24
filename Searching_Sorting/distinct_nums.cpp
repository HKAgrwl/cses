#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    int n,x;cin>>n;
    set<int>s;
    for(int i=0;i<n;++i)
    {
    	cin>>x;
    	s.insert(x);
    }
    cout<<s.size()<<endl;
    return 0;
}
