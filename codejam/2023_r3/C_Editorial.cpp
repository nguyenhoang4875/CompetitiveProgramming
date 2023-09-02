#include <bits/stdc++.h>
#define int long long
using namespace std;
/**
 * Problem: https://codejam.lge.com/contest/problem/1113/3
 * Solution:
 *  - Fenwick Tree
 *  - Binary search
 *  - Math in base
 */

const int MAX_VALUE = 500000;
int n, m;
vector<int> ns;
vector<int> ans;

struct FenwickTree {
    vector<int> bit;
    int size;

    FenwickTree(int size) {
        this->size = size + 1;
        bit.resize(size + 1, 0);
    }

    void clear() {
        bit.clear();
        bit.resize(size, 0);
    }

    void update(int i, int diff) {
        i += 1;
        while (i < size) {
            bit[i] += diff;
            i += (i & -i);
        }
    }

    int sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }

    int sum(int start, int end) { return sum(end + 1) - sum(start); }
};

FenwickTree valueBit(2 * MAX_VALUE + 1);
FenwickTree indexBit(2 * MAX_VALUE + 1);

int getIndexFront(int w) {
    int start = 0;
    int end = MAX_VALUE * 2;
    while (start < end) {
        int mid = (start + end) / 2;
        if (indexBit.sum(0, mid) >= w) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int getIndexBack(int w) {
    int start = 0;
    int end = MAX_VALUE * 2;
    while (start < end) {
        int mid = (start + end) / 2;
        if (indexBit.sum(mid, MAX_VALUE * 2) >= w) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start - 1;
}

void solution() {
    indexBit.clear();
    valueBit.clear();

    for (int num : ns) {
        indexBit.update(num + MAX_VALUE, 1);
        valueBit.update(num + MAX_VALUE, num);
    }

    int offset = 0;

    for (int i = 0; i < m; i++) {
        int q, w;
        cin >> q >> w;
        if (q == 1) {
            int index = w + MAX_VALUE;
            index -= offset;
            indexBit.update(index, 1);
            valueBit.update(index, w - offset);
        } else if (q == 2) {
            offset += w;
        } else if (q == 3) {
            int index = getIndexBack(w);
            int overflow =
                (indexBit.sum(index, MAX_VALUE * 2) - w) * (index - MAX_VALUE);
            ans.push_back(valueBit.sum(index, MAX_VALUE * 2) - overflow +
                          offset * w);
        } else if (q == 4) {
            int index = getIndexFront(w);
            int overflow = (indexBit.sum(0, index) - w) * (index - MAX_VALUE);
            ans.push_back(valueBit.sum(0, index) - overflow + offset * w);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n >> m;

        int value;
        for (int i = 0; i < n; i++) {
            cin >> value;
            ns.push_back(value);
        }
        solution();

        for (int a : ans) {
            cout << a << " ";
        }
        cout << "\n";

        ans.clear();
        ns.clear();
    }
}