#include<bits/stdc++.h>
using namespace std;
#define int long long

// Check if string t is a substring of string S
bool isSubstring(string t) {
    int size = t.size();
    for (int i = 0; i < size; i++) {
        if (t[i] != 'a' && t[i] != 'b' && t[i] != 'c') return false;
    }
    for (int i = 0; i < size - 1; i++) {
        if (t[i] == 'a' && t[i+1] != 'b') return false;
        if (t[i] == 'b' && t[i+1] != 'c') return false;
        if (t[i] == 'c' && t[i+1] != 'a') return false;
    }
    return true;
}

int32_t main() {
	string t;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (isSubstring(t)) cout << "YES\n";
		else cout << "NO\n";
	}
}