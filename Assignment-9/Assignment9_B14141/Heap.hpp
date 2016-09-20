#ifndef HEAP
#define HEAP 1
#define INT_MIN -10000000

class Heap{
	private:
		int heap_size;
		int key;
		int i;
		int A[100];
		int index1[1000000];
	public:
		Heap();
		//~Heap();
		int size();
		int parent(int i);
		int left(int i);
		int right(int i);
		int extract_min(int A[]);
		void heap_insert(int A[],int key);
		void heap_Decrease_key(int A[],int i,int key);
		void Heapify(int A[],int i);
		int index(int key);
};

Heap::Heap(){
	heap_size=0;
}

int Heap::parent(int i){
	return i/2;
}

int Heap::index(int key){
	return index1[key];
}

int Heap::left(int i){
	return 2*i;
}

int Heap::size(){
	return heap_size;
}

int Heap::right(int i){
	return 2*i+1;
}

int Heap::extract_min(int A[]){
	int min=A[0];
	A[0]=A[heap_size];
	heap_size=heap_size-1;
	Heapify(A,0);
	return min;

}

void Heap::heap_insert(int A[],int key){
	heap_size=heap_size+1;
	A[heap_size]= INT_MIN;
	heap_Decrease_key(A,heap_size,key);
}



void Heap::heap_Decrease_key(int A[],int i,int key){
	A[i]=key;
	index1[key]=i;
	while((i>0)&(A[parent(i)]>A[i])){
		int k;
		k=A[i];
		A[i]=A[parent(i)];
		A[parent(i)]=k;
		i=parent(i);
	}
}

void Heap::Heapify(int A[],int i){
	int l=left(i);
	int r=right(i);
	int smallest;
	if((l<=heap_size)&(A[l]<A[i]))
		smallest=l;
	else 
		smallest=i;

	if((r<=heap_size)&(A[r]<A[smallest]))
		smallest=r;

	if(smallest!=i){
		int k=A[i];
		A[i]=A[smallest];
		A[smallest]=k;
		Heapify(A,smallest);
	}
}

#endif