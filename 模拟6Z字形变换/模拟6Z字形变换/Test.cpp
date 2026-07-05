#include<iostream>
#include<string>
using namespace std;
//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//
//请你实现这个将字符串进行指定行数变换的函数：
//
//string convert(string s, int numRows);
//
//
//示例 1：
//
//输入：s = "PAYPALISHIRING", numRows = 3
//输出："PAHNAPLSIIGYIR"
//示例 2：
//输入：s = "PAYPALISHIRING", numRows = 4
//输出："PINALSIGYAHRPI"
//解释：
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
//示例 3：
//
//输入：s = "A", numRows = 1
//输出："A"

class Solution {
public:
    string convert(string s, int line) {

        if (line == 1) return s;
        string ret;
        int d = 2 * line - 2, n = s.size();
        //处理第一行
        for (int i = 0; i < n; i += d)
        {
            ret += s[i];
        }

        //处理中间
        for (int k = 1; k < line - 1; k++)
        {
            for (int i = k, j = d - k; i < n || j < n; i += d, j += d)
            {
                if (i < n) ret += s[i];
                if (j < n) ret += s[j];
            }
        }

        //处理最后一行
        for (int i = line - 1; i < n; i += d)
        {
            ret += s[i];
        }
        return ret;
    }
};

int main()
{

    return 0;
}