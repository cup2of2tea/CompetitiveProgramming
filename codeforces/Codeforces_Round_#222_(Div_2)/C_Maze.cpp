#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<bool> > visites(n,vector<bool>(m,false));
    vector<string> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    int nb_vides=0;
    for(int c=0;c<n;c++) for(int c2 = 0;c2<m;c2++) nb_vides+=v[c][c2]=='.';
    if(nb_vides!=k)
    {
        vector<pair<int,int> > to_do;
        for(int c=0;c<n;c++)
        {
            for(int c2=0;c2<m;c2++)
            {
                if(v[c][c2]=='.')
                {
                    to_do.push_back(make_pair(c,c2));
                    goto go;
                }
            }
        }
        go:
            visites[to_do.back().first][to_do.back().second]=true;
            nb_vides--;
            while(to_do.size()&&nb_vides!=k)
            {
                int x = to_do.back().first, y = to_do.back().second;
                to_do.pop_back();
                int dx[4]={1,-1,0,0};
                int dy[4]={0,0,1,-1};
                for(int c=0;c<4&&nb_vides!=k;c++)
                {
                    int x2 = dx[c]+x;
                    int y2 = dy[c]+y;
                    if(x2>=0&&y2>=0&&x2<n&&y2<m&&!visites[x2][y2]&&v[x2][y2]=='.')
                    {
                        visites[x2][y2]=true;
                        nb_vides--;
                        to_do.push_back(make_pair(x2,y2));
                    }
                }
           }
    }
    for(int c=0;c<n;c++) for(int c2=0;c2<m;c2++) if(!visites[c][c2]&&v[c][c2]=='.') v[c][c2]='X';
    for(int c=0;c<n;c++) cout<<v[c]<<endl;
}