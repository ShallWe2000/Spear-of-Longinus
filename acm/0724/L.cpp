#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100005;
const int M = 5005;

int Case,n,m;
char s[N];
char p[M];
int ans[N];

int main(){

	scanf("%d", &Case);
	
	while (Case > 0){
		Case --;
		scanf("%d%d", &n, &m);
		scanf("%s", s);
		scanf("%s", p);
		for (int i = 0; i < n - m + 1; i++){
			int flag =1; 
			for (int j = 0; j < m; j++){
				if (s[i + j] == p[j + 1] && s[i + j + 1] == p[j]){
					j++;
					continue;
				} 
				if (s[i + j] == p[j]) continue;
				flag = 0;
				break;
			}
			ans[i] = flag;
		}
		for (int i = n - m + 1; i < n; i++) ans[i] = 0;
		for (int i = 0; i < n; i++)
			printf("%d", ans[i]);
		printf("\n");
	}

	return 0;
}
