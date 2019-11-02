#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
        vector<int> row(1000);
        vector<int> col(1000);
        for(int c=0;c<row.size();c++)
                row[c]=col[c]=c;
        int n,m;
        cin>>n>>m;
        int nb_requetes;
        cin>>nb_requetes;
 
        vector<vector<int> > v(n,vector<int>(m));
        for(int c=0;c<n;c++)
                for(int c2=0;c2<m;c2++)
                        cin>>v[c][c2];
                for(int c=0;c<nb_requetes;c++)
        {
                char car;
                int x;
                int y;
                cin>>car>>x>>y;
                x--;
                y--;
                if(car=='c')
                        swap(col[x],col[y]);
                else if(car=='r')
                        swap(row[x],row[y]);
                else
                        cout<<v[row[x]][col[y]]<<endl;
        }               
 
} 