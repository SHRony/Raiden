#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
int arr[200005];
struct node{
    int l,r,val,p;
    node(){
      l = r = -1,val = 0;
    }
    node(int x){
      l = r = -1;
      val = x;
    }
};
vector<node> tre;
struct treap{
  int root;
  treap(){
    root = -1;
  }
  treap(int x){
    root = x;
  }
  pair<int,int> split(int n,int x){
    if(n == -1) return {-1,-1};
    if(tre[n].val < x ){
      auto rt = split(tre[n].r,x);
      tre[n].r = rt.first;
      return {n,rt.second};
    }
    else{
      auto rt = split(tre[n].l,x);
      tre[n].l = rt.second;
      return {rt.first,n};
    }
  }
  int merge(int x,int y){
    if(min(x,y) == - 1) return max(x,y);
    if(rand()&1){
      tre[x].r = merge(tre[x].r,y);
      return x;
    }
    else{
      tre[y].l = merge(x,tre[y].l);
      return y;
    }
  }
  int brutemerge(int l,int r){
    if(min(l,r) == -1) return max(l,r);
    if(rand()&1) swap(l,r);
    auto tmp = split(r,tre[l].val);
    tre[l].l = brutemerge(tre[l].l,tmp.first);
    tre[l].r = brutemerge(tre[l].r,tmp.second);
    return l;
  }
  void paste(int x){
    root = brutemerge(root,x);
  }
  int cut(int l,int r){
    int a,b,c;
    auto tmp = split(root,l);
    a = tmp.first;
    b = tmp.second;
    tmp = split(b,r + 1);
    b = tmp.first;
    c = tmp.second;
    root = merge(a,c);
    return b;
  }
  void insert(int x){
    const auto tmp = split(root,x);
    int l = tmp.first , r = tmp.second;
    int nw = tre.size();
    tre.push_back(node(x));
    l = merge(l,nw);
    root = merge(l,r);
  }
  void print(int n){
    if(n == -1) return ;
    print(tre[n].l);
    cout<<tre[n].val<<' ';
    print(tre[n].r);
  }
  void print(){
    print(root);
    cout<<'\n';
  }
};
void solve(){
  int n;
  cin>>n;
  treap x;
  treap y;
  x.insert(2);
  x.insert(5);
  x.insert(7);
  x.insert(8);
  y.root = x.cut(3,7);
  x.print();
  y.print();
  x.insert(4);
  x.insert(6);
  x.print();
  x.paste(y.root);
  x.print();
  
  
}
int32_t main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int t=1;
  // cin>>t;
  while(t--) solve();
    return 0;
}
