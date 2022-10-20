/*
El trabajo práctico debe ser realizado en un archivo llamado kronos.c, lo que sería la implementación de la
biblioteca kronos.h. 
Además, deberán crear una biblioteca con lo resuelto en el trabajo práctico 1.

 El trabajo debe
ser compilado sin errores al correr el siguiente comando:
 gcc *.c -o juego -std=c99 -Wall -Wconversion -Werror -lm

Aclaración: El main tiene que estar desarrollado en un archivo llamado juego.c, el cual manejará todo el flujo del
programa.
Lo que nos permite *.c es agarrar todos los archivos que tengan la extensión .c en el directorio actual y los compile
todos juntos. Esto permite que se puedan crear bibliotecas a criterio del alumno, aparte de las exigidas por la cátedra.
Por último debe ser entregado en la plataforma de corrección de trabajos prácticos AlgoTrón (patente pendiente),
en la cual deberá tener la etiqueta ¡Exito! significando que ha pasado las pruebas a las que la cátedra someterá al
trabajo.

*/

//El campo id_personaje_actual comienza en 1.
 bool posicion_desocupada(coordenada_t *ubicacion){
        }

//condiciones de coordenadas 
bool esta_en_rango( coordenada_t *prueba_uno){
   

bool esta_primer_cuadrante (int fila , int columna ){
}

bool esta_segundo_cuadrante ( int fila ,int  columna ){
}

bool esta_tercer_cuadrante (int fila ,int  columna ){
}

bool esta_cuarto_cuadrante (int fila , int columna ){
}


int coordenada_random(){
}

int numero_random_cero_nueve(){
}
int numero_random_diez_veinte(){
}

int laser_random(){
}

int coordenada_rango_robot(robot_t *robot){
}

void coordenada_primer_cuadrante(coordenada_t *objeto){
}

void coordenada_segundo_cuadrante(coordenada_t *objeto){
}

void coordenada_tercer_cuadrante(coordenada_t *objeto){
}

void coordenada_cuarto_cuadrante(coordenada_t *objeto){
}


/*INIALIZAR*/

void inicializar_robot(juego_t *michael[MAX_ROBOTS],int tope_robots,char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

void inicializar_lasers(robot_t *prueba_uno, char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

void inicializar_pinzas(coordenada_t *pinza[MAX_PINZAS],int tope_pinza,char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

void inicializar_traje(supertraje_t *supertraje[MAX_SUPERTRAJES],int tope_supertraje,char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

void inicializar_movimientos_iniciales(personaje_t *superheroe){
}

void figura_uno (robot_t *prueba_uno, char matriz[MAX_MATRIZ][MAX_MATRIZ]){ //L
}

void figura_tres (robot_t *prueba_uno, char matriz[MAX_MATRIZ][MAX_MATRIZ]){ //L
}


void figura_cinco (robot_t *prueba_uno,char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

void figura_siete (robot_t *prueba_uno,char matriz[MAX_MATRIZ][MAX_MATRIZ]){

}
//ROTACIONES
void de1a2 (robot_t *prueba_uno, char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

// primer y segubdo cuadrante aumenta j
//mismo?
void de2a3_y_3a4 (robot_t *prueba_uno, char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

void de4a5 (robot_t *prueba_uno, char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

void de5a6 (robot_t *prueba_uno, char matriz[MAX_MATRIZ][MAX_MATRIZ]){
}

/*ACCIONES*/

/*SUPERPODERES*/


void chequear_traje(){
}

void poderes(personaje_t *superheroe){
}


//solo va a rango positivo ,no negativo/////////////-------------------
void mover_posicion_pinzas(personaje_t *personaje,char matriz[MAX_MATRIZ][MAX_MATRIZ],robot_t *robot){
}

//CHAR MOVIMIENTO -> MOVIMIENTO_USUARIO()
//cada vez que llama se baja el tope de cantidad de movimientos 
void caminar_por_mapa(personaje_t *personaje, char matriz[MAX_MATRIZ][MAX_MATRIZ],char movimiento){
}




//funcionamiento del juego en si

int movimiento_usuario(){
}
    
/*
 * Inicializará el juego, cargando toda la información inicial de los robots, los supertrajes, el personaje, los lásers y las pinzas.
 * El campo id_personaje_actual comienza en 1.
 */ 
void inicializar_juego(juego_t* juego, bool contrasenia_completa);

/*
 * Moverá el personaje y se realizarán todas las acciones necesarias en caso de chocas con algún elemento.
 */ 
void realizar_jugada(juego_t* juego, char movimiento);

/*
 * Imprime el juego por pantalla.
 */
void imprimir_terreno(juego_t juego);
/*
 * El juego se dará por ganado si se está sobre el casillero de salida siendo el personaje Mr. Increíble y perdido si el personaje (cualquiera sea) se queda sin movimientos.
 * Devuelve:
 * -> 1 si se ganó el juego.
 * -> 0 si el juego aún se está jugando.
 * -> -1 se se perdió el juego.
 */
int estado_juego(juego_t juego);
