#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef pair<int,int> point;
 
 
 
 
int crossProduct(point p1,point p2)
{
    return p1.first*p2.first + p1.second*p2.second;
}
 
bool angleDroit(const point &p1,const point &p2,const point &p3)
{
    return crossProduct(make_pair(p2.first-p1.first,p2.second-p1.second),make_pair(p3.first-p2.first,p3.second-p2.second)) == 0;
}
 
 
int distSquare(const point &p1, const point &p2)
{
    return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}
 
 
bool rectangles(vector<pair<int,point> > &points)
{
    for(int c=0;c<2;c++)
    {
        for(int c2=0;c2<4;c2++)
        {
            if(!angleDroit(points[c*4+c2].second,points[(c*4+(c2+1)%4)].second,points[(c*4+(c2+2)%4)].second))
                return false;
            if(distSquare(points[c*4+c2].second,points[c*4+(c2+1)%4].second)!=distSquare(points[c*4+(c2+2)%4].second,points[c*4+(c2+3)%4].second) || (c== 0 && distSquare(points[c*4+c2].second,points[c*4+(c2+1)%4].second)!=distSquare(points[c*4+(c2+1)%4].second,points[c*4+(c2+2)%4].second)) )
                return false;
        }
    }
}
 
 
int main()
{
    vector<pair<int,point> > v(8);
    for(int c=0;c<8;c++)
    {
        v[c].first = c+1;
        cin>>v[c].second.first>>v[c].second.second;
    }
    do
    {
        if(rectangles(v))
        {
            cout<<"YES"<<endl;
            for(int c=0;c<v.size();c++)
            {
                cout<<v[c].first<<" ";
                if(c==3) cout<<endl;
            }
            return 0;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout<<"NO"<<endl;
}