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
    ll n;
    cin >> n;

    string s;
    cin >> s;

    string mex = "";
    for (char c = 'a'; c <= 'z'; c++)
        if (s.find(c) == string::npos)
        {
            mex += c;
            break;
        }
    for (char c1 = 'a'; c1 <= 'z' && mex == ""; c1++)
        for (char c2 = 'a'; c2 <= 'z' && mex == ""; c2++)
        {
            string tmp = "";
            tmp.push_back(c1);
            tmp.push_back(c2);
            if (s.find(tmp) == string::npos)
            {
                mex = tmp;
                break;
            }
        }
    for (char c1 = 'a'; c1 <= 'z' && mex == ""; c1++)
        for (char c2 = 'a'; c2 <= 'z' && mex == ""; c2++)
            for (char c3 = 'a'; c3 <= 'z' && mex == ""; c3++)
            {
                string tmp = "";
                tmp.push_back(c1);
                tmp.push_back(c2);
                tmp.push_back(c3);
                if (s.find(tmp) == string::npos)
                {
                    mex = tmp;
                    break;
                }
            }

    cout << mex << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc; // Read number of test cases
    while (tc--)
    {
        solve();
    }
    return 0;
}