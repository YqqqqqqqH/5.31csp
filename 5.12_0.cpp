// 最长回文子序列（Longest Palindromic Subsequence）
// dp[i][j] 表示 s[i..j] 中最长回文子序列的长度
#include <algorithm>
#include <cstdio>
#include <cstring>

const int MAXN = 1001;

int dp[MAXN][MAXN];

int main()
{
	char s[MAXN];
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = '\0';
	int n = strlen(s);

	for (int l = 1; l <= n; l++)
	{
		for (int i = 0; i <= n - l; i++)
		{
			int j = i + l - 1;
			if (l == 1)
			{
				dp[i][j] = 1;
			}
			else if (l == 2)
			{
				dp[i][j] = (s[i] == s[j]) ? 2 : 1;
			}
			else
			{
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}

	// 回溯输出最长回文子序列
	char lps[MAXN];
	int len = 0;
	int left = 0, right = n - 1;
	while (left <= right)
	{
		if (s[left] == s[right])
		{
			lps[len++] = s[left];
			left++;
			right--;
		}
		else
		{
			if (dp[left + 1][right] >= dp[left][right - 1])
				left++;
			else
				right--;
		}
	}

	for (int i = 0; i < len; i++)
		putchar(lps[i]);
	if (left == right + 2) // 奇数长度，中间字符只输出一次
		for (int i = len - 2; i >= 0; i--)
			putchar(lps[i]);
	else // 偶数长度
		for (int i = len - 1; i >= 0; i--)
			putchar(lps[i]);
	putchar('\n');

	return 0;
}
