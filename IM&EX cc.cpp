#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    //variables de opciones
    int op, op2, ofi,con_ofi, con_llamada,l,max,max_min,t=0,pos;
    string con_fun;
    //variables 
    int MinXdependencia,llamadasXdependencia=1, min_lo1, min_lo2,min_lo3, min_rh1,min_rh2,min_rh3,min_finan1,min_finan2,min_finan3;
    //variables random
    int t_llamada,min,to_llamadas=13, k=0;//el valor de to_llamadas debe cambiarse

    //llamadas[minutos][tipo llamada][oficina];
    //matrices se realizaran debido a que el problema no pide (al menos explicitamente) que guarde la informacion del vector-> haremos esto de ultimo
    string nombre[to_llamadas]={"Carlos","Luis","Pedro","Samara","Marta","Maria","Diego","Cielo","Alvaro","Daniel","Camila","Camilo","Cielo"};//12 nombres
    //llamadas[minutos][tipo llamada][oficina];
    int llamadas[to_llamadas][to_llamadas]={{30,1,1},{10,3,3},{15,2,2},{19,1,1},{25,2,2},{5,2,1},{29,3,3},{2,2,1},{27,1,2},{21,3,1},{12,1,3},{15,3,2},{20,2,1}};//12 llamadas
    
    //espacio para calcular el pago de las llamadas
    int pago[to_llamadas];
    for(int i=0;i<to_llamadas;i++){
        
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
    //espacio para calcular datos usados en la op 2 y 3
    
    

    do{
    //Menu general
        system("pause");
        system("cls");
        
        cout<<setw(15)<<"IM&EX SA."<<endl;
        cout<<"\tCONTROL DE LLAMADAS - CENTRO DE COMUNICACIONES"<<endl;
        cout<<"1. Registro de llamadas"<<endl;
        cout<<"2. Reportes"<<endl;
        cout<<"3. Estadisticas"<<endl;
        cout<<"4. Salir"<<endl;
        
        do{ 
            cout<<"Ingrese la opcion: ";cin>>op;
        }while(op<1 && op>4);
        system("cls");
        system("pause");
        //espacio para calcular datos usados en la op 2 y 3
        min_lo1=0;                
        min_lo2=0;
        min_lo3=0;
        min_finan1=0;
        min_finan2=0;
        min_finan3=0;
        min_rh1=0;
        min_rh2=0;
        min_rh3=0;
        for(int p=0;p<to_llamadas;p++){
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
            }
            else{//en financiero
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
        }
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
                //llamadas[minutos][tipo llamada][oficina];
                //llamadas[];
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
                        cout<<"Se encuentra en el espacio de consulta por funcionario "<<endl;
                        cout<<"Ingrese el nombre del funcionario: ";cin>>con_fun;
                        cout<<setw(15)<<"# Llamada"<<setw(15)<<"Funcionario" <<setw(15)<<"Tipo llamada"<<setw(15)<<"Cant minutos "<<endl;
                        for (int g = 0; g < to_llamadas; g++){
                            if(nombre[g]==con_fun){
                                cout<<setw(15)<< g+1 <<setw(15)<< nombre[g] <<setw(15)<< llamadas[g][1] <<setw(15)<< llamadas[g][0] <<endl;
                            }
                        }

                        break;

                    default://Reporte de llamadas
                        //llamadas[0 minutos][1 tipo llamada][2 oficina];
                        cout<<"Numero de llamadas realizadas: "<<to_llamadas<<endl;
                        cout<<setw(15)<<"# Llamada"<<setw(15)<<"Funcionario" <<setw(15)<<"Oficina"<<setw(15)<<"Tipo llamada"<<setw(15)<<"Minutos"<<setw(15)<<"Pago"<<setw(15)<<""<<endl;
                        
                        for(int e=0; e<to_llamadas;e++){
                            cout<<setw(15)<<e+1<<setw(15)<<nombre[e]<<setw(15)<<llamadas[e][2]<<setw(15)<<llamadas[e][1]<<setw(15)<<llamadas[e][0]<<setw(15)<<pago[e]<<endl;
                        }
                        cout<<"\tLOGISTICA"<<endl;
                        cout<<setw(15)<<"LLAMADAS LOCALES"<<setw(15)<<"LLAMADAS CELULARES "<<setw(15)<<"LLAMADAS INTERNACIONALES"<<endl;    
                        cout<<setw(15)<<min_lo1<<setw(15)<<min_lo2<<setw(15)<<min_lo3<<endl;

                        cout<<"\tRECURSOS HUMANOS"<<endl;
                        cout<<setw(15)<<"LLAMADAS LOCALES"<<setw(15)<<"LLAMADAS CELULARES "<<setw(15)<<"LLAMADAS INTERNACIONALES"<<endl;
                        cout<<setw(15)<<min_rh1<<setw(15)<<min_rh2<<setw(15)<<min_rh3<<endl;
                        
                        cout<<"\tFINANCIERO"<<endl;
                        cout<<setw(15)<<"LLAMADAS LOCALES"<<setw(15)<<"LLAMADAS CELULARES "<<setw(15)<<"LLAMADAS INTERNACIONALES"<<endl;
                        cout<<setw(15)<<min_finan1<<setw(15)<<min_finan2<<setw(15)<<min_finan3<<endl;
                        
                    break;
                
                }
                break;
            case 3://Estadisticas
                //1. Dependencia que realizó el mayor número de llamadas local, celular e internacional y el monto a pagar en cada caso.
                if(min_lo1>min_rh1 && min_lo1>min_finan1 ){//evaluamos cual de las locales es mayor
                    cout <<"\n\nLa dependencia de logistica realizo mayor número de llamadas locales con " << min_lo1 <<" \npara un monto total a pagar de $"<<min_lo1*80 <<endl;
                }
                else if(min_rh1>min_lo1 && min_rh1>min_finan1){
                    cout <<"\n\nLa dependencia de recursos humanos realizo mayor número de llamadas locales con " << min_rh1 <<" \npara un monto total a pagar de $"<<min_rh1*80 <<endl;

                } 
                else if(min_finan1>min_lo1 && min_finan1>min_rh1){
                    cout <<"\n\nLa dependencia de finanzas realizo mayor número de llamadas locales con " << min_finan1 <<" \npara un monto total a pagar de $"<<min_finan1*80 <<endl;
                }

                if(min_lo2>min_rh1 && min_lo2>min_finan2 ){//evaluamos cual de las celulares es mayor
                    cout <<"\n\nLa dependencia de logistica realizo mayor número de llamadas celulares con " << min_lo2 <<" \npara un monto total a pagar de $"<<min_lo2*800 <<endl;
                }
                else if(min_rh2>min_lo2 && min_rh2>min_finan2){
                    cout <<"\n\nLa dependencia de recursos humanos realizo mayor número de llamadas celulares con " << min_rh2 <<" \npara un monto total a pagar de $"<<min_rh2*800 <<endl;
                } 
                else if(min_finan2>min_lo2 && min_finan2>min_rh2){
                    cout <<"\n\nLa dependencia de finanzas realizo mayor número de llamadas celulares con " << min_finan2 <<" \npara un monto total a pagar de $"<<min_finan2*800 <<endl;
                }

                if(min_lo3>min_rh3 && min_lo3>min_finan3 ){//evaluamos cual de las internacionales es mayor
                    cout <<"\n\nLa dependencia de logistica realizo mayor número de llamadas internacionales con " << min_lo3 <<" \npara un monto total a pagar de $"<<min_lo3*1500 <<endl;
                }
                else if(min_rh3>min_lo3 && min_rh3>min_finan3){
                    cout <<"\n\nLa dependencia de recursos humanos realizo mayor número de llamadas internacionales con " << min_rh3 <<" \npara un monto total a pagar de $"<<min_rh3*1500 <<endl;
                } 
                else if(min_finan3>min_lo3 && min_finan3>min_rh3){
                    cout <<"\n\nLa dependencia de finanzas realizo mayor número de llamadas internacionales con " << min_finan3 <<" \npara un monto total a pagar de $"<<min_finan3*1500 <<endl;
                }

                //2. Llamada de mayor duración: indicar el funcionario(s), dependencia(s), tipo y tiempo duración 
                cout <<"\n\n Llamada de mayor duracion: "<<endl;
                cout<<"Funcionario" <<setw(15)<<"Oficina"<<setw(15)<<"Tipo llamada"<<setw(15)<<"Minutos"<<setw(15)<<""<<endl;
                max=0;
                for (t = 0; t < to_llamadas; t++){
                    if(llamadas[t][0]>llamadas[max][0]){
                        max=t;
                    }
                }
                cout<<nombre[max]<<setw(15)<<llamadas[max][2]<<setw(15)<<llamadas[max][1]<<setw(15)<<llamadas[max][0]<<endl;
               
                //3. Monto total a pagar por cada tipo de llamada (1: Local - 2: Celular - 3: Internacional) y el Tiempo promedio de las mismas
                cout<<"\n\n";
                cout<<"El total a pagar por las llamadas locales es de $" <<(min_lo1+min_rh1+min_finan1)*80<<" \ny posee un tiempo promedio de "<<(min_lo1+min_rh1+min_finan1)/3 << endl<<endl;
                cout<<"El total a pagar por las llamadas celular es de $" <<(min_lo2+min_rh2+min_finan2)*800<<" \ny posee un tiempo promedio de "<<(min_lo2+min_rh2+min_finan2)/3 << endl<<endl;
                cout<<"El total a pagar por las llamadas internacionales es de $" <<(min_lo3+min_rh3+min_finan3)*1500<<" \ny posee un tiempo promedio de "<<(min_lo3+min_rh3+min_finan3)/3 << endl<<endl;
                
                //4. Nombre del funcionario que realizó el mayor número de llamadas, indicando a que oficina pertenece y la cantidad de llamadas que realizó
                cout<<"\n\nFuncionario con mayor numero de llamadas realizadas: "<<endl;
                max=0;
                for (int w = 0; w < to_llamadas; w++){
                    max_min=0;
                    //for para guardar el mayor numero de llamadas
                    for (int q=0; q < to_llamadas; q++){
                        if(nombre[q]==nombre[w]){//nombre[w] debe ser un valor fijo que se aumentara cuando salga del ciclo
                            max_min++;
                            max=max_min;
                        }
                    }
                    if(max_min>max){
                        max=max_min;
                        pos=w;
                    }
                }
                
                cout<<"Funcionario" <<setw(15)<<"Oficina"<<setw(25)<<"Llamadas realizadas" << setw(15)<<""<<endl;                       
                cout<<nombre[pos]<<setw(15)<<llamadas[pos][2]<<setw(15)<<max<<endl;
                break;

            default://Mensaje salida

                cout<<"Esta saliendo de IM&EX S.A"<<endl;
                system("pause");
                break;
        }
    }while(op!=4);





}
