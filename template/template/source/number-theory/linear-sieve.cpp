void get_p(){
	phi[1]=mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!p[i]){
			prime[++prime[0]]=i;
			phi[i]=i-1;mu[i]=-1;
		}for(int j=1;j<=prime[0];j++){
			if(i*prime[j]>n)break;
			p[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}else{
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
				mu[i*prime[j]]=-mu[i];
			}
		}
	}
}
