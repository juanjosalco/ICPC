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
    lli n,m;
    cin >>n>>m;
    vi scores(n + 1,0);

    fore(i,0,m){

        lli x,y;
        cin>>x>>y;

        lli cont1 = 0;
        vi play(n);

        fore(i,0,n){
            lli num;
            cin >>num;
            if(num == 1)cont1++;
            play[i] = num;
        }
        if(x/(cont1+1)  >= y){
            cont1++;
            scores[n] += x/(cont1);
        }
        else{
            //cout<<"here"<<endl;
            scores[n] += y;
        }
        fore(i,0,n){
            if(play[i] == 1) scores[i]+=x/(cont1);
            else scores[i] += y;
        }

    }

    fore(i,0,n+1) cout <<scores[i] << " ";

}