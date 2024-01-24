#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{   
    int n,m;
    cin>>n>>m;
	vector<int> v(n,0);
	for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
	int cnt=n;
    int sum=0;
    int c=0;
	sort(v.begin(),v.end());
	int i=0;
    int j=n-1;
	while(i<j)
	{
		if(v[i]+v[j]<=m)cnt--,i++,j--;
		else j--;
	}
	cout<<cnt<<endl;
    return 0;
}
