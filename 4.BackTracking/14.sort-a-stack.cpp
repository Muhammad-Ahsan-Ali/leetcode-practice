
class Solution
{
public:
    void Reverse(stack<int> &St)
    {
        if (St.empty())
            return;

        int top = St.top();
        St.pop();
        Reverse(St);
        inserBottom(St, top);
    }

    void inserBottom(stack<int> &St, int el)
    {
        if (St.empty())
        {
            St.push(el);
            return;
        }

        int top = St.top();
        St.pop();
        inserBottom(St, el);
        St.push(top);
    }
};