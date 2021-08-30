#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1

int tree[4 * MAX], arr[MAX + 5];

void build(int st, int en, int nd)
{
    if(st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    build(left);
    build(right);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int query(int st, int en, int nd, int L, int R)
{
    if(R < st || en < L) return 0;
    if(L <= st && en <= R) return tree[nd];
    return query(left, L, R) + query(right, L, R);
}

void update(int st, int en, int nd, int idx, int val)
{
    if(idx < st || en < idx) return;
    if(st == en && st == idx)
    {
        tree[nd] = val;
        return;
    }
    update(left, idx, val);
    update(right, idx, val);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build(0, n - 1, 1);
    cout << query(0, n - 1, 1, 1, 5) << endl;
    update(0, n - 1, 1, 3, -10);
    cout << query(0, n - 1, 1, 0, 3) << endl;
    cout << query(0, n - 1, 1, 3, 3) << endl;
    return 0;
}

