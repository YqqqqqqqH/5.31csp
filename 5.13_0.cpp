#include <bits/stdc++.h>
using namespace std;

const int M = 21;

int dp[M][M];

// 维护dp[][]二维数组，用dp[i][j]表示s的前i个字符和p的前j个字符是匹配的，函数的返回值 = dp[m][n]。
bool isMatch(char *s, char *p)
{
	int m = strlen(s);
	int n = strlen(p);
	int i = 0, j = 0;
	for (int k = 0; k < m; k++)
	{
		if (s[i] == p[j])
		{
			dp[i + 1][j + 1] = 1;
			i++;
			j++;
			continue;
		}
		else
		{
			if (p[j] != '.' && p[j] != '*')
			{
				return false;
			}
			else if (p[j] != '*')
			{
				dp[i + 1][j + 1] = 1;
				i++;
				j++;
				continue;
			}
			else
			{
				// p[j] == '*'
				int tmp0 = i, tmp = j;
				dp[tmp0 + 1][tmp + 1] = dp[tmp0 + 1][tmp - 1];

				// 找到 * 能够替代的最多的位置
				while (s[i] == p[tmp - 1])
				{
					dp[i + 1][tmp + 1] = dp[tmp0 + 1][tmp + 1];
					i++;
				}

				if (p[tmp - 1] == '.')
				{
					while (s[i + 1] != p[tmp + 1])
					{
						dp[i + 2][tmp + 1] = dp[tmp0 + 1][tmp + 1];
						i++;
					}
					if (s[i + 1] == '\0')
						return true;
				}
			}
		}
		if (i == m)
		{
			return true;
		}
	}
	if (i == m)
	{
		return true;
	}
	return false;
}

int main()
{
	char s[M], p[M];
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = '\0';
	fgets(p, sizeof(p), stdin);
	p[strcspn(p, "\n")] = '\0';

	bool result = isMatch(s, p);
	printf((result > 0) ? "true" : "false");
	return 0;
}
