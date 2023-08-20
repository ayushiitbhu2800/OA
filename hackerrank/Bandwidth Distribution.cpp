ll dp[101][int(1e5) + 1];
ll find(vector<int>&a, vector<int>&b, int cur, int n, int m) {
	if (cur == n) return 0;
	if (dp[cur][m] != -1) return dp[cur][m];
	if (a[cur] > m) return dp[cur][m] = find(a, b, cur + 1, n, m);
	return dp[cur][m] = max(find(a, b, cur + 1, n, m), b[cur] + find(a, b, cur + 1, n, m - a[cur]));
}
// n = n
// a = bandwidth
// b = request
// m = total_bandwidth
ll bandwidthDistribution(int n, int m, vector<int>&a, vector<int>&b) {
	memset(dp, -1, sizeof(dp));
	return find(a, b, 0, n, m);
}