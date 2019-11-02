#include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<math.h>
     
    int main()
    {
      char s[100003],r[100003];
      int i,j,k;
  char s1[100003],s2[100003],*ch;
      int flag1=0,flag2=0;
      scanf("%s%s%s",s,s1,s2);
      k=0;
      for(i=strlen(s)-1;i>=0;i--)
        r[k++]=s[i];
        r[k]='\0';
     
      if(strstr(s,s1)){
       ch=strstr(s,s1);
       if(strstr((ch+strlen(s1)),s2)) flag1=1;
       }
          if(strstr(r,s1)){
       ch=strstr(r,s1);
       if(strstr((ch+strlen(s1)),s2)) flag2=1;
       }
     
      if(flag1==1&&flag2==1) printf("both\n");
      else if(flag1==1&&flag2==0) printf("forward\n");
      else if(flag1==0&&flag2==1)printf("backward\n");
  else if(flag1==0&&flag2==0) printf("fantasy\n");
     
    return 0;
    }