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

struct linearSieve {
    vector<int> spf;                 
    explicit linearSieve(int n) {
        spf.resize(n + 1);
        iota(all(spf), 0);
        for (int i = 2; 1LL * i * i <= n; ++i)
            if (spf[i] == i)                       
                for (int j = i * i; j <= n; j += i)
                    if (spf[j] == j) spf[j] = i;
    }

    vector<int> primes(int x) const {
        vector<int> res;
        while (x > 1) {
            int p = spf[x];
            res.pb(p);
            while (x % p == 0) x /= p;
        }
        return res;
    }
};


int main() { _
    int n, m;                      
    if (!(cin >> n >> m)) return 0;

    linearSieve spf(n);               

    vector<int> owner(n + 1, 0);    
    vector<char> on(n + 1, 0);     

    while (m--) {
        char op; int x;
        cin >> op >> x;

        if (op == '+') {
            if (on[x]) {                          
                cout << "Already on" << endl;
                continue;
            }

            int conflict = 0;
            for (int p : spf.primes(x))
                if (owner[p]) { conflict = owner[p]; break; }

            if (conflict) {
                cout << "Conflict with " << conflict << endl;
            } else {
                on[x] = 1;
                for (int p : spf.primes(x)) owner[p] = x;
                cout << "Success\n";
            }
        }
        else { 
            if (!on[x]) {
                cout << "Already off\n";
                continue;
            }
            on[x] = 0;
            for (int p : spf.primes(x))
                if (owner[p] == x) owner[p] = 0;
            cout << "Success\n";
        }
    }
    return 0;
}
