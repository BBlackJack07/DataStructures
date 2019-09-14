#ifndef STACK_HPP
#define STACK_HPP

#include <utility>

template<class T>
class StackNode
{
    public:
        StackNode()
        :next(nullptr) {}

        T val;
        StackNode<T> *next;
};

template<class T>
class Stack
{
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

        void push(T val)
        {
            StackNode<T> *newHead { new StackNode<T> };
            newHead->val = val;
            newHead->next = this->m_top;
            this->m_top = newHead;
            this->m_size++;
        }

        T pop()
        {
            if (this->m_top == nullptr)
            {
                T ret {};
                return ret;
            }

            StackNode<T> *newHead { this->m_top->next };
            T ret { this->m_top->val };
            delete m_top;
            m_top = newHead;
            this->m_size--;
            return ret;
        }

        const T top()
        {
            return this->m_top->val;
        }

    private:
        StackNode<T> *m_top;
        size_t m_size;
};

#endif //STACK_HPP
