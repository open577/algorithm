#include<iostream>
#include<vector>
using namespace std;

//给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//
//你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 1, 3, 2, 5]
//输出：[3, 5]
//解释：[5, 3] 也是有效的答案。
//示例 2：
//
//输入：nums = [-1, 0]
//输出：[-1, 0]
//示例 3：
//
//输入：nums = [0, 1]
//输出：[1, 0]

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto x : nums) ret ^= x;

        unsigned int right = ret &( ~ret+1);
        int a = 0, b = 0;
        for (auto x : nums)
        {
            if (x & right) a ^= x;
            else b ^= x;
        }

        return { a,b };
    }
};

int main()
{

    return 0;
}