#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005
#define MOD 1000000007
#define base 29

ll pre[MAX + 5], po[MAX + 5];
string s;

void precalculate(string &s)
{
    po[0] = 1;
    for (int i = 1; i <= s.size(); i++)
    {
        po[i] = (po[i - 1] * base) % MOD;
    }
    pre[0] = s[0] - 'a';
    for (int i = 1; i < s.size(); i++)
    {
        pre[i] = (pre[i - 1] * base + (s[i] - 'a')) % MOD;
    }
}

ll get_hash(int L, int R)
{
    if (!L) return pre[R];
    return (pre[R] - (pre[L - 1] * po[R - L + 1]) % MOD + MOD) % MOD;
}

int main()
{
    s = "abbaababbab";
    precalculate(s);
    cout << get_hash(0, s.size() - 1) << "\n";
    cout << get_hash(0, 2) << "\n";
    cout << get_hash(6, 8) << "\n";
    return 0;
}
