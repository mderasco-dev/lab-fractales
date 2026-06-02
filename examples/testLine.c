#include "../turtlec.h"
#include <math.h>


void arbol(Turtle *t, float tam, int n){
//caso base
	if (n==0 || tam < 5)
		return;


	if (n>5)
		turtleSetColor(t, 120, 170, 20);
	else
		turtleSetColor(t, 0, 200, 0);
	
	turtleForward(t,tam);

	turtleLeft(t, 30.0f);
	arbol(t,tam*0.7,n-1);

	turtleRight(t,60.0f);
	arbol(t, tam*0.7, n-1);
	
	turtleLeft(t,30.0f);
	turtleBackward(t, tam);
}
void levy ( Turtle * turtle , float length , int depth ) {
	//caso base
	if( depth == 0) {
		turtleForward ( turtle , length ) ;
	return ;
	}


	turtleLeft ( turtle , 45) ;
	levy ( turtle , length / sqrt (2) , depth - 1) ;

	turtleRight ( turtle , 90) ;
	levy ( turtle , length / sqrt (2) , depth - 1) ;

	turtleLeft ( turtle , 45) ;
	}

/*Se realizan 3 llamadas recursivas por nivel por lo que el total de llamadas sería 3^n
*/
void arbol3(Turtle *t, float tam, int n){
	//caso base
	if (n == 0 || tam < 5)
		return;

	turtleForward(t,tam);
//rama izquierda
	turtleLeft(t, 30.0f);
	arbol3(t, tam*0.7, n-1);
//rama central
	turtleRight(t, 30.0f);
	arbol3(t, tam*0.7, n-1);
//rama derecha
	turtleRight(t, 30.0f);
	arbol3(t, tam*0.7, n-1);
//vuelve a la posicion original
	turtleLeft(t, 30.0f);
	turtleBackward(t,tam);
}


/*Se realizan 2 llamadas recursivas por nivel por lo que el total de llamadas sería 2^n
*/
void arbold(Turtle *t, float tam, int n){
	//caso base
	if (n==0 || tam<5)
		return;

	turtleForward(t,tam);
//rama izquierda
	turtleLeft(t, 30.0f);
	arbold(t, tam*0.5, n-1);
//rama derecha
	turtleRight(t, 60.0f);
	arbold(t, tam*0.8,n-1);
//permiten que la tortuga vuelva a la posicion y orientacion adecuada
	turtleLeft(t,30.0f);
	turtleBackward(t,tam);
}

void arbolcolor(Turtle *t, float tam, int n){
	//caso base
	if (n==0 || tam <5)
		return;
	
	turtlePenDown(t);
//variacion de color dependiendo del nivel
	if(n >= 7)
    		turtleSetColor(t, 120, 70, 20);      
	else if(n >= 5)
    		turtleSetColor(t, 0, 120, 0);        
	else if(n >= 3)
    		turtleSetColor(t, 0, 200, 0);        
	else
    		turtleSetColor(t, 100, 255, 100);    

	turtleForward(t,tam);
//rama izquierd
	turtleLeft(t,30.0f);
	arbolcolor(t, tam*0.7, n-1);
//rama derecha
	turtleRight(t, 60.0f);
	arbolcolor(t, tam*0.7, n-1);
//devuelve a la tortuga a la posicion y direccion inicial
	turtleLeft(t,30.0f);
	turtlePenUp(t);
	turtleBackward(t,tam);
}

int main(void){
  
  TurtleApp *app = turtleAppCreate(1100,600, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 550.0f, 590.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 8.0f);
  
  turtleLeft(t, 90.0f);

  arbolcolor(t, 150.0, 7);
turtleSetColor(t, 255, 0, 0);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

