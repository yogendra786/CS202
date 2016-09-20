#include<iostream>
#include<fstream>
#include<string>
#include "vector.hpp"
#include "sorter.hpp"
#include "timer.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"
//#include "graph.hpp"
#define K 10000

using namespace pratap;
using namespace std;

int
main ()
{
  vector < int >array;
  sorter < int >sort;
  clock_t start_time;
  clock_t end_time;
  timer clk;
   int take;
  //graph plt;
  int input, input1, lo, hi, i, c = 0, a, choice, choice1, remain = 1;
  string filename;
  ifstream Myfile (filename.c_str ());
  ofstream file_,file_1,file_2,file_3,file_4,file_5,file_6,file_7,file_8,file_9,file_10,file_11;

  cout <<
    "Choose Input method :\t 1.Manually(Via user)\t2.From File" <<
    endl;
  cin >> choice1;
  switch (choice1)
    {
    case 1:
      while (remain == 1)
	{
	  cout << "How many elements you want to insert" << endl;
	  cin >> input;
	  while (input-- > 0)
	    {
	      cin >> input1;
	      array.push_back (input1);
	    }
	  cout << "want to insert more? then press 1,else 0" << endl;
	  cin >> remain;
	}
      cout<<"Total Number of Inputs : "<<array.size()<<endl;
      cout <<"Entered Inputs :"<<endl;
      for (i = 0; i < array.size (); i++)
	cout << array[i]<<"  ";
      cout<<endl;
     // cout<<"Enter Range for Count Sort"<<endl;
      //cin>>k;
     cout <<"Give Range of indexes to be sorted :"<<endl;
      cout<<"From : ";
      cin >>lo;
      cout<<"To : ";
      cin>>hi;
      lo=lo-1;
      hi=hi-1;
      break;
    case 2:
      cout << "Enter the file  name  ";
      cin >> filename;
      Myfile.open (filename.c_str ());
      Myfile >> a;
      while (!Myfile.eof ())
	{

	  array.push_back (a);
	  Myfile >> a;
	  c++;
	}
      Myfile.close ();
      cout<<"Total Number of Inputs : "<<c<<endl;
      cout <<"Entered Inputs :"<<endl;
      for (i = 0; i < array.size (); i++)
	cout << array[i]<<"  ";
      cout<<endl;
       //cout<<"Enter Range for Count Sort"<<endl;
      //cin>>k;
      cout <<"Give Range of indexes to be sorted :"<<endl;
      cout<<"From : ";
      cin >> lo;
      cout<<"To : ";
      cin>>hi;
      lo=lo-1;
      hi=hi-1;
      break;

   default :
         cout<<"Enter Between the given choices"<<endl;
         break;
    }

cout<<"Wanna run sorting algorithm for all??if(yes=1)or(no=0)"<<endl;
cin>>take;
if(take==1){
      
    
      cout << "sorting using insertion sort is as follows:\n"; 
      clk.start();
      sort.insertion_sort (array, lo, hi);
      clk.stop();
      clk.print();
      cout<<endl;
      file_.open("insertion.txt", std::ios_base::app);
      file_<<hi-lo+1<<"  "<<clk.last_timing();
      //file_.close();
      //plt.plot("insertion.txt");
    
      cout << "sorting using selection sort is as follows:\n";
      clk.start();
      sort.selection_sort (array, lo, hi);
      clk.stop();
      //cout << endl;
      clk.print();
      cout<<endl;
      file_2.open("selection.txt", std::ios_base::app);
      file_2<<array.size()<<"  "<<clk.last_timing()<<endl;
      
      cout << "sorting using Rank Sort is as follows:\n";
      clk.start();
      sort.rank_sort (array, lo, hi);
      clk.stop();
      //cout << endl;
      clk.print();
      cout<<endl;
      file_3.open("rank.txt", std::ios_base::app);
      file_3<<array.size()<<"  "<<clk.last_timing();
      

      cout << "sorting using Bubble Sort is as follows:\n";
      clk.start();
      sort.bubble_sort (array, lo, hi);
      clk.stop();
      //cout << endl;
      clk.print();
      cout<<endl;
      file_4.open("bubble.txt", std::ios_base::app);
      file_4<<array.size()<<"  "<<clk.last_timing();
      

      cout << "sorting using Quick sort is as follows:\n";
      clk.start();
      sort.quick_sort (array, lo, hi);
      clk.stop();
      //cout << endl;
      clk.print();
      cout<<endl;
      file_5.open("quick.txt", std::ios_base::app);
      file_5<<array.size()<<"  "<<clk.last_timing();
    

      cout << "sorting using Merge Sort is as follows:\n";
      clk.start();
      sort.merge_sort (array, lo, hi);
      clk.stop();
      //cout << endl;
      clk.print();
      cout<<endl;
      file_6.open("merge.txt", std::ios_base::app);
      file_6<<array.size()<<"  "<<clk.last_timing();
     

      cout << "sorting using Improved Bubble Sort is as follows:\n";
      clk.start();
      sort.improved_bubble_sort (array, lo, hi);
      clk.stop();  
      //cout << endl;
      clk.print();
      cout<<endl;
      file_7.open("improved_bubble.txt", std::ios_base::app);
      file_7<<array.size()<<"  "<<clk.last_timing();
      

      cout << "sorting using Improved Rank Sort is as follows:\n";
      clk.start();
      sort.improved_rank_sort (array, lo, hi);
      clk.stop();
      //cout << endl;
      clk.print();
      cout<<endl;
      file_.open("improved_rank.txt", std::ios_base::app);
      file_<<array.size()<<"  "<<clk.last_timing();
     cout << "sorting using Count Sort is as follows:\n";
      clk.start();
      sort.count_sort (array, lo, hi,K);
      clk.stop();
      //cout << endl;
      clk.print();
      cout<<endl;
      file_8.open("count_sort.txt", std::ios_base::app);
      file_8<<array.size()<<"  "<<clk.last_timing();

    
        cout << "sorting using Bucket Sort(Stack) is as follows:\n";
      clk.start();
      sort.bucket_sort_list (array, lo, hi,K);
      clk.stop();  
      //cout << endl;
      clk.print();
      cout<<endl;
      file_10.open("bucket_sort_stack.txt", std::ios_base::app);
      file_10<<array.size()<<"  "<<clk.last_timing();

       cout << "sorting using Bucket Sort(List) is as follows:\n";
      clk.start();
      sort.bucket_sort_list (array, lo, hi,K);
      clk.stop();  
      //cout << endl;
      clk.print();
      cout<<endl;
      file_9.open("bucket_list.txt", std::ios_base::app);
      file_9<<array.size()<<"  "<<clk.last_timing();

     

      cout << "sorting using Bucket Sort(Queue) is as follows:\n";
      clk.start();
      sort.bucket_sort_queue (array, lo, hi,K);
      clk.stop();
      //cout << endl;
      clk.print();
      cout<<endl;
      file_11.open("bucket_sort_queue.txt", std::ios_base::app);
      file_11<<array.size()<<"  "<<clk.last_timing();

       cout<<"Sorted List\n";
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;

      
     
     

 }
 
else {

 cout<<"==================================================================================================================================="<<endl;
  
  cout <<
    "1.Insertion Sort\n2.Selection Sort\n3.Rank Sort\n4.Bubble Sort\n5.Quick Sort\n6.Merge Sort\n7.Bubble Sort(Improved Version)\n8.Rank Sort(Improved Version)\n9.Count Sort\n10.Bucket Sort(List)\n11.Bucket Sort(Stack)\n12.Bucket Sort(Queue)"
    << endl;
  cout<<"Choose your sorting algorithm"<<endl;

  cin >> choice;

  switch (choice)
    {

    case 1:
      cout << "sorting using insertion sort is as follows:\n"; 
      clk.start();
      sort.insertion_sort (array, lo, hi);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_.open("insertion.txt", std::ios_base::app);
      file_<<hi-lo+1<<"  "<<clk.last_timing();
      //file_.close();
      //plt.plot("insertion.txt");
      break;

    case 2:
      cout << "sorting using selection sort is as follows:\n";
      clk.start();
      sort.selection_sort (array, lo, hi);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_1.open("selection.txt", std::ios_base::app);
      file_1<<array.size()<<"  "<<clk.last_timing()<<endl;
      break;

    case 3:
      cout << "sorting using Rank Sort is as follows:\n";
      clk.start();
      sort.rank_sort (array, lo, hi);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_2.open("rank.txt", std::ios_base::app);
      file_2<<array.size()<<"  "<<clk.last_timing();
      break;
    case 4:
      cout << "sorting using Bubble Sort is as follows:\n";
      clk.start();
      sort.bubble_sort (array, lo, hi);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_3.open("bubble.txt", std::ios_base::app);
      file_3<<array.size()<<"  "<<clk.last_timing();
      break;
    case 5:
      cout << "sorting using Quick sort is as follows:\n";
      clk.start();
      sort.quick_sort (array, lo, hi);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_4.open("quick.txt", std::ios_base::app);
      file_4<<array.size()<<"  "<<clk.last_timing();
      break;
    case 6:
      cout << "sorting using Merge Sort is as follows:\n";
      clk.start();
      sort.merge_sort (array, lo, hi);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_5.open("merge.txt", std::ios_base::app);
      file_5<<array.size()<<"  "<<clk.last_timing();
      break;
    case 7:
      cout << "sorting using Improved Bubble Sort is as follows:\n";
      clk.start();
      sort.improved_bubble_sort (array, lo, hi);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_6.open("improved_bubble.txt", std::ios_base::app);
      file_6<<array.size()<<"  "<<clk.last_timing();
      break;
    case 8:
      cout << "sorting using Improved Rank Sort is as follows:\n";
      clk.start();
      sort.improved_rank_sort (array, lo, hi);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_7.open("improved_rank.txt", std::ios_base::app);
      file_7<<array.size()<<"  "<<clk.last_timing();
      break;
     case 9:
      //cout<<"Enter Range"<<endl;
      //int k;
      //cin>>k;
      cout << "sorting using Count Sort is as follows:\n";
      clk.start();
      sort.count_sort (array, lo, hi,K);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_8.open("count_sort.txt", std::ios_base::app);
      file_8<<array.size()<<"  "<<clk.last_timing();
      break;
    case 10:
     cout << "sorting using Bucket Sort(List) is as follows:\n";
      clk.start();
      sort.bucket_sort_list (array, lo, hi,K);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_9.open("bucket_sort_list.txt", std::ios_base::app);
      file_9<<array.size()<<"  "<<clk.last_timing();
      break;
     case 11:
     cout << "sorting using Bucket Sort(Stack) is as follows:\n";
      clk.start();
      sort.bucket_sort_stack (array, lo, hi,K);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_10.open("bucket_sort_stack.txt", std::ios_base::app);
      file_10<<array.size()<<"  "<<clk.last_timing();
      break;
     case 12:
     cout << "sorting using Bucket Sort(Queue) is as follows:\n";
      clk.start();
      sort.bucket_sort_queue (array, lo, hi,K);
      clk.stop();
      for (i = 0; i < array.size (); i++)
	cout << array[i]<< "  ";
      cout << endl;
      clk.print();
      file_11.open("bucket_sort_queue.txt", std::ios_base::app);
      file_11<<array.size()<<"  "<<clk.last_timing();
      break;
      
     default :
         cout<<"Enter Between the given choices"<<endl;
         break;


    }
 }
cout<<"==================================================================================================================================="<<endl;
  return 0;
}
