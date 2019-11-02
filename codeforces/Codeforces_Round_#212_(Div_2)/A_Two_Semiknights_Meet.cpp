#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
#define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    int n;
	cin>>n;
	while(n--)
	{
		vector<string> v(8);
		for(int c=0;c<8;c++)
        {
            cin>>v[c];
        }
		int x,y=0;
		for(x=0;x<8&&v[x][y]!='K';x++)
        {
			for(y=0;y<8&&v[x][y]!='K';y++);
			if(y==8) y=0;
			if(v[x][y]=='K') break;
        }
		vector<pair<int,pair<int,int> > > parcours;
		vector<vector<bool> > visites(8,vector<bool>(8,false));
		visites[x][y]=true;
		int dx[4]={2,-2,-2,2};
		int dy[4]={2,2,-2,-2};
		parcours.push_back(make_pair(x,make_pair(y,0)));
		while(parcours.size()!=0)
		{
			int x2=parcours.back().first;
			int y2=parcours.back().second.first;
			int cost=parcours.back().second.second;
			if((x2!=x||y2!=y)&&v[x2][y2]=='K'&&cost%2==0){ cout<<"YES"<<endl; goto end; }
			parcours.pop_back();
			for(int c = 0;c< 4;c++)
			{
				int x3=x2+dx[c];
				int y3=y2+dy[c];
				if(x3>=0&&y3>=0&&x3<8&&y3<8&&!visites[x3][y3])
				{
					visites[x3][y3]=true;
					parcours.push_back(make_pair(x3,make_pair(y3,cost+1)));
				}
			}
		}
	cout<<"NO"<<endl;
	end:;
	}
}