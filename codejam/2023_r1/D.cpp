#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000;

int F[N+1], L[N+1];

int letterRelayScore(int F[], int N) {
    for (int i = 1; i <= N; i++) L[i] = 0;
    for (int i = 1; i <= N; i++) {
        int j = i, k = 0;
        while (L[j] == 0) {
            L[j] = i;
            j = F[j];
            k++;
        }
        if (L[j] == i) return k;
    }
    return -1;
}

int minLetterRelayScore(int F[], int N) {
    int min_score = N + 1;
    for (int x = 1; x <= N; x++) {
        for (int y = x + 1; y <= N; y++) {
            swap(F[x], F[y]);
            int score = letterRelayScore(F, N);
            min_score = min(min_score, score);
            swap(F[x], F[y]); // restore original array
        }
    }
    return min_score;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> F[i];
    }
    int min_score = minLetterRelayScore(F, N);
    cout << min_score << endl;
    return 0;
}
