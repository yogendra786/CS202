#ifndef _list_H_
#define _list_H_
#include <cassert>

namespace pratap{
   
     template <typename T>
     class list {
 
                private:
                     class Node {
                             friend class list<T>;

                             private:
                             T data;
                             Node* next;

                             public:
                             Node(T d, Node* n = NULL) : data(d), next(n) {}
                             };

                     Node* head; 
                     Node* tail; 
                     int count;
                     int c;  

               public:
                     list(const list<T>& x);  
                     ~list(void); 
                     list(void) : head(NULL), tail(NULL), count(0) ,c(0){}
                     inline int length(void) {
                                     return count;
                     }
                     inline bool empty(void) {
                                     return count == 0;
                     }
                     void cons(const T& value);
                     void remove(const T & x);
                     bool has(const T & x){
                              Node* temp;
                              temp=head;
                              while(temp!=NULL){
                                       if(temp->data==x){
                                               return 1;
                                        }
                                    temp=temp->next;
                              }
                              return 0;
                     }
                     int pos(const T & x){
                            Node* temp;
                              temp=head;
                              int p=1;
                              while(temp!=NULL){
                                       if(temp->data==x){
                                               return p;
                                        }
                                    temp=temp->next;
                                    p++;
                              }
                              return 0;
                     }
                     void append(const T& value);
                     void append(list<T>& x);
                     void dump(void);
                      T& front(void) {
                           assert (head != NULL);
                           return head->data;
                     }
                   T& next(void){
                            assert(head != NULL);
                            Node* temp;
                            temp=head;
                            head=head->next;
                            count--;
                            return temp->data;
                               }
                 
                             
                 T& next2(const T& i){
                            assert(head != NULL);
                            Node* temp;
                            temp=head;
                            //int k=1;
                            for(int j=1;j<i;j++){
                                   if(temp!=NULL)
                                      temp=temp->next;
                                    else
                                       break;
                             }
                             if(temp!=NULL)
                                   return temp->data;
                             //else return k;
                           
                 }
         };

      template<typename T>
      void list<T>:: cons(const T& value){

                  Node* new_head = new Node(value,head);

                    if(this->empty()){
                            head = new_head;
                            tail = new_head;
                     }
                   else {
                            head = new_head;
                   }
                  count++;

       }

       template<typename T>
       void list<T>:: remove(const T & x){

                 assert(head != NULL); 
                 Node  *current = head;

	         for (int  i=1;  i < x-1;  i++){
			current = current -> next;
	         }
	         Node  *p = head;
                 if(x==1){
                      head=head->next;
                 }
                else{        
	              p = current -> next;
	              current -> next = p -> next;
                }
	        delete  p;
                count--;
       }

       template<typename T>
       void list<T>::append(const T& value){ 

                Node* new_tail = new Node(value, NULL);

                if(this->empty()) {
                          head = new_tail;
                } 
               else {
                         tail->next = new_tail;
               }

               tail = new_tail;
               count++;
       }

       template<typename T>
       void list<T>::append(list<T>& x){

               Node *temp ;

               if ( head == NULL )
                      head = x.head ;
               else{
                     if ( x.head != NULL ){
                                temp = head ;
                                while ( temp -> next != NULL )
                                        temp = temp -> next ;
                                temp -> next= x.head ;  

                     }
               }       

        }

        template<typename T>
        list<T>::~list(){
 
                int k=count;
                while(!this->empty()){
                         this->remove(k);
                         k--;
                }
        }

        template<typename T>
        list<T>::list(const list<T> & x) : count(0),head(NULL), tail(NULL){
 
                  Node* current = x.head;

                  while(current != NULL){
                        this->append(current->data);
                        current=current->next;
                  }
         }

        template <typename T>
        void list<T>::dump() {
    
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

   


           
}    


#endif


