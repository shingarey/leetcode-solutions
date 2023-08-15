/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <queue>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time:  O(n)
// Space: O(h)
// DFS, Recursive solution.
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root != nullptr)
        {
            invertTree(root->left);
            invertTree(root->right);
            TreeNode *temp_node;
            temp_node = root->right;
            root->right = root->left;
            root->left = temp_node;
        }
        return root;
    }
};

// Time:  O(n)
// Space: O(w), w is the max number of nodes of the levels.
// BFS solution.
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root != nullptr)
        {
            std::queue<TreeNode *> nodes;
            nodes.emplace(root);
            while (!nodes.empty())
            {
                auto node = nodes.front();
                nodes.pop();
                std::swap(node->left, node->right);
                if (node->left != nullptr)
                {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr)
                {
                    nodes.emplace(node->right);
                }
            }
        }
        return root;
    }
};