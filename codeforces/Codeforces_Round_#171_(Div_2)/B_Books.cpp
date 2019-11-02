#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
 
 
int main()
{
    int nb_books,time;
    cin>>nb_books>>time;
    vector<int> v(nb_books);
    for(int c=0;c<nb_books;c++)
    {
        cin>>v[c];
        if(c>0)
            v[c]+=v[c-1];
    }
    int maxi=0;
    for(int c=0;c<nb_books;c++)
    {
        int gauche=c,droite=nb_books-1;
        int temp=(c>0?v[c-1]:0);
        while(droite-gauche>1)
        {
            int mid=droite+gauche;
            mid/=2;
            if(v[mid]-temp==time)
            {
                gauche=droite=mid;
            }
            if(v[mid]-temp>time)
            {
                droite=mid;
            }
            else gauche=mid;
        }
        for(int c2=droite;c2>=gauche;c2--)
        {
            if(v[c2]-temp<=time)
            {
                maxi=max(maxi,c2-c+1);
                break;
            }
        }
 
    }
    cout<<maxi;
}