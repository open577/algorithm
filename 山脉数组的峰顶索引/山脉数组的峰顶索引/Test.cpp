#include<iostream>
#include<vector>
using namespace std;
//LeetCode--852

//给定一个长度为 n 的整数 山脉 数组 arr ，其中的值递增到一个 峰值元素 然后递减。
//
//返回峰值元素的下标。
//
//你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。
//
//
//
//示例 1：
//
//输入：arr = [0, 1, 0]
//输出：1
//示例 2：
//
//输入：arr = [0, 2, 1, 0]
//输出：1
//示例 3：
//
//输入：arr = [0, 10, 5, 2]
//输出：1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size() - 2;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (arr[mid] >arr[mid - 1]) left = mid;
            else right = mid - 1;
        }

        return left;
    }
};

int main()
{

    return 0;
}