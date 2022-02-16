#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back

void merge(vector<int>v,int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;
    vector<int>left(n1);
    vector<int>right(n2);

    for(int i=0;i<n1;i++)
    left[i]=v[i+l];

    for(int i=0;i<n2;i++)
    right[i]=v[i+m+1];

    int i=0;
    int j=0;
    int index=l;

    while(1)
    {
        if(i==n1||j==n2)
        break;
        if(left[i]<right[j])
        {
            v[index]=left[i];
            i++;
            index++;
        }
        else
        {
            v[index]=right[j];
            j++;
            index++;
        }
    }

    if(i==n1)
    {
        while(j<=n2)
        {
            v[index]=right[j];
            j++;
            index++;
        }
    }
    else if(j==n2)
    {
         while(i<=n1)
        {
            v[index]=right[i];
            i++;
            index++;
        }
    }
}



void merge_sort(vector<int>v,int l,int r)
{
    if(l>=r)
    return;

    int m=(l+r)/2;

    merge_sort(v,l,m);
    merge_sort(v,m+1,r);
    merge(v,l,m,r);
    
}
             
int main()
{ 

    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++)
    cin>>v[i];

    merge_sort(v,0,n-1);  

    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";                
                 
    return 0;
}