#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
			
using namespace std;

int tamhash = 10;

struct genCOV{
	string codigo; //clave
};

typedef struct genCOV covid;
covid tabla_Hash[ 7 ];
	
void tabla_hash(  ){
	for( int i = 0; i < 10; i++ ){
		tabla_Hash[ i ].codigo = " vacio ";
	}
}

long suma_Caracteres( string clave ){
	long suma = 0;
	
	for( int j = 0; j < clave.length(); j++ ){
		suma = suma*27 + clave[ j ];
	}
	return suma;
}

int funcion_hash( string clave ){
	long suma;
	
	suma = suma_Caracteres( clave );
	
	int indice_Hash;
	
	indice_Hash = suma%10;
	return indice_Hash;
}

int colisiones( string clave, int indice_Hash ){
	int i = 0;
	
	string codigo = tabla_Hash[ indice_Hash ].codigo;
	while ( codigo != " vacio " ){
		i++;
		indice_Hash = indice_Hash + i * i;
		indice_Hash = indice_Hash%10;
		codigo = tabla_Hash[ indice_Hash ].codigo;
	}
	return indice_Hash;
}

void Insertar( string clave){
	int indice_Hash;
	
	indice_Hash = funcion_hash( clave );
	indice_Hash = colisiones( clave, indice_Hash );
	tabla_Hash[ indice_Hash ].codigo = clave;
}

void imprimir(){
	for( int i = 0; i < tamhash; i++ ){
		cout << i << " | " << tabla_Hash[ i ].codigo << endl;
		for( int i = 0; i < 40; i++ ){
			cout << " - ";
		}
	cout << "\n";
	}
}

int Menu(  ){
	int opcion;
	
	cout << " \t-------" << endl;
	cout << " \tMenu"    << endl;
	cout << " \t-------" << endl;
	cout << " \n\t1. Ingresar ";
	cout << " \n\t2. buscar ";
	cout << " \n\t3. eliminar ";
	cout << " \n\t4. Mostrar ";
	cout << " \n\t5. Finalizar";
	cout << " \n\tIngrese un numero --> ";
	cin  >> opcion; 
	return opcion;
}

int buscar( string clave ){
	int encontrado = -1;
	int indice_Hash = funcion_hash( clave );
	string codigo = tabla_Hash[ indice_Hash ].codigo;
	
	if( codigo != " vacio " ){
		encontrado = indice_Hash;
	} 
	return encontrado;
}

int eliminar( string clave ){
	int indice_Hash;
	int eliminado = 0;
	
	indice_Hash = funcion_hash( clave );
	string codigo = tabla_Hash[ indice_Hash ].codigo;
	
	if( codigo != " vacio " ){
		tabla_Hash[ indice_Hash ].codigo = " vacio ";
		eliminado = 1;
	} 
	return eliminado;
}


main( void ){
	int opcion; int encontrado; int eliminado; // string actualizar
	string clave; int indice_Hash;
	
	tabla_hash(  );
	while( 1 ){
		opcion = Menu(  );
		switch( opcion ){
			case 1: //insertar
				cout << "\n";
				cout << "Codigo: ";
				cin  >> clave;
				cout << "\n"; 
				Insertar( clave );
				break;
			case 2: //buscar
				cout << "Codigo: ";
				cin  >> clave;
				encontrado = buscar( clave );
				if( encontrado != -1 ){
					cout << " \nDatos encontrados: " << endl;
					cout << " codigo: " << tabla_Hash[ encontrado ].codigo << endl;
				}if( encontrado == -1 ){
					cout << "\n";
					cout << " No existe codigo " << endl;
				}
				break;
			case 3: //eliminar
				cout << "Codigo: ";
				cin  >> clave;
				eliminado = eliminar( clave );
				if( eliminado == 1 ){
					cout << "Codigo Eliminados " << endl;
				}else{
					cout << "Codigo no existente " << endl;
				}	
				break;
			case 4: // Mostrar
				imprimir(  );
				break;
			case 5: //finalizar
				exit( 0 );
				break;	
		} 
	}
}