#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli mcd(lli a, lli b){return b ? mcd(b, a % b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

const lli INF = 1e9;
const lli MOD = 1e9+7;
const ld EPS = 1e-9;

struct matrix {
    lli mat[2][2];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (lli i = 0; i < 2; i++) {
          for (lli j = 0; j < 2; j++) {
              c.mat[i][j] = 0;
              for (lli k = 0; k < 2; k++) {
                  c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD;
              }
          }
        }
        return c;
    }
};

matrix matpow(matrix base, lli n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } };
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}

long long fib(lli n) {
    matrix base{ {
      {1, 1},
      {1, 0}
    } };
    return matpow(base, n).mat[0][1] % MOD;
}

int main() { _
    lli n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}