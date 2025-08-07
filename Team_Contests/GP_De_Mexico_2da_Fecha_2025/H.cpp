#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Ledge {
    ll x, y;          
    bool rod;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll h, k;
    cin >> N >> h >> k;

    vector<Ledge> ledges(N);
    vector<int> rodIdx; rodIdx.reserve(N);

    for (int i = 0; i < N; ++i) {
        ll x, y; int z;
        cin >> x >> y >> z;
        ledges[i] = {x, y, z == 1};
        if (z) rodIdx.push_back(i);
    }

    ll a, b;
    cin >> a >> b;

    int start = -1;
    for (int i = 0; i < N; ++i)
        if (ledges[i].x == a && ledges[i].y == b) { start = i; break; }

    if (start == -1) { cout << -1 << '\n'; return 0; }   // sanity

    /* If already at surface */
    if (ledges[start].y == 0) { cout << 0 << '\n'; return 0; }

    const ll k2 = k * k;
    const ll h2 = h * h;

    vector<int> dist(N, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    auto sqDist = [&](int i, int j) -> ll {
        ll dx = ledges[i].x - ledges[j].x;
        ll dy = ledges[i].y - ledges[j].y;
        return dx * dx + dy * dy;
    };

    while (!q.empty()) {
        int u = q.front(); q.pop();
        int d = dist[u];

        /* push directly to surface? */
        if (ledges[u].rod && -ledges[u].y <= h) {
            cout << d + 1 << '\n';
            return 0;
        }

        /* pulls: towards every rod ledge */
        for (int v : rodIdx) if (dist[v] == -1) {
            if (sqDist(u, v) <= k2) {
                dist[v] = d + 1;
                q.push(v);
            }
        }

        /* pushes: only if current ledge has a rod */
        if (ledges[u].rod) {
            for (int v = 0; v < N; ++v) if (dist[v] == -1) {
                if (sqDist(u, v) <= h2) {
                    dist[v] = d + 1;
                    q.push(v);
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
