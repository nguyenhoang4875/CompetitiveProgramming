#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int Q, numFields, numStrips;
    cin >> Q >> numFields >> numStrips;

    vector<int> fields(numFields);
    vector<int> strips(numStrips);

    // Read the number of cypress trees in each field and compute their total.
    int totalFieldTrees = 0;
    for (int i = 0; i < numFields; i++) {
        cin >> fields[i];
        totalFieldTrees += fields[i];
    }

    // Read the number of cypress trees in each strip.
    for (int i = 0; i < numStrips; i++) {
        cin >> strips[i];
    }

    int answer = 0;

    // Case 1: Total field trees is less than Q.
    // In this case, we must use some strips. (Each strip used reduces the olive count by 1.)
    if (totalFieldTrees < Q) {
        // Sort strips in ascending order so that we can pick the largest strips first.
        sort(strips.begin(), strips.end());
        int stripsUsed = 0;
        // Use strips (from largest to smallest) until the total cypress count reaches Q.
        while (stripsUsed < numStrips && totalFieldTrees < Q) {
            totalFieldTrees += strips[numStrips - stripsUsed - 1];
            stripsUsed++;
        }
        // The olive count will be reduced by the number of strips used.
        answer = Q - stripsUsed;
    }
    // Case 2: Total field trees is greater than Q.
    // In this case, the son can pick all trees from fields.
    // However, if it is possible to form exactly Q by a subset of fields, then he gets Q olives;
    // otherwise, he gets Q - 1 olives.
    else if (totalFieldTrees > Q) {
        // DP array: canForm[s] is true if we can form a sum of 's' cypress trees using some fields.
        vector<bool> canForm(Q + 1, false);
        canForm[0] = true;

        // Sort fields in ascending order to improve DP efficiency.
        sort(fields.begin(), fields.end());

        int currentMaxSum = 0;
        // Process each field.
        for (int i = 0; i < numFields && !canForm[Q]; i++) {
            // Update the DP array in reverse order to avoid using the same field twice.
            for (int s = currentMaxSum; s >= 0; s--) {
                if (canForm[s] && s + fields[i] <= Q) canForm[s + fields[i]] = true;
            }
            // Update the maximum sum we can form so far.
            currentMaxSum = min(Q, currentMaxSum + fields[i]);
        }
        // If we can form exactly Q, the son gets Q olives; otherwise, Q - 1.
        answer = Q - (canForm[Q] ? 0 : 1);
    }
    // Case 3: Total field trees equals Q.
    else {
        answer = Q;
    }

    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) solve();

    return 0;
}
