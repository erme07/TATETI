#include<stdio.h>
#include<time.h>
#include<stdbool.h>


void iniciar(char tablero[3][3]);             //prototipos de las funciones
void llenar_tablero(char tablero[3][3]);
void imprimir_tablero(char tablero[3][3]);
void seleccionar_casilla(char tablero[3][3]);
void select_maquina(char tablero[3][3]);
char resultado(char tablero[3][3]);

int main(){    //funcion main 
	
	char tablero[3][3];    //declaro la matriz del tablero
	int opcion;
	
	do{
		iniciar(tablero);
		printf("\nSI = 1    NO = 2\n");
		printf("\nDesea jugar otra vez? :");
		scanf("%i",&opcion);
		
	}while(opcion==1);         //opcion para volver a jugar o salir
	     
	return 0;
}


void iniciar(char tablero[3][3]){   // funcion que llama a todas las funciones
	
	int i=0;
	char ganador;
	
	llenar_tablero(tablero);
	
	do{
		system("cls");
		imprimir_tablero(tablero);
		
		if(i % 2==0){
			seleccionar_casilla(tablero);
			ganador=resultado(tablero);
		}
		
		else{
			select_maquina(tablero);
			ganador=resultado(tablero);
		}
		
		if(ganador=='X'||ganador=='O'){
			i=12;
		}
		i++;
	}while(i<9);
	
	if(ganador=='X'){
		system("cls");
		imprimir_tablero(tablero);
		printf("\nGanaste!!\n");
	}
	else if(ganador=='O'){
		system("cls");
		imprimir_tablero(tablero);
		printf("\nPerdiste\n");
	}
	else if(ganador=='e'){
		system("cls");
		imprimir_tablero(tablero);
		printf("\nEmpate\n");
	}
}

void llenar_tablero(char tablero[3][3]){    //llena los campos de la matriz con los numeros de 1 a 9
	
	int i,j;
	char valor='1';
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			tablero[i][j]=valor++;
		}
	}
	
}

void imprimir_tablero(char tablero[3][3]){    //imprime los campos de la matriz en pantalla
	
	printf("\n\n\t %c | %c | %c",tablero[0][0],tablero[0][1],tablero[0][2]);
	printf("\n\t-----------\n");
	printf("\t %c | %c | %c",tablero[1][0],tablero[1][1],tablero[1][2]);
	printf("\n\t-----------\n");
	printf("\t %c | %c | %c\n\n",tablero[2][0],tablero[2][1],tablero[2][2]);
	
}

void seleccionar_casilla(char tablero[3][3]){   //el jugador selecciona la casilla a marcar con "X"
	
	char seleccion;
	int i,j,aux;
	
	do{
		do{
			printf("Seleccione el numero: ");
			fflush(stdin);
			scanf("%c",&seleccion);
			
		}while(seleccion < '1' || seleccion > '9');
		
		aux=0;
		switch(seleccion){
			
			case '1':{
				
				i=0;
				j=0;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
			case '2':{
				
				i=0;
				j=1;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
			case '3':{
				
				i=0;
				j=2;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
			case '4':{
				
				i=1;
				j=0;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
			case '5':{
				
				i=1;
				j=1;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
			case '6':{
				
				i=1;
				j=2;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
			case '7':{
				
				i=2;
				j=0;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
			case '8':{
				
				i=2;
				j=1;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
			case '9':{
				
				i=2;
				j=2;
				if(tablero[i][j]=='X'||tablero[i][j]=='O'){
					
					aux=1;
					printf("La casilla esta ocupada... Intentalo con otro numero\n\n");
				}
				
				break;
			}
		}
		
	}while(aux==1);
	
	tablero[i][j]='X';
}

void select_maquina(char tablero[3][3]){    //la maquina selecciona una casilla al azar y marca un "O"
	
	int i,j,aux;
	srand(time(NULL)); 
	do{
		i=rand()%3;  //asigno numero aleatorio (0,1,2) modulo 3 (%3)
		j=rand()%3;
		aux=0;
		
		if(tablero[i][j]=='O'||tablero[i][j]=='X'){
			
			aux=1;
		}	
	}while(aux==1);
	
	tablero[i][j]='O';
}

char resultado(char tablero[3][3]){      //Corrobora cuando y quien gana, o si hay empate
	
	int i;
	bool aux,aux1,aux2;
	char ganador='e';
	
	for(i=0;i<3;i++){
		
		aux1=tablero[i][0]==tablero[i][1] ? tablero[i][0]==tablero[i][2] : false;  //si alguna fila tiene sus casilleros con el mismo valor devuelve TRUE si no devuelve FAlSE   
		aux2=tablero[0][i]==tablero[1][i] ? tablero[2][i]==tablero[0][i] : false;  //si alguna columna tiene sus casilleros iguales devuelve TRUE si no devuelve FALSE                             
		if(aux1==true){
			
			ganador=tablero[i][0];  //guarda el valor que se repite en la fila
			return ganador;         //devuelve el valor y salgo de la funcion
		}
		
		if(aux2==true){
			ganador=tablero[0][i]; //guarda el valor que se repite en la comlumna
			return ganador;       //devuelve el valor y salgo de la funcion
		}
		
	}

	aux=tablero[0][0]==tablero[1][1] ? tablero[2][2]==tablero[0][0] : false; //Verifica los casilleros diagonales
	if(aux==true){
				ganador=tablero[0][0];
				return ganador;
			}
			
	aux=tablero[0][2]==tablero[1][1] ? tablero[2][0]==tablero[0][2] : false; //verifica casilleros diagonales
	if(aux==true){
				ganador=tablero[0][2];
				return ganador;
			}
			
	return ganador;  //si no encontro filas, columnas o diagonales con casilleros 
	                 //iguales entonces significa que hubo empate, devuelve el valor por defecto 'e', 
}




