#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    long long int n,a,b;
    cin>>n>>a>>b;
    for(int c=0;c<n;c++)
    {
        int z;
        cin>>z;
        long long int gauche = 0,droite = z;
        long long int paie = (z*a)/b;
        while(gauche!=droite)
        {
            long long int mid = (gauche+droite)/2;
            if((mid*a)/b<paie)
            {
                gauche=mid+1;
            }
            else
            {
                droite=mid;
            }
        }
        cout<<z-droite<<" ";
    }
}