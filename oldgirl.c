#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define cls system("cls");


	int j=0,i=0;
	char player[] = {'s'}; char player_pick[] = {'0'};
 	char tabla[] = {'1' , '2' , '3' ,
	 				'4' , '5' , '6' ,
	 				'7' , '8' , '9'}; 
 	char no[] = {"no"},si[]={"si"},init[100];
 	char options[] = { 'X' , 'O'};
 	char opX = 'X', opO ='O';
 	bool winner = false,all = false;

void print();
bool continuar();
int validInt();
void play();
bool hasAChar(char *strStart, char *strEnd);
void win();
void reset();
bool allLose();

int main(){

	system("color FC");
	printf("\n\n\n");

	do{	
		reset();
		cls;
		play();

	}while(continuar());

	system("pause");
	return 0;
}

void play() {

	srand(time(NULL));
	int e = 0+rand()%(2-0);
	int n = 0,change=e;
	player[0] = options[e];
	
	do { 
		//Cambiar de turno de jugador
		if(change > 0) change = 0;
		else change = 1;
		player[0] = options[change];

		cls;
		print();
		printf("\n Juega una posicion: ");n = validInt();
		sprintf(player_pick,"%d",n);//Pasar un entero a cadena de caracter
		do {

			//Si la casilla elegida esta ocupado (o sea ya almacena X || O)

			if((tabla[n-1] == opX ) || (tabla[n-1] == opO )){
				printf("\n Casilla ocupada intenta otra: ");
				n = validInt();
				sprintf(player_pick,"%d",n);//Pasar un entero a cadena de caracter
			} 
			if(n<1 || n>9){
				printf("\n Solo hay opciones entre 1-9: ");
				n = validInt();
				sprintf(player_pick,"%d",n);//Pasar un entero a cadena de caracter
			} 
			
		}while((n<1 || n>9) || (tabla[n-1] == opX) || (tabla[n-1] == opO));
		cls;
		print();
		win();
	}while(!winner);

	if (!all) printf("\n\n\t INCREIBLE!! han ganado las %c \n\n",player[0]);
	else printf("\n\n\t Que mal. Nadie ha ganado \n\n");
}

//Imprimir tabla de juego en pantalla
void print() {

	printf("\n Turno de las %c",player[0]);

	int cont = 0;
	printf("\n\n");
	printf("   ");
	i = 0; j = 0; 

	for (i = 0;i<9;i++){

	 	//Condicional de juego
	 	//Si el valor es igual a la posicion jugada por el usuario
	 	//Guarda el termino del turno correspodiente
	 	if (tabla[i] == player_pick[0]) {

	 		tabla[i] = player[0];
	 		if(j!=2) printf(" %c |",tabla[i]);
	 		else printf(" %c \n",tabla[i]);
	 	
	 	} else {

	 		if(j!=2) printf(" %c |",tabla[i]);
	 		else printf(" %c \n",tabla[i]);
	 	}
	 	
	 	//Si se ubica en la posicion final muestra la separacion con guiones
	 	//Solo se hara 2 veces(Ya que es de 3x3) 
	 	//para controlarlo esta el contador
	 	if (j==2 && cont < 2) {
	 		printf("   -----------\n");
	 		printf("   ");
	 		j=0;
	 		cont++;

	 	} else {
	 		j++;
	 	} 
	 }
}

// Preguntarle al usuario si quiere Jugat de nuevo al finalizar
bool continuar(){
	
	do{
		printf("\n De nuevo? |si|no|");
		printf("\n Ingresar: ");fgets(init,100,stdin); 
		strcpy(init,strtok(init,"\n"));strlwr(init);	
		if(strcmp(init,si) != 0 && strcmp(init,no) != 0) {
			printf("\n Solo hay dos opciones (si || no). Intenta de nuevo\n\n");
			system("pause");
			cls;
			print();
		} else {
			if(strcmp(init,si) == 0) return true;
			else return false;
		}
	}while(strcmp(init,si) != 0 && strcmp(init,no) != 0);
}
//Determinar si hay un ganador
void win() {

	if       ((tabla[0] == tabla[1]) && (tabla[0] == tabla[2])){
		winner = true; 
	}else if ((tabla[3] == tabla[4]) && (tabla[3] == tabla[5])){
		winner = true;
	}else if ((tabla[6] == tabla[7]) && (tabla[6] == tabla[8])){
		winner = true;
	}else if ((tabla[0] == tabla[3]) && (tabla[0] == tabla[6])){
		winner = true;
	}else if ((tabla[1] == tabla[4]) && (tabla[1] == tabla[7])){
		winner = true;
	}else if ((tabla[2] == tabla[5]) && (tabla[2] == tabla[8])){
		winner = true;
	}else if ((tabla[0] == tabla[4]) && (tabla[0] == tabla[8])){
		winner = true;
	}else if ((tabla[2] == tabla[4]) && (tabla[2] == tabla[6])){
		winner = true;
	}else if (allLose()) {
		winner = true;
    }else {
		winner = false;
	}
}


void reset() {

	char l[] = {'1'};
	player_pick[0] = 'H';
	for (i = 0; i<=8;i++) {
		sprintf(l,"%d",i+1);
		tabla[i] = l[0];
	}
}

//Determinar si la partida ha terminado sin ganadores
bool allLose() {

	int acu=0;
	for(i = 0;i<9;i++){
		if((tabla[i] == 'X' || tabla[i] == 'O') && !winner) acu++;
		
	}
	if (acu == 9){
		all = true; 
		return true;
	} 
	else return false;
	acu = 0;
}






bool hasAChar(char *strStart, char *strEnd) // Para validar que una 
											// cadena no tenga caracteres
{
	char *ptr = strStart;
	if (*ptr == '-') ptr++;
	while (ptr <= strEnd && *ptr != '\0')
	{
		if ((*ptr < 48 || *ptr > 57)) return true;
		if (*(++ptr) == '\n') *ptr = '\0';
	}
	
	return false;
}

int validInt() // Te retorna un int. 
			   // La uso para no validar cada 
			   // que necesitamos ingresar algo
{
	char str[10];
	int num, i;

	fgets(str, 10, stdin);

	while (hasAChar(str, str + 10))
	{
		printf("Caracteres detectados. Intente de nuevo: ");
		fgets(str, 10, stdin);
	}

	return (int)strtol(str, NULL, 10);
}
