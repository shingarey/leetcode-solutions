#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findLongestSubsequence(vector<char> &v)
    {
        int max_sequence = 1;
        int cur_sequence = 1;

        for (size_t i = 1; i < v.size(); i++)
        {
            if ((v[i - 1] == 1) && (v[i] == 1))
            {
                cur_sequence++;
                max_sequence = max(max_sequence, cur_sequence);
            }
            else
            {
                cur_sequence = 1;
            }
        }
        return max_sequence;
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<char> v(matrix[0].size());
        int l = 0;

        for (size_t i = 1; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if (
                    ((matrix.at(i - 1).at(j) == '1') && (matrix.at(i).at(j) == '1')))
                {
                    v[j] = 1;
                }
            }
            l = max(l, findLongestSubsequence(v));
            v = matrix[i];
        }

        return l * l;
    }
};

int main(int argc, char const *argv[])
{
    Solution MySolution;
    vector<vector<char>> vec{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << MySolution.maximalSquare(vec) << endl;

    return 0;
}
