#ifndef VIDEO_H
#define VIDEO_H 

#include "multimedia.h"
#include <string>
#include <iostream>
using namespace std;

class Video: public Multimedia 
{
private:
	int duracion;
	string tematica;
	string autor;
public:
	/*****CONSTRUCTORES Y DESTRUCTORES*****/
	Video();
	Video(int duracion, string tematica, string autor, string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma);
	~Video();
	/*****SETS Y GETS*****/
	inline void setDuracion(int nueva_duracion) {this->duracion = nueva_duracion;}
	inline void setTematica(string nueva_tematica) {this->tematica = nueva_tematica;}
	inline void setAutor(string nuevo_autor) {this->autor = nuevo_autor;}
	inline int getDuracion() {return this->duracion;}
	inline string getTematica() {return this->tematica;}
	inline string getAutor() {return this->autor;}
	/*
	*@Brief, método que imprime los datos del vídeo
	*/
	void print();
	/*
	*@Brief, método que módifica los datos del vídeo
	*@Param, string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string rutaFichero, string formato, string rutaPrograma, int duracion, string tematica, string autor
	*/
	void modificarMultimedia(string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma, int duracion, string tematica, string autor);
	/*
	*@Brief, método que reproduce el vídeo
	*/
	void reproducir();
};

#endif /* VIDEO_H */