struct Nodo{
	T dato;
	Nodo* next;
	Nodo(const T& d, Nodo* n=NULL):dato(d),next(n){}
};