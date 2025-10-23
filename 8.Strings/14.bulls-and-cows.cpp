class Solution
{
public:
    string getHint(string secret, string guess)
    {

        unordered_map<char, int> hash;

        for (auto c : secret)
            hash[c]++;

        int A_Cnt = 0;
        for (int i = 0; i < secret.length(); i++)
            if (secret[i] == guess[i])
            {
                hash[secret[i]]--;
                A_Cnt++;
            }

        int B_Cnt = 0;

        for (int i = 0; i < guess.size(); i++)
            if (secret[i] != guess[i] && hash.find(guess[i]) != hash.end() &&
                hash[guess[i]] > 0)
            {
                B_Cnt++;
                hash[guess[i]]--;
            }

        string ans = to_string(A_Cnt) + "A" + to_string(B_Cnt) + "B";

        return ans;
    }
};