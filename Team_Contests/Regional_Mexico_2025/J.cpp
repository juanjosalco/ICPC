#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef long double ld;
typedef pair<lli,lli> ii;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string s;

lli isIn(string st){
    lli ans = 0;
    fore(i,0,s.size()){
        if(s.substr(i, st.size()) == st){
            ans++;
        }
    }
    return ans;
}

int main(){ _
    cin >> s;
    lli x = isIn("ha");
    lli y = isIn("boooo");
    lli z = isIn("bravo");
    cout << (z*3)+x-y << endl;
    return 0;
}
