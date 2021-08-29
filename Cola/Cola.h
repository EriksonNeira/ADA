#include <iostream>
#include <cstdlib>
#include "Nodo.h"
using namespace std;
typedef int T;

class Cola{	
private:
	
	Nodo *Frente, *Final;
	
public:
	Cola(); // constructor por defecto
	Cola (const Cola &p2); // para los de parámetros por valor
	~Cola(); //destructor
	void VaciaC();
	void AnadeC( T e);
	T PrimeroC();
	void BorrarC();
	void Mostrar();
	void crear();
	bool EsvaciaC();
};

Cola::Cola(){
	Frente = NULL;
	Final = NULL;
}

Cola::Cola (const Cola &p2){
	T e;
	Nodo* a = p2.Frente;
	Frente = NULL;
	Final = NULL;
	
	while ( a != NULL){
		AnadeC ( a -> OE());
		a = a->OSig();
	}
}

Cola:: ~Cola(){
	Nodo *paux;
	while(Frente != 0){
		paux = Frente;
		Frente = Frente->OSig();
		delete paux;
	}
}

void Cola::VaciaC(){
	Frente = NULL;
	Final = NULL;
}

void Cola::AnadeC(T e){
	Nodo *aux;
	aux = new Nodo(e); // nuevo nodo
	if( Final) // cola no vacía se coloca después de Final
	Final->PSig(aux);
	else // la cola está vacía es Frente y Final
	Frente = aux;
	Final = aux;
}

T Cola::PrimeroC(){
	if (Frente)
	return Frente->OE();
}

bool Cola::EsvaciaC(){
	return !Frente;
}

void Cola::BorrarC(){
	Nodo *paux;
	if(Frente){
		paux = Frente; // nodo a borrar
		Frente = Frente->OSig();
		delete paux;
	}
}

void Cola::Mostrar(){
	Nodo *tmp = Frente;
    while(tmp != 0){
        cout<<tmp -> e<<" ";
        tmp = tmp ->Sig;
    }
    delete tmp;
}

void Cola::crear(){
    T x;
    Final = 0;
    do {
        cin >> x;
        if (x != 0)
            AnadeC(x);
    } while (x != 0);

}
