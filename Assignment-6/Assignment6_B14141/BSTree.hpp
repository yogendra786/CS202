#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "Dictionary.hpp"
#include<cstring>
#include<stdlib.h>
//#include "AVL.hpp"

enum Color {RED, BLACK};
template<class Key,class Value>
class Node{
      
      public:
         Key key;
         Color color;
         Value value;
         Node<Key,Value> *left;
         Node<Key,Value> *right;
         Node<Key,Value> *parent;
         int height;
         int blh;
 };
//template<class Key,class Value>
//typedef Node node_ptr;


        

template <class Key,class Value>
class BSTree : public Dictionary<Key, Value>
 {
 
    private:   
         Node<Key,Value> *root;
         int count;
         //typedef Node<Key,Value>* node_ptr; 
    public:
        /*
         * This method returns the current height of the binary search tree.
         */
        virtual int getHeight(){
                       int ld=maxdepleft();
                       int rd=maxdepright();
                       if(count==0)
                            return 0;
                       if(rd>=ld)
                            return rd;
                       else return ld;
        }
        /*
         *  This method returns the total number of elements in the binary search tree.
         */
        virtual int size(){
                     return count;
        }
        /*
         * This method prints the key value pairs of the binary search tree, sorted by
         * their keys.
         */
       virtual void print();
        /*
         *This method takes as an argument a function func.
         *Then it traverses along the tree in in-order traversal, and calls func
         *with every key value pair in the BSTree.
         */
         virtual void in_order(void (*fun)(const Key& key, const Value& value)){
               IN_ORDER(fun,root);
         }
         virtual void IN_ORDER(void (*fun)(const Key& key, const Value& value),Node<Key,Value> *root)
       {
       		if(root==NULL)
       			return;
       		IN_ORDER(fun,root->left);
       		fun(root->key,root->value);
       		IN_ORDER(fun,root->right);
       }

        /*
         *This method takes as an argument a function func.
         *Then it traverses along the tree in pre-order traversal, and calls func
         *with every key value pair in the BSTree.
         */
         virtual void pre_order(void (*fun)(const Key& key, const Value& value)){
               PRE_ORDER(fun,root);
         }
         virtual void PRE_ORDER(void (*fun)(const Key& key, const Value& value),Node<Key,Value> *root)
       {
       		if(root==NULL)
       			return;
       		fun(root->key,root->value);
       		PRE_ORDER(fun,root->left);
       		PRE_ORDER(fun,root->right);
       }

        /*
         *This method takes as an argument a function func.
         *Then it traverses along the tree in post-order traversal, and calls func
         *with every key value pair in the BSTree.
         */
         virtual void post_order(void (*fun)(const Key& key, const Value& value)){
                POST_ORDER(fun,root);
         }
         virtual void POST_ORDER(void (*fun)(const Key& key, const Value& value),Node<Key,Value> *root)
       {
       		if(root==NULL)
       			return;
       		POST_ORDER(fun,root->left);
       		POST_ORDER(fun,root->right);
       		fun(root->key,root->value);
       }
        /*
         *This method print all the key value pairs of the binary search tree, as
         *observed in an in order traversal.
         */
         virtual void print_in_order(){
                         inorder(root);
         }
        /*
         *This method print all the key value pairs of the binary search tree, as
         *observed in an pre order traversal.
         */
         virtual void print_pre_order(){
                        preorder(root);
         }
         virtual void print_level_order(){
                       printLevelOrder(root);
         }
        /*
         *This method print all the key value pairs of the binary search tree, as
         *observed in a post order traversal.
         */
         virtual void print_post_order() {
                       postorder(root);
         }
        /*
         *This method returns the minimum element in the BST.
         */
        virtual Key minimum();
        /*
         * This method returns the maximum element in the BST.
         */
        virtual Key maximum();
        /*
         *This method returns the successor, i.e, the next larget element in the
         *BSTree, after Key.
         */
        virtual Key successor(const Key& key);
       /*
        * This method returns the predessor, ie, the next smallest element in the
        * BSTree, after Key.
        */
       virtual Key predecessor(const Key& key);
       virtual Node<Key,Value>* newNode(const Key& key, const Value& value);
       virtual Node<Key,Value>* insert(Node<Key,Value>* root,const Key& key, const Value& value);
       virtual void put(const Key& key, const Value& value);
       BSTree();
       virtual void inorder(Node<Key,Value>* root);
       virtual void preorder(Node<Key,Value>* root);
       virtual void postorder(Node<Key,Value>* root);
       virtual bool has(const Key& key);
       virtual bool Search(Node<Key,Value>* root,const Key& key);
       virtual Value get(const Key& key);
       virtual Node<Key,Value>* Find(Node<Key,Value>* root,const Key& key);
       virtual void remove(const Key& key);
       virtual Node<Key,Value>* Delete(Node<Key,Value>* root,const Key& key);
       virtual Node<Key,Value>* FindMin( Node<Key,Value>* root);
       virtual Node<Key,Value>* getSuccessor( Node<Key,Value>* root,const Key& key);
       virtual Node<Key,Value>* getpredecessor( Node<Key,Value>* root,const Key& key);
       virtual Node<Key,Value>* maxValue(Node<Key,Value>* root);
       virtual void printLevelOrder(Node<Key,Value>* root);
       virtual int height1(Node<Key,Value>* root);   
       virtual void printGivenLevel(Node<Key,Value>* root, int level);
       virtual int maxdepleft(){
                 Node<Key,Value>* temp;
                 temp=root;
                 int ld=0;
                 while(temp!=NULL){
                      temp=temp->left;
                      ld++;
                 }
                 return ld;
       }           
       virtual int maxdepright(){
                 Node<Key,Value>* temp;
                 temp=root;
                 int rd=0;
                 while(temp!=NULL){
                       temp=temp->right;
                       rd++;
                 }
                 return rd;
       }
      virtual int height(Node<Key,Value>* root){ 
                 Node<Key,Value>* temp=root;
                 if(temp==NULL)
                      return 0;
                 return temp->height;
      }
      virtual int max(int a, int b){
                 return (a > b)? a : b;
      }


 };





 template <class Key,class Value>
 Node<Key,Value>* BSTree<Key,Value>::maxValue(Node<Key,Value>* root){
        Node<Key,Value>* temp= root;
        while(temp->right!=NULL)temp=temp->right;
             return temp;
 }      


 template <class Key,class Value>
 Key BSTree<Key,Value>::predecessor(const Key& key){
       if(has(key)){
             Node<Key,Value>* temp;
             temp= getpredecessor(root,key);
             return temp->key;}
             else return 0;

 }


 template <class Key,class Value>
 Node<Key,Value>* BSTree<Key,Value>:: getpredecessor( Node<Key,Value>* root,const Key& key){
       Node<Key,Value>* temp=root;
       Node<Key,Value>* current = Find(temp,key);
       if(current == NULL) return NULL;
       if(current->left != NULL){  
	    return maxValue(current->left); 
       }
       else{   
            Node<Key,Value>* predecessor = NULL;
	    Node<Key,Value>* ancestor = temp;
            while(ancestor != current) {
		     if(current->key > ancestor->key){
			      predecessor = ancestor; 
			      ancestor = ancestor->right;
		      }
		      else
			      ancestor = ancestor->left;
		      
	     }
             return predecessor;
       }
 }


 template <class Key,class Value>
 Key BSTree<Key,Value>::successor(const Key& key){
      if(has(key)){
          Node<Key,Value>* temp;
          temp= getSuccessor(root,key);
          return temp->key;
      }
      else return 0;
 } 


 template <class Key,class Value>
 Node<Key,Value>* BSTree<Key,Value>:: getSuccessor( Node<Key,Value>* root,const Key& key){
       Node<Key,Value>* temp=root;
       Node<Key,Value>* current = Find(temp,key);
       if(current == NULL) return NULL;
       if(current->right != NULL) {  
	   return FindMin(current->right); 
       }
       else {   
	   Node<Key,Value>* successor = NULL;
	   Node<Key,Value>* ancestor = temp;
	   while(ancestor != current) {
		   if(current->key < ancestor->key) {
			    successor = ancestor; 
			    ancestor = ancestor->left;
		    }
		    else
			    ancestor = ancestor->right;
	   }
           return successor;
       }
 }


 template <class Key,class Value>
 void BSTree<Key,Value>::remove(const Key& key){
        //std::cout<<root->key<<std::endl;
        root=Delete(root,key);
       // std::cout<<root->key<<std::endl;
        count--;
 }


 template <class Key,class Value>
 Node<Key,Value>* BSTree<Key,Value>:: Delete(Node<Key,Value>* root,const Key& key){
       if(root == NULL) return root; 
	else if(key < root->key) root->left = Delete(root->left,key);
	else if (key > root->key) root->right = Delete(root->right,key);	
	else {
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		else if(root->left == NULL) {
			Node<Key,Value>* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			Node<Key,Value>* temp = root;
			root = root->left;
			delete temp;
		}
		else { 
			Node<Key,Value>* temp = FindMin(root->right);
			root->key = temp->key;
                        root->value=temp->value;
			root->right = Delete(root->right,temp->key);
		}
	}
	return root;
 }


 template <class Key,class Value>
 Node<Key,Value>* BSTree<Key,Value>::FindMin( Node<Key,Value>* temp){
      while(temp->left != NULL) temp = temp->left;
	return temp;

 }


 template <class Key,class Value>
 bool BSTree<Key,Value>::has(const Key& key){
       if(Search(root,key))
          return true;
       else 
          return false;
 }


 template <class Key,class Value>
 bool BSTree<Key,Value>::Search(Node<Key,Value>* root,const Key& key){
       Node<Key,Value>* temp;
       temp=root;
       if(temp == NULL) {
	   return false;
       }
       else if(temp->key == key) {
	   return true;
       }
       else if(key <= temp->key) {
	   return Search(temp->left,key);
       }
       else {
	   return Search(temp->right,key);
       }    
 }


 template <class Key,class Value>
 Node<Key,Value>*  BSTree<Key,Value>::Find(Node<Key,Value>* root,const Key& key){
       Node<Key,Value>* temp;
       temp=root;
       if(temp == NULL) {
	    return NULL;
        }
	else if(temp->key == key) {
	    return temp;
	}
	else if(key <= temp->key) {
	    return Find(temp->left,key);
	}
	else {
	    return Find(temp->right,key);
	}
 }


 template <class Key,class Value>
 Value BSTree<Key,Value>::get(const Key& key){      
       Node<Key,Value>* temp;
       temp=root;
       temp=Find(temp,key);
       if(temp==NULL)
           return "Not Found";           
       return  temp->value;
 }            


 template <class Key,class Value>
 void BSTree<Key,Value> :: put(const Key& key, const Value& value){
      if(!(has(key))){
           root=insert(root,key,value);
           //std::cout<<root->key<<std::endl;
           //std::cout<<root->key<<std::endl;
           count++;
      }
      else
    {
      
std::cout << "Already have a key " <<std:: endl;
      
 
return;
    }
 }


 template <class Key,class Value>
 Node<Key,Value>* BSTree<Key,Value> :: insert(Node<Key,Value>* root,const Key& key, const Value& value){
      if(root==NULL)
          return newNode(key,value);
    if(key < root->key)
          root->left=insert(root->left,key,value); 
    else if(key > root->key)
          root->right=insert(root->right,key,value);
    root->height=max(height(root->left),height(root->right)) +1;
    return root;
 }

 template <class Key,class Value>
 Node<Key,Value>* BSTree<Key,Value> :: newNode(const Key& key, const Value& value){
      Node<Key,Value>* temp= new Node<Key,Value>() ;
      temp->key=key;
      temp->value=value;
      temp->color=RED;       
      temp->height=1;
      temp->left=NULL;
      temp->right=NULL;
      temp->parent=NULL;
      return temp;
 }


 template <class Key,class Value>
 BSTree<Key,Value>::BSTree(){
      root=NULL;
      count=0;
 }


 template <class Key,class Value>
 void BSTree<Key,Value>::print(){
     inorder(root);
 }


template <class Key,class Value>
void BSTree<Key,Value>::printLevelOrder(Node<Key,Value>* root)
{
    int h = height1(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 

template <class Key,class Value>
void BSTree<Key,Value>::printGivenLevel(Node<Key,Value>* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1){
        std:: cout<< root->key<<" : "<<root->value;
           if(root->color==0)std::cout<<" : RED : ";
           else std::cout<<" : BLACK : ";
           std::cout<<root->blh<<std::endl;
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

template <class Key,class Value>
int BSTree<Key,Value>::height1(Node<Key,Value>* root)
{
    if (root==NULL)
        return 0;
    else
    {
        
        int lheight = height1(root->left);
        int rheight = height1(root->right); 
        
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}


 template <class Key,class Value>
 void BSTree<Key,Value>:: inorder(Node<Key,Value>* root){
     if (root != NULL){
           inorder(root->left);
           std:: cout<< root->key<<" : "<<root->value;
           if(root->color==0)std::cout<<" : RED : ";
           else std::cout<<" : BLACK : ";
           std::cout<<root->blh<<std::endl;
           inorder(root->right);
     }
  }


 template <class Key,class Value>
 void BSTree<Key,Value>:: preorder(Node<Key,Value>* root){
     if (root != NULL){
           std:: cout<< root->key<<" : "<<root->value;
           if(root->color==0)std::cout<<" : RED : ";
           else std::cout<<" : BLACK : ";
           std::cout<<root->blh<<std::endl;
           preorder(root->left);       
           preorder(root->right);
      } 
 }

 template <class Key,class Value>
 void BSTree<Key,Value>:: postorder(Node<Key,Value>* root){
     if (root != NULL){
           postorder(root->left);
           postorder(root->right);
           std:: cout<< root->key<<" : "<<root->value;
           if(root->color==0)std::cout<<" : RED : ";
           else std::cout<<" : BLACK : ";
           std::cout<<root->blh<<std::endl;        
      }
 }


 template <class Key,class Value>
 Key BSTree<Key,Value>:: minimum(){
           Node<Key,Value>* temp;
           temp=root;
           while(temp->left!=NULL){
                  temp=temp->left;
           }
           return temp->key;
 }


 template <class Key,class Value>
 Key BSTree<Key,Value>:: maximum(){
           Node<Key,Value>* temp;
           temp=root;
           while(temp->right!=NULL){
                  temp=temp->right;
           }
           return temp->key;
 }
   


#endif /* ifndef BSTREE_HPP */
