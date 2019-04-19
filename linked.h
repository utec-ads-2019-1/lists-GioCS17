#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		return this->head->data;
        }

        T back() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		return this->tail->data;
        }

        void push_front(T value) {
		if(!empty()){
			Node<T>* nuevo=new Node<T>{value,nullptr,nullptr};
			nuevo->next=this->head;
			this->head->prev=nuevo;
			this->head=nuevo;
		}
		else
			this->head=this->tail=new Node<T>{value,nullptr,nullptr};
        }

        void push_back(T value) {
		if(!empty()){
			Node<T>* nuevo=new Node<T>{value,nullptr,nullptr};
			nuevo->prev=this->tail;
			this->tail->next=nuevo;
			this->tail=nuevo;
		}
		else
			this->head=this->tail=new Node<T>{value,nullptr,nullptr};
        }

        void pop_front() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		Node<T>*tmp=this->head->next;
		this->head->killSelf();
		this->head=tmp;
		this->head->prev=nullptr;
        }

        void pop_back() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		Node<T>*tmp=this->tail->prev;
		this->tail->killSelf();
		this->tail=tmp;
		this->tail->next=nullptr;
        }

        T operator[](int index) {
		if(index>size()-1)
			throw runtime_error("No existe valor en esta posicion");
		
		Node<T>*tmp=this->head;
		while(index--)
			tmp=tmp->next;
		
		return tmp->data;
        }

        bool empty() {
		return this->head==nullptr;
        }

        int size() {
		int sizel=0;
		Node<T> *tmp=this->head;
		while(tmp!=nullptr){
			tmp=tmp->next;
			sizel++;
		}

		return sizel;
        }

        void clear() {
		if(empty())
			return;
		this->head->killSelfToEnd(this->head);
		this->head=this->tail=nullptr;
        }

        void sort() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		bool faro=true;
		while(faro){
			faro=false;
			Node<T>*tmp=this->head;
			while(tmp->next!=nullptr){
				if(tmp->data>tmp->next->data){
					faro=true;
					T valuetmp=tmp->next->data;
					tmp->next->data=tmp->data;
					tmp->data=valuetmp;
				}
				tmp=tmp->next;
			}
		}
        }
    
        void reverse() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		LinkedList<T> list;
		Node<T>* tmp=this->head;
		while(tmp!=nullptr){
			list.push_front(tmp->data);
			tmp=tmp->next;
		}
		clear();
		BidirectionalIterator<T> t=list.begin();
		while(t!=nullptr){
			this->push_back(*t);
			++t;
		}
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
		return BidirectionalIterator<T>(this->head);
        }

	BidirectionalIterator<T> end() {
		return nullptr;
        }

        void merge(LinkedList<T> list) {
		BidirectionalIterator<T> tmp=list.begin();
		while(tmp!=nullptr){
			this->push_back(*tmp);
			++tmp;
		}
        }
};

#endif
