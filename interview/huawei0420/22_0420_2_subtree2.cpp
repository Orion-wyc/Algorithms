#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//二叉树建立
TreeNode* creat(vector<int>& nums) {
  queue<TreeNode*> qe;
  TreeNode* head = new TreeNode(nums[0]);
  qe.push(head);
  int j = 1;
  while (j < nums.size()) {
    auto t = qe.front();
    qe.pop();
    if (nums[j] != 0) {
      TreeNode* left = new TreeNode(nums[j]);
      t->left = left;
      qe.push(left);
    }
    if (j + 1 < nums.size() && nums[j + 1] != 0) {
      TreeNode* right = new TreeNode(nums[j + 1]);
      t->right = right;
      qe.push(right);
    }
    j++;
    j++;
  }
  return head;
}

//替换
void tihuan(vector<int>& nums, TreeNode* parent, TreeNode* son, int j) {
  if (parent == NULL) {
    return;
  }
  if (parent->left && nums[j] == parent->left->val && j != nums.size() - 1) {
    tihuan(nums, parent->left, son, j + 1);
  } else if (parent->right && nums[j] == parent->right->val &&
             j != nums.size() - 1) {
    tihuan(nums, parent->right, son, j + 1);
  } else if (parent->left && nums[j] == parent->left->val &&
             j == nums.size() - 1) {
    parent->left = son;
    return;
  } else if (parent->right && nums[j] == parent->right->val &&
             j == nums.size() - 1) {
    parent->right = son;
    return;
  }
  return;
}

//层次便利
void mid(vector<int>& result, TreeNode* cur) {
  if (!cur) {
    return;
  }
  queue<TreeNode*> qe;
  qe.push(cur);
  while (!qe.empty()) {
    TreeNode* t = qe.front();
    qe.pop();
    result.push_back(t->val);
    if (t->left) {
      qe.push(t->left);
    }
    if (t->right) {
      qe.push(t->right);
    }
  }
}

int main() {
  //输入父树
  string mys;
  cin >> mys;
  vector<int> vc;
  for (int i = 0; i < mys.size(); i++) {
    if (mys[i] <= '9' && mys[i] >= '0') {
      vc.push_back(mys[i] - '0');
    }
  }
  //输入查找路劲
  string path;
  cin >> path;
  vector<int> mypath;
  for (int i = 0; i < path.size(); i++) {
    if (path[i] <= '9' && path[i] >= '0') {
      mypath.push_back(path[i] - '0');
    }
  }
  //输入子树
  string son;
  cin >> son;
  vector<int> mson;
  for (int i = 0; i < son.size(); i++) {
    if (son[i] <= '9' && son[i] >= '0') {
      mson.push_back(son[i] - '0');
    }
  }

  //建树

  TreeNode* parent = creat(vc);
  TreeNode* mmson = creat(mson);

  //替换树
  if (mypath.size() == 1) {
    parent = mmson;
  } else
    tihuan(mypath, parent, mmson, 1);
  vector<int> result;

  //层次便利

  mid(result, parent);
  string mResult;
  mResult += "[";
  for (int i = 0; i < result.size(); i++) {
    mResult += to_string(result[i]);
    mResult += ',';
  }
  mResult.pop_back();
  mResult += "]";
  cout << mResult << endl;

  system("pause");
  return 0;
}