#include<iostream>
#include<windows.h>
#define MAX 50
using namespace std; 

//DECLARACION DE FUNCIONES DE EJECUCIÓN DE LOS MENUS PRINCIPALES
// MENU, PRODUCTOS, CLIENTES, PROVEEDORES Y FACTURA 
void abrirMenu();
void abrirProductos(); 
void abrirClientes(); 
void abrirProveedores(); 
void abrirFactura(); 

//DECLARACION DE FUNCIONES DE EJECUCION DE LOS SUB-MENUS DE PRODUCTOS
//REGISTRAR PRODUCTO, MODIFICAR PRODUCTO, VER PRODUCTO
void registrarProducto(); 
void modificarProducto(); 
void verProducto(); 

//DECLARACION DE FUNCIONES DE EJECUCUION DE LOS SUB-MENUS DE CLIENTES
//REGISTRAR CLIENTE, MODIFICAR CLIENTE, VER CLIENTES
void registrarCliente(); 
void modificarCliente(); 
void verCliente(); 

//DECLARACION DE FUNCIONES DE EJECUCION DE LOS SUB-MENUS DE PROVEEDORES
//REGISTRAR PROVEEDOR, MODIFICAR PROVEEDOR, VER PROVEEDORES
void registrarProveedor(); 
void modificarProveedor(); 
void verProveedores();

//DECLARACION DE FUNCIONES DE EJECUCION DE LOS SUB-MENUS DE FACTURA
//GENERAR FACTURA, VER FACTURAS
void generarFactura(); 
void verFacturas(); 

//ESTRUCTURAS
//Estructura de PRODUCTO
struct Producto{
    int codigo_producto; 
    string nombre_producto; 
    int cantidad_producto; 
    string categoria_producto; 
    double precio_unitario; 
    string nombre_proveedor; 
}; 
Producto _Producto[MAX];

//Estructura de CLIENTE
struct Cliente{
    int codigo_cliente; 
    string nombre_cliente; 
    string apellido_cliente; 
    long DNI_cliente; 
    long RUC_cliente; 
    long telefono_cliente; 
};
Cliente _Cliente[MAX];

//Estructura de PROVEEDOR
struct Proveedor{
    int codigo_proveedor; 
    string nombre_proveedor; 
    long RUC_proveedor; 
    long telefono_proveedor; 
    string direccion_proveedor; 
};
Proveedor _Proveedor[MAX]; 

//FUNCION PRINCIPAL
int main(){
    system("cls"); 
    abrirMenu();

    return 0; 
}

//FUNCION ABRIR MENU
void abrirMenu(){
    system("cls"); 
    int opc; 
    cout<<">>>>>>>> Bienvenido a nuestro SUPERMERCADO <<<<<<<<"<<endl<<endl; 
    cout<<"\t1. PRODUCTOS"<<endl; 
    cout<<"\t2. CLIENTES"<<endl;
    cout<<"\t3. PROVEEDORES"<<endl;
    cout<<"\t4. FACTURACION"<<endl;
    cout<<"\t5. SALIR"<<endl<<endl;
    cout<<"Elija una de las siguientes opciones del menu :D : "; cin>>opc; 

    switch (opc)
    {
    case 1:
        system("cls");
        abrirProductos(); 
        break;
    case 2: 
        system("cls");
        abrirClientes(); 
        break; 
    case 3: 
        system("cls");
        abrirProveedores(); 
        break; 
    case 4: 
        system("cls");
        abrirFactura(); 
        break;
    case 5:  
        break; 
    default:
        system("cls"); 
        cout<<"Ha seleccionado una opcion incorrecta intentelo otra vez..."<<endl; 
        cout<<"Volviendo al menu principal..."<<endl; 
        Sleep(2000); 
        abrirMenu(); 
        break;
    }
}

//FUNCION ABRIR EL MENU DE PRODUCTOS
void abrirProductos(){
    int opc; 
    system("cls"); 
    cout<<">>>>>>>> PRODUCTOS <<<<<<<<"<<endl<<endl; 
    cout<<"\t1.1 Registrar Producto"<<endl; 
    cout<<"\t1.2 Modificar Producto"<<endl; 
    cout<<"\t1.3 Ver Productos"<<endl; 
    cout<<"\t1.4 Volver al menu principal"<<endl; 
    cout<<"\t1.5 Salir"<<endl<<endl; 
    cout<<"Elige una opcion :D : "; cin>>opc; 

    switch (opc)
    {
    case 1:
        registrarProducto(); 
        break;
    case 2: 
        modificarProducto();
        break; 
    case 3: 
        verProducto(); 
        break; 
    case 4: 
        cout<<"Volviendo al menu principal..."<<endl; 
        Sleep(1500);
        abrirMenu(); 

    case 5: 
        break; 
    default:
        system("cls"); 
        cout<<"Ha seleccionado una opcion incorrecta intentelo otra vez..."<<endl; 
        cout<<"Volviendo al menu productos..."<<endl; 
        Sleep(2000); 
        abrirProductos(); 
        break;
    }
}

//FUNCION REGISTRAR PRODUCTO
void registrarProducto(){
    system("cls"); 
    char opc = 'S'; 
    int i=0; 
    do{
        cout<<"Digite el codigo del Producto "<<i+1<<" (XXX): "; cin>>_Producto[i].codigo_producto; 
        cout<<"Digite el nombre del Producto "<<i+1<<" : "; cin>>_Producto[i].nombre_producto; 
        cout<<"Digite la categoria del Producto "<<i+1<<": "; cin>>_Producto[i].categoria_producto; 
        
    }while((opc == 'S')||(opc == 's'));
    /*
    cout<<"Digite la cantidad de PRODUCTOS a registrar: "; cin>>max_productos; 
    Producto producto[max_productos]; 
    for(int i=0; i<max_productos; i++){
        cout<<"Digite el codigo del Producto "<<i+1<<" (XXX): "; cin>>producto[i].codigo_producto;
        cout<<"Digite el nombre del Producto "<<i+1<<" : "; cin>>producto[i].nombre_producto; 
        cout<<"Digite la categoria del Producto "<<i+1<<": "; cin>>producto[i].categoria_producto; 
        cout<<"Digite el precio unitario del Producto "<<i+1<<": "; cin>>producto[i].precio_unitario; 
        cout<<"Digite la cantidad de "<<producto[i].nombre_producto<<" que va a registrar: "; cin>>producto[i].cantidad_producto;
        cout<<"SUS DATOS DEL PRODUCTO "<<i+1<< "HAN SIDO REGISTRADOS CORRECTAMENTE..."<<endl<<endl; 
    }
    int opc; 
    cout<<"1. Volver al Menu Principal"<<endl;
    cout<<"2. Volver al Menu Productos"<<endl;
    cout<<"3. SALIR"<<endl<<endl; 
    cout<<"Digite una de las opciones: "; cin>>opc; 
    switch(opc){
    case 1:
        cout<<"Volviendo al Menu Principal..."; 
        Sleep(1500);  
        abrirMenu(); 
        break;
    case 2: 
        cout<<"Volviendo al Menu Prodcutos..."; 
        Sleep(1500); 
        abrirProductos(); 
        break; 
    case 3: 
        break; 
    default: 
        cout<<"Ha digitado una opcion erronea.."<<endl; 
        cout<<"Vovlviendo al Menú Principal..."; 
        Sleep(1500); 
        abrirMenu(); 
        break;  
    }*/

}

void modificarProducto(){

}

void verProducto(){

}

//FUNCION ABRIR EL MENU DE CLIENTES
void abrirClientes(){
    int opc; 
    system("cls"); 
    cout<<">>>>>>>> Clientes <<<<<<<<"<<endl<<endl; 
    cout<<"\t1.1 Registrar Cliente"<<endl; 
    cout<<"\t1.2 Modificar CLiente"<<endl; 
    cout<<"\t1.3 Ver Clientes"<<endl; 
    cout<<"\t1.4 Volver al menu principal"<<endl; 
    cout<<"\t1.5 Salir"<<endl<<endl; 
    cout<<"Elige una opcion :D : "; cin>>opc; 

    switch (opc){
    case 1:
        registrarCliente(); 
        break;
    case 2: 
        modificarCliente(); 
        break; 
    case 3: 
        verCliente();
        break; 
    case 4: 
        cout<<"Volviendo al menu principal..."<<endl; 
        Sleep(1500);
        abrirMenu(); 

    case 5: 
        break; 
    default:
        system("cls"); 
        cout<<"Ha seleccionado una opcion incorrecta intentelo otra vez..."<<endl; 
        cout<<"Volviendo al menu cliente..."<<endl; 
        Sleep(2000); 
        abrirClientes(); 
        break;
    }
}

void registrarCliente(){

}

void modificarCliente(){

}

void verCliente(){

}

void abrirProveedores(){
    int opc; 
    system("cls"); 
    cout<<">>>>>>>> PROVEEDORES <<<<<<<<"<<endl<<endl; 
    cout<<"\t1.1 Registrar Proveedor"<<endl; 
    cout<<"\t1.2 Modificar Proveedor"<<endl; 
    cout<<"\t1.3 Ver Proveedores"<<endl; 
    cout<<"\t1.4 Volver al menu principal"<<endl; 
    cout<<"\t1.5 Salir"<<endl<<endl; 
    cout<<"Elige una opcion :D : "; cin>>opc; 

    switch(opc){
    case 1: 
        registrarProveedor(); 
        break;
    case 2: 
        modificarProveedor();
        break;
    case 3: 
        verProveedores(); 
        break;
    case 4: 
        cout<<"Volviendo al menu principal..."<<endl; 
        Sleep(1500);
        abrirMenu(); 

    case 5: 
        break; 
        default:
            system("cls"); 
            cout<<"Ha seleccionado una opcion incorrecta intentelo otra vez..."<<endl; 
            cout<<"Volviendo al menu cliente..."<<endl; 
            Sleep(2000); 
            abrirClientes(); 
            break;
    }
}

void registrarProveedor(){

}

void modificarProveedor(){

}

void verProveedores(){

}

void abrirFactura(){
    int opc; 
    system("cls"); 
    cout<<">>>>>>>> FACTURACION <<<<<<<<"<<endl<<endl; 
    cout<<"\t1.1 Generar Factura"<<endl; 
    cout<<"\t1.2 Ver Facturas"<<endl; 
    cout<<"\t1.3 Volver al menu principal"<<endl; 
    cout<<"\t1.4 Salir"<<endl<<endl; 
    cout<<"Elige una opcion :D : "; cin>>opc;

    switch(opc){
    case 1: 
        generarFactura(); 
        break;
    case 2:
    verFacturas(); 
        break; 
    case 3: 
        cout<<"Volviendo al menu principal..."<<endl; 
        Sleep(1500);
        abrirMenu();

    case 4: 
        break; 
    default: 
        system("cls"); 
        cout<<"Ha seleccionado una opcion incorrecta intentelo otra vez..."<<endl; 
        cout<<"Volviendo al menu factura..."<<endl; 
        Sleep(2000); 
        abrirClientes();
        break; 
    }
    }

void generarFactura(){

}

void verFacturas(){

}