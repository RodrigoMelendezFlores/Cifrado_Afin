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

int main() {
  
  int a, b, n = 27, aux, existencia;
  string lista_letras = "ABCDEFGHIJKLMN#OPQRSTUVWXYZ";
  int opcion;
  
  while(true){
    
    cout << "Ingrese los factores (a,b): " << endl;
    cin >> a;
    cin >> b;
    
    if(n<0){existencia=0;}  
    else if((a<0)&& (b<0)) {existencia=0;}
    else if(b>=27){existencia=0;}
    else{existencia=inverso(a,n);}
    if(existencia!=0){
    
  while(true){
  cout << "Ingrese: " << endl << "1 si quiere cifrar una palabra" << endl;
  cout << "2 si quiere descifrar una palabra" << endl;
  cout << "3 si quiere escoger otros factores (a,b): " << endl;
  cin >> opcion;
    
  if(opcion == 1){
  cout << "Ingrese la palabra que desee cifrar (Ñ=#):" << endl;
  char palabra[100];
  cin >> palabra;
  int cantidad = strlen(palabra);
  int nueva_palabra;
  for(int i = 0; i < cantidad; i++){
    for(int j = 0; j < 27; j++){
      if(palabra[i] == lista_letras[j]){
        nueva_palabra=j;
      }
    }
    nueva_palabra = ( a * nueva_palabra) + b;
    nueva_palabra = (nueva_palabra % 27);
    palabra[i] = lista_letras[nueva_palabra];
  }
  cout << "La palabra ya cifrada es: " << palabra << endl;
  } 
    
  else if(opcion == 2){

  cout << "Ingrese la palabra que desee descifrar: " << endl;
  char palabra[100];
  cin >> palabra;
  int cantidad = strlen(palabra);
  int nueva_palabra;

  for(int i = 0; i < cantidad; i++){
    for(int j = 0; j < 27; j++){
      if(palabra[i] == lista_letras[j]){
        nueva_palabra = j;
      }
    }
    
    nueva_palabra = mod_(mod_(nueva_palabra - b, n) * existencia, n);
    nueva_palabra = mod_(nueva_palabra, n);  //(nueva_palabra%27);
    palabra[i] = lista_letras[nueva_palabra];
  }
  cout << "La palabra ya descifrada es: " << palabra << endl;

  }
  else{break;}
  }
  }
  else cout << "Ocurrió un error al ingresar los números,ingrese números válidos" << endl;
  } 
}
