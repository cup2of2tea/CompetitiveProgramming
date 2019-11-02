#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
 
using namespace std;
 
string tableau[5]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
 
int main()
{
    long long unsigned int nb;
    cin>>nb;
    long long unsigned int tab2[5]={1,1,1,1,1};
    long long unsigned int c,c2=0;
    for(c=0;c<nb-1;c+=tab2[c2%5])
    {
        tab2[c2%5]*=2;
        c2++;
    }
    cout<<tableau[c2%5];
}