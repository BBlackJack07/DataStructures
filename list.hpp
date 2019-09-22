#ifndef LIST_HPP
#define LIST_HPP

#include <utility>
#include "node.hpp"

template<class T>
class List
{
        typedef DoublyLinkedNode<T> _Node;
    public:
        
        List()
        :m_size(0),m_back(nullptr),m_front(nullptr) {}

        List(std::initializer_list<T> init)
        :m_size(0),m_back(nullptr),m_front(nullptr)
        {
            for (T element: init)
                this->push_back(element);
        }

        List(const List<T>& other)
        :m_size(0),m_back(nullptr),m_front(nullptr) { *this = other; }

        List<T>& operator=(const List<T>& other) 
        {
            this->clear();
            _Node *current = other.m_back;
            while (current!=nullptr)
            {
                push_front(current->data);
                current = current->next;
            }

            return *this;
        }

        ~List() { this->clear(); }

        bool   empty() { return (this->m_front == nullptr); }
        size_t size()  { return this->m_size; }
        
        void clear() 
        {
            while (this->m_back != nullptr)
                this->pop_back();
        }
        
        T back() 
        { 
            if (!this->empty())
                return this->m_back->data;
            return T();
        }

        T front() 
        {
            if (!this->empty())
                return this->m_front->data;
            return T();
        }

        void push_back(T data)
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

        void push_front(T data)
        {
            _Node *newFront { new _Node(this->m_front, data) };
            if (this->m_front == nullptr)
            {
                this->m_front = newFront;
                this->m_back = this->m_front;
            }
            else
            {
                this->m_front->next = newFront;
                this->m_front = newFront;
            }
            this->m_size++;
        }
        
        void pop_back()
        {
            if (this->m_back != nullptr)
            {
                if (this->m_front == m_back)
                {
                    delete this->m_back;
                    this->m_back = nullptr;
                    this->m_front = nullptr;
                }
                else
                {
                    this->m_back = m_back->next;
                    delete this->m_back->prev;
                    this->m_back->prev = nullptr;
                }
                this->m_size--;
            }
        }

        void pop_front()
        {
            if (this->m_front != nullptr)
            {
                if (this->m_front == m_back)
                {
                    delete this->m_front;
                    this->m_back = nullptr;
                    this->m_front = nullptr;
                }
                else
                {
                    this->m_front = m_front->prev;
                    delete this->m_front->next;
                    this->m_front->next = nullptr;
                }
                this->m_size--;
            }
        }
 
    private:
        size_t  m_size;
        _Node * m_back;
        _Node * m_front;
}; 

#endif
