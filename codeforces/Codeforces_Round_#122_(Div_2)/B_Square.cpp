#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
 
 
int main()
{
    int nb_cas;
    cin>>nb_cas;
    for(int c=0;c<nb_cas;c++)
    {
        long long int n;
        cin>>n;
        if((n+1)%4==0)
        {
            cout<<(n+1)<<endl;
        }
        else if((n+1)%2==0)
        {
            cout<<(n)*2+1<<endl;
        }
        else
        {
            cout<<n*4+1<<endl;
        }
    }
}