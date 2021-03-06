struct Node
{
	Node *ch[2], *p;
	int isroot;
	bool dir();
	void set(Node*, bool);
	void update();
	void relax();
} *null;
void rot(Node *t)
{
	Node *p = t->p; bool d = t->dir();
	p->relax(); t->relax();
	p->set(t->ch[! d], d);
	if (p->isroot) t->p = p->p, swap(p->isroot, t->isroot);
	else p->p->set(t, p->dir());
	t->set(p, ! d);
	p->update();
}
void Splay(Node *t)
{
	for(t->relax(); ! t->isroot; ) {
		if (t->p->isroot) rot(t);
		else t->dir() == t->p->dir() ? (rot(t->p), rot(t)) : (rot(t), rot(t));
	}
	t->update();
}
void Access(Node *t)
{
	for(Node *s = null; t != null; s = t, t = t->p) {
		Splay(t);
		t->ch[1]->isroot = true;
		s->isroot = false;
		t->ch[1] = s;
		t->update();
	}
}
bool Node::dir() {
	return this == p->ch[1];
}
void Node::set(Node *t, bool _d) {
	ch[_d] = t; t->p = this;
}
void Node::Update(){
}
void Node::Relax(){
	if (this == Null) return;
}