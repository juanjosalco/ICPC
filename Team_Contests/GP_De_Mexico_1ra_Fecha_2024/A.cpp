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
#define fore(i,a,b) for(lli i = a, TT=b; i < TT; i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() { _
    lli t;
    cin >> t;
    while (t--) {
        lli n; 
        cin >> n;
        if (n & (n - 1)) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        vector<lli> A, B;
        A.push_back(1); B.push_back(2);         
        lli cur = 1;
        while ((lli)A.size() < n) {
            lli t = 2 * cur;               
            vector<lli> nA = A, nB = B;
            for (auto x : B) nA.push_back(x + t); 
            for (auto x : A) nB.push_back(x + t);
            A.swap(nA); B.swap(nB);
            cur <<= 1;
        }
        for (auto x : A) cout << x << ' ';
        cout << endl;
        for (auto x : B) cout << x << ' ';
        cout << endl;
    }
    return 0;
}
