class Solution
{
public:
    int xorOperation(int n, int start)
    {

        int i = 1;
        int num = start;

        while (i < n)
        {
            num = num ^ (start + 2 * i);
            i++;
        }

        return num;
    }
};