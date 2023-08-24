#include <algorithm>
#include <ranges>
#include <unordered_map>
#include <vector>

/* Problem:
Given a list of integers as std::vector<int> and the count k,
return the top k most frequent values in the list in any order.

You can assume that the input leads to a unique solution and
your solution is required to operate faster than O(n*logn).
*/

/* Solution:
For a solution that operations faster than O(n*logn),
we only have few options.

We could use nth_element for an O(n) solution, however,
that has a high constant overhead.

For a O(n*logk) we could use:

- ordered containers: std::priority_queue, std::set
- heap algorithms: std::push_heap, std::pop_heap
- partial sort: std::partial_sort, std::partial_sort_copy

In particular, using std::partial_sort_copy allows us
to implement a simple two-step solution.
*/

std::vector<int> most_frequent_elements(const std::vector<int> &nums, int k)
{
    // Compute the frequencies of elements
    std::unordered_map<int, int> map;
    for (auto v : nums)
        ++map[v];

    // Resize the result so it has k elements
    std::vector<int> result(std::min(int64_t{k}, std::ssize(nums)));
    // Partially sort the keys from the frequency map into result
    // in non-ascending order based on their frequency.
    std::ranges::partial_sort_copy(map | std::views::keys, result,
                                   [&map](int l, int r)
                                   {
                                       return map[l] > map[r];
                                   });
    return result;
}

#include <cassert>

int main()
{
    assert(std::ranges::is_permutation(most_frequent_elements({1}, 1), std::vector<int>{1}));
    assert(std::ranges::is_permutation(most_frequent_elements({1}, 2), std::vector<int>{1}));

    assert(std::ranges::is_permutation(most_frequent_elements({1, 1, 1, 2, 2, 3}, 2), std::vector<int>{1, 2}));
    assert(std::ranges::is_permutation(most_frequent_elements({1, 1, 1, 2, 2, 3}, 1), std::vector<int>{1}));

    assert(std::ranges::is_permutation(most_frequent_elements({9, 8, 8, 7, 6, 5, 5, 4, 3, 2, 1}, 2), std::vector<int>{8, 5}));

    assert(std::ranges::is_permutation(most_frequent_elements({1, 8, 3, 8, 7, 5, 2, 6, 2, 4, 6, 9, 8}, 3), std::vector<int>{8, 2, 6}));
    assert(std::ranges::is_permutation(most_frequent_elements({1, 8, 3, 8, 7, 5, 2, 6, 2, 4, 6, 9, 8}, 1), std::vector<int>{8}));
}