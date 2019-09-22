#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <utility>
#include "node.hpp"


template<class T>
class Queue
{
    typedef DoublyLinkedNode<T> _Node;
    public:
        Queue()
        :m_size(0),m_back(nullptr),m_front(nullptr) {}

        ~Queue() { this->clear(); }

        
        size_t size() { return this->m_size; }

        bool empty() { return (this->m_back == nullptr); }

        void swap(Queue<T> &other)
        {
            std::swap(this->m_back, other.m_back);
            std::swap(this->m_front, other.m_front);
            std::swap(this->m_size, other.m_size);
        }
        
        void clear()
        {
            while(m_back != nullptr)
                this->pop();
        }


        void push(T data)
        {
            _Node *newBack { new _Node(data, this->m_back) };
            if (this->m_back == nullptr)
            {
               this->m_back = newBack;
               this->m_front = this->m_back;
            }
            else
            {
               this->m_back->prev = newBack;
               this->m_back = newBack;
            }
            this->m_size++;
        }
        
        void pop()
        {
            if (this->m_back != nullptr)
            {
            
                if (this->m_back == this->m_front)
                {
                    delete this->m_front;
                    this->m_back = nullptr;
                    this->m_front = nullptr;
                }
                else
                {
                    this->m_front = this->m_front->prev;
                    delete this->m_front->next;
                    m_front->next = nullptr;
                }
            
                this->m_size--;
            }
        }

        T back()
        {
            if (this->m_back != nullptr) return this->m_back->data;
            return T();
        }
        
        T front()
        {
           if (this->m_back != nullptr) return this->m_front->data;
           return T();
        }

    private:
        size_t m_size;
        _Node *m_back;
        _Node *m_front;
};

#endif
