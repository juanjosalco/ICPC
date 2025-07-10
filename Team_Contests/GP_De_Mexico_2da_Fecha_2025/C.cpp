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
    lli t;
    cin >> t;

    while(t--){
        string str;
        cin >> str;
        lli cont = 0;
        lli cut = 0;
        fore(i,0,str.size()){

            if(str[i] == 'B' and cont <0){
                cont = 1;
                cut = i;
            }
            else if(str[i] == 'B'){
                cont++;
            }
            else{
                cont--;
            }
        }
        cout << cut<< endl;

    }
    return 0;
}