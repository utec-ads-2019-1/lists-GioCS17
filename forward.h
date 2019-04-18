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
		int sizef=size();
		Node<T>* array[sizef];
		int l=0,u=size()-1;
		if(l<u){
		}
        }
    
        void reverse() {
		int sizef=size();
		Node<T>* array[sizef];
		Node<T>* tmp=this->head;
		for(int i=0;i<sizef;i++){
			array[i]=tmp;
			tmp=tmp->next;
		}
		for(int i=0;i<sizef/2;i++){
			tmp=array[i];
			array[i]=array[sizef-i-1];
			array[sizef-i-1]=tmp;
		}
		for(int i=0;i<sizef-1;i++)
			array[i]->next=array[i+1];
		this->head=array[0];
		this->tail=array[sizef-1];
		this->tail->next=nullptr;
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
		cout<<"inicio merge"<<endl;
		/*while(tmp!=list.end()){
			Node<T> *nuevo=new Node<T>;
			nuevo->data=*tmp;
			tmp++;
		}
		*/
		cout<<"type "<<typeid(tmp).name()<<endl;
		//tmp++;
		cout<<"tmp"<<*(tmp)<<endl;
		cout<<"finalizo merge"<<endl;
        }
};

#endif
