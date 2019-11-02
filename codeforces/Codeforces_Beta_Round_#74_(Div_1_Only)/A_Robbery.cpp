#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
 
using namespace std;
 
int main()
{
    long long int n,m,k;
    cin>>n>>m>>k;
    long long int mini=10000000;
    if(n%2==0)
    {
        cout<<0;
        return 0;
    }
    for(int c=0;c<n;c++)
    {
        long long int z;
        cin>>z;
        if(c%2==0) mini = min(mini,z);
    }
    long long int nbByMin = m/((n+1)/2);
    long long int tot = min(mini,nbByMin*k);
    cout<<tot;
}