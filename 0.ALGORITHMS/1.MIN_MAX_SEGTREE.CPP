
class SegmentTree
{
private:
    struct Node
    {
        int min = INT_MAX;
        int max = INT_MIN;
    };

    vector<Node> seg; // segment tree storage
    int n;

    void build(int idx, int low, int high, const vector<int> &arr)
    {
        if (low == high)
        {
            seg[idx].min = arr[low];
            seg[idx].max = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx].max = max(seg[2 * idx + 1].max, seg[2 * idx + 2].max);
        seg[idx].min = min(seg[2 * idx + 1].min, seg[2 * idx + 2].min);
    }

    void update(int idx, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            seg[idx].min = val;
            seg[idx].max = val;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx].max = max(seg[2 * idx + 1].max, seg[2 * idx + 2].max);
        seg[idx].min = min(seg[2 * idx + 1].min, seg[2 * idx + 2].min);
    }

    Node query(int idx, int low, int high, int l, int r)
    {
        if (low >= l && high <= r)
            return seg[idx];
        if (high < l || low > r)
            return {};

        int mid = (low + high) / 2;
        Node left = query(2 * idx + 1, low, mid, l, r);
        Node right = query(2 * idx + 2, mid + 1, high, l, r);

        Node result;
        result.min = min(left.min, right.min);
        result.max = max(left.max, right.max);
        return result;
    }

public:
    void buildTree(const vector<int> &arr)
    {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void update(int pos, int val)
    {
        update(0, 0, n - 1, pos, val);
    }

    Node query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};

// LAZY UPDATE

class SegmentTree
{
private:
    struct Node
    {
        int min = INT_MAX;
        int max = INT_MIN;
    };

    vector<Node> seg;
    vector<int> lazy;
    int n;

    void build(int idx, int low, int high, const vector<int> &arr)
    {
        if (low == high)
        {
            seg[idx].min = arr[low];
            seg[idx].max = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx].max = max(seg[2 * idx + 1].max, seg[2 * idx + 2].max);
        seg[idx].min = min(seg[2 * idx + 1].min, seg[2 * idx + 2].min);
    }

    void update(int idx, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            seg[idx].min = val;
            seg[idx].max = val;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx].max = max(seg[2 * idx + 1].max, seg[2 * idx + 2].max);
        seg[idx].min = min(seg[2 * idx + 1].min, seg[2 * idx + 2].min);
    }

    void rangeUpdate(int idx, int low, int high, int l, int r, int val)
    {
        if (lazy[idx] != 0)
        {
            seg[idx].min += lazy[idx];
            seg[idx].max += lazy[idx];
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
            seg[idx].min += val;
            seg[idx].max += val;
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

        seg[idx].min = min(seg[2 * idx + 1].min, seg[2 * idx + 2].min);
        seg[idx].max = max(seg[2 * idx + 1].max, seg[2 * idx + 2].max);
    }

    Node query(int idx, int low, int high, int l, int r)
    {
        if (lazy[idx] != 0)
        {
            seg[idx].min += lazy[idx];
            seg[idx].max += lazy[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (l > high || r < low)
            return {};

        if (low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;
        Node left = query(2 * idx + 1, low, mid, l, r);
        Node right = query(2 * idx + 2, mid + 1, high, l, r);

        Node result;
        result.min = min(left.min, right.min);
        result.max = max(left.max, right.max);
        return result;
    }

public:
    void buildTree(const vector<int> &arr)
    {
        n = arr.size();
        seg.resize(4 * n);
        lazy.assign(4 * n, 0);
        build(0, 0, n - 1, arr);
    }

    void update(int pos, int val)
    {
        update(0, 0, n - 1, pos, val);
    }

    void rangeUpdate(int l, int r, int val)
    {
        rangeUpdate(0, 0, n - 1, l, r, val);
    }

    Node query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};
