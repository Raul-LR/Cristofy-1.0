#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
using namespace std;

class Multimedia
{
private:
	//alfanúmerico incremental único id();
	string titulo;
	string compania;
	int anio;
	float puntuacionTotal;
	int totalUsuariosQueHanValorado;
	float valoracionMediaActual;
	string rutaFichero;
	string formato;
	string rutaPrograma;
public:
	/*****CONSTRUCTORES Y DESTRUCTORES*****/
	Multimedia();
	Multimedia(string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma);
	virtual ~Multimedia();//virtual para la herencia de musica, video e imagen
	/*****SETS Y GETS*****/
	inline void setTitulo(string nuevo_titulo) {this->titulo = nuevo_titulo;}
	inline void setCompania(string nueva_compania) {this->compania = nueva_compania;}
	inline void setAnio(int nuevo_anio) {this->anio = nuevo_anio;}
	inline void setPuntuacionTotal(float nueva_puntuacionTotal) {this->puntuacionTotal = nueva_puntuacionTotal;}
	inline void setTotalUsuariosQueHanValorado(int nuevos_usuariosQueHanValorado) {this->totalUsuariosQueHanValorado = nuevos_usuariosQueHanValorado;}
	inline void setValoracionMediaActual(float nueva_valoracionMediaActual) {this->valoracionMediaActual = nueva_valoracionMediaActual;}
	inline void setRutaFichero(string nueva_rutaFichero) {this->rutaFichero = nueva_rutaFichero;}
	inline void setFormato(string nuevo_formato) {this->formato = nuevo_formato;}
	inline void setRutaPrograma(string nueva_rutaPrograma) {this->rutaPrograma = nueva_rutaPrograma;}
	inline string getTitulo() {return this->titulo;}
	inline string getCompania() {return this->compania;}
	inline int getAnio() {return this->anio;}
	inline float getPuntuacionTotal() {return this->puntuacionTotal;}
	inline int getTotalUsuariosQueHanValorado() {return this->totalUsuariosQueHanValorado;}
	inline float getValoracionMediaActual() {return this->valoracionMediaActual;}
	inline string getRutaFichero() {return this->rutaFichero;}
	inline string getFormato() {return this->formato;}
	inline string getRutaPrograma() {return this->rutaPrograma;}
	/*
	*@Brief, método que imprime los datos del multimedia
	*/
	virtual void print();
	/*
	*@Brief, método que reproduce el archivo multimedia
	*/
	virtual void reproducir();
	/*
	*@Brief, método que módifica los datos del multimedia
	*@Param, string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string rutaFichero, string formato, string rutaPrograma
	*/
	virtual void modificarMultimedia(string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma /*,id*/);
};

#endif /* MULTIMEDIA_H */