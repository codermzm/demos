#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>

//AVL树节点信息
template<class T>
class TreeNode
{
    public:
        TreeNode():lson(NULL),rson(NULL),freq(1),hgt(0){}
        T data;//值
        int hgt;//以此节点为根的树的高度
        unsigned int freq;//频率
        TreeNode* lson;//指向左儿子的地址
        TreeNode* rson;//指向右儿子的地址
};

template<class T>
class AVLTree
{
private :
    TreeNode<T>* root;//根节点
    void insertpri(TreeNode<T>* &node,T x);//插入
    TreeNode<T>* findpri(TreeNode<T>* node,T x);//查找
    void insubtree(TreeNode<T>* node);//中序遍历
    void Deletepri(TreeNode<T>* &node,T x);//删除
    int height(TreeNode<T>* node);//求树的高度
    void SingRotateLeft(TreeNode<T>* &k2);//左左情况下的旋转
    void SingRotateRight(TreeNode<T>* &k2);//右右情况下的旋转
    void DoubleRotateLR(TreeNode<T>* &k3);//左右情况下的旋转
    void DoubleRotateRL(TreeNode<T>* &k3);//右左情况下的旋转
    int max(int cmpa,int cmpb);//求最大值

public:
    AVLTree():root(NULL){}
    void insert(T x);//插入接口
    TreeNode<T>* find(T x);//查找接口
    void Delete(T x);//删除接口
    void traversal();//遍历接口
};

#endif // AVLTREE_H
