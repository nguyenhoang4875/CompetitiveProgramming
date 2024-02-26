#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

struct Point {
    int x, y;

    bool operator<(Point p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
    bool operator==(Point p) const { return x == p.x && y == p.y; }
};

bool clockwise(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
}

bool counterClockwise(Point a, Point b, Point c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
}

vector<Point> coverHull(vector<Point> points) {
    if (points.size() <= 2) return points;

    sort(points.begin(), points.end());

    vector<Point> up, down;
    Point first = points[0], last = points.back();

    up.push_back(first);
    down.push_back(first);

    for (int i = 1; i < points.size(); i++) {
        if (i == points.size() - 1 || clockwise(first, points[i], last)) {
            // up set
            while (up.size() >= 2 &&
                   counterClockwise(up[up.size() - 2], up[up.size() - 1],
                                    points[i])) {
                up.pop_back();
            }

            up.push_back(points[i]);
        }

        if (i == points.size() - 1 ||
            counterClockwise(first, points[i], last)) {
            // down set
            while (down.size() >= 2 &&
                   clockwise(down[down.size() - 2], down[down.size() - 1],
                             points[i])) {
                down.pop_back();
            }

            down.push_back(points[i]);
        }
    }

    vector<Point> ans;
    for (auto p : up) ans.push_back(p);
    for (auto p : down) ans.push_back(p);
    sort(ans.begin(), ans.end());

    // remove duplicate element
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> res = coverHull(points);
    for (auto e : res) {
        cout << e.x << " " << e.y << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}