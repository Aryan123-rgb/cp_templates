#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// checks whether ith bit is set or unset in n (0 based indexing)
ll ith_bit_set_unset(ll n, ll i)
{
    if ((n & (1 << i)) != 0)
    {
        return 1;
    }
    else
        return 0;
}

ll set_unset_ith_bit(ll n, ll i)
{
    ll a = (n | (1 << i));    // sets the ith bit
    ll b = (n & (~(1 << i))); // unsets the ith bit
    ll c = (n ^ (1 << i));    // toggle the ith bit
    return a;
}

int main()
{
    return 0;
}