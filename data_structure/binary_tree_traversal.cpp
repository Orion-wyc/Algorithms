#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void preorder_traversal(TreeNode *node) {
  if (node == nullptr) return;
  cout << node->val << " ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

void inorder_traversal(TreeNode *node) {
  if (node == nullptr) return;
  inorder_traversal(node->left);
  cout << node->val << " ";
  inorder_traversal(node->right);
}

void postorder_traversal(TreeNode *node) {
  if (node == nullptr) return;
  postorder_traversal(node->left);
  postorder_traversal(node->right);
  cout << node->val << " ";
}

vector<int> level_order_traversal(TreeNode *root) {
  vector<int> ret;
  if (!root) {
    return ret;
  }

  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    int currentLevelSize = q.size();
    for (int i = 1; i <= currentLevelSize; ++i) {
      auto node = q.front();
      q.pop();
      ret.push_back(node->val);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }

  return ret;
}

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ans;
  stack<TreeNode *> stk;
  if (root != NULL) stk.push(root);
  while (!stk.empty()) {
    TreeNode *cur = stk.top();
    stk.pop();
    ans.push_back(cur->val);
    if (cur->right != NULL) stk.push(cur->right);
    if (cur->left != NULL) stk.push(cur->left);
  }
  return ans;
}

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ans;
  stack<TreeNode *> stk;
  TreeNode *curr = root;
  while (!stk.empty() || curr != NULL) {
    // 找到节点的最左侧节点，同时记录路径入栈
    while (curr != NULL) {
      stk.push(curr);
      curr = curr->left;
    }
    // top定义是此刻的弹栈元素
    TreeNode *top = stk.top();
    ans.push_back(top->val);
    stk.pop();
    // 处理过最左侧结点后，判断其是否存在右子树
    if (top->right != NULL) curr = top->right;
  }
  return ans;
}

vector<int> postorderTraversal(TreeNode *root) {
  vector<int> ans;
  stack<TreeNode *> stk;
  if (root != NULL) stk.push(root);
  // curr存储当前退出栈的结点
  TreeNode *curr = root;
  while (!stk.empty()) {
    TreeNode *top = stk.top();
    if (top->left != NULL && top->left != curr && top->right != curr)
      stk.push(top->left);
    else if (top->right != NULL && top->right != curr)
      stk.push(top->right);
    // 当左右子树都处理过或者不存在情况下，说明此结点可以弹栈
    else {
      ans.push_back(top->val);
      stk.pop();
      curr = top;
    }
  }
  return ans;
}

class Solution {
 private:
  unordered_map<int, int> index;

 public:
  TreeNode *myBuildTree(const vector<int> &preorder, const vector<int> &inorder,
                        int preorder_left, int preorder_right, int inorder_left,
                        int inorder_right) {
    if (preorder_left > preorder_right) {
      return nullptr;
    }

    // 前序遍历中的第一个节点就是根节点
    int preorder_root = preorder_left;
    // 在中序遍历中定位根节点
    int inorder_root = index[preorder[preorder_root]];

    // 先把根节点建立出来
    TreeNode *root = new TreeNode(preorder[preorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的
    // size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到
    // 根节点定位-1」的元素
    root->left = myBuildTree(preorder, inorder, preorder_left + 1,
                             preorder_left + size_left_subtree, inorder_left,
                             inorder_root - 1);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到
    // 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right =
        myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1,
                    preorder_right, inorder_root + 1, inorder_right);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    // 构造哈希映射，帮助我们快速定位根节点
    for (int i = 0; i < n; ++i) {
      index[inorder[i]] = i;
    }
    return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};

int main() {
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  Solution solution;
  TreeNode *root = solution.buildTree(preorder, inorder);
  preorder_traversal(root);
  cout << endl;

  inorder_traversal(root);
  cout << endl;

  postorder_traversal(root);
  cout << endl;

  // 非递归
  vector<int> ans;
  ans = preorderTraversal(root);
  copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  ans = inorderTraversal(root);
  copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  ans = postorderTraversal(root);
  copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  ans = level_order_traversal(root);
  copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}