class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        string start = beginWord;
        set<string> s(wordList.begin(), wordList.end()); // Store wordList in a set for quick lookup
        queue<pair<string, int>> q;                      // Queue to store words along with their transformation steps

        q.push({start, 1}); // Push the starting word with an initial step count of 1

        while (!q.empty())
        {
            string curWord = q.front().first; // Get the current word
            int curStp = q.front().second;    // Get the current step count
            q.pop();                          // Remove the processed word from the queue

            if (curWord == endWord) // If we reach the endWord, return the transformation steps
                return curStp;

            // Try changing each character of the current word
            for (int i = 0; i < curWord.length(); i++)
            {
                string temp = curWord; // Copy the current word
                for (char c = 'a'; c <= 'z'; c++)
                {
                    // Replace with every letter from 'a' to 'z'
                    temp[i] = c;

                    // If the transformed word exists in the set
                    if (s.find(temp) != s.end())
                    {
                        q.push({temp, curStp + 1}); // Push the transformed word with step count +1
                        s.erase(temp);              // Remove the word from the set to avoid revisiting
                    }
                }
            }
        }
        return 0; // If no transformation sequence is found, return 0
    }
};
