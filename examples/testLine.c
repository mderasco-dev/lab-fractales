#include "../turtlec.h"
#include <math.h>


void arbol(Turtle *t, float tam, int n){
	if (n==0 || tam < 5)
		return;
	if (n>5)
		turtleSetColor(t, 120, 170, 20);
	else
		turtleSetColor(t, 0, 200, 0);
	
	turtleForward(t,tam);

	turtleLeft(t, 30.0f);
	arbol(t,tam*0.4,n-1);

	turtleRight(t,60.0f);
	arbol(t, tam*0.4, n-1);
	
	turtleLeft(t,30.0f);
	turtleBackward(t, tam);
}
void levy ( Turtle * turtle , float length , int depth ) {
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

void arbol3(Turtle *t, float tam, int n){
	turtleForward(t,tam);

	turtleLeft(t, 30.0f);
	arbol(t, tam*0.7, n-1);

	turtleRight(t, 30.0f);
	arbol(t, tam*0.7, n-1);

	turtleRight(t, 30.0f);
	arbol(t, tam*0.7, n-1);

	turtleLeft(t, 30.0f);

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

  arbol3(t, 150.0, 6);

  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}

