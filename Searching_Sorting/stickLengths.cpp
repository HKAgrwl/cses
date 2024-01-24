#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (long long &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());
    long long mid = v[n / 2], ans = 0;
    for (long long &i : v)
    {
        ans += abs(i - mid);
    }
    cout << ans << endl;
    return 0;
}
