#include<iostream>
#include "RBTree.hpp"
#include<cstring>

using namespace std;


int
main ()
{

  RBTree < int, string > rbt;
  /*rbt.put(10,"Yogendra");
     rbt.put(21,"Kumar");
     rbt.put(14,"Dhiwar");
     rbt.put(16,"17");
     cout<<rbt.minimum()<<endl;
     cout<<rbt.maximum()<<endl;
     if(rbt.has(14))cout<<"present\n";
     else cout<<"not present\n";

     if(rbt.has(9))cout<<"present\n";
     else cout<<"not present\n";

     if(rbt.has(8))cout<<"present\n";
     else cout<<"not present\n";

     if(rbt.has(18))cout<<"present\n";
     else cout<<"not present\n";

     cout<<rbt.get(22)<<endl;
     cout<<rbt.get(24)<<endl;
     cout<<rbt.get(25)<<endl;
     cout<<rbt.get(21)<<endl;
      cout<<rbt.size()<<endl;
   rbt.print();

   rbt.remove(12);
   rbt.remove(18);

   cout<<endl;
   cout<<endl;
  
   rbt.print();

  cout<<endl;
  cout<<endl;

  cout<<rbt.successor(20)<<endl;
  cout<<rbt.successor(16)<<endl;
  cout<<rbt.predecessor(22)<<endl;
  cout<<rbt.predecessor(16)<<endl;

  cout<<endl;
  cout<<endl;

  cout<<rbt.size()<<endl;


     cout<<rbt.size()<<endl;
     rbt.print(); */
  rbt.put (9, "Yogendra");
  
  rbt.put (5, "Mukesh");
  rbt.put (10, "Ajay");
  rbt.put (0, "Nayan");
  rbt.put (6, "Manoj");
  rbt.put (11, "Khilendra");
 rbt.put (-1, "Virendra");
  rbt.put (1, "Endra");
  cout<<rbt.blackHeight1(11)<<endl;
  
  //rbt.put (2, "Khil");
  rbt.print();
  cout<<endl;
  cout<<endl;
  cout<<endl;
  rbt.remove(9);
   rbt.remove(5);
   rbt.remove(0);
  rbt.print();
 /* rbt.print_pre_order ();
  rbt.remove(10);
 cout<<endl;
  rbt.print_pre_order ();
  
  rbt.remove(9);
  //cout<<rbt.retrun1()<<endl;
   cout<<endl;
  rbt.print_post_order();
   cout<<endl;
  rbt.print_in_order();
  cout<<endl;
  rbt.print_level_order();*/
  cout<<rbt.minimum()<<endl;
  cout<<rbt.maximum()<<endl;
  cout<<rbt.successor(10)<<endl;
  cout<<rbt.successor(6)<<endl;
  cout<<rbt.predecessor(2)<<endl;
  cout<<rbt.predecessor(1)<<endl;




}
