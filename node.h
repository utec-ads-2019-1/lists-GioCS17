#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    void killSelfToEnd(Node<T>* step){
    	if(step==nullptr)
		    return;
    	killSelfToEnd(step->next);
    	step->killSelf();
	}
    void killSelfToEndCircular(Node<T>*step,Node<T>*stop){
	    if(step==stop)
		    return;
	    killSelfToEndCircular(step->next,stop);
	    step->killSelf();
    }

    void killSelf() {
	    delete this;
    }
};


#endif
