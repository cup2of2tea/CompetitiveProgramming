#include<cstdio>
#include<cstring>
#include<algorithm>
unsigned n,m,i,j,k,d[256],e[256],r[256],o[1024],b,c,l;
int main(){
	scanf("%u%u",&n,&m);
	memset(e,255,sizeof(e));
	for(i=1;i<=m;++i)
		for(scanf("%u",&b),r[i]=i;b;--b)
			scanf("%u",&c),e[c]=i<<10|512-b;
	for(k=~0;k>n*2;std::random_shuffle(r+1,r+1+m)){k=0;
		memcpy(d,e,1024);
		for(i=1;i<=n;++i)if(~d[i])d[i]=(r[d[i]>>10]<<10|d[i]&1023);
		for(i=1;i<n;++i){
			for(j=l=i;j<=n;++j)if(d[j]<d[l])l=j;
			if(i!=l)
				if(~d[i]){
					for(b=n;b&&~d[b];--b);
					o[k++]=i<<9|b;
					o[k++]=l<<9|i;
					d[b]=d[i];d[i]=d[l];d[l]=~0;
				}else {
					o[k++]=l<<9|i;
					std::swap(d[i],d[l]);
				}
		}
	}
	printf("%u\n",k);
	for(i=0;i<k;++i)printf("%u %u\n",o[i]>>9,o[i]&511);
	return 0;
}