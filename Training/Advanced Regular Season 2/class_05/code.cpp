#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// MUST ADD

int main()
{
    cout << rng() % 10 << "\n";
    return 0;
}
