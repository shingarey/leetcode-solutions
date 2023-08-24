#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// Given a sequence of numbers, count the number of times that the sequence
// crosses zero.
//
// Examples:
// [1,0,-1] -> 1 zero crossing
// [1,-1,1] -> 2 zero crossings
// [-1,1] -> 1 zero crossing
// [-1,-1] -> no zero crossing
// [0,0,0,0] -> no zero crossing
// [1,0,1] -> no zero crossing
// [-1,0,-1] -> no zero crossing

// [0, 1, -1] -> 1 zero crossing

// [1, 0, 0, 1, -1] prev=arr[0]=1

// To execute C++, please define "int main()"

int crossing_zero(vector<int> &vec)
{

    int cnt = 0;
    int prev = vec[0];

    for (size_t i = 1; i < vec.size(); i++)
    {
        if ((vec[i] > 0) && (prev < 0))
        { // crossing from prev negative
            cnt++;
            prev = vec[i];
        }
        if ((vec[i] < 0) && (prev > 0))
        {
            cnt++;
            prev = vec[i];
        }
        if ((prev == 0) && (vec[i] != 0))
        {
            prev = i;
        }
    }
    return cnt;
}

int main()
{
    vector<int> v1{1, 0, -1};
    vector<int> v2{1, -1, 1};
    vector<int> v3{-1, 1};
    vector<int> v4{-1, -1};
    vector<int> v5{0, 0, 0, 0};
    vector<int> v6{1, 0, 1};
    vector<int> v7{-1, 0, -1};
    vector<int> v8{0, 1, -1};
    vector<int> v9{1, 0, 0, 1, -1};
    vector<int> v10{0, 1, -1, 1, -1};

    assert(crossing_zero(v1) == 1);
    assert(crossing_zero(v2) == 2);
    assert(crossing_zero(v3) == 1);
    assert(crossing_zero(v4) == 0);
    assert(crossing_zero(v5) == 0);
    assert(crossing_zero(v6) == 0);
    assert(crossing_zero(v7) == 0);
    assert(crossing_zero(v8) == 1);
    assert(crossing_zero(v9) == 1);
    assert(crossing_zero(v10) == 3);

    return 0;
}
