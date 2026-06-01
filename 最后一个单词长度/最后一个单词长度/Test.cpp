#include<iostream>
using namespace std;
//给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
//
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        int cur = s.size() - 1;
        //跳过括号
        while (cur >= 0 && s[cur] == ' ')
        {
            cur--;
        }
        //计数
        while (cur >= 0 && s[cur] != ' ')
        {
            size++;
            cur--;
        }
        return size;
    }
};

int main()
{

    return 0;
}