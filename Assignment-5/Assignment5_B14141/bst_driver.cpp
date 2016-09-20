#include<iostream>
#include "BSTree.hpp"
#include<cstring>


using namespace std;

/*void func(const Key& key, const Value& value){
     cout<<key<<" : "<<value;


}*/


int main(){
    
    int key,value;
    BSTree<int,string> bst;
    //cin>>key>>value;
   bst.put(10,"Yogendra");
   bst.put(22,"Kumar");
   bst.put(14,"Dhiwar");
   bst.put(24,"25");
   bst.put(12,"13");
   bst.put(20,"21");
   bst.put(18,"19");
   bst.put(18,"17");
  cout<<bst.minimum()<<endl;
  cout<<bst.maximum()<<endl;
  if(bst.has(14))cout<<"present\n";
     else cout<<"not present\n";
  
   if(bst.has(9))cout<<"present\n";
     else cout<<"not present\n";

   if(bst.has(8))cout<<"present\n";
     else cout<<"not present\n";

  if(bst.has(18))cout<<"present\n";
     else cout<<"not present\n";

   cout<<bst.get(22)<<endl;
   cout<<bst.get(24)<<endl;
   cout<<bst.get(25)<<endl;
   cout<<bst.get(21)<<endl;

   cout<<bst.size()<<endl;
   bst.print();

   bst.remove(12);
   bst.remove(18);

   cout<<endl;
   cout<<endl;
  
   bst.print();

  cout<<endl;
  cout<<endl;

  cout<<bst.successor(20)<<endl;
  cout<<bst.successor(16)<<endl;
  cout<<bst.predecessor(22)<<endl;
  cout<<bst.predecessor(16)<<endl;

  cout<<endl;
  cout<<endl;

  cout<<bst.size()<<endl;

   cout<<endl;
  cout<<endl;
   
   bst.print_in_order();

cout<<endl;
  cout<<endl;
  bst.print_pre_order();

cout<<endl;
  cout<<endl;

  bst.print_post_order();

   cout<<endl;
    cout<<bst.getHeight()<<endl;

  cout<<endl;
  bst.print_level_order();

   
    

}
