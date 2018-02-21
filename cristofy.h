#ifndef CRISTOFY_H
#define CRYSTOFY_H

#include "video.h"
#include "musica.h"
#include "imagen.h"
#include "multimedia.h"
#include "usuario.h"
#include <iostream>
using namespace std;

class Cristofy
{
private:
	Usuario** listaUsuarios;
	int usuariosTotales;
	int dimUsuarios;
	Multimedia** listaContenidoMultimedia;
	int contenidosTotales;
	int dimMultimedia;
public:
	/*
	*@Brief Constructor por defecto
	*/
	Cristofy();
	/*
	*@Brief Constructor por parametro
	*@Param int dimUsuarios, dimension máx de los usuarios, int dimMultimedia, dimensión máx de los multimedia
	*/
	Cristofy(int dimUsuarios, int dimMultimedia);
	/*
	*@Brief Destructor
	*/
	~Cristofy();
	/*****SETS Y GETS*****/
	void setListaUsuarios(Usuario *u);
	inline void setUsuariosTotales(int nuevo_total) {this->usuariosTotales = nuevo_total;}
	inline void setDimUsuarios(int nueva_dimUsuarios) {this->dimUsuarios = nueva_dimUsuarios;}
	inline void setContenidosTotales(int nuevo_total) {this->contenidosTotales = nuevo_total;}
	inline void setDimMultimedia(int nueva_dimMultimedia) {this->dimMultimedia = nueva_dimMultimedia;}
	void setListaContenidoMultimedia(Multimedia *m);
	inline int getUsuariosTotales() {return this->usuariosTotales;}
	inline int getDimUsuarios() {return this->dimUsuarios;}
	inline int getContenidosTotales() {return this->contenidosTotales;}
	inline int getDimMultimedia() {return this->dimMultimedia;}
	inline Usuario* getUsuario(int posicion) {return this->listaUsuarios[posicion];}
	inline Multimedia* getMultimedia(int posicion) {return this->listaContenidoMultimedia[posicion];}
	/*
	*@Brief, método que nos da la bienvenida
	*/
	void bienvenida();
	/*
	*@Brief, método que autentifica los datos del usuario
	*/
	bool autenticacion(int posicion, string password);
	/*
	*@Brief, método para registrar un usuario
	*/
	void registrarUsuario();
	/*
	*@Brief, método para registrar un usuario
	*/
	void registrarMultimedia();
	/*
	*@Brief, método que muestra el menu de administrador
	*/
	void mostrarMenu(bool admin);
	/*
	*@Brief, método que muestra el menu de usuario
	*/
	void mostrarMenu();
	//bool importarFichero(string rutaOrigen);
	//bool exportarFichero(string rutaDestino);
	/*
	*@Brief, método que busca dentro del sistema un usuario mediante su login
	*@Param, const string login, login del usuario
	*/
	int buscarUsuarioEnSistema(const string login);
	/*
	*@Brief, método que añade un usuario al sistema
	*@Param, Usuario *user, puntero a un usuario
	*/
	void anadirUsuarioASistema(Usuario *user);
	/*
	*@Brief, método que módifica un usuario al sistema
	*@Param, Usuario *u, puntero a un usuario
	*/
	void modificarUsuarioEnSistema(Usuario *u);
	/*
	*@Brief, método que elimina un usuario al sistema
	*@Param, Usuario *user, puntero a un usuario
	*/
	void eliminarUsuarioEnSistema(Usuario *user);
	//void guardarUsuarioEnBD(const Usuario *user);
	/*
	*@Brief, método que busca dentro del sistema un multimedia mediante un string
	*@Param, const string str, string generico, para titulo o compañía
	*/
	int buscarMultimediaEnSistema(const string str);
	/*
	*@Brief, método que busca dentro del sistema un multimedia mediante un entero
	*@Param, const int anio, entero año
	*/
	int buscarMultimediaEnSistema(const int anio);
	/*
	*@Brief, método que añade un multimedia al sistema
	*@Param, Multimedia *multi, puntero a un Multimedia
	*/
	void anadirMultimediaASistema(Multimedia *multi);
	/*
	*@Brief, método que modifica un multimedia al sistema
	*@Param, Multimedia *m, puntero a un Multimedia
	*/
	void modificarMultimediaEnSistema(Multimedia *m);
	/*
	*@Brief, método que elimina un multimedia al sistema
	*@Param, Multimedia *multi, puntero a un Multimedia
	*/
	void eliminarMultimediaEnSistema(Multimedia *multi);
	/*
	*@Brief, método que muestra la valoración media actual de un multimedia del sistema
	*@Param, Multimedia *m, puntero a un Multimedia
	*/
	void valoracionMediaMultimedia(Multimedia* m);
	//void informeTop3Musica();
	//void informeTop3Videos();
	//void informeTop3Imagen();
	/*
	*@Brief, método que muestra lel top 3 general de los Multimedia del sistema
	*/
	void informeTop3General();
	//void usuarioFreak();
	/*
	*@Brief, método que muestra los usuarios registrados en el sistema
	*/
	void imprimirUsuarios();
	/*
	*@Brief, método que muestra los Multimedia del sistema
	*/
	void imprimirMulimedias();
};

#endif /*CRYSTOFY_H*/