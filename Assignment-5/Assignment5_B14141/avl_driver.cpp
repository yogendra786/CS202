#include<iostream>
#include "AVL.hpp"
#include<cstring>

using namespace std;


int
main ()
{

  AVL < int, string > av;
  av.put(10,"Yogendra");
     av.put(21,"Kumar");
     av.put(14,"Dhiwar");
     av.put(16,"17");
     cout<<av.minimum()<<endl;
     cout<<av.maximum()<<endl;
     if(av.has(14))cout<<"present\n";
     else cout<<"not present\n";

     if(av.has(9))cout<<"present\n";
     else cout<<"not present\n";

     if(av.has(8))cout<<"present\n";
     else cout<<"not present\n";

     if(av.has(18))cout<<"present\n";
     else cout<<"not present\n";

     cout<<av.get(22)<<endl;
     cout<<av.get(24)<<endl;
     cout<<av.get(25)<<endl;
     cout<<av.get(21)<<endl;
      cout<<av.size()<<endl;
   av.print();

   av.remove(12);
   av.remove(18);

   cout<<endl;
   cout<<endl;
  
   av.print();

  cout<<endl;
  cout<<endl;

  cout<<av.successor(20)<<endl;
  cout<<av.successor(16)<<endl;
  cout<<av.predecessor(22)<<endl;
  cout<<av.predecessor(16)<<endl;

  cout<<endl;
  cout<<endl;

  cout<<av.size()<<endl;


     cout<<av.size()<<endl;
     av.print(); 
  av.put (9, "Yogendra");
  av.put (5, "Mukesh");
  av.put (10, "Ajay");
  av.put (0, "Nayan");
  av.put (6, "Manoj");
  av.put (11, "Khilendra");
  av.put (-1, "Virendra");
  av.put (1, "Endra");
  av.put (2, "Khil");
  av.print_pre_order ();
  av.remove(10);
 cout<<endl;
  av.print_pre_order ();
  //av.remove(0);
  av.remove(9);
  //cout<<av.retrun1()<<endl;
   cout<<endl;
  av.print_post_order();
   cout<<endl;
  av.print_in_order();
  cout<<endl;
  av.print_level_order();




}
