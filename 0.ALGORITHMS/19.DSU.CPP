struct DSU
{
    vector<ll> p; // parent (or negative size)
    vector<ll> w; // sum of values in each component

    // Initialize DSU of size n, optionally with initial values
    DSU(ll n) : p(n, -1), w(n, 0) {}

    ll find(ll x)
    {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    void unite(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;

        if (p[a] > p[b]) // means b is bigger since cnt is stored negative form so >
            swap(a, b);  // a becomes the new root

        p[a] += p[b]; // update size
        p[b] = a;     // merge b under a
        w[a] += w[b]; // sum the component values
    }

    ll get_weight(ll x)
    {
        return w[find(x)];
    }

    ll size(ll x)
    {
        return -p[find(x)];
    }
};
