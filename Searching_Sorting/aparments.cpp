#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{   
    int n,m,k;
    cin>>n>>m>>k;
	vector<int> v(n,0);
	vector<int> u(m,0);
	for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
	for (int i = 0; i < m; i++)
    {
        cin>>u[i];
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
	int cnt=0;
	int i=0;
	int j=0;
	while(i<n and j<m)
	{
		if(v[i]-k>u[j])j++;
		else if(v[i]+k<u[j])i++;
		else
		{
			i++,j++,cnt++;
		}
	}
	cout<<cnt<<endl;
    return 0;
}
