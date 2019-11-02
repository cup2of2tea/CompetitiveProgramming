    #include <iostream>
    using namespace std;
    int n,m,a,b,ans;
    int main()
    {
     cin>>n>>m>>a>>b;
     --a; --b;
     if (m==1 || a/m==b/m || (a%m==0 && (b%m==m-1 || b==n-1))) ans=1; else
      if (a%m==b%m+1 || a%m==0 || b%m==m-1 || (m+b%m-a%m+1==b-a+1) || (b==n-1)) ans=2; else ans=3;
     cout<<ans;
    }