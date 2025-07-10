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

lli binPow(lli a, lli b){
    lli res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

lli binPowMod(lli a, lli b, lli m){
    a %= m;
    lli res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Fibonnacci Problem: Matrix Exponientiation

struct Matrix {
    lli m[2][2];

    Matrix operator*(const Matrix& other) const {
        Matrix result = {0};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.m[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                    // If needed with MOD: result.m[i][j] %= MOD;
                }
            }
        }
        return result;
    }
};

Matrix matrix_power(Matrix base, lli exponent)  {
    Matrix result = {{{1, 0}, {0, 1}}};

    while (exponent > 0) {
        if (exponent & 1) {
            result = result * base;
        }
        base = base * base;
        exponent >>= 1;
    }

    return result;
}

lli fibonacci(lli n) {
    if (n == 0) return 0;
    Matrix base = {{{1, 1}, {1, 0}}};
    Matrix result = matrix_power(base, n - 1);
    return result.m[0][0];
}

int main(){ _
    lli n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}