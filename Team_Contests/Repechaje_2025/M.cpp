#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    int64 K;
    if (!(cin >> N >> K)) return 0;
    vector<int64> x(N+1);
    int64 mn = (int64)4e18, mx = - (int64)4e18;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
        mn = min(mn, x[i]);
        mx = max(mx, x[i]);
    }

    auto feasible = [&](int64 H) -> bool {
        // If all >= H, it's already OK
        int R = -1;                 // rightmost bad index
        int64 U = (int64)4e18;      // j must be <= U
        bool anyBad = false;
        for (int i = 1; i <= N; ++i) {
            if (x[i] < H) {
                anyBad = true;
                R = max(R, i);
                // j <= i + (K - (H - x[i])) = i + K + x[i] - H
                U = min(U, (int64)i + K + x[i] - H);
            }
        }
        if (!anyBad) return true;
        return (int64)R <= U;
    };

    int64 lo = mn, hi = mx + K; // answer lies here
    while (lo < hi) {
        int64 mid = lo + (hi - lo + 1) / 2;
        if (feasible(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
    return 0;
}
