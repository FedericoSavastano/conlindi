#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipos.h"
#include "funciones.h"
#include "jugadores.h"
#include "partido.h"
#include "referi.h"
#include "validaciones.h"

#define CANT_EQUIPOS 3
#define CANT_JUGADORES 4
#define CANT_PARTIDOS 3
#define CANT_REFERIS 2
#define MAX_EQUIPOS 4
#define MAX_JUGADORES 5

#define TRUE 0
#define FALSE 1

void mostrarJugadoresPorEquipo(eEquipo* listaEquipos, eJugador* listaJugadores, int cantidadEquipos, int cantidadJugadores);



void sumarnumero(int *numerogarlompa)
{
    *numerogarlompa=*numerogarlompa+8;
    printf("Tu numero garlompa en la funcion es %d", *numerogarlompa);
}

void comosifueseelmain()
{
    int numeroGarlompa;
    numeroGarlompa=2;

    sumarnumero(&numeroGarlompa);

    printf("\nEl numero garlompa en el pseudo main es %d", numeroGarlompa );


}


int inicializarEquipos (eEquipo listaEquipos[], int cantidad)
{
    int returnInit;
    if(listaEquipos!=NULL && cantidad==CANT_EQUIPOS)
    {
        int i;
        for(i=0;i<cantidad;i++)
        {
            listaEquipos[i].estaVacioEquipo=TRUE;
            returnInit = 0;
        }
    }else{
        returnInit= -1;
    }

    return returnInit;
}


int buscarLugarVacioEquipos(eEquipo* listaEquipos, int cantidad   )
{
    int i;
    int lugarVacioValido=0;
    int indiceEncontrado;

    for(i=0;i<cantidad;i++)
    {
        if(listaEquipos[i].estaVacioEquipo==TRUE)
        {
            indiceEncontrado=i;
            lugarVacioValido=1;
            break;
        }else if(listaEquipos[i].estaVacioEquipo=='\0' && lugarVacioValido==0)
        {
            indiceEncontrado=-1;
        }
    }

    return indiceEncontrado;
}













void mostrarMenu()
{
    int opcionMenu;
    int codigoEquiposAcumulador=0;
    int codigoJugadoresAcumulador=0;
    int codigoPartidosAcumulador=0;
    int codigoReferiAcumulador=0;


    eEquipo listaEquipos[CANT_EQUIPOS];
    int validarInicializarEquipos;
    int lugarVacioEquipo;
    //int validarNombreEquipo;
    //int validarLocalidadEquipo;
    //int validarEquipo;
    int ingresoEquipoValidado;
    int auxCodigoEquipo;
    int auxIndiceEquipo;

    eJugador listaJugadores[CANT_JUGADORES];
    int validarInicializarJugadores;
    int lugarVacioJugadores;

    int ingresoJugadorValidado;
    int auxCodigoJugador;
    int auxIndiceJugador;


    char confirmaSN;


    validarInicializarEquipos=inicializarEquipos(listaEquipos,CANT_EQUIPOS);
    validarInicializarJugadores=inicializarJugadores(listaJugadores,CANT_JUGADORES);
    /**GUARDA PUEDE QUE HAYA QUE VALIDAR TODOS Y HACER QUE EL IF RECONOZCA TODOS PARA EMPEZAR**/



    if (  (validarInicializarEquipos==0)&&(validarInicializarJugadores==0) ) {

        imprimirMenu();
        opcionMenu=getInt("\nElija una opcion : \n");
            fflush(stdin);

        while(opcionMenu!=17)
        {
            if(opcionMenu>0 && opcionMenu<17)
            {
                switch(opcionMenu)
                {
                case 1:
                    /**EQUIPOS**/
                    printf("\nDar de alta un equipo\n");
                    confirmaSN=getChar("Ingresar un equipo? [ S / N ] \n");

                    if(confirmaSN=='s' || confirmaSN=='S'){
                        lugarVacioEquipo=buscarLugarVacioEquipos(listaEquipos,CANT_EQUIPOS);
                        printf("lugar vacio equipo es : %d\n",lugarVacioEquipo);
                        if(lugarVacioEquipo>-1 && listaEquipos!=NULL && CANT_EQUIPOS<MAX_EQUIPOS)
                        {

                            //int auxCodigoEquipo;
                            char auxNombreEquipo[51];
                            char auxLocalidadEquipo[33];

                            //validarNombreEquipo=getValidString("Ingrese el nombre del equipo : ", "nombre no valido ", "nombre demasiado largo ",
                                                         //      auxNombreEquipo,51,3);
                           // validarLocalidadEquipo=getValidString("Ingrese la localidad del equipo : ", "Localidad no valida ", "Nombre demasiado largo ",
                                                             //     auxLocalidadEquipo,51,3);

                            if( ( getValidString(" Ingrese el nombre del equipo : ", " nombre no valido \n", "nombre demasiado largo \n",
                                                               auxNombreEquipo,51,3) )==0

                               && (  getValidString(" Ingrese la localidad del equipo : ", "Localidad no valida \n", "Nombre demasiado largo \n",
                                                                  auxLocalidadEquipo,51,3) )==0)
                            {
                                auxCodigoEquipo=incrementarID(&codigoEquiposAcumulador);
                               // validarEquipo= agregarEquipo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipo,auxNombreEquipo,auxLocalidadEquipo,lugarVacioEquipo);
                                if(  ( agregarEquipo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipo,auxNombreEquipo,auxLocalidadEquipo,lugarVacioEquipo)  ) ==0)
                                {
                                    ingresoEquipoValidado=1;
                                    listaEquipos[lugarVacioEquipo].estaVacioEquipo=FALSE;
                                    printf("\n");
                                    printf("Equipo agregado exitosamente!");
                                    printf("\n\n");
                                    break;
                                }else{
                                printf("No se pudo agregar a ese equipo\n");
                                break;
                                }//if(validarEquipo==0)

                            }else{
                                printf("No se pudo agregar a ese equipo\n");
                                break;
                            }//if(validarNombreEquipo==0 && validarLocalidadEquipo==0)



                        }else{
                            printf("\nNo hay mas lugar para agregar equipos\n");
                            break;
                        }//if(validarNombreEquipo==0 && validarLocalidadEquipo==0)



                        /** PONER UN FLAG DE QUE SE CARGO ALGO PARA PASAR AL MODIFICAR Y DEMAS*/
                        /*int i;
                        for(i=0;i<CANT_EQUIPOS;i++)
                        {
                            printf("\nINGRESAMO UN EQUIPO NO MA\n");

                            printf("\nEl esta vacio de los equipos es : %d \n",listaEquipos[i].estaVacioEquipo);


                            //break;
                        }
                        */
                    }else{
                       printf( "Cancelado el ingreso de equipo" );
                        break;
                    }//(confirmaSN=='s' || confirmaSN=='S')



                    //break;

                case 2:
                    if(ingresoEquipoValidado==1)
                    {
                        ordenarEquiposAlfabeticamente(listaEquipos,CANT_EQUIPOS);
                        mostrarEquipos(listaEquipos,CANT_EQUIPOS);
                        break;

                    }else{
                        printf("\nPrimero ingrese un equipo\n");
                        break;
                    }//if(ingresoEquipoValidado==1)




                    break;
                case 3:
                    if(ingresoEquipoValidado==1)
                    {
                        ordenarEquiposAlfabeticamente(listaEquipos,CANT_EQUIPOS);
                        mostrarEquipos(listaEquipos,CANT_EQUIPOS);


                       auxCodigoEquipo=getInt("Elija el codigo del equipo a modificar : ");

                       auxIndiceEquipo=buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipo);

                      if (  (  modificarEquipo(listaEquipos,auxIndiceEquipo ) ==0    ) )
                      {
                          printf("Modificacion Terminada");
                          break;
                      }else{
                        printf("no se modifico una chorga");
                        break;
                      }

                    }



                    break;
                case 4:
                     if(ingresoEquipoValidado==1)
                    {

                        ordenarEquiposAlfabeticamente(listaEquipos,CANT_EQUIPOS);
                        mostrarEquipos(listaEquipos,CANT_EQUIPOS);
                        if(getValidInt("Ingrese el codigo del equipo a dar de baja [x para cancelar] : ","Codigo no valido ", &auxCodigoEquipo,0,CANT_EQUIPOS,3)==0)
                        {
                            printf("El codigo que elegi para dar de baja es el %d \n",auxCodigoEquipo);

                            if(bajaEquipoConfirm(listaEquipos,CANT_EQUIPOS,auxCodigoEquipo)==0)
                            {
                                printf("Baja exitosa ");
                                break;
                            }else{
                                printf("baja fallida ");
                                break;
                            }

                        }else{
                            printf("\n No se pudo hacer la baja \n");
                        }
                        break;

                    }else{
                        printf("\nPrimero ingrese un equipo \n");
                        break;
                    }//if(ingresoEquipoValidado==1)

                    break;




                case 5:
                    /**JUGADORES**/
                if(ingresoEquipoValidado==1)
                {
                    printf("\nDar de alta un Jugador\n");
                    confirmaSN=getChar("Ingresar un jugador? [ S / N ] \n");

                    if(confirmaSN=='s' || confirmaSN=='S'){
                        lugarVacioJugadores=buscarLugarVacioJugadores(listaJugadores,CANT_JUGADORES);
                        printf("lugar vacio jugadores es : %d\n",lugarVacioJugadores);

                        if(lugarVacioJugadores>-1 && listaJugadores!=NULL && CANT_JUGADORES<MAX_JUGADORES)
                        {

                            int auxCodigoJugador;
                            char auxApellidoJugador[31];
                            char auxNombreJugador[31];
                            int auxCodigoEquipoJugador; //REVISAR SI ESTO TIENE QUE ESTAR LIGADO AL ESTRUC DE EQUIPOS
                            char auxSexo;
                            //int codigoEquipo;
                            eFechaJugador auxFechaNacimiento;

                            if( getValidString( "Ingrese el apellido del jugador : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoJugador, 31,3 ) ==0
                                    && ( getValidString( "Ingrese el nombre del jugador : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreJugador,31,3)  ==0 )

                            ){
                                auxSexo= getChar("Ingrese el sexo del jugador M o F : ");
                                if(validSexo(auxSexo)==0)
                                {
                                    printf("CULOOOO");
                                    if(   introducirFechaJugador2(&auxFechaNacimiento) ==0  )
                                    {
                                        printf("estAMOS ACA");
                                        mostrarEquipos(listaEquipos,CANT_EQUIPOS);
                                        if(getValidInt("Ingrese el codigo del equipo al que el jugador pertenece : ", "Codigo no valido ",&auxCodigoEquipoJugador,1,CANT_EQUIPOS,3) == 0 )
                                       if(buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipoJugador)>-1 )
                                       {
                                                int mostrarIndice;
                                                mostrarIndice=buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,auxCodigoEquipoJugador);
                                                printf("OK pertenece al : %s ", listaEquipos[mostrarIndice].nombre);

                                                confirmaSN=getChar("Ingresar un jugador? [ S / N ] \n");

                                                    if(confirmaSN=='s' || confirmaSN=='S'){
                                           auxCodigoJugador=incrementarID(&codigoJugadoresAcumulador);

                                           if (agregarJugador(listaJugadores,CANT_JUGADORES,auxCodigoJugador,auxApellidoJugador,auxNombreJugador,
                                                          auxSexo,auxCodigoEquipoJugador,auxFechaNacimiento,lugarVacioJugadores) == 0 )
                                                          {
                                                              printf("\n Alta de jugador realizada exitosamente \n\n");
                                                              break;
                                                          }else { printf("No se pudo cargar al jugador \n"); break;}
                                                    }else{printf("Carga cancelada "); break;}



                                       }//if(buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,codigoEquipo)>-1 )

                                    }else{printf(" AAAAA Fecha no valida AAAAA");break;}//if(  ( introducirFechaJugador2(auxFechaNacimiento) ) ==0  )




                            }else{printf("Sexo no valido");break;}//if(auxSexo=='m' || auxSexo=='M' || auxSexo=='f' ||auxSexo'F')
                            }else{printf("Nombre no valido");break;}//if( getValidString( "Ingrese el apellido del jugador : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoJugador, 31,3 ) ==0
                                   // && ( getValidString( "Ingrese el nombre del jugador : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreJugador,31,3)  ==0 )

                        }else{printf("no hay mas lugar");break;}//if(lugarVacioJugadores>-1 && listaJugadores!=NULL && CANT_JUGADORES<MAX_JUGADORES)
                    }else{printf("saliendo"); break;}//if(confirmaSN=='s' || confirmaSN=='S')










                        break;

                }else//if(ingresoEquipoValidado==1)
                    {printf("Primero ingrese un equipo\n\n");
                    break;}

                case 6:
                    printf(" MOSTRAR JUGADORES ");

                    if(ingresoEquipoValidado==1)
                    {
                        ordenarJugadoresAlfabeticamente(listaJugadores,CANT_JUGADORES);
                        mostrarJugadores(listaJugadores,CANT_JUGADORES);
                        break;

                    }else{
                        printf("\nPrimero ingrese un equipo\n");
                        break;
                    }//if(ingresoEquipoValidado==1)


                    break;

                case 7:
                     if(ingresoEquipoValidado==1)
                    {

                        ordenarJugadoresAlfabeticamente(listaJugadores,CANT_JUGADORES);
                        mostrarJugadores(listaJugadores,CANT_JUGADORES);
                        if(getValidInt("Ingrese el codigo del jugador a dar de baja [x para cancelar] : ","Codigo no valido ", &auxCodigoJugador,0,CANT_JUGADORES,3)==0)
                        {
                            printf("El codigo que elegi para dar de baja es el %d \n",auxCodigoJugador);

                            if(bajaJugadorConfirm(listaJugadores,CANT_JUGADORES,auxCodigoJugador)==0)
                            {
                                printf("Baja exitosa ");
                                break;
                            }else{
                                printf("baja fallida ");
                                break;
                            }

                        }else{
                            printf("\n No se pudo hacer la baja \n");
                        }
                        break;

                    }else{
                        printf("\nPrimero ingrese un equipo \n");
                        break;
                    }//if(ingresoEquipoValidado==1)



                    break;

                case 8:
                    mostrarJugadoresPorEquipo(listaEquipos,listaJugadores,CANT_EQUIPOS,CANT_JUGADORES);
                    break;


                default:
                    printf("Opcion no valida pindongas");
                    break;


                }//switch(opcionMenu)














        }else{
        printf("\nOpcion no valida. Ingrese una de las opciones del menu.\n");
        opcionMenu=17;


        //continue;
        }   //if(opcionMenu>0)



        printf("\n\n");
        system("pause");
        system("cls");
        imprimirMenu();
        opcionMenu=getInt("\nElija una opcion : \n");
        fflush(stdin);
        printf("\n\n");

    }//while(opcionMenu!=17)
}else{
    printf("\nHa ocurrido un error, no se puede cargar en este momento\n\n");
}//if(validarInicializarEquipos==0)





}

void imprimirMenu()
{

    printf("\n");
    printf("Equipos");
    printf("\n");
    printf("  1. Alta\n");
    printf("  2. Listar\n");
    printf("  3. Modificar\n");
    printf("  4. Baja\n");
    printf("\n");
    printf("\n");
    printf("Jugadores");
    printf("\n");
    printf("  5. Alta\n");
    printf("  6. Listar\n");
    printf("  7. Baja\n");
    printf("\n");
    printf("\n");
    printf("Referis");
    printf("\n");
    printf("  8. Alta\n");
    printf("\n");
    printf("\n");
    printf("Partidos");
    printf("\n");
    printf("  9. Alta\n");
    printf("  10. Listar\n");
    printf("\n");
    printf("\n");
    printf("Informes y Listados");
    printf("\n");
    printf("  11. Listado de Jugadores por Equipo\n");
    printf("  12. Referi que mas partidos dirigió\n");
    printf("  13. Buscar por jugador\n");
    printf("  14. Equipo con el nombre mas largo\n");
    printf("  15. Buscar por fecha\n");
    printf("  16. Mostrar equipo con promedio de edad mas joven\n");
    printf("\n");
    printf("\n");
    printf("  17. Salir\n");
    printf("\n");
}









void mostrarJugadoresPorEquipo(eEquipo* listaEquipos, eJugador* listaJugadores, int cantidadEquipos, int cantidadJugadores)
{
    printf("EQUIPOS\n");
    printf("\t Codigo  \t  Nombre  \t   Localidad\n");

    int ix;
    int ij;
    for(ix=0;ix<cantidadEquipos;ix++)
    {
      for(ij=0;ij<cantidadJugadores;ij++)
        {
            if(listaEquipos[ix].estaVacioEquipo==FALSE)
            {
                if(listaEquipos[ix].codigoEquipo == listaJugadores[ij].codigoEquipoJugador )

                printf("\n\t %2d  \t %18s  \t %18s\n",listaEquipos[ix].codigoEquipo,listaEquipos[ix].nombre,listaEquipos[ix].localidad);

                if(listaJugadores[ij].estaVacioJugador==FALSE)
        {

             printf("JUGADOR\n");
            printf("\n %3d\t %8s\t %4s\t  %2c\t   %4d/%3d/%5d\t   %3d\t \n", listaJugadores[ij].codigoJugador, listaJugadores[ij].apellidoJugador,
                   listaJugadores[ij].nombreJugador, listaJugadores[ij].sexo, listaJugadores[ij].fechaNacimiento.dia, listaJugadores[ij].fechaNacimiento.mes,
                   listaJugadores[ij].fechaNacimiento.anio, listaJugadores[ij].codigoEquipoJugador);
        }
            }
        }
    }
}
