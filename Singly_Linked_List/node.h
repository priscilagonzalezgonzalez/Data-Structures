#pragma once

template<typename T>
class Node 
{
    private:
        T data;
        Node<T>* next;

    public:
        Node() : next(nullptr){}
        Node(const T &e) : data(e), next(nullptr){}
        Node(const T &e, Node<T> *p) : data(e), next(p){}

        //~Node();
        Node<T>* getNext() const;

        void setData(const T &e);
        void setNext(Node<T> *p);

        const T& getData() const;
};

template <typename T>
Node<T> *Node<T>::getNext() const {
    return this->next;
}

template <typename T>
void Node<T>::setData(const T &e) {
    this->data = e;
}

template <typename T>
void Node<T>::setNext(Node<T> *p) {
    this->next = p;
}

template <typename T>
const T &Node<T>::getData() const {
    return this->data;
}