#ifndef B_S_TREE_H
#define B_S_TREE_H


#include <cstdlib>
#include <stack>


template<typename T>
class Tree {
private:

    class Node {
    public:
        Node() : m_val(0), m_left(NULL), m_right(NULL) {}
        Node(const T &x) : m_val(x), m_left(NULL), m_right(NULL) {}
        Node(const T &x, Node *left, Node *right) : m_val(x), m_left(left), m_right(right) {}
        // members
        T m_val;
        Node *m_left;
        Node *m_right;
    };

    Node *m_root;

public:

    Tree(): m_root(NULL){}

    class Iterator{
    public:
        Iterator():m_treeStack(){}
        Iterator(const Iterator& other): m_treeStack(other.m_treeStack){}

        T& operator *(){ return m_treeStack.top()->m_val; }
        Iterator& operator = (const Iterator& other);
        Iterator& operator ++();
        Iterator operator ++(int);
        
        bool operator ==(const Iterator& other)const ;
        bool operator !=(const Iterator& other)const ;
        void pushRightChildToStack(Node*);

    private:
        std::stack<Node*> m_treeStack;
    };

    Iterator begin() const ;
    Iterator end() const { return Iterator(); }
    void insert(const T& val);

};


template<class T>
void printBST(const Tree<T>& tree);


#include "b_s_tree.hpp"

#endif //B_S_TREE_H