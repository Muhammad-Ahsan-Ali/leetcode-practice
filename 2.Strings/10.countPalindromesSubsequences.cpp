
bool palindrome(string s)
{
    bool isPalindrome = false;
    int len = s.length();

    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] == s[len - 1 - i])
        {
            isPalindrome = true;
        }
        else
        {
            return false;
        }
    }
    return isPalindrome;
}

void recursiveSubsequences(int index, vector<char> array, int len, string c, int &numberOfPalindromes)
{
    if (index >= len)
    {
        string subsequence = "";
        for (size_t i = 0; i < array.size(); ++i)
        {
            subsequence += array[i];
        }
        cout << subsequence << endl;
        if (palindrome(subsequence) && subsequence.length() == 5)
        {
            numberOfPalindromes++;
        }
        return;
    }

    array.push_back(c[index]);
    recursiveSubsequences(index + 1, array, len, c, numberOfPalindromes);
    array.pop_back();
    recursiveSubsequences(index + 1, array, len, c, numberOfPalindromes);
}

int countPalindromes(string s)
{
    int len = s.length();
    int numberOfPalindromes = 0;

    // by generating all recursinve sunsequensces fiding number of palindrome
    // vector<char> array;
    // recursiveSubsequences(0, array, len, s, numberOfPalindromes);

    int l;
    int r;

    for (int i = 2; i <= len - 3; i++)
    {
        int subseqLength = 1;

        r = i + 1;
        l = i - 1;

        while (l >= 0 && r < len)
        {
            if (s[l] == s[r])
            {
                subseqLength += 2;
                l--;
                r++;

                if (subseqLength == 5)
                {
                    numberOfPalindromes++;
                    break;
                }
            }
            else
            {
                r++;
                if (r >= len)
                {
                    l--;
                    r = i + 1;
                    subseqLength = 1;
                }
            }
        }
    }

    return numberOfPalindromes;
}

//........................

class Solution
{
public:
    const int mod = 1e9 + 7; // Large prime to modulate results

    // Helper function to reverse a two-digit number
    int giveRev(int x)
    {
        // If x is a single digit, return it as a reversed 2-digit number
        if (x < 10)
            return 10 * x;
        // Reverse two digits, i.e., if x = 12, return 21
        return (x % 10) * 10 + x / 10;
    }
 
    // Function to count palindromes of length 5
    int countPalindroes(string &str)
    {
        vector<long long> forwardCount(10, 0);  // To count digits in forward traversal
        vector<long long> backwardCount(10, 0); // To count digits in backward traversal
        vector<long long> subFront(100, 0);     // To count two-digit combinations in forward traversal
        vector<long long> subBack(100, 0);      // To count two-digit combinations in backward traversal

        // Step 1: Fill `backwardCount` and `subBack` by traversing the string backward
        for (int i = str.size() - 1; i >= 0; --i)
        {
            int x = str[i] - '0'; // Convert char to digit
            // Update subBack for all two-digit pairs ending with digit `x`
            for (int j = 0; j < 10; ++j)
            {
                subBack[x * 10 + j] += backwardCount[j];
            }
            // Update backwardCount for the current digit `x`
            backwardCount[x]++;
        }

        long long ans = 0;

        // Step 2: Traverse the string forward and calculate palindrome count
        for (int i = 0; i < str.size(); ++i)
        {
            int x = str[i] - '0'; // Convert char to digit

            // Remove the current digit `x` from backward count since we move past it
            backwardCount[x]--;

            // Update subBack for all two-digit pairs ending with digit `x`
            for (int j = 0; j < 10; ++j)
            {
                subBack[x * 10 + j] -= backwardCount[j];
            }

            // Calculate palindrome contribution
            // For each two-digit combination, check if the reverse is valid in `subFront` and `subBack`
            for (int j = 0; j < 100; ++j)
            {
                ans += subFront[j] * subBack[giveRev(j)];
                ans %= mod; // Ensure no overflow
            }

            // Update subFront for all two-digit pairs starting with digit `x`
            for (int j = 0; j < 10; ++j)
            {
                subFront[j * 10 + x] += forwardCount[j];
            }

            // Update forwardCount for the current digit `x`
            forwardCount[x]++;
        }

        return ans;
    }
};
 