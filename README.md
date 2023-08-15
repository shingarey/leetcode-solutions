# leetcode-solutions
solutions to the leetcode programming problems

## hash table

[1. Two Sum](https://leetcode.com/problems/two-sum/) (easy) - [solution](solutions/1_two_sum/)

[3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) (medium) - [solution](solutions/3_longest_substring/)

## linked lists

[2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) (medium) - [solution](solutions/2_add_two_numbers/)

## tree

### tree traversal

* Breadth-First Traversal
* Depth-First Traversal
* Threaded Trees - Stackless Depth-First Traversal

#### Depth-First Traversal

There are three tasks of interest in this type of traversal:

V—visiting a node
L—traversing the left subtree
R—traversing the right subtree

The three tasks can themselves be ordered in 3! = 6 ways, so there are six possible ordered depth-first traversals:
VLR VRL
LVR RVL
LRV RLV

it can be reduced to three traversals where the move is always from left to right and attention is focused on the first column. The three traversals are given these standard names:
VLR—preorder tree traversal
LVR—inorder tree traversal
LRV—postorder tree traversal

Short and elegant functions can be implemented directly from the symbolic descriptions of these three traversal. These functions may seem too simplistic, but their real power lies in recursion, in fact, double recursion. The real job is done by the system on the run-time stack. This simplifies coding but lays a heavy burden upon the system.

[104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) (easy)  - [solution](solutions/104_maximum-depth-of-binary-tree)
