#include<stdio.h>
#include<time.h>
//#include<stdlib.h>
//#include<conio.h>



void iniciar(char tablero[3][3]);        //prototipos de las funciones
void llenar_tablero(char tablero[3][3]);
void imprimir_tablero(char tablero[3][3]);
void seleccionar_casilla(char tablero[3][3]);
void select_maquina(char tablero[3][3]);


int main(){    //funcion main 
	
	char tablero[3][3];    //declaro la matriz del tablero
	
	iniciar(tablero);      
	
	system("pause");
	return 0;
}

void iniciar(char tablero[3][3]){   // funcion que llama a todas las funciones
	
	int i=0;
	
	llenar_tablero(tablero);
	
	do{
		system("cls");
		imprimir_tablero(tablero);
		
		if(i % 2==0){
			seleccionar_casilla(tablero);
		}
		
		else{
			select_maquina(tablero);
		}
		
		
		i++;
	}while(i<=9);
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
		i=rand()%3;
		j=rand()%3;
		aux=0;
		
		if(tablero[i][j]=='O'||tablero[i][j]=='X'){
			
			aux=1;
		}	
	}while(aux==1);
	
	tablero[i][j]='O';
}

