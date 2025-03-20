
int longestsameCharcterSubstring(string s, int k)
{
    int l = 0;
    int r = 0;
    int hash[26] = {0}; // Initialize the hash to track character frequencies
    int maxLen = 0;
    int maxFreq = 0;
    int len = s.length();

    while (r < len)
    {
        hash[s[r] - 'A']++;
        if (maxFreq < hash[s[r] - 'A'])
        {
            maxFreq = hash[s[r] - 'A'];
        }

        // If the number of characters that need to be replaced exceeds k
        while ((r - l + 1) - maxFreq > k)
        {
            hash[s[l] - 'A']--;
            l++;
        }

        if ((r - l + 1) - maxFreq <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }

    return maxLen;
}



//     int len = s.length();
//     int hash[256] = {0}; // Tracks occurrences of each character
//     int longestSubstring = 0;
//     int tempK = k;      // Temporary k for managing replacements
//     int returningK = k; // Store the original value of k for reference

//     for (int i = 0; i < len - 1; i++)
//     {
//         int flag = 0;
//         if (hash[s[i]] == 0)
//         {
//             hash[s[i]] = 1; // First occurrence of character
//         }

//         if (i < len && s[i] == s[i + 1])
//         {
//             hash[s[i]]++; // Consecutive matching characters
//         }

//         else
//         {
//             int j;
//             for (j = i + 1; j <= i + 1 + tempK && j < len; j++)
//             {
//                 if (s[i] == s[j])
//                 {
//                     hash[s[i]] += (j - i); // Add difference between indices
//                     flag = 1;
//                     k -= (j - i - 1); // Update k only for replacements

//                     if (j + 1 == len)
//                     {
//                         k = 0;
//                     }

//                     break;
//                 }
//             }

//             // If no match found, reset hash and k
//             if (flag == 0 && j - 1 == len)
//             {
//                 hash[s[i]] = 0;
//                 k = tempK; // Reset k to the original value
//             }
//             cout << hash[s[i]];
//         }

//         if (longestSubstring < hash[s[i]])
//         {
//             if (i + 2 == len || i + 1 == len)
//             {
//                 k = 0;
//             }
//             longestSubstring = hash[s[i]]; // Update longest substring
//             returningK = k;                // Track the remaining value of k
//         }
//         // Track the longest substring of the same character
//     }

//     return (longestSubstring + returningK); // Return the length of the longest substring
// }

int main()
{

    string s = "ABAB";

    cout
        << longestsameCharcterSubstring(s, 1);

    return 0;
}