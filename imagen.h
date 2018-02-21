#ifndef IMAGEN_H
#define IMAGEN_H 

#include "multimedia.h"
#include <string>
#include <iostream>
using namespace std;

class Imagen: public Multimedia 
{
private:
	string resolucion;
public:
	/*****CONSTRUCTORES Y DESTRUCTORES*****/
	Imagen();
	Imagen(string resolucion, string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma);
	~Imagen();
	/*****SETS Y GETS*****/
	inline void setResolucion(string nueva_resolucion) {this->resolucion = nueva_resolucion;}
	inline string getResolucion() {return this->resolucion;}
	/*
	*@Brief, método que imprime los datos de la imágen
	*/
	void print();
	/*
	*@Brief, método que módifica los datos del vídeo
	*@Param, string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string rutaFichero, string formato, string rutaPrograma, string resolucion
	*/
	void modificarMultimedia(string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma, string resolucion);
	/*
	*@Brief, método que abre la imágen
	*/
	void reproducir();
};

#endif /* IMAGEN_H */