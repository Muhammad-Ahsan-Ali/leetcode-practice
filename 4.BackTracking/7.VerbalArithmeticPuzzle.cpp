int mapDecoder(string s, map<char, int> alphabetsMp)
{
    string temp = "";

    // Convert each character in the string to its mapped digit value
    for (int i = 0; i < s.length(); i++)
    {
        temp += to_string(alphabetsMp[s[i]]);
    }

    // Convert the resulting string of digits to an integer
    return stoi(temp);
}

bool sol(int index, string alphabets, map<int, int> digitsMp, map<char, int> alphabetsMp, string s1, string s2, string s3)
{
    // If all letters have been assigned a digit, check if the equation holds
    if (index >= alphabets.length())
    {
        int num1 = mapDecoder(s1, alphabetsMp);
        int num2 = mapDecoder(s2, alphabetsMp);
        int num3 = mapDecoder(s3, alphabetsMp);

        // Ensure no leading zeros are present by checking the length of converted numbers
        if (to_string(num1).length() != s1.length() ||
            to_string(num2).length() != s2.length() ||
            to_string(num3).length() != s3.length())
        {
            return false;
        }

        // Check if the sum of first two words equals the third word
        if (num1 + num2 == num3)
        {
            return true;
        }

        return false;
    }

    // Try assigning digits (0-9) to the current letter
    for (int i = 0; i < 10; i++)
    {
        if (digitsMp[i] == -1) // Check if digit is available
        {
            alphabetsMp[alphabets[index]] = i; // Assign digit to letter
            digitsMp[i] = 1;                   // Mark digit as used

            // Recursively check the next letter assignment
            bool output = sol(index + 1, alphabets, digitsMp, alphabetsMp, s1, s2, s3);

            if (output)
            {
                return true;
            }

            // Backtrack: Reset digit assignment
            digitsMp[i] = -1;
        }
    }

    return false;
}

bool isSolvable(vector<string> &words, string result)
{
    // Extract words from input
    string s1 = words[0];
    string s2 = words[1];
    string s3 = result;

    set<char> uniqueAlphabetsSet;

    // Identify all unique letters in the given words
    for (const auto &word : words)
    {
        for (char ch : word)
        {
            uniqueAlphabetsSet.insert(ch);
        }
    }

    // Include letters from the result word as well
    for (char ch : result)
    {
        uniqueAlphabetsSet.insert(ch);
    }

    // Convert set of unique letters to a string for easier processing
    string alphabets(uniqueAlphabetsSet.begin(), uniqueAlphabetsSet.end());

    // Maps to track digit assignments and availability
    map<int, int> digitsMp;     // Tracks if a digit is used (-1 = unused, 1 = used)
    map<char, int> alphabetsMp; // Stores mapping of letters to digits

    // Initialize digit map with -1 (unassigned)
    for (int i = 0; i < 10; ++i)
    {
        digitsMp[i] = -1;
    }

    // Start solving the problem recursively
    return sol(0, alphabets, digitsMp, alphabetsMp, s1, s2, s3);
}
