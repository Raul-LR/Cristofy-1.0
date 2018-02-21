#ifndef MUSICA_H
#define MUSICA_H 

#include "multimedia.h"
#include <string>
#include <iostream>
using namespace std;

class Musica: public Multimedia 
{
private:
	int duracion;
	string autor;
	string estilo;
public:
	/*****CONSTRUCTORES Y DESTRUCTORES*****/
	Musica();
	Musica(int duracion, string autor, string estilo, string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma);
	~Musica();
	/*****SETS Y GETS*****/
	inline void setDuracion(int nueva_duracion) {this->duracion = nueva_duracion;}
	inline void setAutor(string nuevo_autor) {this->autor = nuevo_autor;}
	inline void setEstilo(string nuevo_estilo) {this->estilo = nuevo_estilo;}
	inline int getDuracion() {return this->duracion;}
	inline string getAutor() {return this->autor;}
	inline string getestilo() {return this->estilo;}
	/*
	*@Brief, método que imprime los datos de la canción
	*/
	void print();
	/*
	*@Brief, método que módifica los datos de la canción
	*@Param, string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string rutaFichero, string formato, string rutaPrograma, int duracion, string autor, string estilo
	*/
	void modificarMultimedia(string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma, int duracion, string autor, string estilo);
	/*
	*@Brief, método que reproduce la canción
	*/
	void reproducir();
};

#endif /* MUSICA_H */