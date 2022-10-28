#ifndef LISTA_H
# define LISTA_H

#include "libro.h"

typedef struct Nodo
{
    Libro libro;
    struct Nodo *siguiente;
}Nodo;

typedef struct Lista
{
    Nodo *cabeza;
    int longitud;
}Lista;

Nodo    *CrearNodo(Libro *libro);
void    DestruirNodo(Nodo *nodo);
void    InsertarPrincipio(Lista *lista, Libro *libro);
void    InsertarFinal(Lista *lista, Libro *libro);
void    InsertarDespues(int n, Lista *lista, Libro *libro);
Nodo   *ObternerNodo(int n, Lista *lista);
int     ContarNodos(Lista *lista);
int     EstaVacia(Lista *lista);
void    EliminarPrincipio(Lista *lista);
void    EliminarUltimo(Lista *lista);
void    EliminarElemento(int n, Lista *lista);
void    ImprimirLista(Nodo *cabeza);
#endif /*lista_h*/