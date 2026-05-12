// 数据结构：用dp[i][j]表示从s[i]到s[j]的最长回文字符串的长度
#include <bits/stdc++.h>
using namespace std;
int Max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int main()
{
	char s[1000];
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = '\0';

	int dp[1000][1000];
	for (int l = 1; l <= strlen(s); l++)
	{
		for (int i = 0; i <= strlen(s) - l; i++)
		{
			int j = l + i - 1;
			if (l == 1)
			{
				dp[i][j] = 1;
			}
			else
			{
				if (s[i] == s[j] && l == 2)
					dp[i][j] = 2;
				else if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else if (l == 2)
					dp[i][j] = 1;
				else
					dp[i][j] = Max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}

	// 回溯
	char LPS[501], LPS1[501];
	int tmp = 0;
	int left = 0, right = strlen(s) - 1;
	while (left <= right)
	{
		if (s[left] == s[right])
		{
			LPS[tmp++] = s[left];
			left++;
			right--;
		}
		else
		{
			if (dp[left + 1][right] >= dp[left][right - 1])
			{
				left++;
			}
			else
				right--;
		}
	}
	LPS[tmp] = '\0';
	if (left == right + 1)
	{
		// 偶数
		for (int i = 0; i < strlen(LPS); i++)
		{
			printf("%c", LPS[i]);
		}
		for (int i = strlen(LPS) - 1; i >= 0; i--)
		{
			printf("%c", LPS[i]);
		}
	}
	if (left == right + 2)
	{
		// 奇数
		for (int i = 0; i < strlen(LPS); i++)
		{
			printf("%c", LPS[i]);
		}
		for (int i = strlen(LPS) - 2; i >= 0; i--)
		{
			printf("%c", LPS[i]);
		}
	}
	return 0;
}
