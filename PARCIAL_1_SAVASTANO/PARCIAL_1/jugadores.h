
typedef struct{
    int dia;
    int mes;
    int anio;

}eFechaJugador;


typedef struct{
    int codigoJugador;
    char apellidoJugador[31];
    char nombreJugador[31];
    int codigoEquipoJugador; //REVISAR SI ESTO TIENE QUE ESTAR LIGADO AL ESTRUC DE EQUIPOS
    char sexo;
    eFechaJugador fechaNacimiento;

    int estaVacioJugador;  /**CERO PARA CIERTO, 1 PARA FALSO*/

}eJugador;




int agregarJugador(eJugador* listaJugadores, int cantidad, int codigoJugador, char apellido[] ,char nombre[], char sexo, int codigoEquipo, eFechaJugador fechaJugador ,int lugarVacio);
eFechaJugador introducirFechaJugador ();


int buscarLugarVacioJugadores(eJugador* listaJugadores, int cantidad   );
int inicializarJugadores (eJugador* listaJugadores, int cantidad );
