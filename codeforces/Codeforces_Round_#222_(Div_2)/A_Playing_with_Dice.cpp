#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
 
using namespace std;
 
 
int main()
{
    int a,b;
    cin>>a>>b;
    vector<int> res(3,0);
    for(int c=1;c<=6;c++)
    {
       int one = abs(a-c),two = abs(b-c);
       if(one == two ) res[1]++;
       else if(one < two) res[0]++;
       else res[2]++;
   }
   copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
}