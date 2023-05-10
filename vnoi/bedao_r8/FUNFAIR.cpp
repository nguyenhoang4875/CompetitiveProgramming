#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, A[1000005], L[1000005], R[1000005], x, y;

int32_t main() {
	cin >> n;
	cin >> x >> y;
	for (int i = 1; i <= n; i++) cin >> A[i];
	L[0] = 0;
	for (int i = 1; i <= n; i++) {
		L[i] = 0;
		if (A[i] >= x) {
			L[i] = max(L[i-1] + A[i], A[i]);
		}
	}
	R[n+1] = 0;
	for (int i = n; i >= 1; i--) {
		R[i] = 0;
		if (A[i] >= x) {
			R[i] = max(R[i+1]+A[i], A[i]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (x <= A[i] && A[i] <= y) {
			int tmp = A[i];
			if (L[i-1] > 0) tmp += L[i-1];
			if (R[i+1] > 0) tmp += R[i+1];
			ans = max(ans, tmp);
		}
	}
	cout << ans;
}
