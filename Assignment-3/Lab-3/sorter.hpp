/************************************************************
 * Purpose: A class with methods for different sorting algorithms
 *
 * Version : 1.0
 *
 * Date of Creation : 07/03/2016
 *
 * Bugs : 
 *************************************************************/  
#ifndef SORTER_HPP
#define SORTER_HPP


#include "stack.hpp"
#include "queue.hpp"

#include "list.hpp"
#include "vector.hpp"

#include<algorithm>  


  
namespace pratap
{
  
template < class Item > 
class sorter 
  {
  private:
        vector < Item > a;    
        int lo, hi;
  
  public:
        void insertion_sort (vector < Item > &a, int lo, int hi);    
        void merge_sort (vector < Item > &a, int lo, int hi);
        void merge(vector <Item> &a, int lo, int m, int hi);    
        void rank_sort (vector < Item > &a, int lo, int hi);    
        void selection_sort (vector < Item > &a, int lo, int hi);    
        void quick_sort (vector < Item > &a, int lo, int hi);    
        void bubble_sort (vector < Item > &a, int lo, int hi);
        int partition(vector <Item> &a, int lo, int hi);
        void improved_bubble_sort (vector < Item > &a,int lo,int hi);
        void improved_rank_sort (vector < Item > &a,int lo,int hi);
        void count_sort(vector <Item> &a,int lo,int hi,int K);
        void bucket_sort_list(vector <Item> &a,int lo,int hi,int K);
        void bucket_sort_stack(vector <Item> &a,int lo,int hi,int K);
        void bucket_sort_queue(vector <Item> &a,int lo,int hi,int K);


  
};
  
 
 
 
 
template < class Item > 
void sorter <Item >::insertion_sort (vector < Item > &a, int lo, int hi)
  {
    
     int i, j, v;
        
      for (i = lo; i <= hi; i++)
      {
        v = a[i];	
        j = i;	
       while (a[j - 1] > v && j >= 1)
	  {	    
           a[j] = a[j - 1];   
             j--;	  
           }	
        a[j] = v;
      
      }
  
}

template < class Item > 
void sorter <Item >:: selection_sort (vector < Item > &a, int lo, int hi)
  {
    int i,j,min,temp,n;
    n=hi-lo+1;
    for(i=lo;i<=hi;i++){
       min=i;
       for(j=i+1;j<n;j++){
           if(a[j]<a[min])
                min=j;
       }
       temp=a[min];
       a[min]=a[i];
       a[i]=temp;
   }


    
     
  
 }

template < class Item > 
void sorter <Item >:: quick_sort (vector < Item > &a, int lo, int hi)
  {
    int pivot;
    if(hi>lo){
         pivot=partition(a,lo,hi);
         quick_sort(a,lo,pivot-1);
         quick_sort(a,pivot+1,hi);   
         }
  }

template< class Item >
int sorter <Item>:: partition(vector <Item> &a, int lo, int hi)
   {
     int left,right,pivot_item=a[lo];
     left=lo;
     right=hi;
     while(left<right){
            while(a[left]<=pivot_item)
                left++;
            while(a[right]>pivot_item)
                right--;
            if(left<right)
               std :: swap(a[left],a[right]);
     }
    a[lo]=a[right];
    a[right]=pivot_item;
    return right;
  } 

template < class Item > 
void sorter <Item >::bubble_sort (vector < Item > &a, int lo, int hi)
  {
    int n,pass,temp,i;
    n=hi-lo+1;
   for(pass= n-1;pass>=0;pass--){
       for(i=lo;i<=pass-1;i++)   {
         if(a[i]>a[i+1]){
                temp=a[i];
                 a[i]=a[i+1];
                 a[i+1]=temp;
          }
       }
   }
 }

template < class Item > 
void sorter <Item >::merge_sort (vector < Item > &a, int lo, int hi)
  {
   if (lo < hi)
    {
         int m;
         m = lo+(hi-lo)/2;
        merge_sort(a, lo, m);
        merge_sort(a, m+1, hi); 
        merge(a, lo, m, hi);
    }
    
 }

template < class Item >
void sorter <Item> :: merge(vector <Item> &a, int lo, int m, int hi)
{
    int i, j, k;
    int n1 = m - lo + 1;
    int n2 =  hi - m;
 
   
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[lo + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
 
   
    i = 0; 
    j = 0;
    k = lo; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

template <class Item>

void sorter<Item>::rank_sort(vector <Item> &a,int lo,int hi){
     int j,i,n;
      n=hi-lo+1;
      int b[n],c[n];
    for(j=0;j<n;j++)
          b[j]=0;

     for(j=1;j<n;j++)
            for(i=0;i<j;i++)
                    if(a[i]<=a[j])
                         b[j]=b[j]+1;
                     else
                         b[i]=b[i]+1;
              
      
     for(j=0;j<n;j++)
         c[b[j]]=a[j];

     for(j=0;j<n;j++)
          a[j]=c[j];
}

template < class Item > 
void sorter <Item >::improved_bubble_sort (vector < Item > &a, int lo, int hi)
  {
  int pass,n,i,temp,swapped=1;
     n=hi-lo+1;
  for(pass=n-1;pass>=0 && swapped;pass--){
           swapped=0;
           for(i=0;i<=pass-1;i++){
                if(a[i]>a[i+1]){
                     temp=a[i];
                     a[i]=a[i+1];
                     a[i+1]=temp;
                     swapped=1;
                     }
            }
   }
 }


template < class Item > 
void sorter <Item >::improved_rank_sort (vector < Item > &a, int lo, int hi)
  {
 
   int j,i,n,flag=0;
      n=hi-lo+1;
      int b[n],c[n];
    for(j=0;j<n;j++)
          b[j]=0;

     for(j=1;j<n;j++)
            for(i=0;i<j;i++)
                    if(a[i]<=a[j])
                         b[j]=b[j]+1;
                     else
                         { b[i]=b[i]+1;
                           flag=1;}
              
      if(flag==1){
     for(j=0;j<n;j++)
         c[b[j]]=a[j];

     for(j=0;j<n;j++)
          a[j]=c[j];
      }
    
     
  
}

template <class Item>
void sorter<Item>::count_sort(vector <Item> &a,int lo,int hi,int K){

                    int N=hi-lo+1;
                    int array1[N],C[K];
                      int i,j;
                    for(i=0;i<K;i++)
                       C[i]=0;
                    for(j=0;j<N;j++)
                      C[a[j]]=C[a[j]]+1;
                    for(i=1;i<K;i++)
                      C[i]=C[i]+C[i-1];
                    for(j=N-1;j>=0;j--){
                        array1[C[a[j]]]=a[j];
                        C[a[j]]=C[a[j]]-1;
                                       }
                     for(i=0;i<N;i++)
                         a[i]=array1[i+1];
                                       

}

template <class Item>
void sorter<Item>:: bucket_sort_list(vector <Item> &a,int lo,int hi,int K){
  int RANGE=50000;
  /*if(hi<999)
      RANGE=999;
  else RANGE=50000;*/
 list<int> Bu[RANGE];
   int i,j,n,p;
   n=hi-lo+1;
   for(int i=0;i<n;i++){
       p=a[i];
       Bu[p].cons(p);
      
    }
   
   for(int j=1;j<RANGE;j++){
            Bu[0].append(Bu[j]);      
    }
  list<int> Bu1=Bu[0];
  
   
   std::cout<<std::endl;
   for(int j=0;j<n;j++){
       a[j]=Bu1.next();
        

    }
       
     
  
}

template <class Item>
void sorter<Item>::bucket_sort_stack(vector <Item> &a,int lo,int hi,int K){

   int RANGE=K;
   int n=hi-lo+1;
   stack<int> Bu[RANGE];
   for(int i=0;i<n;i++)
       {
            Bu[a[i]].Push(a[i]);
       }
    int j=0;
    for(int i=0;i<RANGE;i++)
        {
         
         while(Bu[i].size()){
          a[j]=Bu[i].Pop();
           j++;
           }
        }
}

template <class Item>
void sorter<Item>::bucket_sort_queue(vector <Item> &a,int lo,int hi,int K){
         
        int RANGE=K;
        queue<int> Bu[RANGE];
   int i,j=0,n,p;
    n=hi-lo+1;
   for(int i=0;i<n;i++){
       Bu[a[i]].push(a[i]);
      
    }

   for(i=0;i<RANGE;i++)
     {  
       while(Bu[i].size()){
       a[j]=Bu[i].pop();
         j++;
        }
     }
}








      
    
    
  
}

            

    
  
   
   

 
 



#endif	/* 
 */
  
 
/*************************************************************
 * Implement your methods here.
 * You may add any number of methods in addition to the above ones.
 * However, the above methods must be implemented.
 * DO NOT name your methods or classes differently in any case.
 * Parameter details :
 * a : the vector to sort
 * lo : the lower index of the vector from where to sort
 * hi : the higher index of the vector till where to sort
 * e.g,
 * insertion_sort(a,2,10) will sort the vector a
 * from index 2, i.e, the third element,
 * till index 10, i.e, the eleventh element.
*************************************************************/ 
