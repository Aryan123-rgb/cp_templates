#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/**
 * MISTAKES
 * 1. left shifting by 1 instead of using pow(2,cnt0) and using ll to avoid overflow
 * cout << (1ll << cnt0) * (ll)cnt1 << '\n';
 *
 * 2. When get tle try changing unordered_map to map
 * 3. Try to look if there is any relation between the input and the output ,       for example n and  * k are given and the answer string length is n*k , the array is given and the answer is -1 * sum(of the entire array)
 */

void solve(ll t)
{
    ll n;
    cin >> n;
    vector<ll> year1 = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<ll> year2 = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<ll> year3 = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<ll> year4 = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n <= 12)
    {
        ll flag = 0;
        for (ll i = 0; i < 24; i++)
        {
            vector<ll> temp;
            for (ll j = 0; j < n; j++)
            {
                temp.push_back(year1[j]);
            }
            if (temp == v)
                flag = 1;
        }
        for (ll i = 0; i < 24; i++)
        {
            vector<ll> temp;
            for (ll j = 0; j < n; j++)
            {
                temp.push_back(year2[j]);
            }
            if (temp == v)
                flag = 1;
        }
        for (ll i = 0; i < 24; i++)
        {
            vector<ll> temp;
            for (ll j = 0; j < n; j++)
            {
                temp.push_back(year3[j]);
            }
            if (temp == v)
                flag = 1;
        }
        for (ll i = 0; i < 24; i++)
        {
            vector<ll> temp;
            for (ll j = 0; j < n; j++)
            {
                temp.push_back(year4[j]);
            }
            if (temp == v)
                flag = 1;
        }
        if (flag == 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else
    {
        ll flag = 0;
        for (ll i = 0; i < 24; i++)
        {
            vector<ll> temp;
            for (ll j = 0; j < n; j++)
            {
                temp.push_back(year1[j]);
            }
            if (temp == v)
                flag = 1;
        }
        for (ll i = 0; i < 24; i++)
        {
            vector<ll> temp;
            for (ll j = 0; j < n; j++)
            {
                temp.push_back(year2[j]);
            }
            if (temp == v)
                flag = 1;
        }
        if (flag == 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}

int main()
{
    fastio();
    ll t = 1;
    while (t--)
    {
        solve(t);
    }
    return 0;
}