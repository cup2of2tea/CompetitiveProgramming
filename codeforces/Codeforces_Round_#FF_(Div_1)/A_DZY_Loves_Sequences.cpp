#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
   int n;
   cin >> n;
   int t[n];
   for(int i=0; i<n; i++)
      cin >> t[i];
   int a[n];
   for(int i=n-1, c=1; i>=0; i--)
   {
      a[i] = c;
      if(i > 0 && t[i] > t[i-1])
         c++;
      else
         c = 1;
   }
   int b[n];
   for(int i=0, c=1; i<n; i++)
   {
      b[i] = c;
      if(i < n-1 && t[i] < t[i+1])
         c++;
      else
         c = 1;
   }
   int r = 1;
   if(n > 1)
   {
      r = 1 + max(a[1], b[n-2]);
      for(int i=1; i<n-1; i++)
      {
         r = max(r, 1 + max(a[i+1], b[i-1]));
         if(0 < i && i < n-1 && t[i-1] + 1 < t[i+1])
            r = max(r, b[i-1] + 1 + a[i+1]);
      }
   }
   cout << r << endl;
   return 0;
}