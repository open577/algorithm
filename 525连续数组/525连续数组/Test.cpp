#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//
//给定一个二进制数组 nums, 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
//
//
//
//示例 1：
//
//输入：nums = [0, 1]
//输出：2
//说明：[0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
//示例 2：
//
//输入：nums = [0, 1, 0]
//输出：2
//说明：[0, 1](或[1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。
//示例 3：
//
//输入：nums = [0, 1, 1, 1, 1, 1, 0, 0, 0]
//输出：6
//解释：[1, 1, 1, 0, 0, 0] 是具有相同数量 0 和 1 的最长连续子数组。

class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int, int> hash;
        //hash[0]=-1;
        int sum = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (hash.count(sum)) ret = max(ret, i - hash[sum]);
            else hash[sum] = i;
        }
        return ret;
    }
};

int main()
{
    return 0;
}