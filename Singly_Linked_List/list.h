#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include "node.h"

template <typename T>
class SinglyLinkedList {
    private:
        Node<T>* head; 
        std::size_t size;

    public:
        SinglyLinkedList() : head(nullptr), size(0) {};

        const std::size_t getSize();

        void insert(const T &e, std::size_t pos = 0);
        void eliminate(std::size_t pos = 0);
};

template<typename T>
inline const std::size_t SinglyLinkedList<T>::getSize()
{
    return this->size;
}

template<typename T>
void SinglyLinkedList<T>::insert(const T &e, std::size_t pos)
{
    if (pos == 0) // First element
    {
        Node<T>* newNode = new Node(e);
        newNode->setNext(head);
        head = newNode;
    }
    else if (pos > 0 && pos < this->size)
    {
        int i = 0;
        Node<T>* aux = head;
        while (i < pos-1)
        {
            aux = aux->getNext();
            i++;
        }

        Node<T>* newNode = new Node(e);
        Node<T>* nodeToMove = aux->getNext();
        aux->setNext(newNode);
        newNode->setNext(nodeToMove);
    }
    /* else
    {
        // Throw an exception out of range
    } */

    this->size++; // Increment size of the list
}

template <typename T>
void SinglyLinkedList<T>::eliminate(std::size_t pos)
{
    if (head == nullptr) return; // No items
    // Delete beginning (default)
    else if (pos == 0)
    {
        Node<T>* aux = head;
        head = head->getNext();
        delete aux; // deallocate memory
    }
    else if (pos > 0 && pos < this->size) // This range ensures a valid position
    {
        std::size_t i = 0;
        Node<T>* aux = head;
        while (i < pos-1)
        {
            aux = aux->getNext();
            i++;
        }
        Node<T>* nodeToRemove = aux->getNext();
        aux->setNext(nodeToRemove->getNext());
        delete nodeToRemove;
    }
    /* else
    {
        // Throw an exception out of range
    } */
    
    this->size--; // Decrement size of the list
}

#endif // LIST_H