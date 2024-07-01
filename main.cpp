#include <stdio.h>
#include <stdlib.h>

struct nodo {
       int dato;
       struct nodo* atras;
       struct nodo* siguiente;
};

nodo* primero = NULL;
nodo* ultimo = NULL;

void menu();
void insertarNodo();
void listar();
void eliminar();
void modificar();
void buscar();

int main() {
  menu();

  return 0;
}

void menu() {
  int opcion = 0;
  do {
    printf("\n1. Insertar\n");
    printf("2. Listar\n");
    printf("3. Eliminar\n");
    printf("4. Modificar\n");
    printf("5. Buscar\n");
    printf("6. Salir\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
      case 1:
        insertarNodo();
        break;
      case 2:
        listar();
        break;
      case 3:
        eliminar();
        break;
      case 4:
        modificar();
        break;
      case 5:
        buscar();
        break;
      case 6:
        break;
      default:
        printf("Opcion no valida\n");
        break;
    }
  } while(opcion != 6);
}

void insertarNodo() {
  nodo* nuevo = (nodo*) malloc(sizeof(nodo));

  printf("Ingrese el dato: ");
  scanf("%d", &nuevo -> dato);

  if(primero == NULL) {
    primero = nuevo;
    primero -> siguiente = primero;
    ultimo = primero;
    primero -> atras = primero;
  } else {
    ultimo -> siguiente = nuevo;
    nuevo -> siguiente = primero;
    nuevo -> atras = ultimo;
    ultimo = nuevo;
    primero -> atras = ultimo;
  }
}

void listar() {
  nodo* actual = (nodo*) malloc(sizeof(nodo));
  actual = primero;
  if(primero != NULL) {
    printf("DATO\t|\tDIRECCION\t|\tSIGUIENTE\t|\tANTERIOR\n");
    do {
      printf("%d\t|\t%p\t|\t%p\t|\t%p\n", actual -> dato, actual, actual -> siguiente, actual -> atras);
      actual = actual -> siguiente;
    } while(actual != primero);
  }
}

void eliminarUltimo() {
  if(primero == ultimo) {
    free(primero);
    free(ultimo);
    primero = NULL;
    ultimo = NULL;
  } else {
    nodo* temp = (nodo*) malloc(sizeof(nodo));
    temp = ultimo;
    ultimo = ultimo -> atras;
    ultimo -> siguiente = primero;
    primero -> atras = ultimo;
    free(temp);
  }
}

void eliminar() {
  listar();
  int dato = 0;
  printf("Ingrese el dato a eliminar: ");
  scanf("%d", &dato);

  nodo* actual = (nodo*) malloc(sizeof(nodo));
  actual = primero;
  nodo* anterior = (nodo*) malloc(sizeof(nodo));
  anterior = NULL;
  bool encontrado = false;

  if(primero != NULL) {
    do {
      if(actual -> dato == dato) {
        if(actual == primero) {
          primero = primero -> siguiente;
          primero -> atras = ultimo;
          ultimo -> siguiente = primero;
        } else if(actual == ultimo) {
          ultimo = anterior;
          ultimo -> siguiente = primero;
          primero -> atras = ultimo;
        } else {
          anterior -> siguiente = actual -> siguiente;
          actual -> siguiente -> atras = anterior;
        }
        printf("Dato eliminado\n");
        encontrado = true;
      }
      anterior = actual;
      actual = actual -> siguiente;
    } while(actual != primero && encontrado != true);
    if(encontrado) {
      printf("Dato no encontrado\n");
    }
  } else {
    printf("Lista vacia\n");
  }
}

void modificar() {
  int dato = 0;
  printf("Ingrese el dato a modificar: ");
  scanf("%d", &dato);

  nodo* actual = (nodo*) malloc(sizeof(nodo));
  actual = primero;
  int encontrado = 0;

  if(primero != NULL) {
    do {
      if(actual -> dato == dato) {
        printf("Ingrese el nuevo dato: ");
        scanf("%d", &actual -> dato);
        printf("Dato modificado\n");
        encontrado = 1;
      }
      actual = actual -> siguiente;
    } while(actual != primero && encontrado != 1);
    if(encontrado == 0) {
      printf("Dato no encontrado\n");
    }
  } else {
    printf("Lista vacia\n");
  }
}

void buscar() {
  int dato = 0;
  printf("Ingrese el dato a buscar: ");
  scanf("%d", &dato);

  nodo* actual = (nodo*) malloc(sizeof(nodo));
  actual = primero;
  int encontrado = 0;

  if(primero != NULL) {
    do {
      if(actual -> dato == dato) {
        printf("Dato encontrado %d en la direccion: %p\n", actual -> dato, actual);
        encontrado = 1;
      }
      actual = actual -> siguiente;
    } while(actual != primero && encontrado != 1);
    if(encontrado == 0) {
      printf("Dato no encontrado\n");
    }
  } else {
    printf("Lista vacia\n");
  }
}

