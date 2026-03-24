#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef vector<lli> vi;
typedef pair<lli,lli> ii;

#define endl '\n'
#define f first
#define s second
#define all(s) begin(s), end(s)
#define pb push_back
#define fore(i,a,b) for(lli i = a; i < (b); i++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const lli MOD = 1e9+7;
const lli INF = 1e9;
const ld EPS = 1e-9;

lli mcd(lli a, lli b){return b ? mcd(b, a%b): a;}
lli mcm(lli a, lli b){return (!b || !a) ? 0 : a * b / mcd(a,b);}

struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli xo;
    Node(lli xo = 0): xo(xo) {}
    Node operator + (const Node &n){
      return Node((xo ^ n.xo));
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].xo += val;
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};
 
int main(){ _
    lli n, m;
    cin >> n >> m;
    Segtree st(n+1);
    fore(i,0,n){
        lli num;
        cin >> num;
        st.update(0,0,n-1, i, num);
    }
    while(m--){
        char op;
        cin >> op;
        if(op == 'P'){
            lli u, v;
            cin >> u >> v;
            u--; v--;
            Segtree::Node x = st.query(0,0,n-1,u,v);
            if(x.xo == 0) cout << "JUAN" << endl;
            else cout << "FRANK" << endl;
        }else{
            lli u, v;
            cin >> u >> v;
            u--;
            st.update(0,0,n-1, u, v);
        }
    }
    return 0;
}