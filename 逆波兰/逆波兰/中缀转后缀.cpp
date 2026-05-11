#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<assert.h>
#include<map>
using namespace std;
//static map<str=ing, int> Pri = {{"+",1},{"-",1},{"*",2},{"/",2}};
int operatorPrecedence(char ch)
{
	struct opPD
	{
		char _op;
		int _pd;
	};
	static opPD arr[] = { {'+', 1},{'-', 1},{'*', 2},{'/', 2} };
	for (auto& e : arr)
	{
		if (e._op == ch)
		{
			return e._pd;
		}
	}
	assert(false);
	return -1;
}
void RPN(string& s,int& size,vector<string>& v)
{
	stack<char> st;
	while (size < s.size())
	{
		//遇到操作数
		if (isdigit(s[size]))
		{
			string num;
			while (size < s.size() && isdigit(s[size]))
			{
				num += s[size];
				++size;
			}
			v.push_back(num);
			
		}

		//遇到左括号
		else if (s[size]=='(')
		{
			++size;
			RPN(s, size, v);
		}
		//遇到右括号
		else if(s[size] == ')')
		{
			while (!st.empty())
			{
				char op = st.top();
				st.pop();

				v.push_back(string(1, op));
			}
			++size;
			return;
		}
		//遇到运算符
		else
		{
			if (st.empty() || operatorPrecedence(s[size]) > operatorPrecedence(st.top()))
			{
				st.push(s[size]);
				++size;
			}

			else
			{
				char op = st.top();
				st.pop();

				v.push_back(string(1, op));
			}
			
		}
		
	}
	while (!st.empty())
	{
		char op = st.top();
		st.pop();

		v.push_back(string(1, op));
	}
}
int main()
{
	int size = 0; 
	int size1 = 0; 
	vector<string> v;
	vector<string> v1;
	string s1 = "2+3-1";
	string str = "1+2-(3*4+5)-7";
	RPN(str, size, v1);
	//RPN(s1,size1,v);
	return  0;
}

//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//#include<set>
//#include<map>
//#include<string>
//#include<vector>
//#include<stack>
//#include<assert.h>
//using namespace std;
//
//class Solution {
//public:
//	int operatorPrecedence(char ch)
//	{
//		struct opPD
//		{
//			char _op;
//			int _pd;
//		};
//		static opPD arr[] = { {'+', 1},{'-', 1},{'*', 2},{'/', 2} };
//		for (auto& e : arr)
//		{
//			if (e._op == ch)
//			{
//				return e._pd;
//			}
//		}
//		assert(false);
//		return -1;
//	}
//
//	// 中缀转后缀
//	void toRPN(const string& s, size_t& i, vector<string>& v)
//	{
//		stack<char> st;
//
//		while (i < s.size())
//		{
//			if (isdigit(s[i]))
//			{
//				// 操作数直接输出
//				string num;
//				while (i < s.size() && isdigit(s[i]))
//				{
//					num += s[i];
//					++i;
//				}
//
//				v.push_back(num);
//			}
//			else if (s[i] == '(')
//			{
//				// 子表达式，递归处理即可
//				++i;
//				toRPN(s, i, v);
//			}
//			else if (s[i] == ')')
//			{
//				// 子表达式结束
//				// 输出栈里面的剩余运算符
//				while (!st.empty())
//				{
//					v.push_back(string(1, st.top()));
//					st.pop();
//				}
//				++i;
//				return;
//			}
//			else
//			{
//				// 运算符
//				if (st.empty() || operatorPrecedence(s[i]) > operatorPrecedence(st.top()))
//				{
//					st.push(s[i]);
//					++i;
//				}
//				else
//				{
//					char op = st.top();
//					st.pop();
//
//					v.push_back(string(1, op));
//				}
//			}
//		}
//
//		// 表达式结束
//		// 输出栈里面的剩余运算符
//		while (!st.empty())
//		{
//			v.push_back(string(1, st.top()));
//			st.pop();
//		}
//	}
//
//};
//
//int main()
//{
//	size_t i = 0;
//	vector<string> v;
//	//string str = "1+2-3";
//	string str = "1+2-(3*4+5)-7";
//	Solution().toRPN(str, i, v);
//	for (auto& e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}