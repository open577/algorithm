#include<iostream>
#include<vector>
using namespace std;

//给你一个整数数组 nums，请你将该数组升序排列。
//
//你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。
//
//
//
//示例 1：
//
//输入：nums = [5, 2, 3, 1]
//输出：[1, 2, 3, 5]
//解释：数组排序后，某些数字的位置没有改变（例如，2 和 3），而其他数字的位置发生了改变（例如，1 和 5）。
//示例 2：
//
//输入：nums = [5, 1, 1, 2, 0, 0]
//输出：[0, 0, 1, 1, 2, 5]
//解释：请注意，nums 的值不一定唯一。

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

    void qsort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int key = Getrandom(nums, l, r);
        int i = l, left = l - 1, right = r + 1;
        while (i < right)
        {
            if (nums[i] < key) swap(nums[++left], nums[i++]);
            else if (nums[i] == key) ++i;
            else swap(nums[i], nums[--right]);
        }
        // [l,left] [left+1,right-1] [right,r]
        qsort(nums, l, left);
        qsort(nums, right, r);
    }


    int Getrandom(vector<int>& nums, int l, int r)
    {
        int a = rand();
        return nums[a % (r - l + 1) + l];
    }
};

int main()
{

    return 0;
}