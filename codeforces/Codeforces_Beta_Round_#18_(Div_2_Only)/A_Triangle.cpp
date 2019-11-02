#include <iostream>
#include <cmath>
 
using namespace std;
 
int coordonnees[3][2];
 
bool droit()
{
        for(int c=0;c<3;c++)
        {
             int x0 = coordonnees[c][0]-coordonnees[(c+1)%3][0], y0 = coordonnees[c][1]-coordonnees[(c+1)%3][1];
             int  x1 = coordonnees[c][0]-coordonnees[(c+2)%3][0], y1 = coordonnees[c][1]-coordonnees[(c+2)%3][1];
                if( (x0||y0) && (x1||y1) && !(x0*x1+y0*y1) )
                        return true;
        }
        return false;
}
 
 
int main()
{
        for(int c=0;c<3;c++)
                for(int c2=0;c2<2;c2++)
                        cin>>coordonnees[c][c2];
        if(droit())
        {
                cout<<"RIGHT";
                return 0;
        }
        for(int c=0;c<3;c++)
                for(int c2=0;c2<2;c2++)
                {
                        coordonnees[c][c2]+=1;
                        if(droit())
                        {
                                cout<<"ALMOST";
                                return 0;
                        }
                        coordonnees[c][c2]-=2;
                        if(droit())
                        {
                                cout<<"ALMOST";
                                return 0;
                        }
                        coordonnees[c][c2]+=1;
                }
        cout<<"NEITHER";
}