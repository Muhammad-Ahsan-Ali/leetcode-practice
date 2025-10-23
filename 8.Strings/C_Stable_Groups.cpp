#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vll vector<ll>
#define f(i, n) for (ll i = 0; i < n; ++i)
#define i(a)           \
    for (auto &&i : a) \
        cin >> i;
#define YES              \
    do                   \
    {                    \
        cout << "YES\n"; \
        return;          \
    } while (0)

#define NO              \
    do                  \
    {                   \
        cout << "NO\n"; \
        return;         \
    } while (0)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;

    vll a(n);
    i(a);

    sort(all(a));

    vll difs;

    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] > x)
            difs.push_back(a[i] - a[i - 1]);

    // group1.....group2
    // here gap=1, groups=2

    ll groups = difs.size() + 1;
    sort(difs.begin(), difs.end());

    for (auto dif : difs)
    {
        ll gaps = (dif + x - 1) / x;
        ll additions = gaps - 1;
        if (k >= additions)
        {
            groups--;
            k -= additions;
        }
    }
    cout << groups << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}