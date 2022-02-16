#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back

const int N=1e5+10;
vector<int>g[N];
int depth[N],height[N];


void dfs(int vertex,int par)
{
    // The 1 and 2 points are generally used when we try go to down side in graphs/trees. 

    //1. take action on vertex after entring the vertex;


    for(auto child: g[vertex])
    {
        //2. take action on child befor entring the child;

        if(child == par)
        continue;

        depth[child]=depth[vertex]+1;

        dfs(child,vertex);

        // The  3 and 4 points are generally used when we try to go to up side in graphs/trees.

        //3. take action on child after exiting the child;

        height[vertex]=max(height[vertex],height[child]+1);

    
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

    dfs(g[0][0],0);

    return 0;
}