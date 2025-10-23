// We can assign types to bytes:

// 0 → single-byte (starts with 0)

// 1 → leading byte for 2-byte char (110xxxxx)

// 2 → leading byte for 3-byte char (1110xxxx)

// 3 → leading byte for 4-byte char (11110xxx)

// -1 → continuation (10xxxxxx)

// -2 → invalid (anything else, e.g. 11111xxx)

class Solution
{
private:
    static vector<int> buildLookUp()
    {
        vector<int> lookUp(256, -2);

        for (int i = 0; i <= 255; i++)
        {
            if (i >> 7 == 0b0)
                lookUp[i] = 0;
            else if (i >> 5 == 0b110)
                lookUp[i] = 1;
            else if (i >> 4 == 0b1110)
                lookUp[i] = 2;
            else if (i >> 3 == 0b11110)
                lookUp[i] = 3;
            else if (i >> 6 == 0b10)
                lookUp[i] = -1;
        }
        return lookUp;
    }

public:
    bool validUtf8(vector<int> &data)
    {
        static vector<int> lookUp = buildLookUp();
        int n = data.size();
        int i = 0;

        while (i < n)
        {
            int t = lookUp[data[i]];

            if (t < 0)
                return false;
            for (int j = 1; j <= t; j++)
                if (i + j >= n || lookUp[data[i + j]] != -1)
                    return false;

            i = i + t + 1;
        }
        return true;
    }
};