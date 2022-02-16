#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
const int N=1e5+10;
vector<int>g[N];
int depth[N];

void dfs(int vertex,int par=-1)
{
    for(int child:g[vertex])
    {
        if(child==par)
        continue;

        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
    }
}
             
int main()
{ 
    int n;cin>>n;  
    int mx_length=-1;
    int mx_l_node;

    for(int i=0;i<n;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // take any node as root node, then find the max depth and also find the node()

    dfs(1); 

    for(int i=0;i<=n;i++)
    {
        if(mx_length<depth[i])
        {
            mx_length=depth[i];
            mx_l_node=i;
        }
        depth[i]=0;
    }              
    // now take the node(which has max depth for root node), and find the max depth.

    dfs(mx_l_node);
    mx_length=-1;

    for(int i=0;i<=n;i++)
    {
        if(mx_length<depth[i])
        {
            mx_length=depth[i];
            mx_l_node=i;
        }
        
    }
    // And this is your diameter of tree.
    cout<<mx_length<<"\n";
            
                    
    return 0;
}