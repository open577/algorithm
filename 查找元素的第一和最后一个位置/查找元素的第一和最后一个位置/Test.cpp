#include<iostream>
#include<vector>
using namespace std;

//LeetCode--34

//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回[-1, -1]。
//
//你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

//示例 1：
//
//输入：nums = [5, 7, 7, 8, 8, 10], target = 8
//输出：[3, 4]
//示例 2：
//
//输入：nums = [5, 7, 7, 8, 8, 10], target = 6
//输出：[-1, -1]
//示例 3：
//
//输入：nums = [], target = 0
//输出：[-1, -1]


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //判断是否为空
        if (nums.size() == 0)
            return { -1,-1 };
        //找左
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }

        if (nums[left] != target) return { -1,-1 };

        int begin = left;

        //找右
        right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }

        return { begin,right };
    }
};

int main()
{

    return 0;
}