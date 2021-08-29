#include<iostream>
#include <string>
#include "Pila.h"
using namespace std;
void crear();
int main()
{
    cout<<"0 para finalizar"<<endl;
    cout<<"z simular ctrl Z"<<endl;  
    cout<<"Ingrese caracteres:";
    crear();
    
    return 0;
}

void crear(){
    char x;
    Pila<char> pi;
    do{
        cin>>x;
        if(x == 'z'){
            pi.pop();
        }
        else if (x != '0'){
            pi.push(x);
        } 
        
    }while(x != '0');
    
    pi.print();
};
