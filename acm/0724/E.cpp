#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1111;
typedef long long LL;
int n;
struct P{
	int x,y,cnt;
	P(){}
	P(int _x,int _y){
		x=_x;y=_y;
	}
}p[maxn];
bool operator<(const P &a,const P &b){
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}
bool operator==(const P &a,const P &b){
	return a.x==b.x&&a.y==b.y;
}
map<pair<int,int>,int>M;
map<pair<int,int>,int>M2;
P ang[maxn];
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
const int mo=1e9+7;
long long pw(long long x,long long k,long long mo){
	long long ans=1;
	for(;k;k>>=1){
		if(k&1)ans=ans*x%mo;
		x=x*x%mo;
	}return ans;
}
LL _inv(int x){
	return pw(x,mo-2,mo);
}
LL inv[maxn],two[maxn];
int main(){
	
	two[0]=1;
	for(int i=1;i<maxn;i++)inv[i]=_inv(i);
	for(int i=1;i<maxn;i++)two[i]=two[i-1]*2%mo;

//	for(int i=1;i<=5;i++)
//		cout<<inv[i]<<" ";

	int T;scanf("%d",&T);	
	while(T--){
		long long ans=0;
		scanf("%d",&n);
		M.clear();
		for(int i=1;i<=n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			M[make_pair(p[i].x,p[i].y)]++;
		}
		sort(p+1,p+1+n);
		n=unique(p+1,p+1+n)-p-1;
		for(int i=1;i<=n;i++)
			p[i].cnt=M[make_pair(p[i].x,p[i].y)];
			
		if(n==1){
			ans=((LL)two[p[1].cnt]-p[1].cnt-1+mo+mo)%mo;
			cout<<ans<<endl;
			continue;
		}
		
		//cerr<<n<<endl;
		//for(int i=1;i<=n;i++)
		//	printf("%d%c",p[i].cnt," \n"[i==n]);
			
		for(int i=1;i<=n;i++){
			int siz=0;
			for(int j=1;j<=n;j++)if(i!=j){
				ang[++siz]=P(p[j].x-p[i].x,p[j].y-p[i].y);
				int d=gcd(ang[siz].x,ang[siz].y);
				d=abs(d);
				ang[siz].x/=d;
				ang[siz].y/=d;				
				if(ang[siz].x<0)ang[siz].x*=-1,ang[siz].y*=-1;
				if(ang[siz].x==0)ang[siz].y=1;
			}
			
			
			sort(ang+1,ang+1+siz);	
//			printf("%d\n",siz);
//			for(int j=1;j<=siz;j++)
//				printf("%d %d %c",ang[j].x,ang[j].y," \n"[j==siz]);
			
			M.clear();
			for(int i=1;i<=siz;i++)
				M[make_pair(ang[i].x,ang[i].y)]+=ang[i].cnt;
			for()
			
			
		}
		cout<<ans%mo<<endl;
		
	}
	return 0;
}
