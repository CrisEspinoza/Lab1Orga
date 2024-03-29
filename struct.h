// Se importan las cosas que ayudaran al funcionamiento del codigo 
#include <stdio.h>
#include <string.h>
#include <locale.h>

// Definimos el arreglo constante que tendres, que se encarga de representar a los registros.

const char *registroMars[32] = {"$zero","$at","$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7",
"$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"};

// Definimos las estructuras a ocupar dentro de la aplicacion

typedef struct LineaDeControl
{
	char* Estado;
	int PC;
	char RegDst;
	char Jump;
	char Branch;
	char MemRead;
	char MemToReg;
	char* ALUOp;
	char MemWrite;
	char ALUSrc;
	char RegWrite;

}LineaDeControl;

typedef struct Label
{
	char *label;
	int PC;

}Label;

typedef struct Instruccion
{
	char *instruccion;
	char *rt;
	char *rs;
	char *rd;
	int inmediato;
	int PC;
	LineaDeControl* lineaDeControl;

}Instruccion;

typedef struct Lista
{
	int largo;
	LineaDeControl* lineaTraza;

}Lista;

typedef struct Informacion
{
	Instruccion* instrucciones;
	int registros[32];
	int cantidadDeInstrucciones;
	Label etiqueta[100];
	int memoria[1000];
	Lista* lineasDeControl;

}Informacion;


// FUNCIONES

LineaDeControl* leerLineaDeControl(char nombre[],int numeroDeLineas);
void inicializarMemoriaParaInstrucciones(Informacion *informacion, int cantidadLineas);
Informacion* leerInstrucciones(char nombre[], int numeroDeLineas);
int obtenerPosicionReg(char* registro);
int contarLineas(char nombre[]);
int obtenerPosicionReg(char* registro);
void add (Informacion* info , Instruccion* instruccion);
void sub (Informacion* info , Instruccion* instruccion);
void subi (Informacion *info , Instruccion *instruccion);
void addi (Informacion *info , Instruccion *instruccion);
void mul (Informacion *info , Instruccion *instruccion);
void divi (Informacion *info , Instruccion *instruccion);
LineaDeControl* asignarLineasDeControl (char* instruccion, int PC);
void traza(Informacion* info, Instruccion* instrucciones,char* nombreArchivoSalida, LineaDeControl* lineasControlDadas);
int jump(Informacion *info, Instruccion *instruccion);
int buscarPosicionEtiqueta(char* etiqueta, Informacion *info);
void sw(Informacion *info, Instruccion *instruccion);
void lw(Informacion *info, Instruccion *instruccion);
int beq(Informacion *info, Instruccion *instruccion);
Lista* crearLista();
Lista* agregarNodo(Lista* lista , LineaDeControl* aux);
void mostrarLineasDeControl(Lista* lista);
void mostrar(LineaDeControl* lista, int largo);
void realizarSalida(Lista* lista,LineaDeControl* lineasControlDadas);