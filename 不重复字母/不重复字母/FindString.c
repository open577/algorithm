#include<stdio.h>
//问题介绍:给定一个字符串，找里面不重复字符串的最大长
int main()
{
	char s[] = "abcabcbb";
	int left = 0, right = 0, ret = 0;
	int arr[128] = { 0 };
	while (right < sizeof(s)/sizeof(s[1]))
	{
		arr[s[right]]++;
		while (arr[s[right]] > 1)
		{
			arr[s[left++]]--;
		}
		ret = ret > (right - left + 1) ? ret : (right - left + 1);
		right++;
	}
	printf("%d", ret);
	return 0;
}