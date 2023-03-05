#include <bits/stdc++.h>
using namespace std;

/**
 * Memory leak:
 *  create and destroy:
 *      C: malloc - free
 *      C++: new - delete
*/

int cash = 100;

void play(int bet) {
    char c[3] = {'J', 'Q', 'K'};
    // // using pointer will create a memory in heap and it will be memory leak if not delete pointer
    // char *c = new char[1000000];
    // c[0] = 'J';
    // c[1] = 'Q';
    // c[2] = 'K';
    printf("Shuffling ...");
    srand(time(NULL)); // seeding random number generator
    int i;
    for (int i = 0; i < 5; i++) {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = c[x];
        c[x] = c[y];
    }
    int playersGuess;
    printf("What's the position of queen: 1, 2 or 3?");
    scanf("%d", &playersGuess);
    if(c[playersGuess -1] == 'Q') {
        cash += 3 * bet;
        printf("You Win ! Result = \"%c %c %c\" Total cash = %d\n",c[0], c[1], c[2], cash);
    } else {
        cash -= bet;
        printf("You Loose! Result = \"%c %c %c\" Total cash = %d\n",c[0], c[1], c[2], cash);
    }
    // delete c; // delete memory in heap that the pointer points
}

int main() { 
    int bet;
    printf("Welcome to the Virtual Casino\n");
    printf("Total cash = %d\n", cash);
    while(cash > 0) {
        printf("What's you bet? $");
        scanf("%d", &bet);
        if(bet == 0 || bet > cash) break;
        play(bet);
    }

    return 0;
}
