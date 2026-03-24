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

lli mcd(lli a, lli b){return b ? mcd(b,a%b): a;}
lli mcm(lli a, lli b){return (!a || !b) ? 0 : a * b / mcd(a,b);}

struct LazySegtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, lazy;
    Node(lli s = 0, lli lazy = 0): s(s), lazy(lazy) {}
    Node operator + (const Node &n){
      return Node(s + n.s);
    }
  };
  vector<Node> st;
  LazySegtree(int n): st(2 * n) {}
  void push(int u, int l, int r){
    if(st[u].lazy){
      if(l < r){
        st[left(u)].lazy += st[u].lazy;
        st[right(u)].lazy += st[u].lazy;
      }
      st[u].s += st[u].lazy * (r - l + 1);
      st[u].lazy = 0;
    }
  }
  void update(int u, int l, int r, int ll, int rr, lli val){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].lazy += val;
      push(u, l, r);
      return;
    }
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};

int main(){
    return 0;
}