#ifndef RB_TREE_H
#define RB_TREE_H  
#include<iostream>  
#include<string>
#include<sstream>  
#include<fstream>  
using namespace std;
template<class KEY  ,class U>
class RB_Tree
{
private:
        RB_Tree(const RB_Tree& input){}  
        const RB_Tree& operator=(const RB_Tree& input){} 
private:
        enum COLOR{RED,BLACK};
        class RB_Node
        {
        public:
                RB_Node():left(NULL),right(NULL),parent(NULL){}
                  COLOR RB_COLOR;
                  RB_Node*left;
                  RB_Node*right;
                  RB_Node*parent;
                  KEY key;
                  U date;
        };
public:
        RB_Tree():m_nullNode(new RB_Node),m_root(m_nullNode){}
        bool Empty()const
        {
                if(m_root==m_nullNode)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
        RB_Node*find(KEY key)
        {
                RB_Node* index = m_root;  
                while(index != m_nullNode)
                {
                        if (key<index->key)
                        {
                                index=index->left;
                        } 
                        else if(key>index->key)
                        {
                             index=index->right;
                        }
                        else
                        {
                                break;
                        }
                }
                return index;
        }
        //--------------------//插入结点的总操作//------------------------
  //全部的工作，都在下述伪代码中：///
        /*TREE-INSERT(T,z)
        1 y=T.nil
        2 x=T.root
        3 while x≠T.nil
        4     y=x
        5     if z.key<x.key
        6                  x=x.left
        7                  else   x=x.right
        8  z.p=y
        9  if y==T.nil
        10       T.root=z //tree Twas empty
        11 else if z.key<y.key
        12                y.left =z
        13 else y.right=z
        14 z.left=T.nil
        15 z.right =T.nil
        16 z.color=RED
        17 RB-INSERT-PIXUP(T.z)
        */
        //因为将z着为红色，可能会违反某一红黑性质。
        //所以需要下面的RB-INSERT-PIXUP(T.z)来保持红黑性质。
        bool Insert(KEY key, U date)
        {
                RB_Node *insert_point =m_nullNode;
                RB_Node *index=m_root;
                while(index!=m_nullNode)
                {
                        insert_point=m_root;
                        if (key<index->key)
                        {
                                index=index->left;
                        } 
                        else if(key>index->key)
                        {
                                index=index->right;
                        }
                        else
                        {
                                return false;
                        }
                }
                RB_Node* insert_node=new RB_Node();
                insert_node->key=key;
                insert_node->date=date;
                insert_node->RB_COLOR=RED;
                insert_node->right=m_nullNode;
                insert_node->left=m_nullNode;
                if (insert_point==m_nullNode)
                {
                        m_root=insert_node;
                        m_root->parent=m_nullNode;
                        m_nullNode->right=m_root;
                        m_nullNode->left=m_root;
                        m_nullNode->parent=m_root;
                }
                else
                {
                        if(key<insert_point->key)
                        {
                                insert_point->left=insert_node;
                        }
                        else
                        {
                                insert_point->right=insert_node;
                        }
                        insert_node->parent=insert_point;
                }
                 InsertFixup(insert_node);
        }
        //---------------------//插入结点性质修复//--------------------------------  
    //3种插入情况，都在下面的伪代码中(未涉及到所有全部的插入情况)。  
     /*  RB-INSERT-FIXUP(T, z) 
         1 while z.p.color==RED
         2        if z.p==z.p.p.left
         3             y=z.p.p.right
         4            if y.color==RED
         5                    z.p.color=BLACK                                         // case 1
     6                    y.color=BLACK                                           // case 1
         7                    z.p.p.color=RED                                        // case 1
         8                    z=z.p.p                                                       // case 1
         9             else if z==z.p.right
         10                        z=z.p                                                  // case 2
         11                        LEFT_ROTATE(T,z)                             // case 2
         12                   z.p.color=BLACK                                   // case 3
         13                  z.p.p.color=RED                                    // case 3
         14                  RIGHT-ROTATE(T,z.p.p)                       // case 3
         15            else(same as then clause
                                          with "right" and"left" exchanged)
         16 T.root.color=BLACK
         */
        void InsertFixup(RB_Node* node)
        {
                while(node->parent->RB_COLOR=RED)
                {
                        if (node->parent==node->parent->parent->left)
                        {
                                RB_Node* uncle=node->parent->parent->right;
                                        if (uncle->RB_COLOR==RED)//插入情况1，z的叔叔y是红色的。 
                                        {
                                                node->parent->RB_COLOR=BLACK;
                                                uncle->RB_COLOR=BLACK;
                                                node->parent->parent->RB_COLOR=RED;
                                                node=node->parent->parent;
                                        }
                                        else if (uncle->RB_COLOR==BLACK) //插入情况2：z的叔叔y是黑色的，。 
                                        {
                                                if (node==node->parent->right)
                                                {
                                                        node=node->parent;
                                                        RotateLeft(node);
                                                }
                                                else//插入情况3：z的叔叔y是黑色的，但z是左孩子。  
                                                {
                                                        node->parent->RB_COLOR = BLACK;  
                                                        node->parent->parent->RB_COLOR = RED;  
                                                        RotateRight(node->parent->parent);  
                                                }  
                                        }
                        }
                        else //这部分是针对为插入情况1中，z的父亲现在作为祖父的右孩子了的情况，而写的。  
                                //15 else (same as then clause with "right" and "left" exchanged)  
                        {  
                                RB_Node* uncle = node->parent->parent->left;  
                                if(uncle->RB_COLOR == RED)  
                                {  
                                        node->parent->RB_COLOR = BLACK;  
                                        uncle->RB_COLOR = BLACK;  
                                        uncle->parent->RB_COLOR = RED;  
                                        node = node->parent->parent;  
                                }  
                                else if(uncle->RB_COLOR == BLACK)  
                                {  
                                        if(node == node->parent->left)  
                                        {  
                                                node = node->parent;  
                                                RotateRight(node);     //与上述代码相比，左旋改为右旋 ; 
                                        }  
                                        else  
                                        {  
                                                node->parent->RB_COLOR = BLACK;  
                                                node->parent->parent->RB_COLOR = RED;  
                                                RotateLeft(node->parent->parent);   //右旋改为左旋，即可。  
                                        }  
                                }  
                        }  
                }
                m_root->RB_COLOR = BLACK; 
        }
        //////左旋////////////
        /*LEFT-ROTATE(T,x)
        1 y=x.right
        2 x.right=y.left
        3 if y.left≠T.nil
        4         y.left.p=x
        5 y.p=x.p
        6 if x.p==T.nil
        7        T.root=y
        8 else if x==x.p.left
        9          x.p.left=y
        10 else x.p.right=y
        11 y.left=x
        12 x.p=y
        */
         //左旋代码实现 ;
        bool RotateLeft(RB_Node *node)
        {
                if(node==m_nullNode||node->right==m_nullNode)
                {
                        return false;//can't rotate
                }
                RB_Node*lower_right=node->right;
                lower_right->parent=node->parent;
                node->right=lower_right->left;
                if (lower_right->left!=m_nullNode)
                {
                        lower_right->left->parent=node;
                }
                if (node->parent==m_nullNode)
                {
                        m_root=lower_right;
                        m_nullNode->left=m_root;
                        m_nullNode->right=m_root;
                } 
                else
                {
                        if ( node==node->parent->left)
                        {
                                node->parent->left=lower_right;
                        } 
                        else
                        {
                                node->parent->right=lower_right;
                        }
                }
                node->parent=lower_right;
                lower_right->left=node;
        }
          //////右旋////
        /*RIGHT-ROTATE(T,y)
        1x=y.left
        2y.left=x.right
        3 if x.right≠T.nil
        4         x.right.p=x
        5 x.p=y.p
        6 if y.p==T.nil
        7        T.root=x
        8 else if y==y.p.left
        9          y.p.left=x
        10 else y.p.right=x
        11 x.p.right=y
        12 y.p=x
        */
         //右旋代码实现 //
        bool RotateRight(RB_Node *node)
        {
                if(node==m_nullNode||node->left==m_nullNode)
                {
                        return false;//can't rotate
                }
                RB_Node*lower_left=node->left;
                node->left=lower_left->right;
                lower_left->parent=node->parent;
                if (lower_left->right!=m_nullNode)
                {
                 lower_left->right->parent=node;
                }
                if (node->parent==m_nullNode)
                {
                        m_root=lower_left;
                        m_nullNode->left=m_root;
                        m_nullNode->right=m_root;
                } 
                else
                {
                        if ( node==node->parent->right)
                        {
                                        node->parent->right=lower_left;
                        } 
                        else
                        {
                        node->parent->left=lower_left;
                        }
                }
                node->parent=lower_left;
                lower_left->right=node;
        }
        //--------------------------删除结点总操作--------------------------------
        /*RB-DEKETE(T,z)
        1 y=z
        2 y-original-color=y.color
        3 if x.left==T.nil
        4    x=z.right
        5   RB-TRANSPLANT(T,z,z.right)
        6 else if z.right==T.nil
        7      x=z.left
        8      RB-TRANSPLANT(T,z,z.right)
        9 else y=TREE-MINiMUM(z.right)
        10        y-original-color=y.color
        11        x=y.right
        12       if y.p==z
        13              x.p=y
        14        else RB-TRANSPLANT(T,y,y.right)
        15                y.right=z.right
        16               y.right.p=y
        17        RB-TRANSPLANT(T,z,y)
        18        y.left=z.left
        19        y.left.p=y
        20        y.color=z.color
        21  if y-original-color==BLACK
        22          RB-DELETB-FIXUP(T,x)
        */
        ///////////////////////////////////////
        bool Delete(KEY key)
        {
                RB_Node*delete_point=find(key);
                delete_point->RB_COLOR=find(key)->RB_COLOR;
                RB_Node*        delete_point_child;
                if(delete_point==m_nullNode)
                {
                        return false;
                }
                if  (delete_point->left==m_nullNode)
                {
                        delete_point_child=delete_point->right;
                        Transplant(delete_point,delete_point_child);
                }
                else if (delete_point->right=m_nullNode)
                {
                        delete_point_child=delete_point->left;
             Transplant(delete_point,delete_point_child);
                }
                else
                {
                        delete_point=Minmum(delete_point->right);
                        delete_point->RB_COLOR=find(key)->RB_COLOR;
                delete_point_child=delete_point->right;
                        if (delete_point->parent==find(key))
                    delete_point_child->parent=delete_point;
                        else
                        {
                                Transplant(delete_point,delete_point_child);
                                delete_point->right=find(key)->right;
                                delete_point->right->parent=delete_point;
                        }
                    Transplant(find(key),delete_point);
                        delete_point->left=find(key)->left;
                        delete_point->left->parent=delete_point;
                        delete_point->RB_COLOR=find(key)->RB_COLOR;
                  delete_point->date=find(key)->date;

                }
                if(delete_point->RB_COLOR==BLACK && !(delete_point_child==m_nullNode && delete_point_child->parent==m_nullNode))  
                {  
                        DeleteFixUp(delete_point_child);  
                }  
                delete delete_point;  
                return true;  
        }  
         bool Transplant(RB_Node*U,RB_Node*V)

        {
                if(U->parent==m_nullNode)
                     m_root=V;
                else if(U==U->parent->left)
                        U->parent->left=V;
                         else
                                         U->parent->right=V;
                U->parent=V->parent;
                return true;
        }
         ///////最小关键字/////////////
         /*TREE-MIXMUM(x)
         1 while x.left≠NIL
         2        x=x.left
         3 return x
         */
RB_Node*Minmum(RB_Node*node)
{
        while(node->left!=m_nullNode)  
                node=node->left;
                
        return node ;
}
///////////////////////////////
//////最大关键字/////////////
/*TREE-MAXIMUM(x)
1 while x.right≠NIL
2        x=x.right
3 return x
*/
///////////////////////////////
RB_Node*Maximum(RB_Node*node)
{
        while(node->right!=m_nullNode)  
                node=node->right;

        return node ;
}
//---------------------删除结点性质修复-----------------------------------  
/*RB-DELETE-FIXUP(T,x)
1 while x≠T.root and x.color==BLACK
2        if x==x.p.left
3            w=x.p.right
4            if w.color==RED
5                  w.color=BLACK                  //case 1
6                  x.p.color=RED                      //case 1
7                  LEFT-ROTATE(T,x.p)               //case 1
8                   w=x.p.right                              //case 1
9            if w.lef.color==BLACK and w.right.color==BLACK
10                     w.color=RED                                   //case 2
11                      x=x.p                                              //case  2
12          else if w.right.color==BLACK
13                        w.left.color=BLACK                    //case3
14                         w.color=RED                             //case 3
15                         RIGHT-ROTATE(T,w)                //case 3
16                        w=x.p.right                              //case 3
17               w.color=x.p.color                             //case 4
18                 x.p.color=BLACK                          //case 4
19                 w.right.color=BLACK                  //case 4
20                 LEFT-ROTATE(T,x.p)                   //case 4
21                   x=T.root                                   //case 4
22              else(same as then clause with "right" and "left" exchanged)
23 x.color=BLACK
*/
void DeleteFixUp(RB_Node* node)  
{
        while(node!=m_root&&node->RB_COLOR==BLACK)
        {
                if (node==node->parent->right)
                {
                        RB_Node*brother=node->parent->left;
                        if (brother->RB_COLOR==RED)  //情况1：x的兄弟w是红色的。  
                        {
                                     brother->RB_COLOR=BLACK;
                                                         node->parent->RB_COLOR=RED;
                                                         RotateLeft(node->parent);
                        } 
                        else      ////情况2：x的兄弟w是黑色的
                        {
                                if (brother->left->RB_COLOR==BLACK&& brother->right->RB_COLOR == BLACK)  
                                        //且w的俩个孩子都是黑色的//
                                {
                                        brother->RB_COLOR=RED;
                                        node=node->parent;
                                } 
                                else if(brother->right->RB_COLOR == BLACK)
                                        //情况3：x的兄弟w是黑色的，w的右孩子是黑色（w的左孩子是红色）。  
                                {  
                                        brother->RB_COLOR = RED;  
                                        brother->left->RB_COLOR = BLACK;  
                                        RotateRight(brother);  
                                }  
                                else if (brother->right->RB_COLOR==RED)
                                        //情况4：x的兄弟w是黑色的，且w的右孩子是红色的
                                {
                                        brother->RB_COLOR=node->parent->RB_COLOR;
                                        node->parent->RB_COLOR=BLACK;
                                        brother->right->RB_COLOR =BLACK;
                                                RotateLeft(node->parent);
                                }
                        }
                }
                else//下述情况针对上面的情况1中，node作为右孩子而阐述的。  
                        //22        else (same as then clause with "right" and "left" exchanged)  
                        //同样，原理一致，只是遇到左旋改为右旋，遇到右旋改为左旋，即可。其它代码不变。  
                {  
                        RB_Node* brother =node->parent->left;  
                        if(brother->RB_COLOR == RED)  
                        {  
                                brother->RB_COLOR = BLACK;  
                                node->parent->RB_COLOR = RED;  
                                RotateRight(node->parent);  
                        }  
                        else  
                        {  
                                if(brother->left->RB_COLOR==BLACK && brother->right->RB_COLOR == BLACK)  
                                {  
                                        brother->RB_COLOR = RED;  
                                        node = node->parent;  
                                }  
                                else if(brother->left->RB_COLOR==BLACK)  
                                {  
                                        brother->RB_COLOR = RED;  
                                        brother->right->RB_COLOR = BLACK;  
                                        RotateLeft(brother);  
                                }  
                                else if(brother->left->RB_COLOR==RED)  
                                {  
                                        brother->RB_COLOR = node->parent->RB_COLOR;  
                                        node->parent->RB_COLOR = BLACK;  
                                        brother->left->RB_COLOR = BLACK;  
                                        RotateRight(node->parent);  
                                        node = m_root;  
                                }  
                        }  
                }  
        }  
        m_nullNode->parent = m_root;   //最后将node置为根结点//
        node->RB_COLOR = BLACK;    //并改为黑色//
}
//////////前驱/////////////
/*TREE-PREDECESSOR(x)
1 if x.left≠NIL
2        return TREE-MAXIMUM(x.left)
3 y=x.p
4 while y≠NIL and x==y.left
5                x=y
6                y=y.p
return   y
*/
////////////////////////////////////
  inline RB_Node* InOrderPredecessor(RB_Node* node)  
  {
          if(node==m_nullNode)       //null node has no predecessor  
          {  
                  return m_nullNode;  
          }  
          if(node->left!=m_nullNode)
               return Maximum(node->left);
          else
          {
                  RB_Node* index = node->parent;  
                  while(index!==m_nullNode&&node==index->left)
                  {
                          node=index;
                          index=index->parent;
                  }
                  return index;
          }
  }
  //////////后继///////////////
  /*TREE-SUCCESSOR(x)
  1 if x.right≠NIL
  2       return TREE-MINIMUM(x.right)
  3 y=x.p
  4 while y≠NIL and x==y.right
  5                 x=y
  6                 y=y.p
  7 return  y
  */
  //////////////////////////////
   inline RB_Node* InOrderSuccessor(RB_Node* node)  
   {
           if(node==m_nullNode)       //null node has no  successor  
           {  
                   return m_nullNode;  
           }  
           if (node->right!=m_nullNode)
           {
                   return Minmum(node->right)
           }
           else
                  { 
                          RB_Node*index=node->parent;
                          while (index!=m_nullNode&&node=index->right)
                                  node=index;
                          index=index->parent;
           }
           return index;
   }
   //debug  
   void InOrderTraverse()  
   {  
           InOrderTraverse(m_root);  
   }  
   void CreateGraph(string filename)  
   {  
           //delete  
   }  
   void InOrderCreate(ofstream& file,RB_Node* node)  
   {  
           //delete  
   }  
   void InOrderTraverse(RB_Node* node)  
   {  
           if(node==m_nullNode)  
           {  
                   return;  
           }  
           else  
           {  
                   InOrderTraverse(node->left);  
                   cout<<node->key<<endl;  
                   InOrderTraverse(node->right);  
           }  
   }  
   ~RB_Tree()  
   {  
           clear(m_root);  
           delete m_nullNode;  
   }  
        private:  
                // utility function for destructor to destruct object;  
                void clear(RB_Node* node)  
                {  
                        if(node==m_nullNode)  
                        {  
                                return ;  
                        }  
                        else  
                        {  
                                clear(node->left);  
                                clear(node->right);  
                                delete node;  
                        }  
                }  
private:
        RB_Node* m_nullNode;
        RB_Node*m_root; 
};
#endif

