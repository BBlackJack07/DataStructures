#ifndef NODE_HPP
#define NODE_HPP

template<class T>
class SimpleNode
{
    public:
        SimpleNode()
        :next(nullptr) {}

        SimpleNode(T value)
        :val(value),next(nullptr) {}
        
        SimpleNode(T value, SimpleNode<T> * n)
        :val(value),next(n) {}
        
        T val;
        SimpleNode<T> * next;
};

template<class T>
class DoublyLinkedNode
{
    public:
        DoublyLinkedNode()
        :prev(nullptr),next(nullptr) {}
        
        DoublyLinkedNode(T value)
        :prev(nullptr),val(value),next(nullptr) {}
        
        DoublyLinkedNode(DoublyLinkedNode<T> * p, T value)
        :prev(p),val(value),next(nullptr) {}
        
        DoublyLinkedNode(T value, DoublyLinkedNode<T> * n)
        :prev(nullptr),val(value),next(n) {}





        DoublyLinkedNode<T> * prev;
        T val;
        DoublyLinkedNode<T> * next;
};

#endif
