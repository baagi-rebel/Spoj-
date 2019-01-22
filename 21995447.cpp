/*
Author :: Shourov Chowdhury
............SUST_MATH14..........
*/
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>

#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define II() ( { int a ; read(a) ; a; } )
#define LL() ( { Long a ; read(a) ; a; } )
#define DD() ({double a; scanf("%lf", &a); a;})
#define DB if(0) 
#define D(x) cout << #x " is " << x << endl
#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

using namespace std;

typedef long long Long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<string> VS;

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; 
    x*=sgn; return ~c;
}

const int INF = 2000000009;
const int MX = 100005;
const double EPS = 1e-9;
const int MOD = 1000000007;

/**********************Code starts here*********************************/
struct Edge
{
    int u,v;
    Edge(){}
    Edge(int u,int v):u(u),v(v){}
};
Edge edg[MX];
vector<int> g[MX];
int in[MX],sub[MX],sol[MX];
int tin,tdeg;
int dsu[MX],sz[MX];

int findParent(int x){
    return x==dsu[x]? x : dsu[x] = findParent(dsu[x]);
}
bool Union(int a,int b){
    a = findParent(a);
    b = findParent(b);
    if (a==b) return false;
    if (sz[b]>sz[a]) swap(a,b);
    dsu[b] = a;
    sz[a]+=sz[b];
    return true;
}


void init()
{
    for (int i = 0;i<MX;i++){
        g[i].clear();
        dsu[i] = i;
        sz[i] = 1;
    }
    memset(sol,0,sizeof(sol));
    memset(in,0,sizeof(in));
}

void dfs(int u,int p = -1){
    sub[u] = in[u];
    for (int i : g[u]){
        int v = edg[i].u^edg[i].v^u;
        if (v==p) continue;
        dfs(v,u);
        sub[u]+=sub[v]+1;
    }
}
void dfs1(int u,int p = -1){
    for (int i : g[u]){
        int v = edg[i].u^edg[i].v^u;
        if (v==p) continue;
        if (sub[v]%2){
            if (u!=edg[i].u) sol[i] = 1;
        }
        else{
            if (u==edg[i].u) sol[i] = 1;
        }
        dfs1(v,u);
    }
}


int main()
{
    //std::ios_base::sync_with_stdio(false);

    int tc = II();
    while (tc--)
    {
        init();
        int n = II(),m=II();
        for (int i = 0;i<m;i++){
            int u,v;
            edg[i].u= u = II(),edg[i].v = v = II();
        }
        if (m%2){
            printf("-1\n");
            continue;
        }
        for (int i = m-1;i>=0;i--){
            int u = edg[i].u,v=edg[i].v;
            if (Union(u,v)){
                g[u].push_back(i);
                g[v].push_back(i);
            }
            else{
                in[v]++;
            }
        }
        dfs(1);
        dfs1(1);
        for (int i = 0;i<m;i++){
            printf("%d ",sol[i] );
        }
        printf("\n");
    }
    return 0;
}