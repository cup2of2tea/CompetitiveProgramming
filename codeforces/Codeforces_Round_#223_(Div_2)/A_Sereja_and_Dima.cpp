#include <iostream>
 
using namespace std;
 
 
int main()
{
    int tab[1001];
    int n;
    cin>>n;
    for(int c=0;c<n;c++) cin>>tab[c];
    int g = 0, d= n-1;
    int sum[2]={0,0};
    for(int c=0;c<n;c++)
    {
        if(tab[d]>tab[g])
        {
            sum[c%2]+=tab[d--];
        }
        else sum[c%2]+=tab[g++];
    }
    cout<<sum[0]<<" "<<sum[1];
}