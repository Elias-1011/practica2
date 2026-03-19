#include <iostream>
#include <problema2.h>
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
        cout << "0. Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion){

        case 1:{
            char letras[200];
            int cont[26] = {0};

            generarLetras(letras, 200);
            contarLetras(letras, 200, cont);

            cout << "Letras: ";
            for(int i = 0; i < 10; i++){
                cout << letras[i];
            }
            cout << endl;

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

        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
        }

    } while(opcion != 0);

    return 0;
}
