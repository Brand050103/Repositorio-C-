#include<iostream>
#include<windows.h>
#include<string>
#include<string.h>
#define MAX 50
using namespace std; 

int contadorProveedores=0; 
struct RUC_PROVEEDOR{
    int tipoRuc;
    long dniProveedor; 
    int codigoRuc; 
};

struct Proveedores{
    string codigoProveedor; 
    string nombreProvedor; 
    RUC_PROVEEDOR rucProveedor; 
    long telefonoProveedor;
    string direccionProveedor; 
};
Proveedores _Proveedores[MAX];

void menuProveedores();
void registrarProveedores();
void verProveedores(); 
void tipoDePersona(); 
int codigoRuc(long);

int main(){
    menuProveedores(); 

    return 0; 
}

void menuProveedores(){
    system("cls"); 
    int opcion; 
    cout<<"DIGITE UNA DE LAS SIGUIENTES OPCIONES: "<<endl<<endl; 
    cout<<"[1] Registrar Proveedores"<<endl; 
    cout<<"[2] Modificar Proveedores"<<endl;
    cout<<"[3] Ver Proveedores"<<endl; 
    cout<<"[4] Salir"<<endl; 
    cout<<"OPCION ======> : "; cin>>opcion; 
    
    switch(opcion){
        case 1: 
            registrarProveedores(); 
            break; 
        case 2: 

        case 3: 
            verProveedores(); 
            break; 
        case 4: 
        break;
        default:
            cout<<"Ha digitado una opcion incorrecta..."<<endl; 
            cout<<"Intentelo Otra Vez..."; 
            Sleep(2500); 
            menuProveedores(); 
    }
}

void registrarProveedores(){ 
    char opcion = 's'; 
    int i=0,digitos=3; 
    do{
        cout<<"Digite su codigo de proveedor PRO-(XXX): "; //CODIGO PROVEEDOR
        cin>>_Proveedores[i].codigoProveedor; 
        int nro_cod = _Proveedores[i].codigoProveedor.length(); 
        cout<<nro_cod;
        while(nro_cod > 3 && nro_cod < 3){
            cout<<"Ha digitado un codigo erróne, intentelo otra vez..."<<endl; 
            cout<<"Digite su codigo de proveedor PRO-(XXX): ";
            fflush(stdin); 
            cin>>_Proveedores[i].codigoProveedor;
            nro_cod = _Proveedores[i].codigoProveedor.length(); 
        }
        cout<<"Digite su nombre de Proveedor(NOMBRE DE PERSONA O EMPRESA): "; //NOMBRE PROVEEDOR
        cin>>_Proveedores[i].nombreProvedor;
        int bool_ruc=1; 
        do{
            int bool_tipo = 1; 
            do{
            tipoDePersona(); 
            int opcTipo; 
            cin>>opcTipo; 
            switch(opcTipo){
            case 1: 
            _Proveedores[i].rucProveedor.tipoRuc=10; 
            bool_tipo=0; 
            break; 
            case 2: 
            _Proveedores[i].rucProveedor.tipoRuc=20;
            bool_tipo = 0; 
            break;
            case 3: 
            _Proveedores[i].rucProveedor.tipoRuc=15;
            bool_tipo=0;  
            break; 
            case 4: 
            _Proveedores[i].rucProveedor.tipoRuc=17; 
            bool_tipo=0; 
            break; 
            default:
            break; 
            }
            }while(bool_tipo==1);
            int bool_dni = 1; 
            do{
            
            cout<<"Digite su numero de DNI: "; 
            cin>>_Proveedores[i].rucProveedor.dniProveedor; 
            int nro_dni = _Proveedores[i].rucProveedor.dniProveedor; 
            if((nro_dni>0)&&(nro_dni<100000000)){
                bool_dni=0; 
            }
            else{
                bool_dni=1; 
            }
            }while(bool_dni== 1);
            int ruc_10_dig = (_Proveedores[i].rucProveedor.tipoRuc*100000000)+_Proveedores[i].rucProveedor.dniProveedor;
            _Proveedores[i].rucProveedor.codigoRuc = codigoRuc(ruc_10_dig);
            cout<<_Proveedores[i].rucProveedor.codigoRuc; 
            bool_ruc=0; 
        }while(bool_ruc == 1);
        contadorProveedores++;
        cout<<"Desea agregar un Proveedor mas?(S/N): "; cin>>opcion; 
    }while(opcion == 's' || opcion == 'S');
    if((opcion == 'n')||(opcion == 'N')){
        menuProveedores(); 
    }
}

void tipoDePersona(){
    cout<<"A continuación rellene los siguientes datos para generar su RUC"<<endl;
    cout<<"[1] Soy una persona natural"<<endl; 
    cout<<"[2] Soy una persona juridica"<<endl; 
    cout<<"[3] Soy una persona de la FF.AA. , extranjero, etc."<<endl; 
    cout<<"[4] Fecha de inscripcion entre 1993 y 2000"<<endl; 
    cout<<"Elije una de las siguientes opciones: "<<endl; 
}

int codigoRuc(long ruc_10){
    int suma=0, resto; 
    int factores[]={5,4,3,2,7,6,5,4,3,2}; 
    for(int i=9; i>=0; i--){
        suma = suma + (ruc_10%10) * factores[i]; 
        ruc_10=ruc_10/10; 
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

void verProveedores(){
    cout<<"Hay "<<contadorProveedores<<"Disponibles"<<endl;
    for(int i=0; i<contadorProveedores; i++){
        cout<<"NOMBRE: "<<_Proveedores[i].nombreProvedor<<endl; 
        cout<<"RUC: "<<_Proveedores[i].rucProveedor.tipoRuc<<_Proveedores[i].rucProveedor.dniProveedor<<_Proveedores[i].rucProveedor.codigoRuc<<endl; 
        cout<<"CODIGO: "<<_Proveedores[i].codigoProveedor<<endl; 
    }
}