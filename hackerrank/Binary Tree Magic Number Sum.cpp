// n = N
// v = value of root node
// a =  graph
int binaryTreeMagicNumberSum(int n, int v, vector<string>&a) {
	vector<vector<int>>g(n);
	unordered_map<string, int>ma;
	ma[""] = 0;
	vector<int>val(n);
	val[0] = v;
	for (int i = 0; i < a.size(); i++) {
		int num = 0;
		string u = a[i];
		int j = 0;
		string t = "";
		while (u[j] != ' ') {
			t += u[j++];
		}
		j++;
		while (j < u.size()) {

			num *= 10;
			num += (u[j] - '0');
			j++;
		}
		ma[u] = i + 1;
		u.pop_back();
		val[i + 1] = num;
		g[ma[u]].push_back(i + 1);
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		auto u = g[i];
		int flag = 0;
		for (int j = 0; j < u.size(); j++) {
			for (int k = j + 1; k < u.size(); k++) {
				if ((u[k] % u[j]) == 0 || (u[j] % u[k]) == 0) {
					flag = 1;
					break;
				}
			}
		}
		if (flag)
			sum += val[i];
	}
	return sum;
}