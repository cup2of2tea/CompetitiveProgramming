#include <iostream>
 
using namespace std;
 
int abs(int n)
{
    return n<0?-n:n;
}
 
int main()
{
    long long unsigned int a, b;
    int joueur=1;
    cin>>a>>b;
    while ((a*10+b>=22) && (b>= 2))
    {
            if (joueur==1||(b<12))
            {
                    a-=2;
                    b-=2;
            }
            else if (b < 22)
            {
                    a--;
                    b-=12;
            }
            else
                    b-=22;
            joueur=abs(joueur-1);
    }
    cout << (joueur==1?"Hanako":"Ciel");
}