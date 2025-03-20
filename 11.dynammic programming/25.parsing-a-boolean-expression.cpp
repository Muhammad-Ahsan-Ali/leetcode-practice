class Solution
{

    void parseAnd(stack<char> &s2)
    {

        bool output = true;

        while (s2.top() != '(')
        {
            char temp = s2.top();
            s2.pop();
            if (temp == 'f')
                output = false;
        }
        s2.pop();

        s2.push(output ? 'f' : 't');
    }

    void parseOr(stack<char> &s2)
    {

        bool output = false;

        while (s2.top() != '(')
        {
            char temp = s2.top();
            s2.pop();
            if (temp == 't')
                output = true;
        }
        s2.pop();

        s2.push(output ? 'f' : 't');
    }

    void parseNot(stack<char> &s2)
    {
        char temp = s2.top();
        s2.pop();
        s2.pop(); // remove "("

        if (temp == 'f')
            s2.push('t');
        else
            s2.push('f');
    }

public:
    bool parseBoolExpr(string expression)
    {

        stack<char> s1;
        stack<char> s2;

        int n = expression.size();
        int i = 0;

        while (i < n)
        {

            if (expression[i] == ')')
            {

                if (!s1.empty())
                {

                    char op = s1.top();
                    s1.pop();

                    switch (op)
                    {

                    case '&':
                        parseAnd(s2);
                        break;

                    case '|':
                        parseOr(s2);
                        break;

                    case '!':
                        parseNot(s2);
                        break;
                    }
                }
            }
            else if (expression[i] == '&' || expression[i] == '|' || expression[i] == '!')
            {
                s1.push(expression[i]);
            }
            else
            {
                if (expression[i] != ',')
                {
                    s2.push(expression[i]);
                }
            }
            i++;
        }

        return (s2.top() == 't');
    }
};