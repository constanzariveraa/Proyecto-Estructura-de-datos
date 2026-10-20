//
// Created by const on 20-10-2026.
//
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#define MAX_SALAS 10

/* Tipos de Pase */
#define PASE_GENERAL 'G'
#define PASE_INFANTIL 'I'
#define PASE_FAMILIAR 'F'
#define PASE_PRIORITARIO 'P'

/* Estados del Pase */
#define ESTADO_PASE_ACTIVO 1
#define ESTADO_PASE_UTILIZADO 2
#define ESTADO_PASE_ANULADO 3
#define ESTADO_PASE_VENCIDO 4


struct Pase {
    int Codigo;
    char Tipo;
    float Valor;
    int Estado;
};

struct NodoPase {
    struct Pase datos;
    struct NodoPase *sig;
};

struct Fecha {
    int Dia;
    int Mes;
    int Anio;
};

struct Cliente {
    char *rut;
    char *nombre;
    struct Fecha FechaNacimiento;
    int dentroTienda;
};

struct NodoCliente {
    struct Cliente datos;
    struct NodoCliente *sig;
};

struct NodoEspera {
    struct Cliente *cliente;
    struct NodoEspera *sig;
};

struct ListaDeEspera {
    struct NodoEspera *primero;
    struct NodoEspera *ultimo;
    int cantClientes;
};

struct Titulo {
    int codigoTitulo;
    char *nombre;
    char *tipoPublicacion;
    int clasificacionEdad;
    int Estado; /* 1=Disponible, 2=Agotado, 3=Preventa, 4=Descatalogado */
    int CantidadEjemplares;
    float precio;
    int ejemplaresPorDespacho;
    int diasEntreDespacho;
    int totalSolicitudes;
};

struct NodoTitulo {
    struct Titulo datos;
    struct ListaDeEspera espera;
    struct NodoTitulo *izq, *der;
};

/* Encapsulamiento del ABB */
struct ArbolTitulos {
    struct NodoTitulo *raiz;
    int cantTitulos;
};

struct SalaTematica {
    int CodigoSala;
    char *Nombre;
    char *Tematica;
    char *Horario;
    char NombreEncargado[50];
    int AforoMaximo;
    int AforoActual;
    struct ArbolTitulos catalogo;
};

struct NodoSala {
    struct SalaTematica *infoSala;
    struct ArbolTitulos catalogo;
};

/* Estructura Estática Principal */
struct Tienda {
    struct NodoSala *salas[MAX_SALAS];
    struct NodoCliente *clientes;
    struct NodoPase *pases;
    struct Fecha FechaOperacion;
    int TotalSalas;
    float TotalRecaudado;
};

int main() {
    printf("Hello, World!\n");
    return 0;
}

