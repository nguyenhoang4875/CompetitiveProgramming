#include <bits/stdc++.h>

#define int long long

using namespace std;

int f[10000];

int d[10000];

int oo = 1000000;

 

int numOfFectory(int n) {

  int c = 0;

  int sqrt_n = sqrt(n);

  for (int i = 1; i <= sqrt_n; i++) {

    if(n % i == 0) c += 2;

  }

  if(sqrt_n * sqrt_n == n) c--;

  return c;

}

 

bool condition2(int a, int b ) {

  int c = 0;

  while(a > 0 || b > 0) {

    int a1 = a % 10;

    int b1 = b % 10;

    if(a1 != b1) c++;

    if( c > 1) return false;

    a /= 10;

    b /= 10;

  }

  return true;

}

 

void bfs(int s) {

  for(int i = 1000; i <= 9999; i++) {

    d[i] = oo;

  }

  d[s] = 0;

  queue<int> q;

  q.push(s);

  while(!q.empty()) {

    int cp = q.front(); q.pop();

    // cout << cp << endl;

    for(int i = 1000; i <= 9999; i++) {

      if(condition2(i, cp)  && (abs(f[i] - f[cp]) <= 1) && d[i] > d[cp] + 1) {

        // cout << i << " " << f[i] << " " << f[cp] << endl;

        // cout << "has value\n";

        d[i] = d[cp] + 1;

        q.push(i);

      }

    }

  }

//    for(int i = 1000; i <= 9999; i++) {

//     cout << d[i] << endl;

//   }

}

 

void solve() {

    int S, E1, E2;

    cin >> S >> E1 >> E2;

    for(int i = 1000; i <= 9999; i++) {

        f[i] = numOfFectory(i);

        // cout << f[i] << " ";

    }

  bfs(S);

  cout << d[E1] << endl;

  cout << d[E2] << endl;

}

 

int32_t main () {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    solve();

    return 0;

}