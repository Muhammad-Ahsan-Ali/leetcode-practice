
void sol(int index, string num, int target, string exp, vector<string> &output, long cur, long prev)
{
    // If we have processed the entire string and the result matches the target
    if (index == num.length())
    {
        if (cur == target)
        {
            output.push_back(exp);
        }
        return;
    }

    // Start forming numbers from the current index
    for (int i = index; i < num.length(); i++)
    {
        // Avoid numbers with leading zeros
        if (i != index && num[index] == '0')
            break;

        // Extract the current number from the string as a substring
        string part = num.substr(index, i - index + 1);
        long currentNum = stol(part);

        if (index == 0)
        {
            // First number, no operator before it
            sol(i + 1, num, target, part, output, currentNum, currentNum);
        }
        else
        {
            // Try addition
            sol(i + 1, num, target, exp + "+" + part, output, cur + currentNum, currentNum);

            // Try subtraction
            sol(i + 1, num, target, exp + "-" + part, output, cur - currentNum, -currentNum);

            // Try multiplication
            sol(i + 1, num, target, exp + "*" + part, output, cur - prev + (prev * currentNum), prev * currentNum);
        }
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> output;
    sol(0, num, target, "", output, 0, 0);
    return output;
}
