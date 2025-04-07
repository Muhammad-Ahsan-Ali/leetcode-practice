#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct node
{
    int min = INT_MAX;
    int max = INT_MIN;
};

// Helper to build the tree
void build(int ind, int low, int high, const vector<int> &arr, vector<node> &seg)
{
    if (low == high)
    {
        seg[ind].min = arr[low];
        seg[ind].max = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, arr, seg);
    build(2 * ind + 2, mid + 1, high, arr, seg);

    seg[ind].max = max(seg[2 * ind + 1].max, seg[2 * ind + 2].max);
    seg[ind].min = min(seg[2 * ind + 1].min, seg[2 * ind + 2].min);
}

// Builds and returns the segment tree
vector<node> segmentTree(const vector<int> &arr)
{
    int n = arr.size();
    vector<node> seg(4 * n);
    build(0, 0, n - 1, arr, seg);
    return seg;
}

// Query function
node query(int ind, int low, int high, int l, int r, const vector<node> &seg)
{
    // Complete overlap
    if (low >= l && high <= r)
        return seg[ind];

    // No overlap
    if (high < l || low > r)
        return {};

    // Partial overlap
    int mid = (low + high) / 2;
    node left = query(2 * ind + 1, low, mid, l, r, seg);
    node right = query(2 * ind + 2, mid + 1, high, l, r, seg);

    node result;
    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);
    return result;
}
int main()
{
    vector<int> arr = {5, 2, 7, 3, 8, 6, 1};
    vector<node> seg = segmentTree(arr);
    int n = arr.size();

    // Query range: 2 to 5 (inclusive)
    int l = 2, r = 5;
    node result = query(0, 0, n - 1, l, r, seg);

    cout << "Range [" << l << ", " << r << "] -> Min: " << result.min << ", Max: " << result.max << endl;

    return 0;
}
