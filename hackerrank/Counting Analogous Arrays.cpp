// n = n
// a = consecutiveDifference
// l = lowerBound
// u = upperBound
int countingAnalogousArrays(int n, vector<int>&a, int l, int u) {
	for (int i = 0; i < a.size(); i++) {
		a[i] = -a[i];
	}
	int mi = INT_MAX, ma = INT_MIN;
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
		mi = min(mi, sum);
		ma = max(ma, sum);
	}
	int start = max(l, l - mi), end = min(u, u - ma);
	if (start > end) return 0;
	return end - start + 1;
}
