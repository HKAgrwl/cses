#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{   
    int n,m;
    cin>>n>>m;
	vector v(n,0);
	vector u(m,0);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>u[i];
    }
    
	multiset<int,greater<int>>s;
	for (int i = 0; i < n; i++)
    {
        /* code */
        s.insert(v[i]);
    }
    for (int i = 0; i < m; i++)
    {
        auto it=s.lower_bound(u[i]);
		if(it==s.end())cout<<-1<<endl;
		else
		{
			cout<<*it<<endl;
			s.erase(it);
		}
    }
    return 0;
}
