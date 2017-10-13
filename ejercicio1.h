#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Estructura que guarda la informacion .*/
typedef struct info{
int dato1;
/*int dato;*/
}Info;

/**
 *Estructura que guarda el nodo, un puntero que apunta al a Info,
 *y otro que apunta al nodo siguiente
 *
 */
typedef struct nodo {
	Info *datos;
	struct nodo *siguiente;
}Nodo;
/**
*Estructura que guarda la Cola, con un puntero que apunta al inicio
*y al fin de esta. Ademas, almacen a el tamano de la Cola .
*
*/
typedef struct cola{
Nodo *inicio;
Nodo *fin;
int tamano;
}Cola;


/**
*Funcion  que permite crear una nueva cola vacıa.
*
*@return nuevo : direccion del nodo inicio de la cola creada.
*
*/
Cola *creaCola()
{
	Cola *nueva;

if(nueva=(Cola *) malloc(sizeof(Cola))) // Pide memoria para la Cola
	{
	nueva->tamano = 0 ; // Cola vacıa
	nueva->inicio = nueva->fin = NULL ; // Inicio y Fin apuntan a NULL
	}
return nueva ;
}


/**
*Funcion que permite eliminar una Cola.
*
*@param c: puntero a la cola
*
*/

void destruirCola (Cola *c)
{
Nodo *aux;

while (c->inicio != NULL)
{
aux = c->inicio;
c->inicio = c->inicio->siguiente;
free (aux->datos);
free (aux);
}
free (c);
}


/**
*Funcion que crea un nodo y lo inicializa con sus datos y la direccion del
*siguiente nodo .
*
@param dato: puntero a los datos
@param ptro: puntero al si guiente nodo
@return ptro: la direccion del nuevo nodo creado.
*
*/

Nodo *crearNodo (Info *dato, Nodo *ptro)
{
Nodo *nuevo ;
if (nuevo = (Nodo *) malloc (sizeof(Nodo))) // Pide memoria para el nodo
{
nuevo->datos = dato;
nuevo->siguiente = ptro;
}
return nuevo;
}



/**
*Funcion que retorna el primer nodo de la cola
*
*@param c: puntero a la cola
*@return tope: direccion del primer nodo de la cola
*
*/

Nodo *primero (Cola *c)
{
return c->inicio;
}

/**
*Funcion que retorna el  ́ultimo nodo de la cola
*
*@param c : puntero a la cola
*@return tope: direccion del  ́ultimo nodo de la cola
*
*/

Nodo *ultimo(Cola *c)
{
return c->fin;

}

/**
* Funcion que permite saber si una cola esta vacıa o no
*
* @param c: puntero a la cola
* @ return bool : true en caso de ser vacıa, false caso contrario
*
*/
bool vacia(Cola *c)
{
return (c->inicio == NULL)	?true:false;
}


/**
* Funcion que ingresa la informacion
*
* @param dato1 : dato aguardar en Info
* @param pdato : informacion a guardar en la cola
*
*/

void ingresar(Info **pdato , int dato1)
{
if (*pdato=(Info*)malloc(sizeof(Info)))
	{
/* Se almacena la informacion en Info*/
	(*pdato)->dato1 = dato1;
/* pdato->dato2 = dato2; */
/* pdato->dato3 = dato3; */
	}
else
	{
printf("problemas en el push\n" ) ;
exit(0) ;
	}
}


/**
*Funcion que insert a un nodo a cola.
*
* @param c : puntero a la Cola
* @param info: informacion a guardar en la cola
*
* @return true: si la insercion tuvo  ́exito, false: en caso contrario .
*
*/

bool push (Cola *c , int info)
{
Info *pdato;
Nodo *aux;
ingresar(&pdato, info);
// Se crea un nodo con datos y a punta a NULL
if (aux = crearNodo (pdato, NULL)) // adem as , se almacen a en aux
{
if(vacia(c))
c->inicio = aux ;
else
c->fin->siguiente = aux ;
c->fin = aux ;
c->tamano++;
return true;
}
else
return false;
}


/**
* Funcion que elimina un nodo de la cola
*
* @param c : puntero a la cola
*@return dato: retorna el dato de Info .
*
*/

Info *pop (Cola *c)
{
Nodo *aux;
Info *dato;
aux = c->inicio; // se guarda el nodo a eliminar ( el primero ) en un aux
dato = aux->datos; // sus datos tambien
c->inicio = aux->siguiente;
c->tamano--;
if(vacia (c))
c->fin = NULL ;
free (aux->datos);
free (aux);

return dato;
}
