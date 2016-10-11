struct node{
	bool Rev;
	int c[2], fa, Chain, Aux, Val;
}T[N];

inline int Sum(int x){
	return T[x].Chain ^ T[x].Aux;
}

inline void Rev(int x){
	if (!x) return;
	swap(T[x].c[0],T[x].c[1]);
	T[x].Rev ^= 1;
}

inline void Update(int x){
	T[x].Chain = Sum(T[x].c[0]) ^ Sum(T[x].c[1]) ^ T[x].Val;
}

inline void Lazy_Down(int x){
	if (!x) return;
	if (T[x].Rev) Rev(T[x].c[0]), Rev(T[x].c[1]), T[x].Rev = 0;
}

inline void Rotate(int x,int c){
	int fa = T[x].fa, ft = T[fa].fa;
	T[x].fa = ft, T[fa].fa = x;
	if (ft) T[ft].c[T[ft].c[1] == fa] = x;
	T[fa].c[c] = T[x].c[!c];
	if (T[x].c[!c]) T[T[x].c[!c]].fa = fa;
	T[x].c[!c] = fa;
	if (Par[fa]) Par[x] = Par[fa], Par[fa] = 0;
	Update(fa);
}

inline void Splay(int x){
	int top = 0;
	for (int u = x; u; u = T[u].fa) Stack[++top] = u;
	
	for( ; top; top--) Lazy_Down(Stack[top]);
	
	for( ; T[x].fa; ){
		int fa = T[x].fa, ft = T[fa].fa;
		if (!ft) Rotate(x, T[fa].c[1] == x); else
		{
			if (T[fa].c[1] == x)
			{
				if (T[ft].c[1] == fa) Rotate(fa, 1),Rotate(x, 1);
				else Rotate(x, 1),Rotate(x, 0);
			} else
				if (T[ft].c[0] == fa) Rotate(fa, 0),Rotate(x, 0);
				else Rotate(x, 0),Rotate(x, 1);
		}
	}
	Update(x);
}

inline int Access(int u){
	
	int Nxt = 0;
	
	while (u){
		Splay(u);
		if (T[u].c[1]){
			T[T[u].c[1]].fa = 0;
			Par[T[u].c[1]] = u;
			T[u].Aux ^= Sum(T[u].c[1]);
		}
		T[u].c[1] = Nxt;
		if (Nxt){
			T[Nxt].fa = u;
			Par[Nxt] = 0;
			T[u].Aux ^= Sum(Nxt);
		}
		Update(u);
		Nxt = u;
		u = Par[u];
	}
	
	return Nxt;
	
}

inline void Root(int u){
	Rev(Access(u));
}

inline void Mark(int x, int col){
	Access(x);
	Splay(x);
	T[x].Val ^= col;
	Update(x);
}

inline void Link(int u, int v){
	Root(v);
	Access(v);
	Access(u);
	Splay(v);
	Splay(u);
	Par[v] = u;
	T[u].Aux ^= Sum(v);
	Access(v);
}

inline void Cut(int u, int v){
	Root(v);
	Access(u);
	Splay(u);
	T[T[u].c[0]].fa = 0;
	T[u].c[0] = 0;
	Update(u);
}
