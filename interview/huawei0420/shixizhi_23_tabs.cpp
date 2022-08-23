/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: 考生实现代码
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 * 23. 代码缩进
 * 题目描述
 * 请实现一个简易的代码缩进功能：把一段未缩进的代码，通过多次操作，最终实现对每一行的缩进长度要求。
 * 一次操作指：
 * 一次操作是缩进一个TAB长度（如样例1图所示）。注：这里缩进仅指从左往右，不能回退。
 * 一次操作可选择一行或连续多行同时缩进。
 * 现给出一段代码的每行缩进长度要求，用一个数字序列表示，请计算至少需要多少次操作才能实现。
 * 解答要求 时间限制：1000ms, 内存限制：256MB
 * 输入
 * 一个整数 n ，表示代码总行数，取值范围：[1, 65535]。
 * 接下来一行有 n 个整数，依次表示第 1~n 行的最终缩进长度要求，
 * 取值范围：[0, 1000000]。
 * 测试样例
 * 5
 * 1 2 3 2 1
 * 9
 * 0 1 2 0 2 4 2 1 0
 *
 * 思路：可以将缩进问题转化为力扣接雨水问题。缩进可以一次缩进一行，也可以连续多行，
 * 这一过程与接雨水类似，雨水一次只能填平一格或者连续多个格子，此处只需要将计算水
 * 体积的部分换算成积水高度即可，配合单调栈，可以计算出tab操作次数。需要注意，先将
 * 缩进转换成凹槽的高度。
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int GetMinStep(const vector<int> &steps) {
  stack<int> stk;
  int ans = 0;

  for (int i = 0; i < steps.size(); ++i) {
    while (!stk.empty() && steps[stk.top()] <= steps[i]) {
      int bottom_idx = stk.top();
      stk.pop();
      if (stk.empty()) break;
      int left_idx = stk.top();
      ans += min(steps[left_idx], steps[i]) - steps[bottom_idx];
    }
    stk.push(i);
  }
  return ans;
}

int main() {
  int num;
  cin >> num;

  vector<int> steps(num + 2, 0);
  int max_val = 0;
  for (int i = 1; i <= num; i++) {
    cin >> steps[i];
    max_val = max(max_val, steps[i]);
  }
  for (int i = 0; i < steps.size(); ++i) {
    steps[i] = max_val - steps[i];
  }

  cout << GetMinStep(steps) << endl;

  return 0;
}
