#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/LAZYPROG/
*/

struct node {
    int a, b, c;
    node() : a(-1), b(-1), c(-1) {}
    node(int x, int y, int z) : a(x), b(y), c(z) {}
    bool operator<(node const &other) const { return c < other.c; }
};

int tcs, n;
node task[100000];
priority_queue<pair<int, int> > pq;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        task[i] = node(x, y, z);
    }
    sort(task, task + n);
    int time = 0;
    double money = 0;
    pq = priority_queue<pair<int, int> >();
    for (int i = 0; i < n; i++) {
        time += task[i].b;
        pq.push({task[i].a, task[i].b});
        if (time <= task[i].c) continue;
        while (true) {
            pair<int, int> temp = pq.top();
            pq.pop();
            if (time - temp.second <= task[i].c) {
                temp.second -= time - task[i].c;
                money += 1.0 * (time - task[i].c) / temp.first;
                time = task[i].c;
                pq.push(temp);
                break;
            } else {
                money += 1.0 * (temp.second) / temp.first;
                time -= temp.second;
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << money << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) solve();
    return 0;
}