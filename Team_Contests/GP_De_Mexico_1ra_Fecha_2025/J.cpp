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

int main(){ _
    lli n;
    cin >> n;
    string st;
    cin >> st;

    vector<string> a(27);

    fore(i, 1, 27){
        string curr = "";
        fore(j,0,i){
            curr += "1";
        }
        fore(j,0,27-i){
            curr += "0";
        }
        a[i] = curr;
    }

    fore(i,0,a.size()){
        cout << a[i] << endl;
    }
    return 0;
}