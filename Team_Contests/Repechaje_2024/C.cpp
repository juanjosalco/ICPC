#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static vector<int> sieve(int n) {
    vector<bool> is(n + 1, true);
    is[0] = is[1] = false;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (is[i]) {
            for (int j = i * i; j <= n; j += i) is[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i) if (is[i]) primes.push_back(i);
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> a(N);
    int mx = 0;
    ll G = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        G = std::gcd(G, (ll)a[i]);
    }

    // Trivial: with N == 2 it’s always YES, but the generic check handles it too.

    int LIM = (int)floor(sqrt(mx)) + 1;
    vector<int> primes = sieve(LIM);

    unordered_set<int> used;  // primes seen across different b_i
    used.reserve(1 << 15);

    for (int i = 0; i < N; ++i) {
        ll x = a[i] / G;
        if (x == 1) continue; // no primes here

        for (int p : primes) {
            if (1LL * p * p > x) break;
            if (x % p == 0) {
                if (used.count(p)) {
                    cout << "NO\n";
                    return 0;
                }
                used.insert(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) { // leftover prime factor > sqrt
            int p = (int)x;
            if (used.count(p)) {
                cout << "NO\n";
                return 0;
            }
            used.insert(p);
        }
    }

    cout << "YES\n";
    return 0;
}
