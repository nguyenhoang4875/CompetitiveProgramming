#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250005;
int N, F[MAXN], pos[MAXN], seen[MAXN];

bool check(int mid) {
    int cnt = 0;
    memset(seen, 0, sizeof(seen));
    for (int i = 1; i <= N; i++) {
        if (seen[i]) continue;
        int j = i;
        while (!seen[j]) {
            seen[j] = 1;
            j = F[j];
        }
        cnt += (j == i);
    }
    return cnt <= mid;
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> F[i];
            pos[F[i]] = i;
        }
        int ans1 = 0, ans2 = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {
                swap(F[i], F[j]);
                swap(pos[F[i]], pos[F[j]]);
                if (pos[i] != j && check(ans2)) ans2 = max(ans2, abs(pos[i]-j));
                if (pos[j] != i && check(ans2)) ans2 = max(ans2, abs(pos[j]-i));
                swap(F[i], F[j]);
                swap(pos[F[i]], pos[F[j]]);
            }
        }
        ans1 = check(N);
        int lo = 1, hi = N;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (check(mid)) hi = mid;
            else lo = mid+1;
        }
        ans2 = hi;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
