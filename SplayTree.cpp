/*And I thought my jokes were bad*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("Viva la vida");
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
#define nl puts("");
#define mp make_pair
#define IN(x) scanf("%d",&x);
#define INL(x) scanf("%lld",&x);
#define OUT(x) printf("%d",x);
#define OUTL(x) printf("%lld",x);
#define MAX 200005
#define MOD 1000000007
#define INF (1 << 31)
#define CASE(x,y) printf("Case %d: %d\n",++x,y);
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);
#define PI acos(-1.0)
#define EPS 1e-19
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
/*
	when i get older
	i will be stronger
	they'll call me freedom
	just like a waving flag
*/
struct vertex{
	int l,r,p,x,sz;
	vertex()
	{
		l=r=p=-1;
		x=0;
		sz=1;
	}
};
vector<vertex> tre;
int root=-1;
void rightRotate(int x)
{

	int l=tre[x].l;
	int lr=tre[l].r;
	int par=tre[x].p;
	tre[x].sz=1+tre[l].sz;
	if(~tre[x].r)
		tre[x].sz+=tre[tre[x].r].sz;
	if(~par)
	{
		if(x==tre[par].l)
			tre[par].l=l;
		else
			tre[par].r=l;
	}
	else
	{
		root=x;
	}
	tre[x].sz-=tre[l].sz;
	if(~lr)
	{
		tre[lr].p=x;
		tre[x].sz+=tre[lr].sz;
		tre[l].sz-=tre[lr].sz;
	}
	tre[x].l=lr;
	tre[l].sz+=tre[x].sz;
	tre[l].r=x;
	tre[l].p=par;
	tre[x].p=l;
}
void leftRotate(int x)
{
	int r=tre[x].r;
	int rl=tre[r].l;
	int par=tre[x].p;
	tre[x].sz=1;
	tre[x].sz+=tre[r].sz;
	if(~tre[x].l)
		tre[x].sz+=tre[tre[x].l].sz;
	if(~par)
	{
		if(tre[par].l==x)
			tre[par].l=r;
		else
			tre[par].r=r;
	}
	tre[x].sz-=tre[r].sz;
	if(~rl)
	{
		tre[rl].p=x;
		tre[x].sz+=tre[rl].sz;
		tre[r].sz-=tre[rl].sz;
	}
	tre[x].r=rl;
	tre[r].sz+=tre[x].sz;
	tre[r].p=par;
	tre[r].l=x;
	tre[x].p=r;
}
void splay(int x)
{
	assert(~x);
	while(~tre[x].p)
	{
		int p=tre[x].p;
		int pp=tre[p].p;
		if(pp==-1)
		{
			if(tre[p].l==x)
				rightRotate(p);
			else
				leftRotate(p);
			break;
		}
		if(p==tre[pp].l)
		{
			if(x==tre[p].l)
			{
				rightRotate(pp);
				rightRotate(p);
			}
			else
			{
				leftRotate(p);
				rightRotate(pp);
			}
		}
		else
		{
			if(x==tre[p].l)
			{
				rightRotate(p);
				leftRotate(pp);
			}
			else
			{
				leftRotate(pp);
				leftRotate(p);
			}
		}
	}
	// cout<<"Baal"<<endl;
	root=x;
	// CHECK(root)
}
void insert(int x)
{
	int cur=root,par;
	if(root==-1)
	{
		root=0;
		tre.emplace_back();
		tre[0].x=x;
		return ;
	}
	while(~cur)
	{
		if(tre[cur].x==x)
		{
			break;
		}
		else if(tre[cur].x>x)
		{
			if(~tre[cur].l)
			{
				cur=tre[cur].l;
			}
			else
			{
				tre[cur].l=tre.size();
				par=cur;
				cur=tre[cur].l;
				break;
			}
		}
		else
		{
			if(~tre[cur].r)
			{
				cur=tre[cur].r;
			}
			else
			{
				tre[cur].r=tre.size();
				par=cur;
				cur=tre[cur].r;
				break;
			}
		}
	}
		if(cur==tre.size())
		{
			tre.emplace_back();
			tre[cur].x=x;
			tre[cur].p=par;
		}
		splay(cur);


}

int find(int x)
{
	if(root==-1) return -1;
	int cur=root;
	while(1)
	{
		if(tre[cur].x==x)
		{
			splay(cur);
			return cur;
		}
		else if(tre[cur].x>x)
		{
			if(~tre[cur].l)
			{
				cur=tre[cur].l;
			}
			else
			{
				splay(cur);
				return -1;
			}
		}
		else
		{
			if(~tre[cur].r)
			{
				cur=tre[cur].r;
			}
			else
			{
				splay(cur);
				return -1;
			}
		}
	}
	return -1;
}
void dfs(int x)
{
	if(x==-1)
	{
		return;
	}
	cout<<x<<' '<<tre[x].l<<' '<<tre[x].r<<' '<<tre[x].x<<' '<<tre[x].sz<<endl;
	dfs(tre[x].l);
	dfs(tre[x].r);
}
void solve()
{
	int i,j,k,l,r,m,n,a,b,c,d,x,y,z,t;
	cin>>n;
}
int32_t main()
{
	FASTIO
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}