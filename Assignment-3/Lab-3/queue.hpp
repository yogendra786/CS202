#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <cassert>

namespace pratap{
   
     template <typename T>
     class queue {
 
                private:
                     class Node {
                             friend class queue<T>;

                             private:
                                T data;
                                Node* next;

                             public:
                                Node(T d, Node* n = NULL) : data(d), next(n) {}
                                };

                     Node* head; 
                     Node* tail; 
                     int count;  

               public:
                     
                     ~queue(void); 
                     queue(void) : head(NULL), tail(NULL), count(0) {}
                     inline int size(void) {
                                     return count;
                     }
                     inline bool empty(void) {
                                     return count == 0;
                     }
                     void push(const T& value);
                      T pop();        
                     T front();
                     void dump(void);
      };

      
      
       template<typename T>
       void queue<T>::push(const T& t){ 

                Node* new_tail = new Node(t, NULL);

                if(this->empty()) {
                          head = new_tail;
                } 
               else {
                         tail->next = new_tail;
               }

               tail = new_tail;
               count++;
       }

       
       template<class T>
   T queue<T>::pop(){
              Node* temp;
              temp=head;
              int x=temp->data;
              head=head->next;
             
              delete(temp);
              count--;
              return x;
   }
   
   template<class T>
   T queue<T>::front(){
              return head->data;
   }
  
        template <typename T>
        void queue<T>::dump() {
    
         std::cout << "(";

        Node* current = head;

     if (current != NULL) {
   
        while (current->next != NULL) {
            std::cout << current->data << ", ";
            current = current->next;
        }
        std::cout << current->data;
    }

    std::cout << ")"<<std:: endl;
     }

  template<typename T>
   queue<T>::~queue(){
                while(!this->empty()){
                         this->pop();
                }
   }





           
}    


#endif


