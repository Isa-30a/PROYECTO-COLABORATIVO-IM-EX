#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    //variables de opciones
    int op,op2, ofi;
    //variables vectores
    int ;
    //variables random
    int t_llamada,min,to_llamadas;


    cout<<"Ingresar cantidad de llamadas realizadas";cin>>to_llamadas;

    //matrices se realizaran debido a que el problema no pide (al menos explicitamente) que guarde la informacion del vector
    string nombre[12]={"Carlos","Luis","Pedro","Samara","Marta","Maria","Diego","Cielo","Alvaro","Daniel","Camila","Camilo"};//12 nombres
    int oficina[12]={1,3,2,1,2,1,3,2,1,2,3,1};//12 llamadas
    int llamadas[12][12]={{30,1},{10,3},{15,2},{19,1},{25,2},{5,2},{29,3},{2,2},{27,1},{21,3},{12,1},{15,3}};//12 llamadas
    /*
    Nombre del funcionario que realizó la llamada
    Oficina o dependencia de la cual se realiza la llamada (1: Logística; 2: Recursos humanos; 3: Financiero)
    Cantidad de minutos de la llamada
    Tipo de llamada (1: local; 2: celular; 3: internacional).
    */
   




    cout<<"Ingrese la oficina desde la cual se realiza la llamadas: ";
    cout<<"1. Logistica"<<endl;
    cout<<"2. Recursos humanos"<<endl;
    cout<<"3. Financiero "<<endl;    
    do{
        cout<<"Ingrese la opcion: ";cin>>ofi;
    }while(ofi>3 && ofi<1);

    do{
        cout<<"Ingrese la duracion de la llamada (minutos): ";cin>>min;

        if(min<1 && min<30){
            cout<<"Favor ingresar una cantidad valida ";
        }
    }while(min<1 && min<30);

    
    cout<<"Ingresar el tipo de llamada: "<<endl;
    cout<<"1. Local"<<endl;
    cout<<"2. Celular"<<endl;
    cout<<"3. Internacional"<<endl;
    do{
        cin>>t_llamada;
    }while(t_llamada<1 && t_llamada>3);
    cout<<"\tIM&EX SA."<<endl;
    cout<<"\tCONTROL DE LLAMADAS - CENTRO DE COMUNICACIONES"<<endl;
    cout<<"1. Registro de llamadas"<<endl;
    cout<<"2. Reportes"<<endl;
    cout<<"3. Estadisticas"<<endl;
    cout<<"4. Salir"<<endl;
    
    do{ 
        cout<<"Ingrese la opcion: ";cin>>op;
    }while(op<1 && op>4);

    switch (op){
        case 1://Registro de llamadas
            

            
            break;
        case 2:// Reportes / consultas
            cout<<"1. Consulta por oficina"<<endl;
            cout<<"2. Consulta por tipo de llamada"<<endl;
            cout<<"3. Consulta llamadas por funcionario"<<endl;
            cout<<"4. Reporte de llamadas"<<endl;
            do{ 
                cout<<"Ingrese la opcion: ";cin>>op2;
            }while(op2<1 && op2>4);

            break;
        case 3://Estadisticas



            break;
        default://Mesnsaje salida

            cout<<"Esta saliendo de IM&EX S.A"<<endl;
            system("pause");
            break;
    }






}