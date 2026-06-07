#include<iostream>
#include<vector>
using namespace std;

//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

//输入:
//s = "cbaebabacd", p = "abc"
//输出 :
//    [0, 6]
//    解释 :
//    起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//    起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26] = { 0 };
        vector<int> s1;
        for (auto a : p)
        {
            hash1[a - 'a']++;
        }

        int hash2[26] = { 0 };
        int count = 0;
        for (int left = 0, right = 0; right < s.size(); right++)
        {
            //进窗口+维护count
            char in = s[right];
            hash2[in - 'a']++;
            if (hash2[in - 'a'] <= hash1[in - 'a'])count++;

            //出窗口+维护count
            if (right - left + 1 > p.size())
            {
                char out = s[left];
                if (hash2[out - 'a']-- <= hash1[out - 'a'])count--;
                left++;
            }
            if (count == p.size())
                s1.push_back(left);

        }
        return  s1;
    }
};

int main()
{

    return 0;
}