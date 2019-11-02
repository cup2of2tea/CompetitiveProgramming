#include <iostream>
 
using namespace std;
 
 
int main()
{
    int nb100 = 0, nb200 = 0;
    int n;
    cin>>n;
    for(int c=0;c<n;c++)
    {
        int a;
        cin>>a;
        if(a==100) nb100++;
        else nb200++;
    }
    for(int c=0;c<=nb100;c++) for(int c2=0;c2<=nb200;c2++)
        if(c+c2*2 == nb100-c + 2*(nb200-c2))
        {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
}
    