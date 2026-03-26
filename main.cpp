#include <iostream>
#include <My_libreria.h>
#include <cstdlib>

using namespace std;

int main(){
    int opcion;

    do{
        cout << "\n===== MENU =====" << endl;
        cout << "1. Contar letras" << endl;
        cout << "2. Mayusculas" << endl;
        cout << "3. Convertir a entero" << endl;
        cout << "4. Separar texto y numeros" << endl;
        cout << "5. Romano a entero" << endl;
        cout << "6. Imprimir matriz" << endl;
        cout << "7. Rotar matriz" << endl;
        cout << "8. Numero de caminos" << endl;
        cout << "0. Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion){

        case 1:{
            char letras[200];
            int cont[26] = {0};

            generarLetras(letras, 200);
            contarLetras(letras, 200, cont);

            imprimirLetras(letras, 200);

            imprimir_conteo(cont);
            break;
        }

        case 2:{
            char cadena[] = "Man-zana";

            cout << "Original: " << cadena << endl;
            convertirAMayuscula(cadena);
            cout << "Mayuscula: " << cadena << endl;
            break;
        }

        case 3:{
            char cadena[] = "12345";

            cout << "Entero: " << convertirCadenaANumero(cadena) << endl;
            break;
        }

        case 4:{
            char entrada[] = "abc54rst";
            char texto[50];
            char numero[50];

            separarTextoNumero(entrada, texto, numero);

            cout << "Texto: " << texto << endl;
            cout << "Numero: " << numero << endl;
            break;
        }

        case 5:{
            char romano[] = "DCLXVI";

            int resultado = convertirRomano(romano);

            cout << "El numero ingresado fue: " << romano << endl;
            cout << "Que corresponde a: " << resultado << endl;
            break;
        }

        case 6:{

            int size;
            int matriz[5][5];

            cout << "Ingrese le tamano de la matriz: ";
            cin >> size;

            llenar_matriz(matriz, size);
            cout << "\nMatriz:\n\n";
            imprimir_matriz(matriz, size);

            if(esMagico(matriz, size)){
                cout << "\nEs un cuadrado magico." << endl;
            } else {
                cout << "\nNo es un cuadrado magico." << endl;
            }
            break;
        }

        case 7:{
            int matriz[5][5];

            llenar_matriz25(matriz);

            cout << "\nMatriz original:\n";
            imprimir_matriz(matriz, 5);

            cout << "\nRotada 90 grados:\n";
            rotar90(matriz);

            cout << "\nRotada 180 grados:\n";
            rotar180(matriz);

            cout << "\nRotada 270 grados:\n";
            rotar270(matriz);

            break;
        }

        case 8:{
            int n;
            long long resultado;

            cout << "Ingrese un numero n: ";
            cin >> n;

            resultado = caminos(n);

            cout << "\nPara una malla de " << n << "x" << n << " puntos hay " << resultado << " caminos." << endl;

            break;
        }

        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while(opcion != 0);

    return 0;
}
