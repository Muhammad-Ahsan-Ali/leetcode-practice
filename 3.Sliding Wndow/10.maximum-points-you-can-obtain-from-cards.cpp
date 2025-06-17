class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int l = 0;
        int ans = 0;

        int windowSum = 0;
        int windowSize = n - k;

        for (int i = 0; i < windowSize; i++)
            windowSum += cardPoints[i];

        int MinWindowSum = windowSum;
        for (int i = windowSize; i < n; i++)
        {
            windowSum += cardPoints[i] - cardPoints[i - (windowSize)];
            MinWindowSum = min(MinWindowSum, windowSum);
        }

        return sum - MinWindowSum;
    }
};
