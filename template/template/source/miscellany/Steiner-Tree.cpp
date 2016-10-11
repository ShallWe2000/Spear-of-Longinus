priority_queue<pair<int, int> > Q;

// m is key point
// n is all point

for (int s = 0; s < (1 << m); s++){
	for (int i = 1; i <= n; i++){
		if (id[i]) continue;
		for (int s0 = 0; s0 < s; s0++)
			if ( (s0 & s) == s0 ){
				f[s][i] = min(f[s][i], f[s0][i] + f[s - s0][i]);
			}
	}
	for (int i = 1; i <= n; i++) vis[i] = 0;
    while (!Q.empty()) Q.pop();	
	for (int i = 1; i <= n; i++){
		if (id[i]) continue;
		Q.push(mp(-f[s][i], i)); 
	}       
	while (!Q.empty()){
		while (!Q.empty() && Q.top().first != -f[s][Q.top().second]) Q.pop();
			if (Q.empty()) break;
			int Cur = Q.top().second; Q.pop();
			for (int p = g[Cur]; p; p = nxt[p]){
				int y = adj[p];
				if ( f[s][y] > f[s][Cur] + 1){
					f[s][y] = f[s][Cur] + 1;
					Q.push(mp(-f[s][y], y));
				}
			}
	}
}
