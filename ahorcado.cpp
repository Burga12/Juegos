#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#define cls system("cls");

using namespace std;

	const string words[5] = {"cambur","anzoategui","marico triste","hitler","akara messi"};
	string help = "",palabra = "";
	char key[100],letrasUsadas[100];
	int life = 10,bien = 0,cont = 0;
	bool repetido = false;

void esconder();
void show();
void play();
bool check();
bool repeat();

int main(int argc, char const *argv[])
{	
	system("color 05");

	srand(time(NULL));
	int select = 0+rand()%(5-0);

	palabra = words[select];

	esconder();

	do{
		show();
 		play();
	}while(!check());


	cls;
	if (life == 0) cout << "\n\n\t\t\tO vaya es una lastima has perdido";
	else {
		cout << "\n\n O vaya. HAS GANADO, felicidades. \n\n Tu premio sera una recarga de saldo";
		cout << "\n\n\tPalabra: ";for (int i = 0; i< palabra.length();i++) printf("%c",help[i]);
	}


	cout<<endl<<endl;
	system("pause");
	return 0;
}

void show(){
	cls;
	cout << "\n\tAHORCADO \n\n\n";
	printf("\t");
	for (int i = 0; i< palabra.length();i++) printf("%c",palabra[i]);
	cout<<endl<<endl;	
}

void play(){

	do{
		repetido = false;

		cout << "\n\tJuega\n";
		cout << "\n Vidas restantes: "<<life;
		if (cont >= 1){
			cout << "\n\n Letras usadas: ";cout<<letrasUsadas;
		} 
		cout << "\n\n Ingresa una letra: "; cin.getline(key,100,'\n'); 

		//Si ingresa una letra minuscula pasa a mayuscula
		if 	( key[0] >= 97 || key[0] <= 122) 
		{
			key[0] -= 32; 
		}
	
		if (strlen(key) >= 2 ){
			cout << "\nOye te he pedido solo una letra. Intentalo de nuevo\n\n";
			system("pause");
			show();
			repetido = true;
		} else if (key[0] < 'A' || key[0] > 'Z'){
			printf("\nOye eso es una letra");
			system("pause");
			show();
			repetido = true;
		} 

		if (repeat()){
			printf("\nOye ya has utilizado esa letra, ahi arriba te lo digo\n\n");
			system("pause");
			show();
			repetido = true;
		}

	}while(repetido);

	letrasUsadas[cont] = key[0]; //Almacena las letras que se han utilizado
 	cont++; //controla las veces que se ingresa una letra correcta
 		   //Sera la posicion donde se guarde la letra ingresada 
}

void esconder(){

	help = palabra;

	for (int i = 0; i <  palabra.length(); i++){

		if(palabra[i] != ' ') palabra[i] = '-'; help[i] -= 32;
	}	
}

bool check(){

	//COMPARAR SI LA LETRA INGRESADA ES CORRECTA
	for(int i = 0; i<=help.length();i++){ 

		if (key[0] == help[i]){
			palabra[i] = help[i];
			bien++;
		} 
		
	}
	
	if ( bien == 0) life--;//SI LA LETRA ES INCORRECTA RESTARLE UNA VIDA
	bien = 0;

	//DEVUELVE TRUE SOLO SI HA GANADO O SI HA PERDIDO
	if (life == 0) return true;
	else if (help == palabra) return true;
	else return false;
}

//Determinar que la letra ingresada no este repetida
bool repeat(){

	int asd = 0;

	for(int i = 0; i <= strlen(letrasUsadas); i++) {
		if (key[0] == letrasUsadas[i]) asd++;
	}

	if (asd == 0) return false;
	else return true;
}