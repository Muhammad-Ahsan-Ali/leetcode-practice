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

    void update(int pos, int val) { update(0, 0, n - 1, pos, val); }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

class NumArray
{
    SegmentTree st;

public:
    NumArray(vector<int> &nums) { st.buildTree(nums); }

    void update(int index, int val) { st.update(index, val); }

    int sumRange(int left, int right) { return st.query(left, right); }
};
