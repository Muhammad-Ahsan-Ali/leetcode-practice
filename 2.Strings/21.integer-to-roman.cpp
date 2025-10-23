class Solution
{
public:
    string intToRoman(int num)
    {
        string result = "";

        while (num >= 1000)
        {
            result += "M";
            num -= 1000;
        }

        if (num >= 900)
        {
            result += "CM";
            num -= 900;
        }

        if (num >= 500)
        {
            result += "D";
            num -= 500;
        }

        if (num >= 400)
        {
            result += "CD";
            num -= 400;
        }

        while (num >= 100)
        {
            result += "C";
            num -= 100;
        }

        if (num >= 90)
        {
            result += "XC";
            num -= 90;
        }

        if (num >= 50)
        {
            result += "L";
            num -= 50;
        }

        if (num >= 40)
        {
            result += "XL";
            num -= 40;
        }

        while (num >= 10)
        {
            result += "X";
            num -= 10;
        }

        if (num >= 9)
        {
            result += "IX";
            num -= 9;
        }

        if (num >= 5)
        {
            result += "V";
            num -= 5;
        }

        if (num >= 4)
        {
            result += "IV";
            num -= 4;
        }

        while (num >= 1)
        {
            result += "I";
            num -= 1;
        }

        return result;
    }
};

// map

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> valueSymbols = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string result = "";

        for (const auto &[value, symbol] : valueSymbols)
        {
            while (num >= value)
            {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};
