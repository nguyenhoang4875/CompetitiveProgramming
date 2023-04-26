#include<bits/stdc++.h>

using namespace std;

int tcs;
int n = 9;
string s1, s2;
vector<bool> cnt(10);
unordered_map<char, int> mci;
vector<int> t(10, 0);
int preSum = 0;

int hv[10];
bool used[10];

bool found = false;

int check(char c, int i) {
    int num = 0;
    if(cnt[1] && cnt[2] && cnt[3]) num++;
    if(cnt[4] && cnt[5] && cnt[6]) num++;
    if(cnt[7] && cnt[8] && cnt[9]) num++;
    if(cnt[1] && cnt[4] && cnt[7]) num++;
    if(cnt[2] && cnt[5] && cnt[8]) num++;
    if(cnt[3] && cnt[6] && cnt[9]) num++;
    if(cnt[1] && cnt[5] && cnt[9]) num++;
    if(cnt[3] && cnt[5] && cnt[7]) num++;
    return num - preSum;
}


vector<int> gent(string &s1) {
    vector<int> t (10,0);
    for(int i = 1; i <= n ; i++) {
        char ch = s1[i];
        cnt[mci[ch]] = true;
        t[i] = check(ch, i);
        preSum += t[i];
    }
    return t;

}

vector<int> calculate(string sc) {
    preSum = 0;
    fill(cnt.begin(), cnt.end(), false);
    return  gent(sc);
}

void gen(int index, string &sc) {
    if(found == true) return;
    if(index > n) {
        string str=" ";
        for (int i = 1; i <= n ; i++) {
            str += sc[hv[i]];
        }
        vector<int> tc = calculate(str);
        if(t == tc) {
            found = true;
            for (int k = 1; k <= n ; k++) {
                cout << t[k];
            }
            cout << str << endl;
            return;
        }


    } else {
        for (int val = 1;  val <= n; val++) {
            if(used[val]) continue;
            used[val] = true;
            hv[index] = val;
            gen(index+1, sc);
            used[val] = false; 
        }
    }
}

void solve() {
    preSum = 0;
    fill(cnt.begin(), cnt.end(), false);
    mci.clear();
    cin >> s1;
    s1 = " " + s1;
    s2 = " ";

    for (int i = 1; i <= 3; i++) {
        string temp;
        cin >> temp;
        s2+=temp;
    }
    for(int i = 1; i <= n ; i++) {
        mci[s2[i]] = i;
    }

    t  = gent(s1);

    string sc = s1;
    sort(sc.begin() + 1, sc.end());

    found = false;
    gen(1, sc);
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}