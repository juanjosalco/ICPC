#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli n;
    lli c, t1, t2;
    cin >> n >> c >> t1 >> t2;
    vi f(n);
    fore(i,0,n){
        cin >> f[i];
    }

    vi a(2 * n);
    fore(i,0,n){
        a[i] = f[i];
    }
    fore(i,0,n){
        a[i + n] = F[i] + c;
    }

    vi next1(2 * n), next2(2 * n);
    for (lli i = 0; i < 2 * n; ++i) {
        next1[i] = upper_bound(a.begin(), a.end(), a[i] + t1) - a.begin();
        next2[i] = upper_bound(a.begin(), a.end(), a[i] + t2) - a.begin();
    }

    vi dp(2 * n + 1, 0);
    lli answer = INF;

    for (lli s = 0; s < n; ++s) {
        lli end = s + n;
        dp[end] = 0;
        for (lli i = end - 1; i >= s; --i) {
            lli j1 = min(next1[i], end);
            lli j2 = min(next2[i], end);
            dp[i] = min(t1 + dp[j1], t2 + dp[j2]);
        }
        answer = min(answer, dp[s]);
    }

    cout << answer << '\n';
    return 0;
}
