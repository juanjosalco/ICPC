#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

#define endl '\n'
#define fore(i, a, b) for (lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vi> ans;
vector<vector<char>> g;
lli n, m;

lli dfs(lli i, lli j) {
    if (ans[i][j] != -1) return ans[i][j];

    ans[i][j] = 1; // base case: only the current cell

    // 8 directions
    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

    for (int d = 0; d < 8; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m && g[ni][nj] == g[i][j] + 1) {
            ans[i][j] = max(ans[i][j], 1 + dfs(ni, nj));
        }
    }

    return ans[i][j];
}

int main() { _
    cin >> n >> m;
    ans.assign(n, vi(m, -1));
    g.assign(n, vector<char>(m));

    fore(i, 0, n) {
        fore(j, 0, m) {
            cin >> g[i][j];
        }
    }

    lli maxLen = 0;
    fore(i, 0, n) {
        fore(j, 0, m) {
            maxLen = max(maxLen, dfs(i, j));
        }
    }

    cout << maxLen << endl;

    return 0;
}
