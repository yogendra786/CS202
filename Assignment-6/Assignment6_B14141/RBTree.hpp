#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
#include<cstring>
#include<stdlib.h>

//#include "typedef.hpp"

/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree
 */
//enum Color { RED, BLACK };

template <class Key, class Value>
class RBTree : public  BSTree<Key,Value>{
      private:
              Node<Key,Value> *root;

      public:          
         
/* Inherit as many functions as possible from BSTree.
 * Only override those which absolutely need it.
 * Also make sure that all inherited functions work correctly in the context of a red black tree.
 * Node<Key,Value>* in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 * Use a typedef to refer to a pointer to your node via Node<Key,Value>*
 */

	/* Function : blackHeight
	 * 
	 * Returns:
	 * the black height of the red black tree which begins at Node<Key,Value>* root
	 */
        int blackHeight(Node<Key,Value>* h);

	/* Function insertRBFixup
	 *
	 * Used for:
	 * Used after an insertion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	void insertRBFixup(Node<Key,Value>* z);

/* Function deleteRBFixup
	 * Used for:
	 * Used after a deletion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBFixup(Node<Key,Value>* x);
	
	/*
	 * Apart from these functions, also provide functions for rotations in the tree.
	 * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 */
         Node<Key,Value>* insert(Node<Key,Value>* root,const Key& key, const Value& value);
         Node<Key,Value>* Delete(Node<Key,Value>* root,const Key& key);
         void rbtransplant(Node<Key,Value>* u,Node<Key,Value>* v);
         void leftRotate(Node<Key,Value>* x);
         void rightRotate(Node<Key,Value>* y);
         int blackHeight1(const Key& key);
         void postorder1(Node<Key,Value>* k);
         void blackheight_updater();
         int blh_min(){
              int k=BSTree<Key, Value>::minimum();
              return blackHeight1(k);
         }
         int blh_max(){
              int k=BSTree<Key, Value>::maximum();
              return blackHeight1(k);
         }
         int treeblheight();
         RBTree();

};
template <class Key,class Value>
 void RBTree<Key,Value>:: postorder1(Node<Key,Value>* k){
     if (k != NULL){
           postorder1(k->left);
           postorder1(k->right);
           k->blh=blackHeight1(k->key);        
      }
 }

template <class Key, class Value>
void RBTree<Key,Value>::blackheight_updater(){
           Node<Key,Value>* k=root;
           postorder1(k);
          // cout<<k-
}
           
template <class Key, class Value>
int RBTree<Key,Value>::treeblheight(){
     Node<Key,Value>* k=root;
     return blackHeight(k);
}
template <class Key, class Value>
int RBTree<Key,Value>::blackHeight1(const Key& key){
       Node<Key,Value>* k=BSTree<Key, Value>::Find(root,key);
       return blackHeight(k);
}


template <class Key, class Value>
int RBTree<Key,Value>::blackHeight(Node<Key,Value>* h){

int c=0;
h=h->left;
while(h!=NULL){
    if(h->color==BLACK)
          c++;
    h=h->left;
}
return c;

}





template <class Key, class Value>
RBTree<Key,Value>::RBTree(){
    root=NULL;
}
template <class Key, class Value>
Node<Key,Value>* RBTree<Key,Value>::Delete(Node<Key,Value>* root,const Key& key){
 Node<Key,Value>* z= BSTree<Key,Value>::Find(root,key);
 Node<Key,Value>* y=z;
 bool y_ori_color=y->color;
 Node<Key,Value>* x;
if(z->left==NULL){
   x=z->right;
   rbtransplant(z,z->right);
}
else if(z->right==NULL){
       x=z->left;
       rbtransplant(z,z->left);
}

else {
          y=BSTree<Key, Value>::getSuccessor(root,z->key);
          y_ori_color=y->color;
          x=y->right;
          if(y->parent==z)
                 if(x!=NULL)
                 x->parent=y;
          else {
                 rbtransplant(y,y->right);
                 y->right=z->right;
                 if(y->right!=NULL)
                 y->right->parent=y;
           }
           rbtransplant(z,y);
           y->left=z->left;
           y->left->parent=y;
           y->color=z->color;
           //delete z;
   }

   blackheight_updater();
if(y_ori_color==BLACK)
   deleteRBFixup(x);


return this->root;

}

template <class Key, class Value>
void RBTree<Key,Value>::rbtransplant(Node<Key,Value>* u,Node<Key,Value>* v){
if(u->parent==NULL)
    root=v;
else if(u==u->parent->left)
          u->parent->left=v;
else u->parent->right=v;

if(v!=NULL)
v->parent=u->parent;

}



template <class Key, class Value>
void RBTree<Key,Value>:: deleteRBFixup(Node<Key,Value>* x){
  Node<Key,Value>* w;
  while(x!=NULL and x!=root and x->color==BLACK){
         if(x==x->parent->left){
               w=x->parent->right;
               if(w->color==RED){
                     w->color=BLACK;
                     x->parent->color=RED;
                     leftRotate(x->parent);
                     w=x->parent->right;
                }
                if(w!=NULL and w->left->color==BLACK and w->right->color==BLACK){
                     w->color=RED;
                     x=x->parent;
                 }
                 else if(w->right->color==BLACK){
                    w->left->color=BLACK;
                    w->color=RED;
                    rightRotate(w);
                    w=x->parent->right;
                 }
                 w->color=x->parent->color;
                 x->parent->color= BLACK;
                 w->right->color= BLACK;
                 leftRotate(x->parent);
                 x=root;
        }
         else{
               w=x->parent->left;
               if(w->color==RED){
                     w->color=BLACK;
                     x->parent->color=RED;
                     rightRotate(x->parent);
                     w=x->parent->right;
                }
                if(w!=NULL and w->left->color==BLACK and w->right->color==BLACK){
                     w->color=RED;
                     x=x->parent;
                 }
                 else if(w->left->color==BLACK){
                    w->right->color=BLACK;
                    w->color=RED;
                    leftRotate(w);
                    w=x->parent->left;
                 }
                 w->color=x->parent->color;
                 x->parent->color= BLACK;
                 w->left->color= BLACK;
                 rightRotate(x->parent);
                 x=root;
         }

   }
  if(x!=NULL)
 x->color=BLACK;
 blackheight_updater();

}

             








template <class Key, class Value>
Node<Key,Value>* RBTree<Key,Value>:: insert(Node<Key,Value>* root,const Key& key, const Value& value){
    Node<Key, Value>* z =BSTree<Key, Value>:: newNode(key,value);
    Node<Key, Value>* y=NULL;
    Node<Key, Value>* x=root;
    while(x!=NULL){
              y=x;
              if(z->key < x->key)
                   x=x->left;
              else
                   x=x->right;
    }
    z->parent=y;
    if(y==NULL)
          this->root=z;
          
    else if(z->key < y->key)
             y->left=z;
    else
        y->right=z;
    
     insertRBFixup(z);

   return this->root;
    

}


template <class Key, class Value>
void RBTree<Key,Value>:: insertRBFixup(Node<Key,Value>* z){
  Node<Key,Value> *y;
    while(z != root and z->parent->color == RED and z->color!=BLACK){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right;
            if(y!=NULL and y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->right){
                    z = z->parent;
                    leftRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        }
        else{
            y = z->parent->parent->left;
            if(y!=NULL and y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->left){
                    z = z->parent;
                    rightRotate(z);
                }

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }



    root->color = BLACK;
     blackheight_updater();

}

template <class Key, class Value>
void RBTree<Key,Value>:: leftRotate(Node<Key,Value>* x){
     Node<Key,Value> *y = x->right;
    x->right = y->left;

    if(y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if(x->parent == NULL)
        root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

template <class Key, class Value>
void RBTree<Key,Value>:: rightRotate(Node<Key,Value>* y){
      Node<Key,Value> *x = y->left;
    y->left = x->right;

    if(x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if(y->parent == NULL)
        root = x;
    else if(y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x; 
}









         






#endif /* ifndef RBTree_HPP_ */
