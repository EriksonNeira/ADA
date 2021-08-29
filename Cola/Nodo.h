#include <cstdlib>
typedef int T;

class Nodo{
private:
	friend class Cola;
	T e;
	Nodo *Sig;
public:
	Nodo(){}
	~Nodo(){}
	Nodo (T x){ e = x; Sig = NULL;}
	T OE(){ return e;} 
	void PE(T x){ e = x;} 
	Nodo * OSig(){ return Sig;}
	void PSig( Nodo *p){ Sig = p;} 
};
