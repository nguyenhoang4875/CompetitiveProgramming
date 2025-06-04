#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<vector<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<set<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

void debug(map<int, vector<int>>& m)
{
    for (auto v : m) {
        cout << v.first << " : ";
        for (auto x : v.second)
            cout << x << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> m1;
        for (auto& x : a) cin >> x, m1[x]++;
        if (n == 1) {
            cout << 1 << " " << 1 << '\n';
            continue;
        }

        int l = 0, r = 0, start = -1, end = -1;
        map<int, int> m;
        int max_score = n - m1.size();
        // cout << "initial score : " << max_score << '\n';
        int min_length = n;
        for ( ; r < n; r++)
        {
            while (m[a[r]] > 0) {
                m[a[l]]--;
                m1[a[l]]++;
                l++;
                int len = n - (r-1-l+1);
                int score = len - m1.size();
                if (score > max_score || (score == max_score && len < min_length)) {
                    max_score = score;
                    min_length = len;
                    start = l;
                    end = r-1;
                }
            }

            m[a[r]]++;
            m1[a[r]]--;
            if (m1[a[r]] == 0) m1.erase(a[r]);

            int len = n - (r-l+1);
            int score = len - m1.size();
            // cout << "l: " << l << " r: " << r << " len: " << len << " score: " << score << '\n';
            if (score > max_score || (score == max_score && len < min_length)) {
                max_score = score;
                min_length = len;
                start = l;
                end = r;
            }
        }

        if (start == end && end == -1)
            cout << 0 << '\n';
        else
            cout << start+1 << " " << end+1 << '\n';
    }
    return 0;
}