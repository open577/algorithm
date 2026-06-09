#include<iostream>
#include<string>
using namespace std;

//给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，
//使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。

class Solution {
public:
    string minWindow(string s, string t) {
        //统计目标字符串(进行映射+统计种类)
        int hash1[128] = { 0 }; int kinds = 0;
        for (auto ch : t)
            if (hash1[ch]++ == 0)
                kinds++;

        int begin = -1; int len = INT_MAX;//合法字符起始地址和子串长度,方便后序返回子串
        int hash2[128] = { 0 };
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            //进窗口+维护count
            char in = s[right];
            if (++hash2[in] == hash1[in])count++;

            //判断  合法时再出窗口
            while (count == kinds)
            {
                //先判断是否更新子串起始地址和长度，再出窗口
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    begin = left;
                }

                //出窗口+维护count

                char out = s[left++];
                if (hash2[out]-- == hash1[out]) count--;

            }
        }
        if (begin == -1) return "";
        else return s.substr(begin, len);
    }
};

int main()
{

	return 0;
}