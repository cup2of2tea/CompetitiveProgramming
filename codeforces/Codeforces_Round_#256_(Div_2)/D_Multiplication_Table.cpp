#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
 
 
 
 
int main()
{
 
//    ifstream in("input.txt");
//#define cin in
//    srand(time(NULL));
    long long n,m,k;
    cin>>n>>m>>k;
 
    long long gauche=0,droite=n*m+1;
    while(gauche!=droite)
    {
        long long mid = (gauche+droite)/2;
        long long dessous = 0;
        long long int found = 0;
        for(long long int c=1;c<=min(mid,n);c++)
        {
            dessous+=min(m,mid/c);
            if(mid%c==0&&mid/c<=m) found++;
        }
        if(k >= dessous-(found-1) && k <= dessous)
        {
            if(found == 0)
            {
                gauche = mid+1;
                continue;
            }
            else
            {
                cout<<mid<<endl;
                goto end ;
            }
        }
        else if(k <= dessous - found) droite = mid;
        else gauche = mid+1;
    }
    cout<<gauche<<endl;
    end:;
}