#include <iostream>

using namespace std;

int main(){
    //variables de opciones
    int op,op2;

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