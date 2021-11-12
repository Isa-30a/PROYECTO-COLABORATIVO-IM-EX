#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    //variables de opciones
    int op,op2, ofi;
    //variables vectores
    int llamadas;
    //variables random
    int t_llamada,min;
    cout<<"Ingresar cantidad de llamadas realizadas";cin>>llamadas;
    string nombres[llamadas];

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