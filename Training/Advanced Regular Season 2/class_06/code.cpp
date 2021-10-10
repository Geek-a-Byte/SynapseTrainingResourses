#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define MOD 1000000007

ll bm(ll a, ll b)
{
    if(b == 0) return 1;
    if(b % 2 == 0)
    {
        ll t = bm(a, b/2) % MOD;
        return (t * t) % MOD;
    }
    return (a * bm(a, b - 1)) % MOD;
}

int main()
{
    for (int i = 1; i < 100; i++)
    {
        cout << i << " : " << bm(3, i) << "\n";
    }
    return 0;
}
