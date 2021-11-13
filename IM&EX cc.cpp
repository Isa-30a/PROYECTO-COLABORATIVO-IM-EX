#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    //variables de opciones
    int op, op2, ofi,con_ofi, con_llamada;
    string con_fun;
    //variables 
    int MinXdependencia,llamadasXdependencia=1, min_lo1, min_lo2,min_lo3, min_rh1,min_rh2,min_rh3,min_finan1,min_finan2,min_finan3;
    //variables random
    int t_llamada,min,to_llamadas=12, k=0;//el valor de to_llamadas debe cambiarse

    //llamadas[minutos][tipo llamada][oficina];
    //matrices se realizaran debido a que el problema no pide (al menos explicitamente) que guarde la informacion del vector-> haremos esto de ultimo
    string nombre[12]={"Carlos","Luis","Pedro","Samara","Marta","Maria","Diego","Cielo","Alvaro","Daniel","Camila","Camilo"};//12 nombres
    //llamadas[minutos][tipo llamada][oficina];
    int llamadas[12][12]={{30,1,1},{10,3,3},{15,2,2},{19,1,1},{25,2,2},{5,2,1},{29,3,3},{2,2,1},{27,1,2},{21,3,1},{12,1,3},{15,3,2}};//12 llamadas
    
    //espacio para calcular el pago de las llamadas
    int pago[12];
    for(int i=0;i<12;i++){
        
       if(llamadas[i][1]==1) {//si la llamada es local tiene un costo de $80
           pago[i]=80*llamadas[i][0];
        }
       else if(llamadas[i][1]==2){
           pago[i]=800*llamadas[i][0];
        }
       else{
           pago[i]=1500*llamadas[i][0];
        }
    }


    do{
    //Menu general
        cout<<"\t\tIM&EX SA."<<endl;
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
                cout<<"Ingresar cantidad de llamadas realizadas"<<endl;cin>>to_llamadas;
                cout<<"Ingrese la oficina desde la cual se realiza la llamadas: "<<endl;
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

                
                break;
            case 2:// Reportes / consultas
                cout<<"1. Consulta por oficina"<<endl;
                cout<<"2. Consulta por tipo de llamada"<<endl;
                cout<<"3. Consulta llamadas por funcionario"<<endl;
                cout<<"4. Reporte de llamadas"<<endl;
                do{ 
                    cout<<"Ingrese la opcion: ";cin>>op2;
                }while(op2<1 && op2>4);
                //llamadas[minutos][tipo llamada][oficina];
                switch (op2){

                    case 1://Consulta por oficina
                        cout<<"Se encuentra en el espacio de consulta por oficina"<<endl;
                        cout<<"1. Logistica"<<endl;
                        cout<<"2. Recursos humanos"<<endl;
                        cout<<"3. Financiero "<<endl;
                        cout<<"Ingresar numero de la oficina a consultar: ";cin>>con_ofi;
                        cout<<setw(15)<<"# Llamada"<<setw(15)<<"Funcionario" <<setw(15)<<"Oficina"<<setw(15)<<"Tipo llamada"<<setw(15)<<"Cant minutos"<<setw(15)<<"Cant a pagar"<<endl;
                        for (int k = 0; k < to_llamadas; k++)
                        {
                            if(llamadas[k][2]==con_ofi){
                                cout<<setw(15)<<k+1<<setw(15)<<nombre[k]<<setw(15)<<llamadas[k][2]<<setw(15)<<llamadas[k][1]<<setw(15)<<llamadas[k][0]<<setw(15)<<pago[k]<<endl;
                            }
                        }
                        break;
                    case 2://Consulta por tipo de llamadas
                        MinXdependencia=0;
                        cout<<"Se encuentra en el espacio de consulta por tipo de llamadas "<<endl;
                        cout<<"1. Local"<<endl;
                        cout<<"2. Celular"<<endl;
                        cout<<"3. Internacional"<<endl;
                        cout<<"Ingresar el numero del tipo de llamada a consultar: ";cin>>con_llamada;
                        cout<<setw(15)<<"# Llamada"<<setw(15)<<"Funcionario" <<setw(15)<<"Oficina"<<setw(15)<<"Tipo llamada"<<setw(15)<<"Cant minutos "<<setw(15)<<"Min por dependencia "<<setw(15)<<"Cant de llamadas "<<endl;
                        for (int k = 0; k < to_llamadas; k++)
                        {
                            if(llamadas[k][1]==con_llamada){
                                MinXdependencia+=llamadas[k][0];
                                cout<<setw(15)<<k+1<<setw(15)<<nombre[k]<<setw(15)<<llamadas[k][2]<<setw(15)<<llamadas[k][1]<<setw(15)<<llamadas[k][0]<<setw(15)<<MinXdependencia<<setw(15)<<llamadasXdependencia<<endl;
                                llamadasXdependencia++;
                            }
                        }
                        break;
                    case 3://Consulta llamadas por funcionario
                        cout<<"Se encuentra en el espacio de consulta por funcionario "<<endl;cin>>con_fun;
                        cout<<setw(15)<<"# Llamada"<<setw(15)<<"Funcionario" <<setw(15)<<"Tipo llamada"<<setw(15)<<"Cant minutos "<<endl;
                        for (int g = 0; g < to_llamadas; g++)
                        {
                            if(nombre[g]==con_fun){
                                cout<<setw(15)<< g+1 <<setw(15)<< nombre[g] <<setw(15)<< llamadas[g][1] <<setw(15)<< llamadas[g][0] <<endl;
                            }
                        }

                        break;

                    default://Reporte de llamadas
                        min_lo1=0;
                        min_lo2=0;
                        min_lo3=0;
                        min_finan1=0;
                        min_finan2=0;
                        min_finan3=0;
                        min_rh1=0;
                        min_rh2=0;
                        min_rh3=0;
                        //llamadas[0 minutos][1 tipo llamada][2 oficina];
                        cout<<"Numero de llamadas realizadas: "<<to_llamadas<<endl;
                        cout<<setw(15)<<"# Llamada"<<setw(15)<<"Funcionario" <<setw(15)<<"Oficina"<<setw(15)<<"Tipo llamada"<<setw(15)<<"Cant minutos oficina"<<setw(15)<<""<<endl;
                        
                        for(int p=0;p<12;p++){
                            if(llamadas[p][2]==1){//en logistica
                                if(llamadas[p][1]==1){//llamadas locales
                                    min_lo1+=llamadas[p][0];
                                }
                                else if(llamadas[p][1]==2){//llamadas celular
                                    min_lo2+=llamadas[p][0];
                                }
                                else if(llamadas[p][1]==3){//llamadas internacionales
                                    min_lo3+=llamadas[p][0];
                                }
                            }
                            else if(llamadas[p][2]==2){//en recursos humanos
                                if(llamadas[p][1]==1){//llamadas locales
                                    min_rh1+=llamadas[p][0];
                                }
                                else if(llamadas[p][1]==2){//llamadas celular
                                    min_rh2+=llamadas[p][0];
                                }
                                else if(llamadas[p][1]==3){//llamadas internacionales
                                    min_rh3+=llamadas[p][0];
                                }
                                
                            }else{//en financiero
                                if(llamadas[p][1]==1){//llamadas locales
                                    min_finan1+=llamadas[p][0];
                                }
                                else if(llamadas[p][1]==2){//llamadas celular
                                    min_finan2+=llamadas[p][0];
                                }
                                else if(llamadas[p][1]==3){//llamadas internacionales
                                    min_finan3+=llamadas[p][0];
                                }
                            }
                            cout<<setw(15)<<p+1<<setw(15)<<nombre[p]<<setw(15)<<llamadas[p][2]<<setw(15)<<llamadas[p][1]<<setw(15)<<llamadas[p][0]<<pago[p]<<endl;
                        }
                        cout<<"\tLOGISTICA";
                        cout<<setw(15)<<"LLAMADAS LOCALES"<<setw(15)<<"LLAMADAS CELULARES "<<setw(15)<<"LLAMADAS INTERNACIONALES"<<endl;
                        for(int u=0; u<to_llamadas;u++){
                            cout<<setw(15)<<min_lo1<<setw(15)<<min_lo2<<setw(15)<<min_lo3<<endl;
                        }
                        cout<<"\tRECURSOS HUMANOS";
                        cout<<setw(15)<<"LLAMADAS LOCALES"<<setw(15)<<"LLAMADAS CELULARES "<<setw(15)<<"LLAMADAS INTERNACIONALES"<<endl;
                        for(int y=0;y<to_llamadas;y++){
                            cout<<setw(15)<<min_rh1<<setw(15)<<min_rh2<<setw(15)<<min_rh3<<endl;
                        }
                        cout<<"\tFINANCIERO";
                        cout<<setw(15)<<"LLAMADAS LOCALES"<<setw(15)<<"LLAMADAS CELULARES "<<setw(15)<<"LLAMADAS INTERNACIONALES"<<endl;
                        for(int r=0;r<to_llamadas;r++){
                            cout<<setw(15)<<min_finan1<<setw(15)<<min_finan2<<setw(15)<<min_finan3<<endl;
                        }
                    break;
                }

                break;
            case 3://Estadisticas



                break;
            default://Mensaje salida

                cout<<"Esta saliendo de IM&EX S.A"<<endl;
                system("pause");
                break;
        }
    }while(op!=4);





}
