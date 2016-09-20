#ifndef STACK_HPP_
#define STACK_HPP_
#include <cassert>
namespace pratap
{
  template<typename T>
    class stack
    {
              private:
                     class Node {
                             friend class stack<T>;

                             private:
                                 T data;
                                 Node* next;

                             public:
                                  Node(T d, Node* n = NULL) : data(d), next(n) {}
                                  };

                     Node* head; 
                     int count;  

               public: 
                     void Push(const T& t);
                     T Pop();        
                     inline int size(void) {
                                     return count;
                     }        
                     ~stack(void); 
                     stack(void) : head(NULL),count(0){}                     
                     inline bool IsEmpty(void) {
                                     return count == 0;
                     }
                     T Top();
                     void dump(void);
      
        
       
    };

   template<typename T>
   void stack<T>::Push(const T& t){
                  Node* new_head = new Node(t,head);

                    if(this->IsEmpty()){
                            head = new_head;
                     }
                   else {
                            head = new_head;
                   }
                  count++;
   } 
  
   template<typename T>
   T stack<T>::Pop(){
   
         assert(head != NULL);
           Node* temp;
           temp=head;
           head=head->next;
           count--;
           return temp->data;
           
    }
    
   template<typename T>
   T stack<T>::Top(){
 
           return head->data;
    }

   template<typename T>
   void stack<T>::dump(){
            Node* temp;
            temp=head;
            while(temp!=NULL){
                  std::cout<<temp->data<<std::endl;
                  temp=temp->next;
             }
    }

   template<typename T>
   stack<T>::~stack(){
                while(!this->IsEmpty()){
                         this->Pop();
                }
   }

}

#endif
