#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
		BidirectionalIterator<T> aux(other->current);
		return aux;
        }

        bool operator!=(BidirectionalIterator<T> other) {
		return this->current!=other.current;
        }

        BidirectionalIterator<T> operator++() {
		if(this->current==nullptr)
			throw runtime_error("Operacion no valida ++");
		this->current=this->current->next;
		return (*this);
        }

        BidirectionalIterator<T> operator--() {
		if(this->current==nullptr)
			throw runtime_error("Operacion no valida --");
		this->current=this->current->prev;
		if(this->current==nullptr)
			throw runtime_error("Operacion no valida --");
		return (*this);
        }

        T operator*() {
		if(this->current==nullptr)
			throw runtime_error("Operacion no valida *");
		return this->current->data;
        }
};

#endif
