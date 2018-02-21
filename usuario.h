#ifndef USUARIO_H
#define USUARIO_H

#include "multimedia.h"
#include <string>
#include <iostream>
using namespace std;

class Usuario
{
private:
	string login;
	string password;
	string nombre;
	string apellido1;
	string apellido2;
	int edad;
	Multimedia** listaContenidosUsuario;
	float* listaValoraciones;
	int utilesCV;
	Multimedia** listaDeResultadosDeBusqueda;
	int utilesDeResultadosDeBusqueda;
public:
	/****CONSTRUCTORES Y DESTURCTORES*****/
	Usuario();
	Usuario(string login, string password, string nombre, string apellido1, string apellido2, int edad, int utilesCV);
	~Usuario();
	/*****SETS Y GETS*****/
	inline void setLogin(string nuevo_login) {this->login = nuevo_login;}
	inline void setPassword(string nueva_password) {this->password = nueva_password;}
	inline void setNombre(string nuevo_nombre) {this->nombre = nuevo_nombre;}
	inline void setApellido1(string nuevo_apellido1) {this->apellido1 = nuevo_apellido1;}
	inline void setApellido2(string nuevo_apellido2) {this->apellido2 = nuevo_apellido2;}
	inline void setEdad(int nueva_edad) {this->edad = nueva_edad;};
	void setListaContenidosUsuario(Multimedia* m);
	inline Multimedia* getListaContenidosUsuario(int posicion){return this->listaContenidosUsuario[posicion];}
	void setListaValoraciones(int posicion, float valoracion);
	inline void setUtilesCV(int nuevas_utilesCV) {this->utilesCV = nuevas_utilesCV;}
	inline void setUtilesDeResultadosDeBusqueda(int nuevas_utilesListaDeResultados) {this->utilesDeResultadosDeBusqueda = nuevas_utilesListaDeResultados;}
	inline string getLogin() {return this->login;}
	inline string getPassword() {return this->password;}
	inline string getNombre() {return this->nombre;}
	inline string getApellido1() {return this->apellido1;}
	inline string getApellido2() {return this->apellido2;}
	inline int getEdad() {return this->edad;}
	inline int getUtilesCV() {return this->utilesCV;}
	inline int getUtilesDeResultadosDeBusqueda() {return this->utilesDeResultadosDeBusqueda;}
	/*
	*@Brief, método que asocia un contenido al la lista del usuario
	*@Param, Multimedia*m, puntero a multimedia
	*/
	bool asociarContenidoMultimedia(Multimedia *m);
	/*
	*@Brief, método que desasocia un contenido al la lista del usuario
	*@Param, Multimedia*m, puntero a multimedia
	*/
	bool desasociarContenidoMultimedia(Multimedia *m);
	/*
	*@Brief, método que valora un contenido multimedia, insertando un float en su posición correspondiente en el vector de valoraciones
	*@Param, int posicion, posicion del multimedia, float valoracion, valoracion a realizar
	*/
	void votarContenidoMultimedia(int posicion, float valoracion);
	/*
	*@Brief, método que modifica los datos del usuario
	*@Param, string login, string password, string nombre, string apellido1, string apellido2 , int edad
	*/
	void modificarDatosUsuario(string login, string password, string nombre, string apellido1, string apellido2, int edad);
	/*
	*@Brief, método que imprime al usuario
	*/
	void print();
	/*
	*@Brief, método que busca un contenido en la lista de asociados mediante un string generico o una sub-cadena
	*@Param, string str, cadena o sub cadena cualquiera
	*/
	bool buscarContenidoAsociado(string str);
	/*
	*@Brief, método que busca un contenido en la lista de asociados mediante un número n
	*@Param, int n, número n cualquiera
	*/
	bool buscarContenidoAsociado(int n);
	/*
	*@Brief, método que imprime la lista de asociados y valoraciones del usuario
	*/
	void imprimirListaContenidosAsociadosYValoraciones();
	/*
	*@Brief, método que imprime la lista de resultados del usuario
	*/
	void imprimirListaResultadosBusqueda();
	//int buscarPosicionEnlistaAsociados(/*alfanumerico incremental unico id*/);
	//int buscarPosicionEnListaDeResultados(/*alfanumerico incremental unico id*/);
};

#endif /*USUARIO_H*/