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
	int asiento[2];//añadi el asiento que ocupara la reserva en el vuelo
}datosclient[50];

void vuelo();
void generarvuelo();
void mostrarvuelo();
void modificarvuelo();
void cancelarvuelo();

void precios();

void reserva();
void generarReserva();
void mostrarReserva();
void modificarReserva();
void cancelarReserva();

int avionAsien[21][7]={0};//Este arreglo se mostrara al momento de seleccionar el asiento para la reserva(mas detalles en la funcion generarReserva)
int reservPosic=0;//nueva variable global, funciona igual que VueloEsp, para comtrolar los espacios en struct datacliente
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
		cout<<"2. Reservas."<<endl;
		cout<<"3. Modificar Precios."<<endl;
		cout<<"4. Salir. "<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			vuelo();
			break;
		case 2:
			reserva();
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
		int numeVuelo, indice=-1;//indice ayudara a seleccionar y establecer el espacio de struct datosvuelo a modificar
		cout<<"Ingrese el numero de vuelo que va a modificar: ";
		cin>>numeVuelo;
		for(int i=0;i<VueloEsp;i++){
			if(Plane[i].numeVuelo==numeVuelo){
				indice=i;
				break;
			}
		}
		if(indice!=-1){
			//Mostrara los datos anteriores para asistir al usuario en la modificacion
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
	void cancelarvuelo() {
		while (true) {
			system("cls");
			mostrarvuelo();
			int numeVuelo, indice=-1;
			cout<<"Ingrese el número del vuelo a cancelar (o -1 para salir al menú principal): ";
			cin>>numeVuelo;
			if(numeVuelo==-1){
				return;
			}
			for(int i=0;i<VueloEsp;i++){
				if(Plane[i].numeVuelo==numeVuelo){
					indice=i;
					break;
				}
			}
			if(indice!=-1){
				int confirmacion;
				while(true){
					cout<<"Solo para estar seguros... ¿Cancelar vuelo? Si (1) No (0): ";
					cin>>confirmacion;
					if(confirmacion==1){
						for(int i=indice;i<VueloEsp-1;i++){
							Plane[i]=Plane[i+1];
						}
						VueloEsp--;//cuando se cancela un vuelo, VueloEsp reduce en -1 y los vuelos que se encontraban despues del vuelo borrado, recorren un espacio hacia atras
						cout << "Vuelo cancelado exitosamente."<<endl;
						system("pause");
						return;
					}else if(confirmacion==0){
						cout<<"Cancelación de vuelo cancelada."<<endl;
						break;
					}else{
						cout<<"Opción inválida. Por favor, ingrese 1 para sí o 0 para no." << endl;
					}
				}
			}else{
				cout<<"Vuelo no encontrado."<<endl;
			}
		}
	}
	
	void reserva(){
		system("cls");
		int opc;
		cout<<"2.1. Generar una reserva"<<endl;
		cout<<"2.2. Mostrar reservas"<<endl;
		cout<<"2.3. Modificar reservas"<<endl;
		cout<<"2.4. Cancelar reserva"<<endl;
		cin>>opc;
		switch(opc){
		case 1:
			generarReserva();
			break;
		case 2:
			mostrarReserva();
			break;
		case 3:
			modificarReserva();
			break;
		case 4:
			cancelarReserva();
		case 5:
			break;
		}
	}
	void generarReserva() {
		int numeVuelo;
		int indice=-1;
		system("cls");
		mostrarvuelo();
		cout<<"Ingrese el numero del vuelo para reservar: ";
		cin >> numeVuelo;
		for(int i=0;i<VueloEsp;i++){
			if(Plane[i].numeVuelo==numeVuelo){
				indice=i;//si no se cumple el if, indice seguira siendo -1
				break;
				}
			}
		if(indice==-1){
			cout<<"Vuelo no encontrado."<<endl;
			system("pause");
			return;//vuelve al menu principal
		}
		cin.ignore();
		cout<<"Ingrese nombres: ";
		cin.getline(datosclient[reservPosic].nombres,30);
		cout<<"Ingrese apellidos: ";
		cin.getline(datosclient[reservPosic].apellidos,30);
		cout<<"Ingrese DNI: ";
		cin>>datosclient[reservPosic].DNI;
		cout<<"Ingrese correo: ";
		cin>>datosclient[reservPosic].correo;
		cout<<"Ingrese telefono: ";
		cin>>datosclient[reservPosic].telefono;
		datosclient[reservPosic].avion=numeVuelo;//se asigna el numero del vuelo a la reserva del pasajero
		datosclient[reservPosic].costoboleto=Plane[indice].precio;//igualmente al costo de su boleto
		
		int fila, columna;
		while(true){
			system("cls");
			int cont=0;
			for (int i=1; i<=20; i++) {
				for (int j=1;j<=6;j++) {
					if (j==4) {
						cont++;
						cout<< "   " <<cont<<"  ";//separadores y cont mostrara los numeros de las final
					}
					cout<<" "<<avionAsien[i][j];//separador, para que los 0 no se vean tan juntos
				}
				cout<<"\n";
			}
				
				cout<<"Escoja un lugar "<<endl;
				cout<<"Fila: ";
				cin>>fila;
				cout<<"Columna: ";
				cin>>columna;
				
				if(avionAsien[fila][columna]==0){//identificara si el espacio es un 0 (vacio)
					avionAsien[fila][columna]=1;//si se cumple el if, la seleccion se volvera 1
					datosclient[reservPosic].asiento[0]=fila;//se le da los numeros de las posiciones al asiento del datosclient que se esta usando
					datosclient[reservPosic].asiento[1]=columna;
					break;
				}else{
					cout<<"El asiento ya está ocupado. Seleccione otro asiento."<<endl;
					system("pause");
				}
			}
			
			cout<<"Reserva generada correctamente."<<endl;
			reservPosic++;//cuando se realice la reserva con exito, aumentara en 1 su valor y asi se podra llenar progresivamente
			system("pause");
		}
	void mostrarReserva(){//mostrara todas las reservas creadas
		system("cls");
		if(reservPosic==0){//si no hay reservas, manda un mensaje en la pantalla y vuelve al menu principal
			cout<<"No hay reservas para mostrar."<< endl;
			system("pause");
			return;
		}
		
		cout<<"------ RESERVAS ------"<<endl;
		for(int i=0;i<reservPosic;i++){
			cout<<"Reserva Nº"<<i+1<<endl;
			cout<<"Nombre: "<<datosclient[i].nombres<<endl;
			cout<<"Apellidos: "<<datosclient[i].apellidos<<endl;
			cout<<"DNI: "<<datosclient[i].DNI<<endl;
			cout<<"Correo: "<<datosclient[i].correo<<endl;
			cout<<"Teléfono: "<<datosclient[i].telefono<<endl;
			cout<<"Número de vuelo: "<<datosclient[i].avion<<endl;
			cout<<"Costo del boleto: "<<datosclient[i].costoboleto<<endl;
			cout<<"Asiento: Fila "<<datosclient[i].asiento[0]<<", Columna "<<datosclient[i].asiento[1]<<endl;
			cout<<"-------------------------" << endl;
		}
		system("pause");
	}	
	void modificarReserva(){
		
	}
	void cancelarReserva(){
		
	}
	
	
	void precios(){
		while(true){
			system("cls");
			mostrarvuelo();
			int numeVuelo, indice=-1;
			cout<<"Ingrese el numero de vuelo para cambiar su precio"<<endl;
			cout<<"(o ponga -1 para volver al menu principal): ";
			cin>>numeVuelo;
			if(numeVuelo==-1){
				return;
			}
			for(int i=0;i<VueloEsp;i++){
				if(Plane[i].numeVuelo==numeVuelo){
					indice=i;
					break;
				}
			}
			if(indice!=-1){
				float nuevoPrecio;//Permitira actualizar el precio del vuelo
				cout<<"Ingrese el nuevo precio para el vuelo Nº"<<Plane[indice].numeVuelo<<endl;
				cin>>nuevoPrecio;
				Plane[indice].precio=nuevoPrecio;
				cout<<"El precio fue actualizado."<<endl;
				system("pause");
				return;
			}else{
				cout<<"Numero de vuelo no encontrado, Intente nuevamente."<<endl;
			}
		}
	}
	
