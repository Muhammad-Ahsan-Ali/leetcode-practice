class Solution
{
    bool isOp(string &str)
    {
        return (str == "+" || str == "-" || str == "*" || str == "/");
    }

    int cal(int num1, int num2, string op)
    {
        if (op == "+")
            return num1 + num2;
        if (op == "-")
            return num1 - num2;
        if (op == "*")
            return num1 * num2;
        if (op == "/")
            return num1 / num2;
        return 0;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (auto str : tokens)
        {
            if (isOp(str))
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int newNum = cal(num1, num2, str);
                st.push(newNum);
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};