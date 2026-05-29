#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> table;
        int i = 0;
        while (i != s.size())
        {
            if (s[i] == '(')
            {
                table.push(')');
            }
            else if (s[i] == '[')
            {
                table.push(']');
            }
            else if (s[i] == '{')
            {
                table.push('}');
            }

            else
            {
                if (table.empty() || s[i] != table.top())
                    return false;

                table.pop();
            }
            i++;
        }
        return table.empty();
    }
};

int main()
{

    return 0;
}