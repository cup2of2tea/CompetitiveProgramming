#include <iostream>
 
using namespace std;
 
int pgcd(int a,int b)
{
    return a==0?b:pgcd(b%a,a);
}
 
 
int main()
{
    int N;
    cin>>N;
    int z;
    cin>>z;
    for(int c=1;c<N;c++)
    {
        int bla;
        cin>>bla;
        z = pgcd(z,bla);
    }
    cout<<z*N;
}