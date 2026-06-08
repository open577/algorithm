#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
//
//s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
//
//例如，如果 words = ["ab", "cd", "ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"，
//和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
//返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> hash1;
        int len = words[0].size();
        for (auto a : words)
            hash1[a]++;
        //循环len次
        vector<int> ret;
        for (int i = 0; i < len; i++)
        {
            unordered_map<string, int> hash2;
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                //进窗口+维护count
                string in = s.substr(right, len);
                hash2[in]++;
                if (hash1.count(in) && hash2[in] <= hash1[in]) count++;
                //判断  出窗口+维护count
                if (right - left + 1 > len * words.size())
                {
                    string out = s.substr(left, len);
                    if (hash1.count(out) && hash2[out] <= hash1[out]) count--;
                    hash2[out]--;
                    left += len;
                }
                //更新结果
                if (count == words.size())
                    ret.push_back(left);
            }
        }
        return ret;
    }
};

int main()
{

    return 0;
}