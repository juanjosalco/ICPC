#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef long double ld;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){ _
    string w;
    cin >> w;
    string x = "TAP";
    lli i = 0, j = 0;
    while(j < w.size()){
        if(w[j] == x[i]){
            i++;
            if(i == 3){
                cout << "S" << endl;
                return 0;
            }
        }
        j++;
    }
    cout << "N" << endl;
    return 0;
}