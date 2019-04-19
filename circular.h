#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

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
			this->head->prev=nuevo;
			nuevo->next=this->head;
			nuevo->prev=this->tail;
			this->head=nuevo;
			this->tail->next=this->head;
		}
		else{
			this->head=this->tail=new Node<T>{value,nullptr,nullptr};
			this->head->next=this->head->prev=this->tail;
			this->tail->next=this->tail->prev=this->head;
		}
        }

        void push_back(T value) {
		if(!empty()){
			Node<T>*nuevo=new Node<T>{value,nullptr,nullptr};
			this->tail->next=nuevo;
			nuevo->next=this->head;
			nuevo->prev=this->tail;
			this->tail=nuevo;
			this->head->prev=this->tail;
		}
		else{
			this->head=this->tail=new Node<T>{value,nullptr,nullptr};
			this->head->next=this->head->prev=this->tail;
			this->tail->next=this->tail->prev=this->head;
		}
        }

        void pop_front() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		if(this->head==this->tail){
			this->head->killSelf();
			this->head=this->tail=nullptr;
		}
		else{
			Node<T>*tmp=this->head->next;
			this->tail->next=tmp;
			tmp->prev=this->tail;
			this->head->killSelf();
			this->head=tmp;
		}
        }

        void pop_back() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		if(this->head==this->tail){
			this->head->killSelf();
			this->head=this->tail=nullptr;
		}
		else{
			Node<T>*tmp=this->tail->prev;
			this->head->prev=tmp;
			tmp->next=this->head;
			this->tail->killSelf();
			this->tail=tmp;
		}
        }

        T operator[](int index) {
		if(index>size()-1)
			throw runtime_error("indice fuera de limite");
		Node<T>* tmp=this->head;
		while(index--)
			tmp=tmp->next;
		
		return tmp->data;
        }

        bool empty() {
		return this->head==nullptr;
        }

        int size() {
		int sizec=0;
		Node<T>* tmp=this->head;
		if(tmp==nullptr)
			return 0;
		sizec++;
		tmp=tmp->next;
		while(tmp!=this->head){
			tmp=tmp->next;
			sizec++;
		}
		return sizec;
        }

        void clear() {
		if(empty())
			return;
		this->head->killSelfToEndCircular(this->head->next,this->head);
		this->head->killSelf();

		this->head=this->tail=nullptr;
        }

        void sort() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");

		bool faro=true;
		while(faro){
			faro=false;
			Node<T>* tmp=this->head;
			while(tmp!=this->tail){
				if(tmp->data>tmp->next->data){
					faro=true;
					T valuetmp=tmp->data;
					tmp->data=tmp->next->data;
					tmp->next->data=valuetmp;
				}
				tmp=tmp->next;
			}
		}
        }
    
        void reverse() {
		if(empty())
			throw runtime_error("La lista se encuentra vacia");
		Node<T>*tmpright=this->head;
		Node<T>*tmpleft=this->tail;
		while(tmpright!=tmpleft){
			T valuetmp=tmpright->data;
			tmpright->data=tmpleft->data;
			tmpleft->data=valuetmp;
			if(tmpright->next==tmpleft && tmpleft->prev==tmpright)
				break;
			tmpright=tmpright->next;
			tmpleft=tmpleft->prev;
		}
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
		return BidirectionalIterator<T>(this->head);
        }

	BidirectionalIterator<T> end() {
		return BidirectionalIterator<T>(this->tail);
        }

        void merge(CircularLinkedList<T> &list) {
		BidirectionalIterator<T> tmp=list.begin();
		do{
			this->push_back(*tmp);
			++tmp;
		}
		while(tmp!=list.begin());
        }
};

#endif
