#include<cstdlib>
#include<cstring>
namespace pratap
{
template <class item>
class vector
{
	public:
		vector();
		~vector();
		void push_back(const item & i);
		bool empty();
		unsigned int getsize();
		vector(const int & g_size);			
		void setSize(unsigned int newsize); 		
 	 	
		vector(const int & g_size,const item & ival); 	

	int &operator[](int i)
      {
        
          return array[i];
      }

	private:
	item *array;	
	item *array2;

	unsigned int size;
	int cap;
	const static int dyns=128;
	const static int dynm=2;

};

template <class item>
vector <item>::vector()
{
	array=NULL;
	size=0;
	cap=dyns;
		
}

template <class item>
vector <item>::vector(const int & g_size)
{
	size=0;
	cap=g_size;
		array=new item [g_size];
}

template <class item>
vector <item>::vector(const int & g_size,const item & ival)
{
	size=0;
	cap=g_size;
	array=new item [g_size];
	int i;
	for(i=0;i<g_size;i++)
	array[i]=ival;
	size=g_size;
}
template <class item>
vector <item>::~vector()
{

		delete[] array;
		
	
}

template <class item>
void vector <item>::push_back(const item &i)
{
	if(size==0)
	{
		array=new item[1];
		array[0]=i;
		size=1;		
	}
	else
		{
			item *temp;
			temp=new item[size+1];
			int j=0;
			while(j<size)
		{
			temp[j]=array[j];
			j++;
		}
			temp[j]=i;
			delete[] array;
			array=temp;
			size++;
	}
	}


template <class item>
unsigned int vector <item>::getsize()
{
	return size;
}

template<class item>
bool vector<item>:: empty()
{
	if(size==0)
	return true;
	else
	false;
}

}
