#include <iostream>
using namespace std;

int N; // 풍경화의 크기
int a[10 + 10][10 + 10]; // 풍경화
int X1, X2, X3; // 숨은 그림을 의미하는 2개의 숫자

int di[8] = { -1,-1,0,1,1,1,0,-1 };
int dj[8] = { 0,1,1,1,0,-1,-1,-1 };
int Solve(void) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] != X1) continue;
			for (int k = 0; k < 8; k++) {
				int ni = i + di[k];
				int nj = j + dj[k];
				if (ni < 0 || ni >= N) continue;
				if (nj < 0 || nj >= N) continue;
				if (a[ni][nj] != X2) continue;
        int nii = ni + di[k];
        int njj = nj + dj[k];
				if (nii < 0 || nii >= N) continue;
				if (njj < 0 || njj >= N) continue;
        if(a[nii][njj] != X3) continue;
				count++;
			}
		}
	}
	return count;
}

void InputData(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	cin >> X1 >> X2 >> X3;
}

int main(void) {
	int ans;
	InputData();
	ans = Solve();
	cout << ans;
	return 0;
}