#ifndef QUEUE_HPP
#define QUEUE_HPP

template<class T>
class Node
{
    public:
        Node()
        :next(nullptr),prev(nullptr) {}

        T val;
        Node<T> *next;
        Node<T> *prev;
};

template<class T>
class Queue
{
    public:
        Queue()
        :head(nullptr) {}

        ~Queue() { this->clear(); }

        void clear()
        {
            while(head != nullptr)
                this->pop_back();
        }

        void push(T val)
        {
            Node<T> *newHead { new Node<T> };
            newHead->val = val;
            newHead->next = this->head;
            newHead->prev = nullptr;
            if (head == nullptr)
            {
               this->head = newHead;
               this->end = this->head;
            }
            else
            {
               this->head->prev = newHead;
               this->head = newHead;
            }
        }
        
        T pop_back()
        {
            if (this->head == nullptr)
            {
                T ret {};
                return ret;
            }
            
            if (this->head == this->end)
            {
               T ret = this->head->val;
               delete this->head;
               this->head = nullptr;
               this->end = nullptr;
               return ret;
            }
            
            T ret { this->end->val };
            this->end = end->prev;
            delete end->next;
            end->next = nullptr;
            return ret;
        }

        const Node<T>* top()
        {
            return this->head;
        }
        
        const Node<T>* bot()
        {
           return this->end;
        }

    private:
        Node<T> *head;
        Node<T> *end;
};

#endif
