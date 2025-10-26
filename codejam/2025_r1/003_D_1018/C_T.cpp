#include <bits/stdc++.h>
using namespace std;

long long P_v[31][4];
long long Q_v[31][4];
long long R_v[31][4];
long long S_v[31][4];

pair<long long, long long> find_pos(int k, long long target[4]) {
    if (k == 1) {
        if (target[0] == 0 && target[1] == 0 && target[2] == 0 && target[3] == 1) return {0, 0};
        if (target[0] == 0 && target[1] == 0 && target[2] == 1 && target[3] == 0) return {0, 1};
        if (target[0] == 0 && target[1] == 1 && target[2] == 0 && target[3] == 0) return {1, 0};
        if (target[0] == 1 && target[1] == 0 && target[2] == 0 && target[3] == 0) return {1, 1};
        return {-1, -1};
    }
    long long centers[4][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };
    long long* miss_list[4] = {S_v[k-1], R_v[k-1], Q_v[k-1], P_v[k-1]};
    long long total_sub[4] = {0};
    for (int i = 0; i < 4; i++) {
        total_sub[i] = P_v[k-1][i] + Q_v[k-1][i] + R_v[k-1][i] + S_v[k-1][i];
    }
    long long m = 1LL << (k - 1);
    for (int q = 0; q < 4; q++) {
        long long remain[4];
        bool ok = true;
        for (int i = 0; i < 4; i++) {
            remain[i] = target[i] - centers[q][i];
            if (remain[i] < 0) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        long long req[4];
        ok = true;
        for (int i = 0; i < 4; i++) {
            long long sum_fake_i = total_sub[i] - miss_list[q][i];
            req[i] = remain[i] - sum_fake_i;
            if (req[i] < 0) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        auto res = find_pos(k - 1, req);
        long long lx = res.first;
        long long ly = res.second;
        if (lx == -1) continue;
        long long gx, gy;
        if (q == 0) {
            gx = lx;
            gy = ly;
        } else if (q == 1) {
            gx = lx;
            gy = ly + m;
        } else if (q == 2) {
            gx = lx + m;
            gy = ly;
        } else {
            gx = lx + m;
            gy = ly + m;
        }
        return {gx, gy};
    }
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    P_v[1][0] = 0; P_v[1][1] = 0; P_v[1][2] = 0; P_v[1][3] = 1;
    Q_v[1][0] = 0; Q_v[1][1] = 0; Q_v[1][2] = 1; Q_v[1][3] = 0;
    R_v[1][0] = 0; R_v[1][1] = 1; R_v[1][2] = 0; R_v[1][3] = 0;
    S_v[1][0] = 1; S_v[1][1] = 0; S_v[1][2] = 0; S_v[1][3] = 0;
    for (int k = 2; k <= 30; k++) {
        long long cent[4] = {0, 0, 0, 1};
        for (int i = 0; i < 4; i++) {
            P_v[k][i] = cent[i] + 2 * P_v[k-1][i] + Q_v[k-1][i] + R_v[k-1][i];
        }
        cent[0] = 0; cent[1] = 0; cent[2] = 1; cent[3] = 0;
        for (int i = 0; i < 4; i++) {
            Q_v[k][i] = cent[i] + P_v[k-1][i] + 2 * Q_v[k-1][i] + S_v[k-1][i];
        }
        cent[0] = 0; cent[1] = 1; cent[2] = 0; cent[3] = 0;
        for (int i = 0; i < 4; i++) {
            R_v[k][i] = cent[i] + P_v[k-1][i] + 2 * R_v[k-1][i] + S_v[k-1][i];
        }
        cent[0] = 1; cent[1] = 0; cent[2] = 0; cent[3] = 0;
        for (int i = 0; i < 4; i++) {
            S_v[k][i] = cent[i] + Q_v[k-1][i] + R_v[k-1][i] + 2 * S_v[k-1][i];
        }
    }
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int K;
        long long vA, vB, vC, vD;
        cin >> K >> vA >> vB >> vC >> vD;
        long long target[4] = {vA, vB, vC, vD};
        auto res = find_pos(K, target);
        cout << res.first << " " << res.second << "\n";
    }
    return 0;
}