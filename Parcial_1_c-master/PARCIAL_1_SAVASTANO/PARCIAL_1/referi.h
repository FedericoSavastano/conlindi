

typedef struct{
    int dia;
    int mes;
    int anio;

}eFechaReferi;
typedef struct{
    int codigoReferi;
    char apellido[31];
    char nombre[31];
    char sexo;
    char email[31];
    eFechaReferi fechaNacimiento;


}eReferi;
