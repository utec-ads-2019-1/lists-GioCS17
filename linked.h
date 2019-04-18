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
            // TODO
        }
    
        void reverse() {
		int sizel=size();
		Node<T>* array[sizel];
		Node<T>* tmp=this->head;
		for(int i=0;i<sizel;i++){
			array[i]=tmp;
			tmp=tmp->next;
		}
		for(int i=0;i<sizel/2;i++){
			tmp=array[i];
			array[i]=array[sizel-1-i];
			array[sizel-1-i]=tmp;
		}
		for(int i=0;i<sizel-1;i++)
			array[i]->next=array[i+1];
		for(int i=1;i<sizel;i++)
			array[i]->prev=array[i-1];

		this->head=array[0];
		this->head->prev=nullptr;
		this->tail=array[sizel-1];
		this->head->prev=nullptr;
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> list) {
            // TODO
        }
};

#endif
