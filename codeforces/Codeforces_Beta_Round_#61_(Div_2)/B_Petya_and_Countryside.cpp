#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int nb;
    cin>>nb;
    int prec=1000000;
    vector<int> garden;
    garden.resize(nb);
    for(int c=0;c<nb;c++)
        cin>>garden[c];
    int c2,c3;
    int max_ecart=-1;
    for(int c=0;c<nb;c++)
    {
        for(c2=c-1;c2>=0;c2--)
            if(c2+1<nb&&garden[c2]>garden[c2+1])
                break;
        for(c3=c+1;c3<nb;c3++)
            if(c3-1>=0&&garden[c3]>garden[c3-1])
                break;
        if(max_ecart<c3-c2-2)
        {
            max_ecart=c3-c2-2;
        }
    }
    cout<<max_ecart+1<<endl;
}