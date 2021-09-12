#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100500
#define sq 320

ll arr[MAX + 5];
vector<ll> sets[MAX + 5], indices[MAX + 5];
int contribution[sq + 5][MAX + 5];
ll heavy_set[sq + 5], sum[sq + 5], to_add[sq + 5];

int main()
{
    int n, m, q, color = 1;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for(int i = 1; i <= m; i++)
    {
        int set_size, ind;
        scanf("%d", &set_size);
        ll set_sum = 0;
        for(int j = 1; j <= set_size; j++)
        {
            scanf("%d", &ind);
            set_sum += 1LL*arr[ind];
            sets[i].push_back(ind);
            indices[ind].push_back(i);
        }
        if(set_size >= sq)
        {
            heavy_set[i] = color;
            sum[color] = set_sum;
            color++;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(heavy_set[i] > 0) // If this is a heavy set...
        {
            for(auto idx : sets[i])
            {
                for(auto st : indices[idx])
                {
                    contribution[heavy_set[i]][st]++;
                }
            }
        }
    }
    while(q--)
    {
        char com;
        int query_set;
        ll X;
        scanf(" %c", &com);
        if(com == '?')
        {
            ll val = 0;
            scanf("%d", &query_set);
            if(heavy_set[query_set] == 0)
            {
                for(auto id : sets[query_set])
                {
                    val += arr[id];
                }
            }
            else
            {
                val += sum[heavy_set[query_set]];
            }
            for(int i = 1; i < color; i++)
            {
                val += (1LL * to_add[i] * contribution[i][query_set]);
            }
            printf("%lld\n", val);
        }
        else
        {
            scanf("%d%lld", &query_set, &X);
            if(heavy_set[query_set] == 0)
            {
                for(auto id : sets[query_set])
                {
                    arr[id] += X;
                }
                for(int i = 1; i < color; i++)
                {
                    sum[i] += (1LL * X * contribution[i][query_set]);
                }
            }
            else
            {
                to_add[heavy_set[query_set]] += X;
            }
        }
    }
    return 0;
}
