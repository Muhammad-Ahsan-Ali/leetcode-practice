
bool isSubsequence(string s, string t)
{
    int lenT = t.length();
    bool isSubsequence = true;
    int lenS = s.length();

    if (lenT == 0 && lenS == 0)
    {
        return true;
    }

    int j = 0;

    for (int i = 0; i < lenS; i++)
    {
        int flag = 0;
        for (; j < lenT; j++)
        {
            if (s[i] == t[j])
            {
                j++;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return false;
        }
    }

    // genrate all subsequnces very hight complexity
    //  for (int i = 0; i < (1 << len) - 1; i++)
    //  {
    //      string subsequence = "";
    //      for (int j = 0; j < len; j++)
    //      {
    //          if ((i & (1 << j)) != 0)
    //          {
    //              subsequence = subsequence + t[j];
    //          }
    //      }
    //      if (s == subsequence)
    //      {
    //          return true;
    //      }
    //  }

    return isSubsequence;
}
