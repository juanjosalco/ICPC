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

const lli INF = 1e9;

int main(){ _
    string num;
    cin >> num;
    lli ans = 0;
    fore(i,0,num.size()){
        ans += num[i]-'0';
    }
    cout << ans % 3 << endl;
    return 0;
}