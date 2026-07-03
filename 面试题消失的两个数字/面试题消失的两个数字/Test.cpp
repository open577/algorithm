#include<iostream>
#include<vector>
using namespace std;

//给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？
//
//以任意顺序返回这两个数字均可。
//
//示例 1：
//
//输入：[1]
//输出：[2, 3]
//示例 2：
//
//输入：[2, 3]
//输出：[1, 4]

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int ret = 0;
        for (int i = 1; i <= nums.size() + 2; i++)
            ret ^= i;
        for (int x : nums)
            ret ^= x;

        int n = 0;
        while (1)
        {
            if (((ret >> n) & 1) == 1) break;
            else n++;
        }
        int right = ret & -ret;
        int a = 0, b = 0;

        for (auto x : nums)
        {
            if (x & right) a ^= x;
            else b ^= x;
        }

        for (int i = 1; i <= nums.size() + 2; i++)
        {
            if (i & right) a ^= i;
            else b ^= i;
        }

        // for(int x:nums)
        // {
        //    if(((x>>n)&1)==1) a^=x;
        //     else b^=x;
        // }
        // for(int i=1;i<=nums.size()+2;i++)
        // {
        //     if(((i>>n)&1)==1) a^=i;
        //     else b^=i;
        // }

        return { a,b };
    }
};

int main()
{

    return 0;
}