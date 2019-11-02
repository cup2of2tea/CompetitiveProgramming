#include<stdio.h>
    #include<stdlib.h>
#include<string.h>
    #include<math.h>
     
    int main()
    {
          int a[100009],b[100009],c[100009];
      int i,j,k,l,m,n,count;
      int alice=0,bob=0;
      scanf("%d",&n);
      alice=0;bob=0;
      for(i=0;i<n;i++){
       scanf("%d",&a[i]);
       b[i]=c[i]=a[i];
       }
      for(i=1;i<n;i++){
        b[i]=b[i]+b[i-1];
      }
  for(j=n-2;j>=0;j--){
        c[j]=c[j]+c[j+1];     }
     
      i=0;
      j=n-1;
      count=0;
      while(1){
       if(count>=n) break;
       if(b[i]<c[j]) {alice++;i=i+1;count++;}
       else if(c[j]<b[i]){bob++;j=j-1;count++;}
       else if(c[j]==b[i]){alice++;i=i+1;count++;}
       }
 
      printf("%d %d\n",alice,bob);
 
    return 0;
    }