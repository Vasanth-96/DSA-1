#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back

const int N=1e5+10;
vector<int>g[N];
bool visited[N];

bool dfs(int vertex, int par)
{

    // take action on vertex after entring the vertex;
    bool isloopexists=false;

    visited[vertex]=true;

    for(auto child: g[vertex])
    {
        
        // take action on child befor entring the child;
        if(visited[child]&&child==par)
        continue;
        if(visited[child])
        {
            return true;
        }

        isloopexists |= dfs(child,vertex);

        // take action on child after exiting the child;
    }

    // take action on vertex befor exiting the vertex;

    return isloopexists;
    
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

    bool isloopexists=false;

    for(int i=1;i<=n;i++)
    {
        if(visited[i])
        continue;
        if(dfs(i,0))
        {
            isloopexists=true;
            break;
        }
    }

    cout<<isloopexists<<"\n";

    return 0;
}