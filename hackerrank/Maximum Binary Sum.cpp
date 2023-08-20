// k = numberOfBits
// m = maximumOperationsAllowed
// n = N
// a = arr
string maximumBinarySum(int k, int m, int n, vector<string>&a) {
	sort(a.begin(), a.end());
	m = min(m, (int)a.size());
	for (int i = 0; i < m; i++) {
		if (a[i][0] != '0') break;
		for (int j = 0; j < k; j++) {
			if (a[i][j] == '0') a[i][j] = '1';
			else a[i][j] = '0';
		}
	}
	int sum = 0;
	string ans = "";
	for (int j = k - 1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			sum += (a[i][j] - '0');
		}
		ans += to_string(sum % 2);
		sum /= 2;
	}
	while (sum) {
		ans += to_string(sum % 2);
		sum /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}