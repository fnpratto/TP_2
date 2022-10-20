#include <stdio.h>
#include "kronos.h"
#define MAX_LASERS 100
#define MAX_ROBOTS 10
#define MAX_PERSONAJES 10
#define MAX_PINZAS 100
#define MAX_SUPERTRAJES 10

typedef struct coordenada{
    int fila;
    int columna;
} coordenada_t;

typedef struct robot{
    coordenada_t posicion;
    coordenada_t lasers[MAX_LASERS];
    int tope_lasers;
} robot_t;

typedef struct supertraje{
    coordenada_t posicion;
    int cuadrante;
    bool recolectado;
    bool usado;
} supertraje_t;

typedef struct personaje{
    bool poder_activado;
    bool tiene_supertraje;
    coordenada_t posicion;
    int movimientos;
    int movimientos_con_poder;
    int cuadrante_inicial;
} personaje_t;

typedef struct juego{
    personaje_t personajes [MAX_PERSONAJES];
    int tope_personajes;
    robot_t robots [MAX_ROBOTS];
    int tope_robots;
    coordenada_t pinzas [MAX_PINZAS];
    int tope_pinzas;
    supertraje_t supertrajes [MAX_SUPERTRAJES];
    int tope_supertraje;
    int longitud_laser;
    int id_personaje_actual;
} juego_t;


void inicializar_juego(juego_t* jugada_actual, bool contrasenia_completa,supertraje_t *supertraje[MAX_SUPERTRAJES],int tope_supertraje){
        
    char matriz[MAX_MATRIZ][MAX_MATRIZ]=inicializar_matriz();
    inicializar_robot(jugada_actual->robots,jugada_actual->tope_robots,matriz);
    for(int i=0;i<4;i++){
        inicializar_lasers(jugada_actual->robots, matriz);
    }
    inicializar_pinzas(&jugada_actual->pinzas[MAX_PINZAS], &jugada_actual->tope_pinzas, matriz);
    inicializar_traje(&supertraje,&tope_supertraje,matriz);

    inicializar_movimientos_iniciales(juego->personajes[MAX_PERSONAJES]);

}
/*
 * Moverá el personaje y se realizarán todas las acciones necesarias en caso de chocas con algún elemento.
 */ 
void realizar_jugada(juego_t* juego, char movimiento){
    caminar_por_mapa(personaje_t *personaje, char matriz,movimiento_usuario());
}

/*
 * Imprime el juego por pantalla.
 */
void imprimir_terreno(juego_t jugada_actual/*,char matriz[MAX_MATRIZ][MAX_MATRIZ]*/){

    for(int i=0;i<MAX_TABLERO;i++){
        int j=0;
        for (int j = 0; j < MAX_TABLERO; j++){
            char k=matriz[i][j];
            printf("%c",k);
        }
        printf("/n");
    }
}

int estado_juego(juego_t *jugada_actual){
    if((!jugada_actual->personajes[jugada_actual->id_personaje_actual].la_quedo)&&(!jugada_actual->gano)){
        return(SIGUE_EN_JUEGO);
    }else if(jugada_actual->personajes[jugada_actual->id_personaje_actual].la_quedo){
        return(PERDIO_EL_JUEGO);
    }else{
        return(GANO_EL_JUEGO);
    }
}

