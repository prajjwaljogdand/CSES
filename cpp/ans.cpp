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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }

        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            stack<int> s;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node != NULL)
                {
                    if (level % 2 == 0)
                    {
                        v.push_back(node->val);
                        if (node->left != NULL)
                            q.push(node->left);
                        if (node->right != NULL)
                            q.push(node->right);
                    }
                    else
                    {
                        s.push(node->val);
                        if (node->left != NULL)
                            q.push(node->left);
                        if (node->right != NULL)
                            q.push(node->right);
                    }
                }
            }
            if (level % 2 == 0)
            {
                ans.push_back(v);
            }
            else
            {

                vector<int> h;
                while (!s.empty())
                {
                    h.push_back(s.top());
                    cout << s.top() << endl;
                    s.pop();
                }
                ans.push_back(h);
            }
            level++;
        }
        return ans;
    }
};