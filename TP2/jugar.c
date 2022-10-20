//main
#include "kronos.h"
#define LONGITUD_LASER 5
#define MAX_LASERS 100
#define MAX_ROBOTS 10
#define MAX_PINZAS 100
#define MAX_SUPERTRAJES 10
#define MAX_MATRIZ 20
#define DIVISION_MATRIZ 10

#define LONGITUD_LASER 5

typedef struct coordenada{
    int fila;
    int columna;
} coordenada_t;

typedef struct robot{
    coordenada_t posicion;
    coordenada_t lasers[MAX_LASERS];
    int tope_lasers;
} robot_t;


main(){
    //randoms
    rand ((unsigned)time(NULL));

robot_t robot;
robot.posicion.fila= coordenada_random;
robot.posicion.columna= coordenada_random;
robot.lasers[MAX_LASERS];
robot.tope_lasers;

char matriz[MAX_MATRIZ][MAX_MATRIZ];
//vector de capacidad de poder
int contador_poder[MAX_PERSONAJES]={0,0,0,0};

system("clear"); // Limpiamos la pantalla
inicializar_lasers ( &robot ,matriz);
return 0;
}