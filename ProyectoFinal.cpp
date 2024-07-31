//codigo casi finalizado
#include <iostream>
#include <cstring>
using namespace std;

struct datosvuelo{
	int fechaVuelo;
	int horaVuelo;
	char destino[20];
	int numeVuelo;
	float precio;
	int EsqAsien[21][7];//matriz que guarda los asientos de las reservas de cada vuelo 
}Plane[6];

struct datacliente{
	char nombres[30];
	char apellidos[30];
	int DNI;
	char correo[20];
	int telefono;
	int avion;
	int costoboleto;
	int asiento[2];//guarda la fila y columna del asiento de una reserva
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

int reservPosic=0;//variable global para controlar los espacios de datosclient
int VueloEsp=0;//variable global que controla los espacios de Plane

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
		default:
			cout<<"Opcion invalida. Intentelo de nuevo."<<endl;
			system("pause");
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
		cout<<"1.3. Cambiar o retrasar fecha y hora de vuelo."<<endl;
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
			break;
		case 5:
			break;
		default:
			cout<<"Opcion invalida. Intentelo de nuevo."<<endl;
			system("pause");
			break;
		}
	}

//llenando la memoria del struct datosvuelo(un espacio)
	void generarvuelo(){
		if(VueloEsp<6){
			system("cls");
			cin.ignore();
			cout<<"Destino del vuelo Nº"<<VueloEsp+1<<endl;
			cin.getline(Plane[VueloEsp].destino,20);
			cout<<"Fecha de vuelo: "<<endl;
			cin>>Plane[VueloEsp].fechaVuelo;
			cout<<"Hora de vuelo: "<<endl;
			cin>>Plane[VueloEsp].horaVuelo;
			cout<<"Nº número de vuelo: "<<endl;
			cin>>Plane[VueloEsp].numeVuelo;
			cout<<"Precio de vuelo: "<<endl;
			cin>>Plane[VueloEsp].precio;
			//aqui se crea la matriz para EsqAsien para un vuelo
			for(int i=1;i<=20;i++){
				for(int j=1;j<=6;j++){
					Plane[VueloEsp].EsqAsien[i][j]=0;
				}
			}
			VueloEsp++;
		}else{
			cout<<"Se ha alcanzado el máximo número de vuelos creados."<<endl;
		}
	}

	void mostrarvuelo(){//muestra todos los vuelos creados
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
	//ahora funcion modificarvuelo solo cambia la fecha y hora de un vuelo
	void modificarvuelo(){
		system("cls");
		mostrarvuelo();
		int numeVuelo, indice=-1;
		cout<<"Ingrese el número del vuelo que va a modificar: ";
		cin>>numeVuelo;
		for(int i=0;i<VueloEsp;i++){
			if(Plane[i].numeVuelo==numeVuelo){
				indice=i;
				break;
			}
		}
		if(indice!=-1){
			cout<<"Modificando vuelo Nº"<<numeVuelo<<endl;
			cout<<"Fecha anterior: "<<Plane[indice].fechaVuelo<<endl;
			cout<<"Nueva fecha: ";
			cin>>Plane[indice].fechaVuelo;
			cout<<"Hora anterior: "<<Plane[indice].horaVuelo<<endl;
			cout<<"Nueva hora: ";
			cin>>Plane[indice].horaVuelo;
			cout<<"Número de vuelo: "<<Plane[indice].numeVuelo<<endl;
			cout<<"Precio actual: "<<Plane[indice].precio<<endl;
			cout<<"Para cambiar el precio deberá ir a la opción de Precios en el menú principal."<<endl;//una indicacion para el usuario
		}else{
			cout<<"Vuelo no encontrado."<<endl;
		}
		system("pause");
	}
	void cancelarvuelo(){
		while(true){
			system("cls");
			mostrarvuelo();
			int numeVuelo, indice=-1;
			cout<<"Ingrese el numero del vuelo a cancelar (o -1 para salir al menu principal): ";
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
						//la matriz del vuelo tambien sera borrada
						for(int fila=1;fila<=20;fila++){
							for(int columna=1;columna<=6;columna++){
								if(Plane[indice].EsqAsien[fila][columna]==1){
									Plane[indice].EsqAsien[fila][columna]=0;
								}
							}
						}
						for(int i=indice;i<VueloEsp-1;i++){
							Plane[i]=Plane[i+1];
						}
						VueloEsp--;//VueloEsp resta en -1 el tamaño de datosvuelo
						cout<<"Vuelo cancelado exitosamente."<<endl;
						system("pause");
						return;
					}else if(confirmacion==0){
						cout<<"Cancelacion de vuelo cancelada."<<endl;
						break;
					}else{
						cout<<"Opcion invalida. Por favor, ingrese 1 para Si o 0 para No."<<endl;//repite la solicitud de confirmacion, si no se introduce una opcion diferente de 1 o 0
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
		cout<<"2.5. Volver"<<endl;
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
		default:
			cout<<"Opcion invalida. Intentelo de nuevo."<<endl;
			system("pause");
			break;
		}
	}
	void generarReserva(){
		system("cls");
		mostrarvuelo();
		if(reservPosic<50){//para que no sobrepase la memoria de datosclient
			int numeVuelo;
			cout<<"Ingrese el número del vuelo para reservar: ";
			cin>>numeVuelo;
			int indice=-1;
			for(int i=0;i<VueloEsp;i++){
				if(Plane[i].numeVuelo==numeVuelo){
					indice=i;
					break;
				}
			}
			if(indice!=-1){
				cin.ignore();
				cout<<"Ingrese nombres: ";
				cin.getline(datosclient[reservPosic].nombres,30);
				cout<<"Ingrese apellidos: ";
				cin.getline(datosclient[reservPosic].apellidos,30);
				cout<<"Ingrese DNI: ";
				cin>>datosclient[reservPosic].DNI;
				cin.ignore();
				cout<<"Ingrese correo: ";
				cin.getline(datosclient[reservPosic].correo,20);
				cout<<"Ingrese telefono: ";
				cin>>datosclient[reservPosic].telefono;
				datosclient[reservPosic].avion=numeVuelo;
				datosclient[reservPosic].costoboleto=Plane[indice].precio;
				system("cls");
				//mostrando la matriz de asientos
				cout<<"----Vista de Asientos del Avion---Nº"<<numeVuelo<<endl;
				cout<<"    "<<endl;
				for(int i=1;i<=20;i++){
					cout<<"HH    ";
					for(int j=1;j<=6;j++){
						cout<<Plane[indice].EsqAsien[i][j]<<" ";
						if(j==3){
							cout<<"    ";
						}
					}
					cout<<"    HH"<<endl;
				}
				cout<<" "<<endl;
				int fila, columna;//para llenar asiento[0] y asiento[1]
				cout<<"Ingrese el número de fila (1-20): ";
				cin>>fila;
				cout<<"Ingrese el número de columna (1-6): ";
				cin>>columna;
				if(Plane[indice].EsqAsien[fila][columna]==0){
					Plane[indice].EsqAsien[fila][columna]=1;
					datosclient[reservPosic].avion=numeVuelo;
					datosclient[reservPosic].asiento[0]=fila;
					datosclient[reservPosic].asiento[1]=columna;
					reservPosic++;
					cout<<"Reserva realizada con éxito."<<endl;
				}else{
					cout<<"El asiento ya está ocupado."<<endl;
				}
			}else{
				cout<<"Vuelo no encontrado."<<endl;
			}
		}else{
			cout<<"Se ha alcanzado el máximo número de reservas."<<endl;
		}
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
			system("cls");
			if(reservPosic==0){
				cout<<"No hay reservas para modificar."<<endl;
				system("pause");
				return;
			}
			mostrarReserva();
			cout<<" "<<endl;
			int dni, indice=-1;
			cout<<"Ingrese el DNI de la reserva a modificar: ";
			cin>>dni;
			for(int i=0;i<reservPosic;i++){
				if(datosclient[i].DNI==dni){
					indice=i;
					break;
				}
			}
			if(indice==-1){
				cout<<"Reserva no encontrada para el DNI "<<dni<<endl;
				system("pause");
				return;
			}
			//mostrando vuelos existentes
			mostrarvuelo();
			cout<<" "<<endl;
			int nuevoVuelo, nuevoIndice=-1;
			cout<<"Ingrese el número del nuevo vuelo al que desea cambiar la reserva: ";
			cin>>nuevoVuelo;
			for(int i=0;i<VueloEsp;i++){
				if(Plane[i].numeVuelo==nuevoVuelo){
					nuevoIndice=i;
					break;
				}
			}
			if(nuevoIndice==-1){
				cout<<"Nuevo vuelo no encontrado."<<endl;
				system("pause");
				return;
			}
			//mostrara la matriz de asientos del vuelo al que se cambiara
			system("cls");
			cout<<"----Vista de Asientos del Avion---Nº"<<nuevoVuelo<<endl;
			cout<<"  "<<endl;
			for(int i=1;i<=20;i++){
				cout<<"HH    ";
				for(int j=1;j<=6;j++){
					cout<<Plane[nuevoIndice].EsqAsien[i][j]<<" ";
					if(j==3) {
						cout<<"    ";
					}
				}
				cout<<"    HH"<<endl;
			}
			cout<<" "<<endl;
			
			int fila, columna;
			cout<<"Ingrese el número de fila (1-20): ";
			cin>>fila;
			cout<<"Ingrese el número de columna (1-6): ";
			cin>>columna;
			if(Plane[nuevoIndice].EsqAsien[fila][columna]==0){
				Plane[nuevoIndice].EsqAsien[fila][columna]=1;
				datosclient[indice].avion=nuevoVuelo;
				datosclient[indice].asiento[0]=fila;
				datosclient[indice].asiento[1]=columna;
				datosclient[indice].costoboleto=Plane[nuevoIndice].precio;
				cout<<"Reserva modificada exitosamente."<<endl;
			} else {
				cout<<"El asiento ya está ocupado."<<endl;
			}
			system("pause");
		}

	void cancelarReserva(){
		system("cls");
		if(reservPosic==0){
			cout<<"No hay reservas para cancelar."<<endl;
			system("pause");
			return;
		}
		mostrarReserva();
		int dni, indice=-1;
		cout<<"Ingrese el DNI de la reserva a cancelar: ";
		cin>>dni;
		for(int i=0;i<reservPosic;i++){
			if(datosclient[i].DNI==dni){
				indice=i;
				break;
			}
		}
		if(indice==-1){
			cout<<"Reserva no encontrada para el DNI "<<dni<<endl;
			system("pause");
			return;
		}
		//confirmacion para cancelacion
		int confirmacion;
		cout<<"¿Está seguro que desea cancelar la reserva? Si (1) No (0): ";
		cin>>confirmacion;
		if(confirmacion!=1){
			cout<<"Cancelación de reserva abortada."<<endl;
			system("pause");
			return;
		}
		//libera el asiento del vuelo anterior
		int numVuelo=datosclient[indice].avion;
		int fila=datosclient[indice].asiento[0];
		int columna=datosclient[indice].asiento[1];
		for(int i=0;i<VueloEsp;i++){
			if(Plane[i].numeVuelo==numVuelo){
				Plane[i].EsqAsien[fila][columna]=0;
				break;
			}
		}
	}
		//elimina la reserva
		for(int i=indice;i<reservPosic-1;i++){
			datosclient[i]=datosclient[i+1];
		}
		reservPosic--;
		cout<<"Reserva cancelada exitosamente."<<endl;
		system("pause");
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
	
