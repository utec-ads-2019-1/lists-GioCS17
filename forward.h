#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"
#include<typeinfo>

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
		if(empty())
			throw runtime_error("La lista no cuenta con heap\n");
		return this->head->data;
        }

        T back() {
		if(empty())
			throw runtime_error("La lista no cuenta con tail\n");
		return this->tail->data;
        }

        void push_front(T value) {
		if(!empty()){
			Node<T> *nuevo=new Node<T>{value,nullptr,nullptr};
			nuevo->next=this->head;
			this->head=nuevo;
		}
		else
			this->head=this->tail=new Node<T>{value,nullptr,nullptr};
        }

        void push_back(T value) {
		if(!empty()){
			Node<T> *nuevo=new Node<T>{value,nullptr,nullptr};
			this->tail->next=nuevo;
			this->tail=nuevo;
		}
		else
			this->head=this->tail=new Node<T>{value,nullptr,nullptr};
        }

        void pop_front() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia\n");
		Node<T> *tmp=this->head->next;
		this->head->killSelf();
		this->head=tmp;
        }

        void pop_back() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia\n");

		Node<T> *tmp=this->head;
		while(tmp->next!=this->tail)
			tmp=tmp->next;

		this->tail->killSelf();
		this->tail=tmp;
		this->tail->next=nullptr;
        }

        T operator[](int index) {

		if(index<0)
			throw runtime_error("Indice debe ser positivo o 0\n");
		if(index>size()-1)
			throw runtime_error("Indice ingresado es mayor a la cantidad de elementos de la lista\n");

		Node<T> *tmp=this->head;
		while(index--)
			tmp=tmp->next;
		
		
		return tmp->data;
        }

        bool empty() {
	    return this->head==nullptr;
        }

        int size() {
		int sizef=0;
		Node<T> *tmp=this->head;
		while(tmp!=nullptr){
			tmp=tmp->next;
			sizef++;
		}
		return sizef;
        }

        void clear() {
		if(empty())
			return;
		
		this->head->killSelfToEnd(this->head);
		this->head=this->tail=nullptr;
        }

        void sort() {
		if(empty())
			throw runtime_error("la lista se encuentra vacia");
		bool faro=true;
		while(faro){
			faro=false;
			Node<T>* tmp=this->head; 
			while(tmp->next!=nullptr){
				if(tmp->data>tmp->next->data){
					T valuetmp=tmp->data;
					tmp->data=tmp->next->data;
					tmp->next->data=valuetmp;
					faro=true;
				}
				tmp=tmp->next;
			}
		}

        }
    
        void reverse() {
		if(empty())
			throw runtime_error("la lista se encuentra vacia");
		ForwardList<T> list;
		Node<T>* tmp=this->head;
		while(tmp!=nullptr){
			list.push_front(tmp->data);
			tmp=tmp->next;
		}
		ForwardIterator<T> t=list.begin();
		clear();
		while(t!=nullptr){
			this->push_back(*t);
			++t;
		}

        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
		return ForwardIterator<T>(this->head);
        }

	ForwardIterator<T> end() {
		return nullptr;
        }

        void merge(ForwardList<T> list) {
		ForwardIterator<T> tmp=list.begin();
		while(tmp!=nullptr){
			this->push_back(*tmp);
			++tmp;
		}
        }
};

#endif
