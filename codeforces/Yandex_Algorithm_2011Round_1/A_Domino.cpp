#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    for(int c=0;c<4;c++)
    {
        if(c<2) cout<<'a';
        for(int c2=0;c2<(n-(c<2?1:0))/2;c2++) 
            cout<<(char)('a'+(c+c2)%24+1)<<(char)('a'+(c+c2)%24+1);
        if((n-(c<2?1:0))%2)
            cout<<"z";
        cout<<endl;
    }
}