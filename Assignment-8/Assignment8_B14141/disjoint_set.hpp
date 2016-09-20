#ifndef DISJOINT_SET
#define DISJOINT_SET 1

struct vertice{
	int val;
	int rank;
	struct vertice* parent;
};

class Disjoint{
	private:
		struct vertice v[100];

	public:
		Disjoint();
		void make_set(int x);
		int find_set(int x);
		void make_union(int x,int y);
		void link(int x, int y);
};

Disjoint::Disjoint(){
	for(int i=0;i<100;i++)
		v[i].parent=NULL;
}

void Disjoint::make_set(int x){
	v[x].parent=&v[x];
	v[x].val=x;
	v[x].rank=0;
}

int Disjoint::find_set(int x){
	if(v[x].parent!=&v[x])
		v[x].parent=&v[find_set((v[x].parent)->val)];

	return (v[x].parent)->val;
}

void Disjoint::make_union(int x,int y){
	link(find_set(x),find_set(y));
}

void Disjoint::link(int x,int y){
	if(v[x].rank > v[y].rank)
		v[y].parent=&v[x];

	else{
		v[x].parent=&v[y];
		if(v[x].rank==v[y].rank)
			v[y].rank=v[y].rank+1;
	}

}

#endif