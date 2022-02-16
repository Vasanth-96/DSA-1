#include<bits/stdc++.h>
using namespace std;
             
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
             
int main()
{
    int n;cin>>n;

    int ar[n];
    
    for(int i=0;i<n;i++)
    cin>>ar[i];

    for(int i=1;i<n;i++)
    {
        int temp=ar[i];
        int j=i-1;

        while(j>=0)
        {
            if(ar[j]>temp)
            {
                ar[j+1]=ar[j];
                ar[j]=temp;
            }
            j--;
        }
    }

    for(int i=0;i<n;i++)
    cout<<ar[i]<<" ";               
                    
                    
                    
                    
                    
                    
    return 0;
}