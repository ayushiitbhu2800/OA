// s = s
// n = n
// a = dictionary
string glideTyping(string &s, int n, vector<string>&a) {
	vector<string>ans;
	for (int i = 0; i < n; i++) {
		int j = 0, k = 0;
		string t = a[i];
		while (j < s.length() && k < t.length()) {
			if (s[j] == t[k]) {
				k++;
			}
			j++;
		}
		if (k == t.length()) {
			ans.push_back(t);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size()) return ans[0];
	return "-1";
}
