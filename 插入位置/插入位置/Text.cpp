#include<iostream>
#include<vector>

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。


using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (target == nums[mid])
            {
                return mid;
            }

            else if (target < nums[mid])
            {
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }

        }
        return left;
    }
};
int main()
{

    return 0;
}