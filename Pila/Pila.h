#include <iostream>
#include<cstddef>
#include<stdexcept>
using namespace std;

template<class T>
class Pila{
    private:
    #include "Nodo.h"
    
    public:
    	Pila();
    	Pila(const Pila<T> &p);
    	~Pila();
    	void push(const T& d);
    	void pop();
    	const T& top()const;
    	const T& Siguiente()const;
    	bool isEmpty()const;
    	T size();
    	void print();
    	void create();
    	
    private:
    	Nodo* cima;
};

template<class T>
Pila<T>::Pila(){ 
    cima = NULL;
}

template<class T>
Pila<T> :: Pila(const Pila<T> &p){
    cima = p.cima;
}

template <class T>
void Pila<T>::push(const T& d){
	if (!cima){
		cima = new Nodo(d);
	}
	else{
		cima = new Nodo(d, cima);
	}
}

template<class T>
void Pila<T>::pop(){
	if (!cima){ 
	    return;
	}
	else{
    	Nodo* tmp = cima;
    	cima = cima->next;
    	delete tmp;
	}
}

template<class T>
const T& Pila<T>::top()const{
	if (cima){
		return (cima->dato);
	}
	else{
		throw std::out_of_range("Pila sin elementos... /n");
	}
}

template<class T>
bool Pila<T>::isEmpty()const{
	return !cima;
}

template<class T>
T Pila<T> :: size(){
    int n=0;
    if(isEmpty()){
        return 0;
    }
    else{
        while(cima != 0){
            n++;
            cima = cima->next;
        }
        return n;
    }
}

template<class T>
Pila<T> :: ~Pila(){
    while(cima != 0){
        Nodo *tmp = cima;
        cima = cima->next;
        delete tmp;
    }
}

template <class T>
void Pila<T> :: print(){
    Nodo *tmp = cima;
    while(tmp != 0){
        cout<<tmp -> dato<<" ";
        tmp = tmp ->next;
    }
    delete tmp;
}

template <class T>
void Pila<T> :: create(){
    T x;
    cima = 0;
    do {
        cin >> x;
        if (x != '0')
            cima = new Nodo(x,cima);
    } while (x != '0');

}

