#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <utility>
#include "node.hpp"

template<class T>
using QueueNode = DoublyLinkedNode<T>;

template<class T>
class Queue
{
    public:
        Queue()
        :m_back(nullptr), m_size(0) {}

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


        void push(T val)
        {
            QueueNode<T> *newBack { new QueueNode<T>(val, this->m_back) };
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
        
        T pop()
        {
            if (this->m_back == nullptr)
            {
                T ret {};
                return ret;
            }
            
            T ret { this->m_front->val };
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
            return ret;
        }

        const T back()
        {
            return this->m_back->val;
        }
        
        const T front()
        {
           return this->m_front->val;
        }

    private:
        QueueNode<T> *m_back;
        QueueNode<T> *m_front;
        size_t m_size;
};

#endif
