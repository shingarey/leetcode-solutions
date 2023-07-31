#include <vector>
#include <algorithm>
#include "../src/profiler.h"

using namespace std;

// use 2 for-loops
class Solution // slow O(n^2)
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t i2 = i; i2 < nums.size(); i2++)
            {
                if ((nums[i] + nums[i2]) == target)
                {

                    return {nums[i] + nums[i2]};
                }
            }
        }
        throw;
    }
};

// use hash table, or unordered_map
class Solution2 // slow O(n)
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numToIndex;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (const auto it = numToIndex.find(target - nums[i]);
                it != numToIndex.cend())
                return {it->second, i};
            numToIndex[nums[i]] = i;
        }

        throw;
    }
};

void fillVector(vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = i;
    }
}

int main(int argc, char const *argv[])
{

    // test execution time of both solutions

    Solution SolutionSlow;
    Solution2 SolutionFast;

    vector<int> v1(10000);
    int target = (10000 - 1) + (10000 - 2);
    fillVector(v1);
    {
        LOG_DURATION("SolutionSlow"); // 277ms
        SolutionSlow.twoSum(v1, target);
    }
    {
        LOG_DURATION("SolutionFast"); // 4ms
        SolutionFast.twoSum(v1, target);
    }
    return 0;
}
