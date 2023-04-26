    base = 1;
    up = 2*n - 3;
    for(int i = 1; i < n ; i++) {
        if(i % 2 == 1) {
            a[2][i] = base;
            base+= 2;
        } else {
            a[2][i] = up;
            up-= 2;
        }
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n ; j++) {
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }