#ifndef NODE_HPP
#define NODE_HPP

template<class T>
class SimpleNode
{
    
    typedef SimpleNode<T> _Self;
    public:
        SimpleNode()
        :next(nullptr) {}
        
        SimpleNode(const _Self &_x)
        {
            *this = _x;
        }

        _Self& operator=(const _Self &_x)
        {
            this->data = _x.data;
            this->next = _x.next;
            return *this;
        }

        SimpleNode(T value)
        :data(value),next(nullptr) {}
        
        SimpleNode(T value, _Self * n)
        :data(value),next(n) {}
        
        T data;
        _Self * next;
};

template<class T>
class DoublyLinkedNode
{
    typedef DoublyLinkedNode<T> _Self;
    public:
        DoublyLinkedNode()
        :prev(nullptr),next(nullptr) {}

        DoublyLinkedNode(const _Self &_x)
        {
            *this = _x;
        }

        _Self& operator=(const _Self &_x)
        {
            this->prev = _x.prev;
            this->data = _x.data;
            this->next = _x.next;
            return *this;
        }
        
        DoublyLinkedNode(T value)
        :prev(nullptr),data(value),next(nullptr) {}
        
        DoublyLinkedNode(_Self * p, T value)
        :prev(p),data(value),next(nullptr) {}
        
        DoublyLinkedNode(T value, _Self * n)
        :prev(nullptr),data(value),next(n) {}


        _Self * prev;
        T data;
        _Self * next;
};

#endif
