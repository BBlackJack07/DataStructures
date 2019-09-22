#ifndef STACK_HPP
#define STACK_HPP

#include <utility>
#include "node.hpp"

template<class T>
class Stack
{
    typedef SimpleNode<T> _Node;
    public:
        Stack()
        :m_top(nullptr),m_size(0) {}

        ~Stack() { this->clear(); }

        bool empty() { return (this->m_top==nullptr); }

        size_t size() { return this->m_size; };

        void swap(Stack<T> &other)
        {
            std::swap(this->m_top, other.m_top);
            std::swap(this->m_size, other.m_size);
        }

        void clear()
        {
            while(m_top != nullptr)
                this->pop();
        }

        void push(T data)
        {
            _Node *newHead { new _Node(data, this->m_top) };
            this->m_top = newHead;
            this->m_size++;
        }

        void pop()
        {
            if (this->m_top != nullptr)
            {
                _Node *newHead { this->m_top->next };
                delete m_top;
                m_top = newHead;
                this->m_size--;
            }
        }

        T top()
        {
            if (this->m_top != nullptr) return this->m_top->data;
            return T();
        }

    private:
        _Node *m_top;
        size_t m_size;
};

#endif //STACK_HPP
