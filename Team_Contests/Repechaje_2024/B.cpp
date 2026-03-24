#include <bits/stdc++.h> 

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first 
#define s second
#define pb push_back()
#define all(s) begin(s), end(s)
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}

int main(){ _
    lli n;
    cin >> n;
    vi a(n);
    fore(i,0,n){
        cin >> a[i];
    }
    lli prev = mcd(a[0], a[1]);
    set<lli> st;
    st.insert(prev);
    fore(i,1,n-1){
        prev = mcd(prev, a[i+1]);
        st.insert(prev);
    }
    if(st.size() == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}