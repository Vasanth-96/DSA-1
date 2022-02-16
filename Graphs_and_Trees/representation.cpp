#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back

const int N=1e3+10;

int graph1[N][N];

vector<pair<int,int>> graph2[N];
             
int main()
{
    int n,m;
    // n is number of nodes , m is number of edges
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph1[v1][v2]=wt;
        graph1[v2][v1]=wt;

        graph2[v1].push_back({v2,wt});
        graph2[v2].push_back({v1,wt});
    }    
                    
    // space complexcity of graph1 is O(N^2);
    // space complexcity of graph2 is O(N+M);                
                    
                    
                    
                    
                    
    return 0;
}