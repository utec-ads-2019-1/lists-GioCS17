#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T> other) {
		ForwardIterator<T> aux(other->current);
		return aux;
        }

        bool operator!=(ForwardIterator<T> other) {
		return this->current!=other.current;
        }

        ForwardIterator<T> operator++(){
		cout<<"entro a ++"<<endl;
		this->current=this->current->next;
		return this;
        }

        T operator*() {
		cout<<"entro a *"<<endl;
		return this->current->data;
        }
};

#endif
