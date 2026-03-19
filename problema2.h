#ifndef PROBLEMA2_H
#define PROBLEMA2_H

int numero_aleatorio(int max,int min);
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

#endif // PROBLEMA2_H
