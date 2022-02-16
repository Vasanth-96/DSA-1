#include<bits/stdc++.h>
using namespace std;
             
#define ll long long
#define pb push_back

int bin(int a,int b)
{
    if(b==0)
    return 1;

    int val=bin(a,b/2);

    if(b%2==0)
    return val*val;
    else
    return a*val*val;

}
             
int main()
{
 
 
 
 
 
 
 
return 0;
}