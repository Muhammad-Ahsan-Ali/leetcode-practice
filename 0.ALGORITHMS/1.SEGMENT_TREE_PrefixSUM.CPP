
class SegmentTree
{
private:
    // Each segment tree node stores the minimum and maximum in its range
    struct Node
    {
        int min = INT_MAX;
        int max = INT_MIN;
    };

    vector<Node> seg; // segment tree storage
    int n;            // size of input array

    // Recursive function to build the tree
    void build(int ind, int low, int high, const vector<int> &arr)
    {
        if (low == high)
        {
            // Leaf node → single element
            seg[ind].min = arr[low];
            seg[ind].max = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);      // build left child
        build(2 * ind + 2, mid + 1, high, arr); // build right child

        // Internal node stores min/max of its children
        seg[ind].max = max(seg[2 * ind + 1].max, seg[2 * ind + 2].max);
        seg[ind].min = min(seg[2 * ind + 1].min, seg[2 * ind + 2].min);
    }

    // Recursive function to update value at position `pos`
    void update(int ind, int low, int high, int pos, int val)
    {
        // Base case: we reached the leaf node (single element segment)
        if (low == high)
        {
            // Update both min and max since it's just one element
            seg[ind].min = val;
            seg[ind].max = val;
            return;
        }

        // Find the midpoint of the current segment
        int mid = (low + high) / 2;

        // If the update position is in the left half
        if (pos <= mid)
            update(2 * ind + 1, low, mid, pos, val); // recurse on left child
        else
            // Otherwise, it's in the right half
            update(2 * ind + 2, mid + 1, high, pos, val); // recurse on right child

        // After updating the child, recalculate min and max for the current node
        seg[ind].max = max(seg[2 * ind + 1].max, seg[2 * ind + 2].max);
        seg[ind].min = min(seg[2 * ind + 1].min, seg[2 * ind + 2].min);
    }

    // Recursive function to query min/max in range [l, r]
    Node query(int ind, int low, int high, int l, int r)
    {
        // Full overlap
        if (low >= l && high <= r)
            return seg[ind];
        // No overlap → return neutral node
        if (high < l || low > r)
            return {};

        // Partial overlap → check both children
        int mid = (low + high) / 2;
        Node left = query(2 * ind + 1, low, mid, l, r);
        Node right = query(2 * ind + 2, mid + 1, high, l, r);

        // Merge results
        Node result;
        result.min = min(left.min, right.min);
        result.max = max(left.max, right.max);
        return result;
    }

public:
    void buildTree(const vector<int> &arr)
    {
        n = arr.size();
        seg.resize(4 * n);       // allocate safe size
        build(0, 0, n - 1, arr); // build tree
    }

    // Public update wrapper
    void update(int pos, int val)
    {
        update(0, 0, n - 1, pos, val);
    }

    // Public query wrapper
    Node query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};

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
