#include<iostream>
#include< unordered_map>
#include<vector>
using namespace std;
//
//给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
//
//子数组是数组中元素的连续非空序列。
//
//
//
//示例 1：
//
//输入：nums = [1, 1, 1], k = 2
//输出：2
//示例 2：
//
//输入：nums = [1, 2, 3], k = 3
//输出：2

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        hash[0] = 1;
        int sum = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (hash.count(sum - k)) ret += hash[sum - k];
            hash[sum]++;
        }
        return ret;
    }
};

int main()
{

    return 0;
}