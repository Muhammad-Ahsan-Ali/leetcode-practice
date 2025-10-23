
// FOR PREFIX SUM AND UPDATE

class SegmentTree
{
private:
    vector<int> seg;
    int n;

    void build(int idx, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (high + low) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void update(int idx, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (high + low) / 2;

        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r)
    {
        if (low >= l && high <= r)
            return seg[idx];

        if (high < l || low > r)
            return 0;

        int mid = (low + high) / 2;

        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return (left + right);
    }

public:
    void buildTree(vector<int> &arr)
    {
        n = arr.size();
        seg.assign(n * 4, 0);
        build(0, 0, n - 1, arr);
    }

    void update(int pos, int val)
    {
        update(0, 0, n - 1, pos, val);
    }

    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};

// FOR PREFIX SUM AND LAZY RANGE UPDATE

class SegmentTree
{
private:
    vector<int> seg;
    vector<int> lazy;
    int n;

    void build(int idx, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (high + low) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateAdd(int idx, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            seg[idx] += val;
            return;
        }

        int mid = (high + low) / 2;

        if (pos <= mid)
            updateAdd(2 * idx + 1, low, mid, pos, val);
        else
            updateAdd(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void rangeUpdate(int idx, int low, int high, int l, int r, int val)
    {

        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (l > high || r < low || low > high)
            return;

        if (low >= l && high <= r)
        {
            seg[idx] += (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }

        int mid = (low + high) >> 1;
        rangeUpdate(2 * idx + 1, low, mid, l, r, val);
        rangeUpdate(2 * idx + 2, mid + 1, high, l, r, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int queryLazy(int idx, int low, int high, int l, int r)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] += (high - low + 1) * lazy[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (low >= l && high <= r)
            return seg[idx];

        if (high < l || low > r)
            return 0;

        int mid = (low + high) / 2;

        int left = queryLazy(2 * idx + 1, low, mid, l, r);
        int right = queryLazy(2 * idx + 2, mid + 1, high, l, r);

        return (left + right);
    }

public:
    void buildTree(vector<int> &arr)
    {
        n = arr.size();
        seg.assign(n * 4, 0);
        lazy.assign(n * 4, 0);
        build(0, 0, n - 1, arr);
    }

    void updateAdd(int pos, int val)
    {
        updateAdd(0, 0, n - 1, pos, val);
    }
    void rangeUpdate(int l, int r, int val)
    {
        rangeUpdate(0, 0, n - 1, l, r, val);
    }

    int queryLazy(int l, int r)
    {
        return queryLazy(0, 0, n - 1, l, r);
    }
};
