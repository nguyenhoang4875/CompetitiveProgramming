#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, A[1000005], L[1000005], R[1000005], x, y;
int idL[1000005], idR[1000005];

int32_t main() {
	cin >> n;
	cin >> x >> y;
	for (int i = 1; i <= n; i++) cin >> A[i];
	L[0] = 0;
	for (int i = 1; i <= n; i++) {
		L[i] = 0;
		if (A[i] >= x) {
			L[i] = A[i];
			idL[i] = i;
			if (L[i-1] > 0) {
				L[i] = L[i-1] + A[i];
				idL[i] = idL[i-1];
			}
		}
	}
	R[n+1] = 0;
	for (int i = n; i >= 1; i--) {
		R[i] = 0;
		if (A[i] >= x) {
			R[i] = A[i];
			idR[i] = i;
			if (R[i+1] > 0) {
				R[i] = R[i+1] + A[i];
				idR[i] = idR[i+1];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << L[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << R[i] << " ";
	}
	cout << endl;
	int ans = -1e18;
	int l, r;
	for (int i = 1; i <= n; i++) {
		if (x <= A[i] && A[i] <= y) {
			int tmp = A[i];
			int tmpL = i, tmpR = i;
			if (L[i-1] > 0) {
				tmp += L[i-1];
				tmpL = idL[i-1];
			}
			if (R[i+1] > 0) {
				tmp += R[i+1];
				tmpR = idR[i+1];
			}
			if (ans < tmp) {
				ans = tmp;
				l = tmpL;
				r = tmpR;
			}
		}
	}
	cout << ans << "\n";
	cout << l << " " << r;
}
