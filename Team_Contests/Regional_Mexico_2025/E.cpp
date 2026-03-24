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

const lli INF = 1e10;

struct LazySegtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))

  struct Node{
    lli s, lazy, mn;
    Node(lli s = 0, lli mn = INF, lli lazy = 0): s(s), lazy(lazy), mn(mn) {}

    Node operator + (const Node &n){
      return Node(s + n.s, min(mn, n.mn));
    }
  };

  vector<Node> st;
  int n;

  LazySegtree(int n): st(2 * n), n(n) {}

  void build(int u, int l, int r, const vector<lli>& a){
    if(l == r){
      st[u].s = a[l];
      st[u].mn = a[l];
      st[u].lazy = 0;
      return;
    }
    build(left(u), l, mid, a);
    build(right(u), mid + 1, r, a);
    st[u] = st[left(u)] + st[right(u)];
    st[u].lazy = 0;
  }

  void push(int u, int l, int r){
    if(st[u].lazy){
      if(l < r){
        st[left(u)].lazy += st[u].lazy;
        st[right(u)].lazy += st[u].lazy;
      }
      st[u].s += st[u].lazy * (r - l + 1);
      st[u].mn += st[u].lazy;
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

int main(){ _
    lli n;
    cin >> n;

    vi vals(n);
    vi querys(n);

    fore(i,0,n){
        cin >> querys[i];
        vals[i] = abs(querys[i]);
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    int m = vals.size();

    vi base(m + 1);
    base[0] = 0;
    fore(i,0,m){
        base[i+1] = vals[i];
    }

    LazySegtree st(m+1);
    st.build(1, 0, m, base);         

    fore(i,0,n){
        lli pos = lower_bound(all(vals), abs(querys[i])) - vals.begin();

        if (querys[i] > 0) {
            st.update(1, 0, m, 0, pos, +1);
        } else {
            st.update(1, 0, m, 0, pos, -1);
        }

       cout << st.query(1,0,m,0,m).mn << " ";
    }
    return 0;
}
