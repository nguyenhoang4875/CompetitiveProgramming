#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<pair<int, int>> participants(N);

    // Read input values
    for (int i = 0; i < N; ++i) {
        cin >> participants[i].first >> participants[i].second;
    }

    // Sort participants based on their starting points
    sort(participants.begin(), participants.end());

    // Calculate the number of groups
    int groups = 1;  // The first participant starts a new group
    int lastEndpoint = participants[0].first + T * participants[0].second;

    for (int i = 1; i < N; ++i) {
        // Calculate the endpoint for the current participant
        int currentEndpoint = participants[i].first + T * participants[i].second;

        // Check if the current participant is still part of the same group
        if (currentEndpoint <= lastEndpoint) {
            continue;  // Still part of the same group
        } else {
            groups++;  // Start a new group
            lastEndpoint = currentEndpoint;
        }
    }

    cout << groups << endl;

    return 0;
}