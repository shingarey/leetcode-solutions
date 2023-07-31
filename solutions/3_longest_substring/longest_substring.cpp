#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        /*
        1. define a temporarry empty unordered set (hash table), and empty result set
        2. iterate over the elements of s
        3. compare every element if it is in the temp hash table
        4. add to table, if element does not exist
        5. if element exist, stop adding
        6. compare the length of the current set with the default set
        7. if it is smaller
        8.  reinitialize new empty unordered set
        9. if bigger
        10. rewrite default set with the current set
        11. reinitialize new empty unordered set
        */
        unordered_set<char> result_set;
        unordered_set<char> temp_set;

        for (auto c : s)
        {
            if (temp_set.find(c) != temp_set.end())
            {
                if (temp_set.size() > result_set.size())
                {
                    result_set = temp_set;
                }
                temp_set.clear();
            }
            temp_set.insert(c);
        }
        return result_set.size();
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";

    Solution MySolution;

    cout << MySolution.lengthOfLongestSubstring(s1) << endl;
    cout << MySolution.lengthOfLongestSubstring(s2) << endl;
    cout << MySolution.lengthOfLongestSubstring(s3) << endl;

    return 0;
}
