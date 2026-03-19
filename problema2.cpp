#include <iostream>
#include <problema2.h>
#include <cstdlib>

using namespace std;

int numero_aleatorio(int min,int max){
    return rand() % (max - min + 1) + min;
}

void generarLetras(char array[], int n){
    for (int i = 0; i < n; i++){
        array[i] = numero_aleatorio(65, 90);
    }
}

void contarLetras(char *array, int n, int *contador){
    int pos;
    char letra;

    for(int i = 0; i < n; i++){
        letra = *(array + i);
        pos = letra - 'A';
        (*(contador + pos))++;
    }
}

void imprimirLetras(char *array, int n){
    for(int i = 0; i < n; i++){
        cout << *(array + i);
    }
    cout << endl;
}

void imprimir_conteo(int *contador){
    for(int j = 0; j < 26; j++){
        if(*(contador + j) > 0){
            cout << char('A' + j) << ": " << *(contador + j) << endl;
        }
    }
}

//------------------------------------------------------------------------

int convertirCadenaANumero(char *cadena){
    int numero = 0;

    while(*cadena != '\0'){
        numero = numero * 10 + (*cadena - '0');
        cadena++; // avanzar con el puntero
    }

    return numero;
}

//-------------------------------------------------------------------------

void convertirAMayuscula(char *cadena){
    while(*cadena != '\0'){
        if(*cadena >= 'a' && *cadena <= 'z'){
            *cadena = *cadena - 32;
        }
        cadena++;
    }
}

//-----------------------------------------------------------------

void separarTextoNumero(char *entrada, char *texto, char *numero){
    while(*entrada != '\0'){

        if(*entrada >= '0' && *entrada <= '9'){
            *numero = *entrada;
            numero++;
        }
        else{
            *texto = *entrada;
            texto++;
        }

        entrada++;
    }

    *texto = '\0';
    *numero = '\0';
}


//-------------------------------------------------------------

int valorRomano(char c){
    switch(c){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int convertirRomano(char *cadena){
    int resultado = 0;

    while(*cadena != '\0'){
        int actual = valorRomano(*cadena);
        int siguiente = valorRomano(*(cadena + 1));

        if(actual < siguiente){
            resultado -= actual;
        } else {
            resultado += actual;
        }

        cadena++;
    }

    return resultado;
}







