#ifndef MY_LIBRERIA_H
#define MY_LIBRERIA_H

int letra_aleatoria(int max,int min);
void generarLetras(char array[], int n);
void contarLetras(char *array, int n, int *contador);
void imprimirLetras(char *array, int n);
void imprimir_conteo(int *contador);

//-------------------------------------------------------

int convertirCadenaANumero(char *cadena);

//-------------------------------------------------------

void convertirAMayuscula(char *cadena);

//-------------------------------------------------------

void separarTextoNumero(char *entrada, char *texto, char *numero);

//-------------------------------------------------------

int valorRomano(char c);
int convertirRomano(char *cadena);

//------------------------------------------

void llenar_matriz(int arreglo[5][5], int size_matriz);
void imprimir_matriz(int arreglo[5][5], int size_matriz);
bool esMagico(int arreglo[5][5], int size_matriz);

//------------------------------------------

void llenar_matriz25(int arreglo[5][5]);
void rotar90(int mat[5][5]);
void rotar180(int mat[5][5]);
void rotar270(int mat[5][5]);

//-------------------------------------------

long long factorial(int n);
long long caminos(int n);

#endif // MY_LIBRERIA_H
