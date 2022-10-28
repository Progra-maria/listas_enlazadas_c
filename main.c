
#include "lista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Nodo *CrearNodo(Libro *libro){

    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    strncpy(nodo->libro.titulo, libro->titulo, 50);
    strncpy(nodo->libro.autor, libro->autor, 50);
    strncpy(nodo->libro.isbn, libro->isbn, 13);
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo *nodo)
{
    free(nodo);
}

void InsertarPrincipio(Lista *lista, Libro *libro)
{
    Nodo *nodo = CrearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}
void InsertarFinal(Lista *lista, Libro *libro)
{
    Nodo *nodo = CrearNodo(libro);
    
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
        
    }else{
        Nodo *puntero = lista->cabeza;
    while (puntero->siguiente)
        puntero = puntero->siguiente;
    puntero->siguiente = nodo;
    }
    lista->longitud++;
}

int ContarNodos(Lista *lista)
{   
    return (lista->longitud);
}

void    ImprimirLista(Nodo *cabeza)
{
    Nodo *puntero = cabeza;
    while (puntero != 0)
    {
        printf("%s -", puntero->libro.titulo);
        printf("%s -", puntero->libro.autor);
        printf("%s -", puntero->libro.isbn);
        printf("\n");
        puntero = puntero->siguiente;
    } 
}

void InsertarDespues(int n, Lista *lista, Libro *libro)
{
    Nodo *nodo = CrearNodo(libro);
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
    }else{
        Nodo *puntero = lista->cabeza;
        int posicion = 0;
    while (posicion < n && puntero->siguiente)
    {
        puntero = puntero->siguiente;
        posicion ++;
    }
    nodo->siguiente = puntero->siguiente;
    puntero->siguiente = nodo;
    }
    lista->longitud++;
}

Nodo *ObternerNodo(int n, Lista *lista)
{
    if (lista->cabeza == NULL)
            return (NULL);
    else
    {
        Nodo *puntero = lista->cabeza;
        int posicion = 0;
    while (posicion < n && puntero->siguiente)
    {
        puntero = puntero->siguiente;
        posicion ++;
    }if (posicion != n)
        return (NULL);
    return (puntero);
    }
}

void EliminarPrincipio(Lista *lista)
{
    if(lista->cabeza)
    {
    Nodo *eliminado = lista->cabeza;
    lista->cabeza = lista->cabeza->siguiente;
    DestruirNodo(eliminado);
    lista->longitud--;
    }
}

void EliminarUltimo(Lista *lista)
{   
    if (lista->cabeza)
    {
    if (lista ->cabeza->siguiente)
    {
    Nodo *puntero = lista->cabeza;
        while(puntero->siguiente->siguiente)
            puntero = puntero->siguiente;
            Nodo *eliminado = puntero->siguiente;
    puntero->siguiente = NULL;
    DestruirNodo(eliminado);
    lista->longitud--;
    }
    else
    {
        Nodo *eliminado = lista->cabeza;
        lista->cabeza = NULL;
        DestruirNodo(eliminado);
        lista->longitud--;
    }
    }
}

void EliminarElemento(int n, Lista *lista)
{
if (lista->cabeza) 
{
    if (n == 0)
    {
        EliminarPrincipio(lista);
    }
    else if (n < lista->longitud)
    {   
    Nodo *puntero = lista->cabeza;
    int i = n;
    while (i < (n - 1))
        {   
        puntero = puntero->siguiente;
        i++;
        }
    Nodo *eliminado = puntero->siguiente;
    puntero->siguiente = eliminado->siguiente;
    DestruirNodo(eliminado);
    lista->longitud--;
    }
}
}
int main(void)
{
    Libro libro;
    Nodo *nuevo_nodo = CrearNodo(&libro);

    strncpy(nuevo_nodo->libro.titulo, "Las Horas", 50);
    strncpy(nuevo_nodo->libro.autor, "Virgina Wolf", 50);
    strncpy(nuevo_nodo->libro.isbn, "1234768056900", 13);

    Lista librosPorLeer;
    librosPorLeer.cabeza = nuevo_nodo;
    librosPorLeer.longitud = 1;
    printf("Añadir primer elemento\n");
    ImprimirLista(librosPorLeer.cabeza);
    printf("-----------\n");
    printf("Añadir último elemento\n");
    InsertarFinal(&librosPorLeer,&libro);
    nuevo_nodo = librosPorLeer.cabeza->siguiente;
    strncpy(nuevo_nodo->libro.titulo, "El Pez Dorado", 50);
    strncpy(nuevo_nodo->libro.autor, "David Lynch", 50);
    strncpy(nuevo_nodo->libro.isbn, "1234768056901", 13);
    ImprimirLista(librosPorLeer.cabeza);    
    printf("Longitud de la lista: %d\n", librosPorLeer.longitud);
    printf("-----------\n");
    printf("Añadir primer elemento\n");
    InsertarPrincipio(&librosPorLeer,&libro);
    nuevo_nodo = librosPorLeer.cabeza;
    strncpy(nuevo_nodo->libro.titulo, "Ulises", 50);
    strncpy(nuevo_nodo->libro.autor, "James Joyce", 50);
    strncpy(nuevo_nodo->libro.isbn, "1234768056901", 13);
    ImprimirLista(librosPorLeer.cabeza);  
    printf("Longitud de la lista: %d\n", ContarNodos(&librosPorLeer));
    printf("-----------\n");
    printf("Añadir primer elemento\n");
    InsertarPrincipio(&librosPorLeer,&libro);
    nuevo_nodo = librosPorLeer.cabeza;
    strncpy(nuevo_nodo->libro.titulo, "La Casa de los Espíritus", 50);
    strncpy(nuevo_nodo->libro.autor, "Isabel Allende", 50);
    strncpy(nuevo_nodo->libro.isbn, "1234768056902", 13);
    ImprimirLista(librosPorLeer.cabeza);  
    printf("Longitud de la lista: %d\n", librosPorLeer.longitud);
    printf("-----------\n");
    printf("Añadir elemento después posición 1 \n");
    InsertarDespues(1, &librosPorLeer, &libro);
    nuevo_nodo = ObternerNodo(2, &librosPorLeer);
    strncpy(nuevo_nodo->libro.titulo, "Ensayo sobre la Ceguera", 50);
    strncpy(nuevo_nodo->libro.autor, "José Saramago", 50);
    strncpy(nuevo_nodo->libro.isbn, "1234768056903", 13);
    ImprimirLista(librosPorLeer.cabeza);  
    printf("Longitud de la lista: %d\n", librosPorLeer.longitud);
    printf("-----------\n");
    printf("Eliminar último elemento\n");
    EliminarUltimo(&librosPorLeer);
    ImprimirLista(librosPorLeer.cabeza);  
    printf("Longitud de la lista: %d\n", librosPorLeer.longitud);
    printf("-----------\n");
    printf("Eliminar primer elemento\n");
    EliminarPrincipio(&librosPorLeer);
    ImprimirLista(librosPorLeer.cabeza);  
    printf("Longitud de la lista: %d\n", librosPorLeer.longitud);
    printf("-----------\n");
    printf("Eliminar elemento posición 1\n");
    EliminarElemento(1, &librosPorLeer);
    ImprimirLista(librosPorLeer.cabeza);  
    printf("Longitud de la lista: %d\n", librosPorLeer.longitud);
    printf("-----------\n");
    return (0);
}

