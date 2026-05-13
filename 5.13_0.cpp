#include <bits/stdc++.h>
using namespace std;

const int M = 21;

int dp[M][M];

// 维护dp[][]二维数组，用dp[i][j]表示s的前i个字符和p的前j个字符是匹配的，函数的返回值 = dp[m][n]。
bool isMatch(char *s, char *p)
{
	int m = strlen(s);
	int n = strlen(p);

	// 初始化：空串和空串匹配
	dp[0][0] = 1;

	// 处理 p 中连续的 '*'，它们可以匹配零次（即跳过）
	for (int j = 1; j <= n; j++)
	{
		if (p[j - 1] == '*')
			dp[0][j] = dp[0][j - 2];
	}

	// 按行填表
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (p[j - 1] != '*')
			{
				// 当前字符匹配（相等或 '.'），取决于左上角
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
					dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				// p[j-1] == '*'，匹配零次：跳过 x*
				dp[i][j] = dp[i][j - 2];

				// 匹配一次或多次：当前 s 字符和 * 前面的字符匹配
				if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
					dp[i][j] = dp[i][j] || dp[i - 1][j];
			}
		}
	}

	return dp[m][n];
}

int main()
{
	char s[M], p[M];
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = '\0';
	fgets(p, sizeof(p), stdin);
	p[strcspn(p, "\n")] = '\0';

	bool result = isMatch(s, p);
	printf(result ? "true" : "false");
	return 0;
}
