#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> longueur(n);
    for(int c=0;c<n;c++) cin>>longueur[c];
    int best = 10000000000;
    for(int c=0;c<n;c++)
    {
        int tot = 0;
        for(int c2=0;c2<longueur[c];c2++)
        {
            int z;
            cin>>z;
            tot+=z*5+15;
        }
        best = min(best,tot);
    }
    cout<<best;
}
 