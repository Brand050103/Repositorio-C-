#include<iostream>
using namespace std; 

int codigoRuc(long);

int main(){
    long ruc;
    int codigoDeRuc;  
    cout<<"Digite tu RUC de 10 Digitos: "; 
    cin>>ruc; 
    codigoDeRuc=codigoRuc(ruc); 
    cout<<"Tu codigo de RUC es: "<<codigoDeRuc<<endl; 
    return 0; 
}

int codigoRuc(long ruc){
    int suma=0, resto; 
    int factores[]={5,4,3,2,7,6,5,4,3,2}; 
    for(int i=9; i>=0; i--){
        suma = suma + (ruc%10) * factores[i]; 
        ruc=ruc/10; 
    }
    resto = 11 - (suma%11); 
    if(resto == 10){
        resto = 0; 
    }
    else if(resto == 11){
        resto = 1; 
    }

    return resto; 
}