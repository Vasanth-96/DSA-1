#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back

vector<int>v;

void merge(int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    vector<int>left(n1),right(n2);

    for(int i=0;i<n1;i++)
    left[i]=v[i+l];

    for(int i=0;i<n2;i++)
    right[i]=v[i+m+1];

    int i=0,j=0,index=l;

    while (1)
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
        while(j<n2)
        {
            v[index]=right[j];
            j++;
            index++;
        }
    }

    else if(j==n2)
    {
        while(i<n1)
        {
            v[index]=left[i];
            i++;
            index++;
        }
    }
    
    return;
}


void mergeSort(int l,int r)
{
    if(l>=r)
    return;

    int m=(l+r)/2;

    mergeSort(l,m);
    mergeSort(m+1,r);
    merge(l,m,r);
}
             
int main()
{ 
    int n;cin>>n;
    

    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        v.push_back(a);
    }

    mergeSort(0,n-1); 

    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";                 
                    
              
                    
    return 0;
}