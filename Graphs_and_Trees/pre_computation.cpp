#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back

const int N=1e5+10;
vector<int>g[N];
int subtree_sum[N];
int even_ct[N];

void dfs(int vertex,int par)
{
    // The 1 and 2 points are generally used when we try go to down side in graphs/trees. 

    //1. take action on vertex after entring the vertex;

    if(vertex%2==0)
    {
        even_ct[vertex]++;
    }
    subtree_sum[vertex]+=vertex;
    for(auto child: g[vertex])
    {
        //2. take action on child befor entring the child;

        if(child == par)
        continue;

        dfs(child,vertex);

        subtree_sum[vertex]+=subtree_sum[child];
        even_ct[vertex]+=even_ct[child];

        // The  3 and 4 points are generally used when we try to go to up side in graphs/trees.

        //3. take action on child after exiting the child;

    
    }

    //4. take action on vertex befor exiting the vertex;

    return ;
}
             
int main()
{

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1,0);

    int q;cin>>q;
    while(q--)
    {
        int v;cin>>v;
        cout<<subtree_sum[v]<<" "<<even_ct[v]<<"\n";

    }

    return 0;
}