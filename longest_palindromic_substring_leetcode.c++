class Solution {
public:
   string longestPalindrome(string s)
{
    int n = s.size();

    int low, high;

    int lps_start = 0;
    int lps_size = 1; // there will always be an lps of size 1 in any string

    for (int i = 0; i < n; i++)
    {
        // even case
        low = i, high = i + 1;

        while (low >= 0 and high < n and s[low] == s[high])
        {
            if (high - low + 1 > lps_size)
            {
                lps_start = low;
                lps_size = high - low + 1;
            }
            low--;
            high++;
        }

        // odd case
        low = i;
        high = i;

        while (low >= 0 and high < n and s[low] == s[high])
        {
            if (high - low + 1 > lps_size)
            {
                lps_start = low;
                lps_size = high - low + 1;
            }
            low--;
            high++;
        }
    }

    return s.substr(lps_start, lps_size);
}
};