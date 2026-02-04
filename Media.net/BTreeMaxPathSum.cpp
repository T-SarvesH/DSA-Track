// Binary Tree Max sum path
// Approach: DFS
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int solve(TreeNode* root, int &maxi) {
        if (!root) return 0;

        // Take max with 0 to ignore paths that decrease the sum
        int leftMax = max(0, solve(root->left, maxi));
        int rightMax = max(0, solve(root->right, maxi));

        // Update the global max using the "V-Shape" (Bridge)
        maxi = max(maxi, leftMax + rightMax + root->val);

        // Return the "Straight Line" (Branch) to the parent
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};

TreeNode* buildTreeFromInput() {
    string input;
    cout << "Enter nodes in level order (e.g., -10 9 20 null null 15 7): " << endl;
    getline(cin, input);
    
    stringstream ss(input);
    string val;
    vector<string> nodes;
    while (ss >> val) nodes.push_back(val);

    if (nodes.empty() || nodes[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        
        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

       
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    TreeNode* root = buildTreeFromInput();
    
    Solution sol;
    int result = sol.maxPathSum(root);
    
    if (root == NULL) {
        cout << "The tree is empty." << endl;
    } else {
        cout << "\nMaximum Path Sum: " << result << endl;
    }

    return 0;
}
