#include <bits/stdc++.h>

using namespace std;

// Debugging helpers
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
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
#define f(i,n) for (ll i = 0; i < n; ++i)
#define i(a) for (auto &&i : a) cin >> i;
#define YES         \
    do              \
    {               \
        cout << "YES\n"; \
        return;     \
    } while (0)
#define NO          \
    do              \
    {               \
        cout << "NO\n";  \
        return;     \
    } while (0)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

// Utility functions
bool isPrime(ll x) {
    if (x == 2 || x == 3) return true;
    if (x == 1 || x % 2 == 0 || x % 3 == 0) return false;
    for (ll i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

ll modPow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long myPow(long long x, long long n) {
    long long ans = 1;
    long long pow = n;
    while (pow > 0) {
        if (pow % 2 == 1) {
            ans = (ans * x) % MOD;
            pow--;
        } else {
            x = (x * x) % MOD;
            pow /= 2;
        }
    }
    return ans;
}

long long modInverse(long long p, long long q) {
    return (p * myPow(q, MOD - 2)) % MOD;
}

vector<long long> fact(1e6 + 1);
vector<long long> ifact(1e6 + 1);
void countfact() {
    fact[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        fact[i] = (i * fact[i - 1]) % MOD;
    ifact[1e6] = myPow(fact[1e6], MOD - 2);
    for (int i = 1e6 - 1; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
}

// Prime Sieve
vector<int> PRIMES;
vector<vector<int>> pfac(1e5 + 1);
void createPrimeSieve() {
    vector<int> NUMBERS(100000 + 1, 1);
    NUMBERS[0] = NUMBERS[1] = 0;
    for (int i = 2; 1LL * i * i <= 100000; i++)
        if (NUMBERS[i])
            for (int j = i * i; j <= 100000; j += i)
                NUMBERS[j] = 0;
    for (int i = 2; i <= 100000; i++)
        if (NUMBERS[i]) PRIMES.push_back(i);
  for (int p : PRIMES)
   for (int j = p; j <= MAXN; j += p)
   pfac[j].push_back(p);
}

// Bits
string decToBinary(ll n) {
    string s = "";
    while (n > 0) {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}
ll binaryToDecimal(string n) {
    ll ans = 0, base = 1;
    for (int i = n.length() - 1; i >= 0; i--) {
        if (n[i] == '1') ans += base;
        base *= 2;
    }
    return ans;
}
// GCD and LCM
int gcd(int a, int b) { while (b != 0) { int temp = b; b = a % b; a = temp; } return a; }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
// Base conversion
string toBaseB(string num, int b) {
    if (num == "0") return "0";
    string res = "";
    while (num != "") {
        string next = "";
        int rem = 0;
        for (int i = 0; i < num.length(); i++) {
            int cur = rem * 10 + (num[i] - '0');
            int div = cur / b;
            rem = cur % b;
            if (!next.empty() || div != 0) next += (div + '0');
        }
        res = char(rem + '0') + res;
        num = next;
    }
    return res;
}
// Combinatorics
long long ncr(int n, int r) {
    long long ans = 1;
    if (r > n - r) r = n - r;
    for (int i = 0; i < r; i++) ans = ans * (n - i) / (i + 1);
    return ans;
}

// ll n; vi a(n); i(a);
void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // createPrimeSieve(); countfact();
    int tc;
    cin >> tc;  // Read number of test cases
    while (tc--) {
        solve();
    }
    return 0;
}