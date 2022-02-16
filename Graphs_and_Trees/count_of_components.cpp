#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back

const int N=1e5+10;
vector<int>g[N];
bool visited[N];

void dfs(int vertex)
{
    // take action on vertex after entring the vertex;

    visited[vertex]=true;

    cout<<"vertex\n";

    for(auto child: g[vertex])
    {

        cout<<" parent "<<vertex<<" , child  "<<child<<"\n";
        // take action on child befor entring the child;
        if(visited[child])
        continue;

        dfs(child);

        // take action on child after exiting the child;
    }

    // take action on vertex befor exiting the vertex;

    return ;
}
             
int main()
{

    int n,m;
    int count=0;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i])
        continue;
        count++;
        dfs(i);
    }

    cout<<count<<"\n";

    

    return 0;
}