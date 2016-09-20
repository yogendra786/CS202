#include<iostream>
#include<cstring>
#include "RBTree.hpp"


using namespace std;

int main(){

     RBTree<int,string> rbt;
     string inp;
     int choice;
     string value;
     int flag1=0;
     int key,loop=0;
     
     cout<<"----------------------------------------Dictionary Data Structures---------------------------------------"<<endl;
     cout<<endl;
     
                         cout<<"--------------------RED-BLACK Tree-------------------"<<endl;
                         cout<<"---------------------------------------------------------"<<endl;
                         cout<<endl;
                         while(loop!=1){
                         cout<<"1).Insert a key\n2).Search for a key\n3).Delete a key along  with color\n4).Display all the keys with color and black height as obserbed in inorder traversal\n5).Display all the keys with color and black height as obserbed in preorder traversal\n6).Display all the keys with color and black height as obserbed in postorder traversal\n7).Display all the keys with color and black height as obserbed in levelorder traversal\n8).Display the minimum key along with color and black height in a tree\n9).Display the maximum key along with color and black height in a tree\n10).Display the successor of a key along with color and black height\n11).Display the predecessor of a key along with color and black height\n12).Display the height of a tree\n13).Display the black height of a tree\n14).Exit\n\n";
                         cout<<"Enter your choice"<<endl;
                         cin>>choice;
                         while(cin.fail()){
                               cout << "Error!" <<endl;
                               cin.clear();
                               cin.ignore(256,'\n');
                               cout<<"Enter your choice"<<endl;
                               cin >> choice;
                          }
                           switch(choice){
  
                               case 1 :
                                          cout<<"Enter key and value (only unique keys will be accepted and should be integer)"<<endl;
                                          cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Enter key and value (only unique keys will be accepted and should be integer)"<<endl;
                                              cin >> key;
                                          }
                                          cin>>value;
                                          rbt.put(key,value);
                                          break;

                               case 2 :
                                          cout<<"Insert key to search"<<endl;
                                          cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Insert key to search"<<endl;
                                              cin >> key;
                                          }
                                          if(rbt.has(key)){
                                               cout<<key<<" : "<<rbt.get(key)<<endl;
                                          }
                                          else cout<<"Key is not present"<<endl;
                                          break;

                               case 3 :
                                         cout<<"Insert key to delete"<<endl;
                                         cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Insert key to delete"<<endl;
                                              cin >> key;
                                          }
                                          if(rbt.has(key)){
                                                   rbt.remove(key);
                                                   cout<<"Deleted Successfully\n";
                                          }
                                          else cout<<"Key is not present"<<endl;
                                          break;
                                        
                               case 4 :
                                         cout<<"Key-Value pairs through Inorder Traversal\n";
                                         rbt.print_in_order();
                                         cout<<endl;
                                         break;

                               case 5 : 
                                         cout<<"Key-Value pairs through Preorder Traversal\n";
                                         rbt.print_pre_order();
                                         cout<<endl;
                                         break;

                               case 6 :
                                         cout<<"Key-Value pairs through Postorder Traversal\n";
                                         rbt.print_post_order();
                                         cout<<endl;
                                         break;

                               case 7 :
                                         cout<<"Key-Value pairs through Levelorder Traversal\n";
                                         rbt.print_level_order();
                                         cout<<endl;
                                         break;

                               case 8 :
                                         cout<<"Minimum key present is along with black height "<<rbt.minimum()<<" : "<<rbt.blh_min()<<endl;
                                         break;
                         
                               case 9 :
                                         cout<<"Maximum key present is along with black height"<<rbt.maximum()<<" : "<<rbt.blh_max()<<endl;
                                         break;

                               case 10 :
                                        cout<<"Insert key to find its successor"<<endl;
                                        cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Insert key to find its successor"<<endl;
                                              cin >> key;
                                          }
                                        if(rbt.has(key)){
                                               if(key==rbt.maximum()){
                                                      cout<<"No successor is present bcoz you entered maximum key in the tree\n";
                                               }
                                               else
                                                      cout<<"Successor of the Key along with black height is "<<rbt.successor(key)<<" : "<<rbt.blackHeight1(key)<<endl;
                                        }
                                        else cout<<"Key is not present\n";
                                        break;

                              case 11 : 
                                       cout<<"Insert key to find its predecessor"<<endl;
                                        cin>>key;
                                          while(cin.fail()){
                                              cout << "Error!" <<endl;
                                              cin.clear();
                                              cin.ignore(256,'\n');
                                              cout<<"Insert key to find its predecessor"<<endl;
                                              cin >> key;
                                          }
                                        if(rbt.has(key)){
                                               if(key==rbt.minimum()){
                                                      cout<<"No predecessor is present bcoz you entered minimum key in the tree\n";
                                               }
                                               else
                                                      cout<<"Predecessor of the Key along with black height is "<<rbt.predecessor(key)<<" : "<<rbt.blackHeight1(key)<<endl;
                                        }
                                        else cout<<"Key is not present\n";
                                        break;

                              case 12 :
                                        cout<<"Height of the tree is "<<rbt.getHeight()<<endl;
                                        break;
                              
                              case 13 :
                                       cout<<"Black Height of the tree is "<<rbt.treeblheight()<<endl;
                                       break;
                           
                              case 14:
                                      loop=1;
                                        break;

                              default :
                                       cout<<"Enter valid Choice\n";
                                       break;
                       }
               }
               
    cout<<"---------------------------------------------THANKS FOR USING-------------------------------------------------------------"<<endl;

  

 

return 0;

} 
    
    
         
                                          

                       

