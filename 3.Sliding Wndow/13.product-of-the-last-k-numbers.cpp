class ProductOfNumbers
{
    vector<unsigned long long> prefix;

public:
    ProductOfNumbers()
    {
        prefix.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            prefix.clear();
            prefix.push_back(1);
        }
        else
        {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k)
    {
        if (prefix.size() <= k)
            return 0;
        int n = prefix.size();
        return prefix.back() / prefix[n - k - 1];
        ;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */