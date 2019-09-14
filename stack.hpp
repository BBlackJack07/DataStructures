#ifndef STACK_HPP
#define STACK_HPP

template<class T>
class Node
{
    public:
        Node()
        :next(nullptr) {}

        T val;
        Node<T> *next;
};

template<class T>
class Stack
{
    public:
        Stack()
        :head(nullptr) {}

        ~Stack() { this->clear(); }

        void clear()
        {
            while(head != nullptr)
                this->pop();
        }

        void push(T val)
        {
            Node<T> *newHead { new Node<T> };
            newHead->val = val;
            newHead->next = this->head;
            this->head = newHead;
        }

        T pop()
        {
            if (this->head == nullptr)
            {
                T ret {};
                return ret;
            }

            Node<T> *newHead { this->head->next };
            T ret { this->head->val };
            delete head;
            head = newHead;
            return ret;
        }

        const Node<T>* top()
        {
            return this->head;
        }

    private:
        Node<T> *head;
};

#endif //STACK_HPP
