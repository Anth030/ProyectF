#include <iostream>
#include <cstring>
using namespace std;

struct datosvuelo{
	int fechaVuelo;
	int horaVuelo;
	char destino[20];
	int numeVuelo;
	float precio;
}Plane[6];

struct datacliente{
	char nombres[30];
	char apellidos[30];
	int DNI;
	char correo[20];
	int telefono;
	int avion;
	int costoboleto;
}datosclient[50];

void vuelo();
void generarvuelo();
void mostrarvuelo();
void modificarvuelo();
void cancelarvuelo();

void passenger();
void buscarReserva();
void mostrarReserva();

void precios();
void modificarprecios();

int VueloEsp=0;//Este valor es para que al crearse un vuelo solo
//avance en 1 el espacio de struct "datosvuelo" y asi generar vuelos individualmente
//repitiendo la selecion de los menus
int main(){
	int opcion;
	bool repetir=true;
	do{
		system("cls");
		cout<<"-------SISTEMA DE AEROPUERTO-------"<<endl;
		cout<<"1. Vuelos."<<endl;
		cout<<"2. Pasajeros y Reservas."<<endl;
		cout<<"3. Precios."<<endl;
		cout<<"4. Salir. "<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			vuelo();
			break;
		case 2:
			passenger();
			break;
		case 3:
			precios();
			break;
		case 4:
			repetir=false;
			break;
		}
	} while(repetir);
	return 0;
}
	
	void vuelo(){
		system("cls");
		int opc;
		cout<<"1.1. Generar vuelo."<<endl;
		cout<<"1.2. Mostrar vuelos."<<endl;
		cout<<"1.3. Modificar vuelo."<<endl;
		cout<<"1.4. Cancelar vuelo."<<endl;
		cout<<"1.5. Volver."<<endl;
		cin>>opc;
		switch(opc){
		case 1:
			generarvuelo();
			break;
		case 2:
			mostrarvuelo();
			break;
		case 3:
			modificarvuelo();
			break;
		case 4:
			cancelarvuelo();
		case 5:
			break;
		}
	}

//llenando la memoria del struct datosvuelo(un espacio)
	void generarvuelo(){
		if(VueloEsp<6){//VueloEsp, valor global importante para llenar el struct
		system("cls");
		cin.ignore();
		cout<<"Destino del vuelo "<<"Nº"<<VueloEsp+1<<endl;
		cin.getline(Plane[VueloEsp].destino,20);
		cout<<"Fecha de vuelo "<<endl;
		cin>>Plane[VueloEsp].fechaVuelo;
		cout<<"Hora de vuelo "<<endl;
		cin>>Plane[VueloEsp].horaVuelo;
		cout<<"Nº numero de vuelo "<<endl;
		cin>>Plane[VueloEsp].numeVuelo;
		cout<<"Precio de vuelo "<<endl;
		cin>>Plane[VueloEsp].precio;
		VueloEsp++;
	}else{
		cout<<"Se ha alcanzado el máximo número de vuelos creados."<<endl;
		}
	}
	
	void mostrarvuelo(){
		system("cls");
		for(int i=0;i<VueloEsp;i++){
			cout<<"Vuelo Nº"<<i+1<<endl;
			cout<<"Destino: "<<Plane[i].destino<<endl;
			cout<<"Fecha: "<<Plane[i].fechaVuelo<<endl;
			cout<<"Hora de partida: "<<Plane[i].horaVuelo<<endl;
			cout<<"Numero de vuelo: "<<Plane[i].numeVuelo<<endl;
			cout<<"Precio: "<<Plane[i].precio<<endl;
			cout<<"----------------------------------"<<endl;
			cout<<"\n";
		}
		system("pause");
	}
	void modificarvuelo(){
		system("cls");
		mostrarvuelo();
		int numeVuelo, indice=0;//indice ayudara a seleccionar y establecer el espacio de struct datosvuelo a modificar
		cout<<"Ingrese el numero de vuelo que va a modificar: ";
		cin>>numeVuelo;
		for(int i=0;i<VueloEsp;i++){
			if(Plane[i].numeVuelo==numeVuelo){
				indice=i;
				break;
			}
		}
		if(indice!=-1){//Mostrara los datos anteriores para asistir al usuario en la modificacion
			cout<<"Modificando vuelo Nª"<<numeVuelo<<endl;
			cout<<"Destino actual: "<<Plane[indice].destino<<endl;
			cout<<"Nuevo destino: ";
			cin.ignore();
			cin.getline(Plane[indice].destino,20);
			cout<<"Fecha actual: "<<Plane[indice].fechaVuelo<<endl;
			cout<<"Nueva fecha: ";
			cin>>Plane[indice].fechaVuelo;
			cout<<"Hora actual: "<<Plane[indice].horaVuelo<<endl;
			cout<<"Nueva hora: ";
			cin>>Plane[indice].horaVuelo;
			cout<<"Numero de vuelo actual: "<<Plane[indice].numeVuelo<<endl;
			cout<<"Nuevo numero de vuelo: ";
			cin>>Plane[indice].numeVuelo;
			cout<<"Precio actual: "<<Plane[indice].precio<<endl;
			cout<<"Nuevo precio: ";
			cin>>Plane[indice].precio;
		}else{
			cout<<"Vuelo no encontrado."<<endl;
		}
		system("pause");
	}
	void cancelarvuelo(){
		system("cls");
		mostrarvuelo();
		int numeVuelo, indice=0;
		cout<<"Ingrese el numero del vuelo a cancelar."<<endl;
		cin>>numeVuelo;
		for(int i=0;i<VueloEsp;i++){
			if(Plane[i].numeVuelo==numeVuelo){
				indice=i;
				break;
			}
		}
		if(indice!=-1){
			for(int i=indice;i<VueloEsp-1;i++){
				Plane[i]=Plane[i+1];
			}
			VueloEsp--;
			cout<<"El vuelo a sido cancelado correctamente."<<endl;
		}else{
			cout<<"Vuelo no encontrado."<<endl;
		}
		system("pause");
	}
	void precios(){
		
	}
	void passenger(){
		
	}
