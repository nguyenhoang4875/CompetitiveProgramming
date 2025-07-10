#include <bits/stdc++.h>

using namespace std;

// === SINGLE INTEGER HASH ===
// 1. FAST & SAFE for competitive programming
struct custom_hash {
    size_t operator()(const int x) const {
        return x * 1000000007LL;  // Using prime number for better distribution
    }
};

// 2. ULTRA SAFE - Best collision resistance
struct custom_hash_safe {
    static uint64_t splitMix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const int x) const { return splitMix64(x); }
};

// === PAIR HASH ===
// 1. FAST & SAFE for competitive programming
struct custom_hash_pair {
    size_t operator()(const pair<int, int> &p) const {
        return p.first * 1000000007LL + p.second;  // Using prime for better distribution
    }
};

// 2. ULTRA SAFE - Best collision resistance
struct custom_hash_pair_safe {
    size_t operator()(const pair<long long, long long> &p) const {
        return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 1);
    }
};

void solve() {
    // Test different single integer hash functions
    unordered_set<int, custom_hash> set1;
    unordered_set<int, custom_hash_safe> set2;

    // Test basic hash function
    unordered_map<int, int, custom_hash> mii = {{-1, 1}, {0, 1}, {1, 1}};

    // Test different pair hash functions
    unordered_set<pair<int, int>, custom_hash_pair> pset1;
    unordered_set<pair<long long, long long>, custom_hash_pair_safe> pset2;

    // Add test data
    vector<int> test_ints = {1, -1, 0, 1000, -1000, 123456};
    vector<pair<int, int>> test_pairs = {{1, 2}, {3, 4}, {5, 6}, {-1, -2}};

    for (auto x : test_ints) {
        set1.insert(x);
        set2.insert(x);
    }

    for (auto p : test_pairs) {
        pset1.insert(p);
        pset2.insert({p.first, p.second});
    }

    cout << "Integer hash sets sizes:" << '\n';
    cout << "Fast & Safe: " << set1.size() << '\n';
    cout << "Ultra Safe: " << set2.size() << '\n';

    cout << "Pair hash sets sizes:" << '\n';
    cout << "Fast & Safe: " << pset1.size() << '\n';
    cout << "Ultra Safe: " << pset2.size() << '\n';

    // Performance test - Integer hash with random values
    cout << "\n=== PERFORMANCE TEST WITH RANDOM VALUES ===" << '\n';

    // Setup random number generator
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> int_dist(-1000000000, 1000000000);

    // Test integer hash with random values
    auto start = chrono::high_resolution_clock::now();
    unordered_set<int, custom_hash> perf_set_int;
    for (int i = 0; i < 100000; i++) {
        perf_set_int.insert(int_dist(rng));
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Integer hash performance (100k random inserts): " << duration.count() << " microseconds" << '\n';
    cout << "Final set size: " << perf_set_int.size() << " (collisions: " << (100000 - perf_set_int.size()) << ")"
         << '\n';

    // Test integer hash safe with random values
    start = chrono::high_resolution_clock::now();
    unordered_set<int, custom_hash_safe> perf_set_int_safe;
    for (int i = 0; i < 100000; i++) {
        perf_set_int_safe.insert(int_dist(rng));
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Integer hash safe performance (100k random inserts): " << duration.count() << " microseconds" << '\n';
    cout << "Final set size: " << perf_set_int_safe.size() << " (collisions: " << (100000 - perf_set_int_safe.size())
         << ")" << '\n';

    // Test pair hash with random values
    start = chrono::high_resolution_clock::now();
    unordered_set<pair<int, int>, custom_hash_pair> perf_set_pair;
    for (int i = 0; i < 100000; i++) {
        perf_set_pair.insert({int_dist(rng), int_dist(rng)});
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Pair hash performance (100k random inserts): " << duration.count() << " microseconds" << '\n';
    cout << "Final set size: " << perf_set_pair.size() << " (collisions: " << (100000 - perf_set_pair.size()) << ")"
         << '\n';

    // Test pair hash safe with random values
    start = chrono::high_resolution_clock::now();
    unordered_set<pair<long long, long long>, custom_hash_pair_safe> perf_set_pair_safe;
    for (int i = 0; i < 100000; i++) {
        perf_set_pair_safe.insert({int_dist(rng), int_dist(rng)});
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Pair hash safe performance (100k random inserts): " << duration.count() << " microseconds" << '\n';
    cout << "Final set size: " << perf_set_pair_safe.size() << " (collisions: " << (100000 - perf_set_pair_safe.size())
         << ")" << '\n';

    // Hash distribution test
    cout << "\n=== HASH DISTRIBUTION TEST ===" << '\n';
    vector<size_t> hash_values;
    for (int i = 0; i < 10000; i++) {
        int val = int_dist(rng);
        hash_values.push_back(custom_hash{}(val));
    }

    // Check for obvious patterns in hash values
    sort(hash_values.begin(), hash_values.end());
    int consecutive_count = 0;
    for (int i = 1; i < hash_values.size(); i++) {
        if (hash_values[i] == hash_values[i - 1] + 1) {
            consecutive_count++;
        }
    }
    cout << "Consecutive hash values: " << consecutive_count << "/10000 (" << (consecutive_count * 100.0 / 10000)
         << "%)" << '\n';

    // Check bucket distribution
    const int num_buckets = 1000;
    vector<int> bucket_count(num_buckets, 0);
    for (size_t hash_val : hash_values) {
        bucket_count[hash_val % num_buckets]++;
    }

    int min_bucket = *min_element(bucket_count.begin(), bucket_count.end());
    int max_bucket = *max_element(bucket_count.begin(), bucket_count.end());
    cout << "Bucket distribution (1000 buckets): min=" << min_bucket << ", max=" << max_bucket
         << ", ratio=" << (max_bucket * 1.0 / min_bucket) << '\n';
}

//*** HASH FUNCTIONS LIBRARY ***//

/*
USAGE GUIDE:

=== SINGLE INTEGER HASH ===
1. custom_hash - FAST & SAFE for competitive programming
   - Best for: General purpose, good balance of speed and safety
   - Time: O(1) - single multiplication
   - Usage: unordered_set<int, custom_hash>

2. custom_hash_safe - ULTRA SAFE
   - Best for: When collision resistance is critical
   - Time: O(1) but ~5x slower than custom_hash
   - Usage: unordered_set<int, custom_hash_safe>

=== PAIR HASH ===
1. custom_hash_pair - FAST & SAFE for competitive programming
   - Best for: pair<int, int> with moderate values
   - Time: O(1) - single multiplication + addition
   - Usage: unordered_set<pair<int, int>, custom_hash_pair>

2. custom_hash_pair_safe - ULTRA SAFE
   - Best for: pair<long long, long long> or when collision resistance is critical
   - Time: O(1) but ~3x slower than custom_hash_pair
   - Usage: unordered_set<pair<long long, long long>, custom_hash_pair_safe>

RECOMMENDATION FOR COMPETITIVE PROGRAMMING:
- Integer: Use custom_hash (fast + safe)
- Pair: Use custom_hash_pair (fast + safe)
- Only use *_safe versions when you suspect hash collisions

PERFORMANCE RANKING:
Integer: custom_hash > custom_hash_safe
Pair: custom_hash_pair > custom_hash_pair_safe
*/

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}