/*
You can solve this problem using brute-force method because the total number of cases from a standard deck of cards is small enough to try.
In a standard deck of cards, there are the thirteen face values and each face value has four suits.
So, you can organize the cases without N cards and count the number of cases as follows:

A[i] means the number of cases to remove cards in i th face values.
A[1] + A[2] + A[3] + ... + A[13] = N
0 <= A[i] <= 4

Because A[i] can be an integer value between 0 and 4, the number of cases for each A[i] is five and the total number of cases that the above equation can express is 5^13 (=1,220,703,125)

However, we are not interested in the exact face values and suits of cards Alex has lost. We are interested in the pairs of the remaining cards which share the same face value; how many cards with the same face values remain.
You can realize there are many cases you can deal the same in the above equation.

For example, if N = 1, you can remove a card from cards with any face value; it doesn't matter if its face value is 1 or 13.
Using the assumption, you can dramatically reduce the number of cases to try as follows:

B[i] means the number of cases that the number of cards with the same face value is i
0 <= B[i] <= 13
0 <= B[0] + B[1] + B[2] + B[3] + B[4] <= 13
S: ∑(i * B[i])
The number of the remaining cards after removing N cards (S = 52 - N)

Because B[i] can be an integer value between 0 and 13, the number of cases for each B[i] is fourteen and the total number of cases that the equation can express is 14^5 (=537,824)

So, though you try all of possible cases, you can get the answer within a second with a machine to execute 1,000,000,000 operations per second.
Eventually, solving this problem depends on how to refine the number of cases and how to try them efficiently.
You can try all of cases as follows.




*/
#include <iostream>
#include <vector>
using namespace std;
 
constexpr int inf = 123;
int count(vector<int> cards) {
    int ans = 0;
    while (true) {
        int three = 0;
        if (cards[3])
            three = 3;
        else if (cards[4])
            three = 4;
        else
            break;
 
        int two = 0;
        if (cards[2])
            two = 2;
        else if (cards[4] > 1 || (cards[4] && three != 4))
            two = 4;
        else if (cards[3] > 1 || (cards[3] && three != 3))
            two = 3;
        else
            break;
 
        --cards[three], ++cards[three-3];
        --cards[two], ++cards[two-2];
        ++ans;
    }
    return ans;
}
 
static inline int minhouse(int remove, int n, vector<int> &cards) {
    if (remove == 0)
        return count(cards);
    if (remove < 0 || n < 1)
        return inf;
    int ans = inf;
    for (int i = 0; i <= cards[4]; ++i) {
        cards[4] -= i, cards[4-n] += i;
        ans = min(ans, minhouse(remove - i * n, n - 1, cards));
        cards[4] += i, cards[4-n] -= i;
    }
    return ans;
}
 
int minhouse(int remove) {
    vector<int> cards { 0, 0, 0, 0, 13 };
    return minhouse(remove, 4, cards);
}
 
int maxhouse(int remove) {
    return min(8, (52 - remove) / 5);
}
 
int main(void) {
    int n;
    cin >> n;
    cout << minhouse(n) << ' ' << maxhouse(n) << endl;
    return 0;
}
