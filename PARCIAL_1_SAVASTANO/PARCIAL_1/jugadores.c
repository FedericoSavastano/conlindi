
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "validaciones.h"
#include "equipos.h"
#include "jugadores.h"

#define CANT_EQUIPOS 3
#define CANT_JUGADORES 4
#define CANT_PARTIDOS 3
#define CANT_REFERIS 2

#define TRUE 0
#define FALSE 1




/** \brief Carga un equipo al array lista de equipos devuelve 0 si lo hizo bien, -1 si falló.
 *
 * \param listaEquipos eEquipo* puntero al array a donde cargar
 * \param cantidad int cantidad de elementos que tiene el array
 * \param codigo int codigo incrementado que se copia de otra funcion
 * \param nombre[] char nombre a cargar
 * \param localidad[] char localidad a cargar
 * \param lugarVacio int el indice donde cargar
 * \return int 0 si fue exitoso , -1 si falló
 *
 */
int agregarJugador(eJugador* listaJugadores, int cantidad, int codigoJugador, char apellido[] ,char nombre[], char sexo, int codigoEquipo, eFechaJugador fechaJugador ,int lugarVacio)
{
    if(listaJugadores!=NULL && cantidad==CANT_JUGADORES)
    {
        ponerMayusculas(nombre);
        ponerMayusculas(apellido);

        listaJugadores[lugarVacio].codigoJugador=codigoJugador;
        strcpy(listaJugadores[lugarVacio].nombreJugador,nombre);
        strcpy(listaJugadores[lugarVacio].apellidoJugador,apellido);
        ///CODIGO DE EQUIPO VALIDAR

        listaJugadores[lugarVacio].sexo=sexo;

        listaJugadores[lugarVacio].fechaNacimiento=fechaJugador;

        listaJugadores[lugarVacio].estaVacioJugador=FALSE;

        return 0;
    }

    return -1;

}

/** \brief Guarda la fecha de nacimiento de un jugador
 *
 * \return la estructura de fecha jugador
 *
 */
eFechaJugador introducirFechaJugador ()
{
    eFechaJugador fechaDeUnJugador;

    printf("Ingrese la fecha de nacimiento del jugador\n");
    printf("Dia : ");
    scanf("%d",&fechaDeUnJugador.dia);
    printf("Mes : ");
    scanf("%d",&fechaDeUnJugador.mes);
    printf("Anio : ");
    scanf("%d",&fechaDeUnJugador.anio);

    return fechaDeUnJugador;
}










/** \brief busca lugar vacio en el array de jugadores, devuelve el indice del primer lugar vacio
 *
 * \param listaJugadores eJugador* array de jugadores
 * \param cantidad int cantidad de elementos del array
 * \return int el indice encontrado o -1 si no hay mas lugar
 *
 */
int buscarLugarVacioJugadores(eJugador* listaJugadores, int cantidad   )
{
    int i;
    int lugarVacioValido=0;
    int indiceEncontrado;

    for(i=0;i<cantidad;i++)
    {
        if(listaJugadores[i].estaVacioJugador==TRUE)
        {
            indiceEncontrado=i;
            lugarVacioValido=1;
            break;
        }else if(listaJugadores[i].estaVacioJugador=='\0' && lugarVacioValido==0)
        {
            indiceEncontrado=-1;
        }
    }

    return indiceEncontrado;
}







/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int inicializarJugadores (eJugador* listaJugadores, int cantidad )
{
    int returnInit;
    if(listaJugadores!=NULL && cantidad==CANT_JUGADORES)
    {
        int i;
        for(i=0;i<cantidad;i++)
        {
            listaJugadores[i].estaVacioJugador=TRUE;
            returnInit = 0;
        }
    }else{
        returnInit= -1;
    }

    return returnInit;
}
