#include <iostream>
#include <My_libreria.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

int letra_aleatoria(int min,int max){
    return rand() % (max - min + 1) + min;
}

void generarLetras(char array[], int n){
    for (int i = 0; i < n; i++){
        array[i] = letra_aleatoria(65, 90);
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


//---------------------------------------------

void llenar_matriz(int arreglo[5][5], int size_matriz){
    for(int i = 0; i < size_matriz; i++){
        cout << "Ingrese los valores de la fila " << i + 1 << endl;
        for(int j = 0; j < size_matriz; j++){
            cout << "Valor numero " << j + 1 << ": ";
            cin >> *(*(arreglo + i) + j);
        }
    }
}

void imprimir_matriz(int arreglo[5][5], int size_matriz){
    for(int i = 0; i < size_matriz; i++){
        for(int j = 0; j < size_matriz; j++){
            cout << *(*(arreglo + i) + j) << "\t";
        }
        cout << endl;
    }
}

bool esMagico(int arreglo[5][5], int size_matriz){
    int sumaRef = 0;

    // primera fila
    for(int j = 0; j < size_matriz; j++){
        sumaRef += *(*(arreglo + 0) + j);
    }

    // filas
    for(int i = 0; i < size_matriz; i++){
        int suma = 0;
        for(int j = 0; j < size_matriz; j++){
            suma += *(*(arreglo + i) + j);
        }
        if(suma != sumaRef) return false;
    }

    // columnas
    for(int j = 0; j < size_matriz; j++){
        int suma = 0;
        for(int i = 0; i < size_matriz; i++){
            suma += *(*(arreglo + i) + j);
        }
        if(suma != sumaRef) return false;
    }

    // diagonal principal
    int diag1 = 0;
    for(int i = 0; i < size_matriz; i++){
        diag1 += *(*(arreglo + i) + i);
    }

    // diagonal secundaria
    int diag2 = 0;
    for(int i = 0; i < size_matriz; i++){
        diag2 += *(*(arreglo + i) + (size_matriz - 1 - i));
    }

    if(diag1 != sumaRef || diag2 != sumaRef){
        return false;
    }

    return true;
}

//------------------------------------------------------

void llenar_matriz25(int arreglo[5][5]){
    int valor = 1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            *(*(arreglo + i) + j) = valor++;
        }
    }
}

void rotar90(int mat[5][5]){
    for(int j = 0; j < 5; j++){
        for(int i = 4; i >= 0; i--){
            cout << *(*(mat + i) + j) << "\t";
        }
        cout << endl;
    }
}

void rotar180(int mat[5][5]){
    for(int i = 4; i >= 0; i--){
        for(int j = 4; j >= 0; j--){
            cout << *(*(mat + i) + j) << "\t";
        }
        cout << endl;
    }
}

void rotar270(int mat[5][5]){
    for(int j = 4; j >= 0; j--){
        for(int i = 0; i < 5; i++){
            cout << *(*(mat + i) + j) << "\t";
        }
        cout << endl;
    }
}

//-------------------------------------------------

long long factorial(int n){
    long long f = 1;
    for(int i = 1; i <= n; i++){
        f *= i;
    }
    return f;
}

long long caminos(int n){
    return factorial(2*n) / (factorial(n) * factorial(n));
}
