/* Lab 0x03
* Matias alburquenque Salinas 19996835-1  asrieltada@gmail.com
* Claudio Vasquez Campos      16365587-k  c.vasquezcampos@uandresbello.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include "ruleta.h"



int main(){
Cola *C, *G;
C = creaCola();
G = creaCola();
push(C,1);
push(C,2);
push(C,3);
push(C,4);
printf("inicio: %d - fin: %d\n",
primero(C)->datos->dato1, ultimo(C)->datos->dato1);
pop(C);
printf("inicio: %d - fin : %d\n",primero(C)->datos->dato1 , ultimo(C)->datos->dato1 ) ;
push(C,5);
push(C,6);
printf ("inicio: %d - fin:%d\n",primero(C)->datos->dato1 , ultimo(C)->datos->dato1);
destruirCola(C);
C = creaCola();
push (C,7);
push (C,8);
printf ("inicio: %d - fin: % d\n",primero(C)->datos->dato1 , ultimo(C)->datos->dato1);
int q = 0,w = 0,m=0;
while(q==0){
    printf("#########Menu:############ \n");
    printf("Seleccione opcion \n");
    printf("1)crear ruleta (automatica) \n");
    printf("2)girar ruleta \n");
    printf("3)mostrar ruleta \n");
    printf("4)salir \n");
    printf("########################## \n");
    scanf("%d",&w);
    if (w == 1){
       crearRuleta(G);
       continue;
    }
    if (w == 2 ){
        m = giraruleta(G);
        printf("el numero ganador es : %d\n",m);
        continue;
    }
    if (w== 3){
        printf("imprimiendo la ruleta:\n");
        imprime_la_ruleta(G);
        continue;
    }
    if (w ==4){
        printf("Hasta luego\n");
        q = 1 ;

    }
}


return 0 ;
}



