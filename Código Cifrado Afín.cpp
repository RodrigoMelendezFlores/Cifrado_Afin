#include <iostream>
#include <string.h>

using namespace std;

int mod_ (int a, int b) {
    int q = a / b;
    int r = a - (q * b);
    if (r < 0) { q--; r = a - (q * b); }
    return r;
}

int EuclidesExtendido(int a, int b, int &x, int &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }
    int x1, y1;
    int euclides = EuclidesExtendido(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return euclides;
}

int inverso(int a, int n)
{
    int x, y;
    int eucli = EuclidesExtendido(a, n, x, y);
    if (eucli == 1){
      if(0 <= x <= n-1){
        int resultado = (x % n + n) % n;
        //cout << "inverso es:  " << resultado;
        return resultado;
      }
       else {//cout << "no esta en el rango de Zn";
           return 0;
         }
    }
    else {//cout << "no existe";
      return 0;
      }
}

void cifrar_afin(int a, int b, string abe){
  cout << "Ingrese la palabra que desee cifrar (Ñ=#):" << endl;
  char palabra[100];
  cin >> palabra;
  int cantidad = strlen(palabra);
  int nueva_palabra;
  for(int i = 0; i < cantidad; i++){
    for(int j = 0; j < 27; j++){
      if(palabra[i] == abe[j]){
        nueva_palabra = j;
      }
    }
    nueva_palabra = ( a * nueva_palabra) + b;
    nueva_palabra = (nueva_palabra % 27);
    palabra[i] = abe[nueva_palabra];
  }
  cout << "La palabra ya cifrada es: " << palabra << endl;
  } 

string descifrar_afin(int a, int b, string s, string abe){
  int n = 27;
  //cout << "Ingrese la palabra que desee descifrar: " << endl;
  //char palabra[100];
  //cin >> palabra;
  int cantidad = s.size();
  int nueva_palabra;
  int existencia = inverso(a,n);
  for(int i = 0; i < cantidad; i++){
    for(int j = 0; j < 27; j++){
      if(s[i] == abe[j]){
        nueva_palabra = j;
      }
    }
    
    nueva_palabra = mod_(mod_(nueva_palabra - b, n) * existencia, n);
    nueva_palabra = mod_(nueva_palabra, n);  //(nueva_palabra%27);
    s[i] = abe[nueva_palabra];
  }
  return s;
  //cout << "La palabra ya descifrada es: " << palabra << endl;
}

void adivinar_text_cifrado (string s, int existencia){
  //affine Adivinador;
	string lista_letras = "ABCDEFGHIJKLMN#OPQRSTUVWXYZ";
  string mensaje_desc;
	int x1, y1, n = 0;
	char algo = '"';
	for (int a = 1; a <= 27; a++) {
		for (int b = 0; b <= 27; b++) {
			if (EuclidesExtendido(a, 27, x1, y1) == 1) {
				cout << "Clave A: " << a << "\tClave B: " << b << endl;
				//Adivinador.setPrivateKey(a, b);
				mensaje_desc = descifrar_afin(a, b, s, lista_letras);
				cout << mensaje_desc << endl;
				cout << "-------------------------------------" << endl;
				n++;
			}
		}
	}
	cout << endl << "Posibles frases: " << n << endl;
	cout << "Claves corretas -> a: 23    b: 17" << endl;
	//Adivinador.setPrivateKey(23, 17);
	mensaje_desc = descifrar_afin(23, 17, s, lista_letras);
	cout << mensaje_desc << endl;
}

int main() {
  
  int a, b, n = 27, aux, existencia;
  string lista_letras = "ABCDEFGHIJKLMN#OPQRSTUVWXYZ";
  int opcion;
  
  while(true){  
    cout << "Ingrese los factores (a,b): " << endl;
    cin >> a;
    cin >> b;
    cout << endl;
    if(n < 0) existencia=0;  
    else if((a < 0) && (b < 0)) existencia=0;
    else if(b >= 27) existencia=0;
    else existencia = inverso(a,n);
    
    if(existencia != 0) {
      while(true){
        cout << "Ingrese: " << endl << "1. Cifrar una palabra." << endl;
        cout << "2. Descifrar una palabra." << endl;
        cout << "3. Escoger otros factores (a, b): " << endl;
        cout << "4. Descifrar el mensaje oculto." << endl;
        cout << "0. Cerrar el programa" << endl;
        cin >> opcion;
          
        if (opcion == 1){cifrar_afin(a,b,lista_letras); cout << endl; } 
          
        else if (opcion == 2){
          cout << "Ingrese la palabra que desee descifrar: " << endl;
          string palabra;
          cin >> palabra;
          string mensaje = descifrar_afin(a, b, palabra, lista_letras);
          cout << "La palabra ya descifrada es: " << mensaje << endl;
        }
          
        else if (opcion == 3) { cout << endl; break; }

        else if (opcion == 4) {
          adivinar_text_cifrado("SLBCMVRBSHZBTÑNSRQVVMSZBVHÑNBVRQVLALHZBTÑNSRQVWQAXLZWÑNAQFQV", existencia); cout << endl; 
          }

        else if (opcion == 0) {cout << "Programa finalizado" << endl; return 0;}
      }
    }
    else cout << "Ocurrió un error al ingresar los números,ingrese números válidos" << endl;
  } 
  return 0;
}
