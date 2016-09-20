#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"
#include<cstring>
template < class Key, class Value > 
class AVL:public BSTree < Key, Value >
 {
  
    /*
     * Inherit as much functionality as possible from the BSTree class.
     * Then provide custom AVL Tree functionality on top of that.
     * The AVL Tree should make use of as many BST functions as possible.
     * Override only those methods which are extremely necessary.
     */ 
    /*
     * Apart from that, your code should have the following four functions:
     * getBalance(node) -> To get the balance at any given node;
     * doBalance(node) -> To fix the balance at the given node;
     * rightRotate(node) -> Perform a right rotation about the given node.
     * leftRotate(node) -> Perform a left rotation about the given node.
     *
     * The signature of these functions are not provided in order to provide you
     * some flexibility in how you implement the internals of your AVL Tree. But
     * make sure these functions are there.
     */
public:  
      int getBalance (Node < Key, Value > *root); 
      Node < Key, Value > *leftRotate (Node < Key, Value > *root);  
      Node < Key, Value > *rightRotate (Node < Key, Value > *root);
      Node < Key, Value >* doBalance (Node < Key, Value > *root, const Key & key);  
      Node < Key, Value > *insert (Node < Key, Value > *root, const Key & key,const Value & value) ;
      Node < Key, Value > *Delete (Node < Key, Value > *root, const Key & key);
 };


template < class Key, class Value > 
int AVL < Key, Value >::getBalance (Node < Key, Value > *root)
  {   
       if (root == NULL)        
            return 0;    
       return BSTree<Key,Value>::height (root->left) - BSTree<Key,Value>::height (root->right);  
  }


 
template < class Key, class Value > 
Node < Key, Value > *AVL < Key, Value >::leftRotate (Node < Key, Value > *root)
 {
       Node < Key, Value > *temp = root->right;  
       Node < Key, Value > *temp2 = temp->left;  
       temp->left = root;  
       root->right = temp2;
       root->height = BSTree<Key,Value>::max (BSTree<Key,Value>::height (root->left), BSTree<Key,Value>::height (root->right)) + 1;  
       temp->height = BSTree<Key,Value>::max (BSTree<Key,Value>::height (temp->left), BSTree<Key,Value>::height (temp->right)) + 1; 
       return temp; 
 }
 
 
template < class Key, class Value > 
Node < Key, Value > *AVL < Key, Value >::rightRotate (Node < Key, Value > *root)
 { 
      Node < Key, Value > *temp = root->left;  
      Node < Key, Value > *temp2 = temp->right; 
      temp->right = root;  
      root->left = temp2; 
      root->height = BSTree<Key,Value>::max (BSTree<Key,Value>::height (root->left), BSTree<Key,Value>::height (root->right)) + 1;  
      temp->height = BSTree<Key,Value>::max (BSTree<Key,Value>::height (temp->left), BSTree<Key,Value>::height (temp->right)) + 1; 
      return temp;
 }

 
template < class Key, class Value > 
Node < Key, Value >* AVL < Key, Value >::insert (Node < Key, Value > *root, const Key & key, const Value & value)
 {
     if (root == NULL)
        return(BSTree < Key, Value >::newNode (key,value)); 
     if (key < root->key)
        root->left  = insert(root->left, key,value);
     else
        root->right = insert(root->right, key,value);

    root->height = BSTree<Key,Value>::max(BSTree<Key,Value>::height(root->left), BSTree<Key,Value>::height(root->right)) + 1;
    //std::cout<<root->height<<std::endl;
    return doBalance(root,key);
 }

template < class Key, class Value > 
Node < Key, Value > *AVL < Key, Value >::Delete (Node < Key, Value > *root, const Key & key)
 {
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
			Node<Key,Value>* temp = BSTree<Key,Value>::FindMin(root->right);
			root->key = temp->key;
                        root->value=temp->value;
			root->right = Delete(root->right,temp->key);
		}
	}
        
	
   
  
  return doBalance(root,key);
 }
  
   
template < class Key, class Value > 
Node < Key, Value >* AVL < Key, Value >::doBalance (Node < Key, Value > *root, const Key & key) 
 {
   if (root == NULL)
      return root;
 
    
   root->height = BSTree<Key,Value>::max(BSTree<Key,Value>::height(root->left), BSTree<Key,Value>::height(root->right)) + 1;
    //std::cout<<root->height<<std::endl;
  int balance = getBalance (root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);    
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }   
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);    
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    } 
    return root;
 }



 
 
 
 
 
#endif	/* ifndef AVL_HPP */
