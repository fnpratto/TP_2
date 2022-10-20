//todo

/*#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // Para usar rand
#include <time.h> // Para obtener una semilla desde el reloj*/

#define MAX_LASERS 100
#define MAX_ROBOTS 10
#define MAX_PINZAS 100
#define MAX_SUPERTRAJES 10
#define MAX_PERSONAJES 4
#define MAX_MATRIZ 40
#define MAX_TABLERO 20
#define DIVISION_TABLERO 10

#define LONGITUD_LASER 5
const int CAPACIDAD_PODER = 5;
const int CAPACIDAD_PODER_DASH = 1;

//ESTADO DEL JUEGO
const int GANO_EL_JUEGO = 1;
const int PERDIO_EL_JUEGO = -1;
const int SIGUE_EN_JUEGO = 1;

//OBSTACULOS
const char ROBOT ='R';
const char LASER ='L';
const char PINZA ='P';
const char SALIDA ='S';
const char SUPERTRAJE ='T';

const char VACIO ='-';

/*MOVIMIENTOS*/
const char ARRIBA ='W';
const char ABAJO ='S';
const char DERECHA ='D';
const char IZQUIERA ='A';
const char ACTIVAR_PODER ='C';

/*PERSONAJES*/
const char MR_INCREIBLE ='I'; 
const char VIOLETA ='V'; 
const char DASH ='D'; 
const char ELASTICGIRL ='E'; 

  //ID (El campo id_personaje_actual comienza en 1)
const int ID_MR_INCREIBLE =4; 
const int ID_VIOLETA =2; 
const int ID_DASH =3;
const int ID_ELASTICGIRL =1;



typedef struct coordenada {
    int fila;
    int columna;
} coordenada_t;

typedef struct robot{
    coordenada_t posicion;
    coordenada_t lasers[MAX_LASERS];
    int tope_lasers;
} robot_t;


typedef struct supertraje{
    int supertraje[MAX_SUPERTRAJES];
    coordenada_t posicion;
    bool recogido;
} supertraje_t;

typedef struct personaje{
    coordenada_t posicion;
    coordenada_t personaje;
    bool la_quedo;
    bool tiene_poderes;
    int cantidad_de_movimiento;
    int capacidad_movimiento;
    char nombre_personaje;
    supertraje_t traje;
    bool no_puede_morir;
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
    bool gano;
} juego_t;

//El campo id_personaje_actual comienza en 1.
 bool posicion_desocupada(coordenada_t *ubicacion){
        return((ubicacion->fila==VACIO)&&(ubicacion->columna==VACIO));
 }

//condiciones de coordenadas 
bool esta_en_rango( coordenada_t *robot){
    return( robot->fila <MAX_TABLERO && robot->columna <MAX_TABLERO);
}

bool esta_primer_cuadrante (int fila , int columna ){
    return( fila <DIVISION_TABLERO && columna <DIVISION_TABLERO);
}

bool esta_segundo_cuadrante ( int fila ,int  columna ){
    return( fila >DIVISION_TABLERO && columna <DIVISION_TABLERO);
}

bool esta_tercer_cuadrante (int fila ,int  columna ){
    return( fila <DIVISION_TABLERO && columna >DIVISION_TABLERO);
}

bool esta_cuarto_cuadrante (int fila , int columna ){
    return( fila >DIVISION_TABLERO && columna >DIVISION_TABLERO);
}



int coordenada_random(){
    return(rand() % 21 );// la amplitud del rango es 20 

}

int numero_random_cero_nueve(){
    return(rand() % 10 );// la amplitud del rango es 9

}
int numero_random_diez_veinte(){
    return(rand() % 21 +10);// la amplitud del rango es de 10 a 20

}

int laser_random(){
    return(rand() % 5 );// la amplitud del rango es 20 
}

int coordenada_rango_robot(robot_t *robot){
    (rand() % LONGITUD_LASER+1 );

}

void coordenada_primer_cuadrante(coordenada_t *objeto){
            do{
                objeto->fila=numero_random_cero_nueve;
                objeto->columna=numero_random_cero_nueve;
            }while(posicion_desocupada(objeto->fila,objeto->columna));
}

void coordenada_segundo_cuadrante(coordenada_t *objeto){
            do{
                objeto->fila=numero_random_diez_veinte;
                objeto->columna=numero_random_cero_nueve;
            }while(posicion_desocupada(objeto->fila,objeto->columna));
}

void coordenada_tercer_cuadrante(coordenada_t *objeto){
            do{
                objeto->fila=numero_random_cero_nueve;
                objeto->columna=numero_random_diez_veinte;
            }while(posicion_desocupada(objeto->fila,objeto->columna));
}

void coordenada_cuarto_cuadrante(coordenada_t *objeto){
            do{
                objeto->fila=numero_random_diez_veinte;
                objeto->columna=numero_random_diez_veinte;
            }while(posicion_desocupada(objeto->fila,objeto->columna));
}

void game_over(personaje_t *superheroe){
    bool la_quedo=true;
}

int ganaste(){

    bool gano=true;
}

int chequear_posicion_ocupada(char matriz[MAX_MATRIZ][MAX_MATRIZ],juego_t *jugada_actual){
        if(matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna] != VACIO){
            if(matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna] == ROBOT||matriz [jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna]==LASER){
                game_over(jugada_actual->personajes);
            }else if (matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna] ==PINZA){
                mover_posicion_pinzas(&jugada_actual,matriz,jugada_actual->robots);
            }else if(matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna] ==SUPERTRAJE){
                recoger_traje(&jugada_actual);
            }else if(matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna] == SALIDA && jugada_actual->id_personaje_actual==3){
                ganaste();
            }else if(matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna] ==VIOLETA&&jugada_actual->id_personaje_actual==1){
                mover_de_personaje(jugada_actual);
            }else if(matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna] ==DASH&&jugada_actual->id_personaje_actual==2){
                mover_de_personaje(jugada_actual);     
            }else if(matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna] ==MR_INCREIBLE&&jugada_actual->id_personaje_actual==3){
                mover_de_personaje(jugada_actual);     
            }
        }else {
            matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna]= jugada_actual->personajes->nombre_personaje;
        }
        }


/*INIALIZAR*/

void inicializar_robot(juego_t *robot[MAX_ROBOTS],int tope_robots,char matriz[MAX_MATRIZ][MAX_MATRIZ]){
    for(int i=0;i<4;i++){
        if(i==0){
            coordenada_primer_cuadrante(&robot[i]);
            inicializar_lasers(robot[i], matriz);
        }else if (i==1){ 
            coordenada_segundo_cuadrante(&robot[i]);
        }else if (i==2){ 
            coordenada_tercer_cuadrante(&robot[i]);
        } else{
            coordenada_cuarto_cuadrante(&robot[i]);
        }
        tope_robots++;
        matriz[robot[i]->robots->posicion.fila][robot[i]->robots->posicion.columna] = PINZA;
    }
}

void inicializar_lasers(juego_t *jugada_actual, char matriz[MAX_MATRIZ][MAX_MATRIZ]){
    int figura_laser = laser_random();
    if(figura_laser==1){
         figura_uno(&jugada_actual->robots, matriz);
    }else if(figura_laser==2){
        figura_tres(&jugada_actual->robots, matriz);
    }else if(figura_laser==3){
        figura_cinco(&jugada_actual->robots, matriz);
    }else{
        figura_siete(&jugada_actual->robots, matriz);
    }
}

void inicializar_pinzas(coordenada_t *pinza[MAX_PINZAS],int tope_pinza,char matriz[MAX_MATRIZ][MAX_MATRIZ]){
    for(int i=0;i<16;i++){
    do{
        if(i<5){ 
            coordenada_primer_cuadrante(&pinza[i]);
        }else if (i<9){ 
            coordenada_segundo_cuadrante(&pinza[i]);
        }else if (i<13){ 
            coordenada_tercer_cuadrante(&pinza[i]);
        } else{
            coordenada_cuarto_cuadrante(&pinza[i]);
        }
        tope_pinza++;
        matriz[pinza[i]->fila][pinza[i]->columna] = PINZA;
    }while(posicion_desocupada(pinza));   
    }
        
}

void inicializar_traje(supertraje_t *supertraje[MAX_SUPERTRAJES],int *tope_supertraje,char matriz[MAX_MATRIZ][MAX_MATRIZ]){
    for(int i=0;i<MAX_PINZAS;i++){
        do{
        if(i==0){ 
            coordenada_primer_cuadrante(&supertraje[i]);
        }else if (i==1){ 
            coordenada_segundo_cuadrante(&supertraje[i]);
        }else if (i==2){ 
            coordenada_tercer_cuadrante(&supertraje[i]);
        } else{
            coordenada_cuarto_cuadrante(&supertraje[i]);
        }
        tope_supertraje++;
        matriz[supertraje[i]->posicion.fila][supertraje[i]->posicion.columna] = PINZA;
        }while(posicion_desocupada(supertraje)); // le pase supertraje_t traje??
    }
}

void inicializar_personajes(juego_t *jugada_actual,char matriz[MAX_MATRIZ][MAX_MATRIZ]){
    char personaje='x';
    for(int i=0;i<MAX_PERSONAJES;i++){
    do{
        if(i==0){ 
            coordenada_primer_cuadrante(&jugada_actual->personajes[i]);
            personaje = ELASTICGIRL;
        }else if (i==1){ 
            coordenada_segundo_cuadrante(&jugada_actual->personajes[i]);
            personaje = VIOLETA;
        }else if (i==2){ 
            coordenada_tercer_cuadrante(&jugada_actual->personajes[i]);
            personaje = DASH;
        } else{
            coordenada_cuarto_cuadrante(&jugada_actual->personajes[i]);
            personaje = MR_INCREIBLE;
        }
        }while(posicion_desocupada(jugada_actual->personajes[i].posicion));
        matriz[jugada_actual->personajes[i].posicion.fila][jugada_actual->personajes[i].posicion.columna] = personaje;
        jugada_actual->tope_personajes++;
    }
}


void inicializar_movimientos_iniciales(juego_t *jugada_actual){
    if(jugada_actual->id_personaje_actual==ID_ELASTICGIRL){
        jugada_actual->personajes[jugada_actual->id_personaje_actual].cantidad_de_movimiento=25;
    } else if(jugada_actual->id_personaje_actual==ID_VIOLETA){
        jugada_actual->personajes[jugada_actual->id_personaje_actual].cantidad_de_movimiento=30;
    } else if(jugada_actual->id_personaje_actual==ID_DASH){
        jugada_actual->personajes[jugada_actual->id_personaje_actual].cantidad_de_movimiento=20;
    } else {
        jugada_actual->personajes[jugada_actual->id_personaje_actual].cantidad_de_movimiento=15;
    }
}

void figura_uno (robot_t *robot, char matriz[MAX_MATRIZ][MAX_MATRIZ]){ //L

        robot->lasers->fila=robot->posicion.fila;
        robot->lasers->columna=robot->posicion.columna;
        robot->lasers->fila++;
        robot->lasers->columna++;

    for (int i=0; i <= LONGITUD_LASER; i++){
        while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
        matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
        robot->lasers->fila=+1;

         if(i== LONGITUD_LASER){
         for (int j = 0; j < LONGITUD_LASER; j++){
            while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
                matriz[robot->lasers->fila][robot->lasers->columna]  =LASER;
                robot->lasers->columna=+1;
            }
         }
         }
        }
    }
}

void figura_tres (robot_t *robot, char matriz[MAX_MATRIZ][MAX_MATRIZ]){ //L

    robot->lasers->fila=robot->posicion.fila;
    robot->lasers->columna=robot->posicion.columna;
    robot->lasers->fila++;
    robot->lasers->columna++;

    for (int i=0; i <= LONGITUD_LASER; i++){
    while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
        if(i== 0){
         for (int j = 0; j < LONGITUD_LASER; j++){
            while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
                matriz[robot->lasers->fila][robot->lasers->columna]  =LASER;
                robot->lasers->columna=+1;
            }
         }
        matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
        robot->lasers->fila=+1;

         }
        }
    }
}


void figura_cinco (robot_t *robot,char matriz[MAX_MATRIZ][MAX_MATRIZ]){

    robot->lasers->fila=robot->posicion.fila;
    robot->lasers->columna=robot->posicion.columna;
    robot->lasers->fila++;
    robot->lasers->columna++;
    
    for (int i=0; i <= LONGITUD_LASER; i++){
    while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
        if(i==0){
            for (int j = 0; j < LONGITUD_LASER; j++){
                while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
                matriz[robot->lasers->fila][robot->lasers->columna] =LASER;
                robot->lasers->columna=+1;
                }
                }
        }
    matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
    robot->lasers->fila=+1;
    }
    }

}

void figura_siete (robot_t *robot,char matriz[MAX_MATRIZ][MAX_MATRIZ]){

        robot->lasers->fila=robot->posicion.fila;
        robot->lasers->columna=robot->posicion.columna;
        robot->lasers->fila++;
        robot->lasers->columna++;
    
    for (int i=0; i <= LONGITUD_LASER; i++){
        while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
        matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
        robot->lasers->fila=+1;

         if(i== LONGITUD_LASER){
         for (int j = 0; j < LONGITUD_LASER; j++){
            while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
                matriz[robot->lasers->fila][robot->lasers->columna]  =LASER;
                robot->lasers->fila=-1;
            }
         }
         }
        }
    }

}
//ROTACIONES
void de1a2 (robot_t *robot, char matriz[MAX_MATRIZ][MAX_MATRIZ]){

    for (int i=LONGITUD_LASER; i <= 0; i--){
    while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
   robot->lasers->fila=+i;
    matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
    
        if(i== 0){
            while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
            for (int j=LONGITUD_LASER; j <= 0; j--){
            robot->lasers->fila=+j;
            matriz[robot->lasers->fila][robot->lasers->columna]  =LASER;
            }
        }
        }
    }
    }

}

// primer y segubdo cuadrante aumenta j
//mismo?
void de2a3_y_3a4 (robot_t *robot, char matriz[MAX_MATRIZ][MAX_MATRIZ]){

    for (int i=LONGITUD_LASER; i <= 0; i--){
        while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
            robot->lasers->fila=+i;
            matriz[robot->lasers->fila][robot->lasers->columna]  =LASER;
        if(i== 0){
            while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
            for (int i=LONGITUD_LASER; i <= 0; i--){
                robot->lasers->fila=-i;
                matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
            }
            }
        }
        }
    
    }

}

void de4a5 (robot_t *robot, char matriz[MAX_MATRIZ][MAX_MATRIZ]){

    for (int i=LONGITUD_LASER; i <= 0; i--){
    while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
    robot->lasers->fila=+i;
    matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
    
        if(i== 0){
            while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
            for (int j=LONGITUD_LASER; j <= 0; j--){
            robot->lasers->fila=-j;
            matriz[robot->lasers->fila][robot->lasers->columna]  =LASER;
            } 
            }
        }
    }
    }
}

void de5a6 (robot_t *robot, char matriz[MAX_MATRIZ][MAX_MATRIZ]){

    for (int j=LONGITUD_LASER; j <= 0; j--){
        while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
        if(j== 0){
            while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
            for (int i=LONGITUD_LASER; i <= 0; i--){
                robot->lasers->fila=-i;
                matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
            }
            }
        } 
        robot->lasers->fila=+j;
        matriz[robot->lasers->fila][robot->lasers->columna]  =LASER;

        }
    
    }
}

void de6a7 (robot_t *robot, char matriz[MAX_MATRIZ][MAX_MATRIZ]){

    for (int j=LONGITUD_LASER; j <= 0; j--){
        while(esta_en_rango(robot->lasers->fila&&robot->lasers->columna)){
        if(robot->posicion.columna<j){
                robot->lasers->fila=+j;
                matriz[robot->lasers->fila][robot->lasers->columna] = LASER;
        } 
        robot->lasers->fila=+j;
        matriz[robot->lasers->fila][robot->lasers->columna]  =LASER;

        }
    
    }
}



/*ACCIONES*/

/*SUPERPODERES*/

void activar_poder_elastigirl(personaje_t *superheroe,int contador_poder[MAX_PERSONAJES]){
    if(contador_poder[0]<CAPACIDAD_PODER){
        superheroe->capacidad_movimiento=3;
        contador_poder[0]=+1; 
    }
}

void activar_poder_violeta(personaje_t *superheroe,int contador_poder[MAX_PERSONAJES]){
    if(contador_poder[1]<CAPACIDAD_PODER){
        superheroe->no_puede_morir = true;
        contador_poder[1]=+1;
    }else {
        superheroe->no_puede_morir = false;
    }
}

void activar_poder_dash(personaje_t *superheroe,int contador_poder[MAX_PERSONAJES],char matriz[MAX_MATRIZ][MAX_MATRIZ]){
    if(contador_poder[2]<CAPACIDAD_PODER_DASH){
        superheroe->posicion.fila=coordenada_random();
        superheroe->posicion.columna=coordenada_random();
        matriz[superheroe->posicion.fila][superheroe->posicion.columna]=DASH;
    }
}

void activar_poder_mrincreible(personaje_t *superheroe,int contador_poder[MAX_PERSONAJES]){
     if(contador_poder[3]<CAPACIDAD_PODER){
        superheroe->no_puede_morir = true;
        contador_poder[3]=+1;
    }else {
        superheroe->no_puede_morir = false;
    }
}

void recoger_traje( juego_t *jugada_actual){
    for(int i=0;i<MAX_PERSONAJES;i++){
        if (jugada_actual->supertrajes==i && jugada_actual->id_personaje_actual== i){
            jugada_actual->supertrajes [i].recogido = true;
        }
    }
}

void activar_poder( juego_t *jugada_actual,int contador_poder[MAX_PERSONAJES],char matriz[MAX_MATRIZ][MAX_MATRIZ]){
        if (jugada_actual->supertrajes [0].recogido){
            activar_poder_elastigirl(&jugada_actual->personajes,contador_poder);
        }else if(jugada_actual->supertrajes [1].recogido){
            activar_poder_violeta(&jugada_actual->personajes,contador_poder);
        }else if(jugada_actual->supertrajes [2].recogido){
            activar_poder_dash(&jugada_actual->personajes,contador_poder,matriz);
        }else if(jugada_actual->supertrajes [3].recogido){
           activar_poder_mrincreible(&jugada_actual->personajes,contador_poder); 
        }

}

//solo va a rango positivo ,no negativo/////////////-------------------
void mover_posicion_pinzas(juego_t *jugada_actual,char matriz[MAX_MATRIZ][MAX_MATRIZ],robot_t *robot){
    int hi=(rand() % 2);
    if(hi=0){
        jugada_actual->personajes[jugada_actual->id_personaje_actual].posicion.fila=(robot->posicion.fila)-coordenada_rango_robot(robot);
        jugada_actual->personajes[jugada_actual->id_personaje_actual].posicion.columna=(robot->posicion.columna)-coordenada_rango_robot(robot);
    }else{
        jugada_actual->personajes[jugada_actual->id_personaje_actual].posicion.fila=(robot->posicion.fila)+coordenada_rango_robot(robot);
        jugada_actual->personajes[jugada_actual->id_personaje_actual].posicion.columna=(robot->posicion.columna)+coordenada_rango_robot(robot);
    }
    matriz[jugada_actual->personajes->posicion.fila][jugada_actual->personajes->posicion.columna]=jugada_actual->id_personaje_actual;
    
}

void mover_personaje(juego_t *juego_actual){
    juego_actual->id_personaje_actual=+1;
}



//CHAR MOVIMIENTO -> MOVIMIENTO_USUARIO()
//cada vez que llama se baja el tope de cantidad de movimientos 
void caminar_por_mapa(personaje_t *personaje, juego_t *jugada_actual, char matriz[MAX_MATRIZ][MAX_MATRIZ], char movimiento,int contador_poder[MAX_PERSONAJES]){
    int j=personaje->posicion.fila;
    int i=personaje->posicion.columna;
    for(int i=0;i<personaje->capacidad_movimiento;i++){
        if(movimiento==ARRIBA){
            while(esta_en_rango(j-1)){
                personaje->posicion.fila=-1;
                chequear_posicion_ocupada(matriz,&personaje, &jugada_actual);
            }
        }else if(movimiento==ABAJO){
            while(esta_en_rango(j+1)){
                per
                sonaje->posicion.fila=+1;
                chequear_posicion_ocupada(matriz,&personaje, &jugada_actual);
            }
        }else if(movimiento==IZQUIERA){
            while(esta_en_rango(i-1)){
                personaje->posicion.columna=-1;
                chequear_posicion_ocupada(matriz,&personaje, &jugada_actual);
            }
        }else if(movimiento==DERECHA){
           while(esta_en_rango(i+1)){
                personaje->posicion.columna=+1;
                chequear_posicion_ocupada(matriz,&personaje, &jugada_actual);
           
            }
        }else{
            activar_poder(&jugada_actual,contador_poder,matriz);
        }
    }
    personaje->cantidad_de_movimiento--;   
}


/*PROCEDIMIENTO DEL JUEGO*/

char inicializar_matriz(){
    char matriz_og[MAX_MATRIZ][MAX_MATRIZ];
    for(int i=0;i<MAX_TABLERO;i++){
        int j=0;
        for (int j = 0; j < MAX_TABLERO; j++){
            matriz_og[i][j]=VACIO;
        }
    }return(matriz_og);
}

int movimiento_usuario(){
    int movimiento;
    do{
        scanf("%c",movimiento);
    }while(movimiento==ARRIBA||movimiento==ABAJO||movimiento==DERECHA||movimiento==IZQUIERA ||movimiento==ACTIVAR_PODER);
        return(movimiento);
    }
    


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
void imprimir_terreno(juego_t jugada_actual,char matriz[MAX_MATRIZ][MAX_MATRIZ]){

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
