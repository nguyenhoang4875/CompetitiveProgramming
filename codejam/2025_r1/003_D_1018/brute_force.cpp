#include <bits/stdc++.h>
using namespace std;

// Brute-force using plain int (32-bit).
// Intended for small tests (N <= 8, coordinates small) to stress-test logic.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> p(N), w(N);
        for (int i = 0; i < N; ++i) cin >> p[i] >> w[i];

        if (N == 0) {
            cout << 0 << '\n';
            continue;
        }

        int minP = p[0], maxP = p[0];
        for (int i = 1; i < N; ++i) {
            minP = min(minP, p[i]);
            maxP = max(maxP, p[i]);
        }

        // search window around monster positions (include 0)
        int L = min(minP - 3, 0);
        int R = max(maxP + 3, 0);

        vector<int> perm(N);
        for (int i = 0; i < N; ++i) perm[i] = i;

        int best = INT_MAX;

        for (int s = L; s <= R; ++s) {
            int teleport_cost = s * s; // may overflow for very large s, OK for small tests
            sort(perm.begin(), perm.end());
            do {
                int pos = s;
                int time = 0;
                int monster_cost = 0;
                bool overflow = false;
                for (int idx = 0; idx < N; ++idx) {
                    int id = perm[idx];
                    int travel = abs(pos - p[id]);
                    time += travel;
                    // check potential overflow roughly (optional)
                    // but we keep plain int per request
                    int add = w[id] * time;
                    monster_cost += add;
                    pos = p[id];
                }
                int total;
                // be careful with potential overflow when adding
                if (teleport_cost > INT_MAX - monster_cost) total = INT_MAX;
                else total = teleport_cost + monster_cost;
                if (total < best) best = total;
            } while (next_permutation(perm.begin(), perm.end()));
        }

        cout << best << '\n';
    }
    return 0;
}
