#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void solution(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	for (int i = 0; i <= m; ++i) {//设置第一行的边界值
		dp[0][i] = i;
	}

	for (int i = 0; i <= n; ++i) {//设置每一列的边界值
		dp[i][0] = i;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int temp = s1[i] == s2[j] ? 1 : 0;
			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] +temp);
		}
	}
	cout<< dp[n][m];
}

int main() {
	string s1 = "123", s2 = "321";
	solution(s1,s2);
	return 0;
}