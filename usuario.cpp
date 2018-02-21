#include "multimedia.h"
#include "usuario.h"
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define BLACK_COLOR "\033[30m"
#define GREEN_COLOR "\033[1;32m"
#define LIGHT_CYAN "\033[1;36m"
#define RED_COLOR "\033[1;31m"
#define BLUE_COLOR "\033[34m"
#define LIGHT_BLUE_COLOR "\033[1;34m"
#define RESTORE_DEFAULT_COLOR "\033[0m"

Usuario::Usuario(){
	this->login = " ";
	this->password = " ";
	this->nombre = " ";
	this->apellido1 = " ";
	this->apellido2 = " ";
	this->edad = 0;
	this->utilesCV = 4;
	this->utilesDeResultadosDeBusqueda = 0;
	this->listaContenidosUsuario = new Multimedia*[this->utilesCV];
    if (this->listaContenidosUsuario == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
    for (int i = 0; i < this->utilesCV; ++i)
	{
		this->listaContenidosUsuario[i] = 0;
	}
	this->listaValoraciones = new float[this->utilesCV];
    if (this->listaValoraciones == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
	for (int i = 0; i < this->utilesCV; ++i)
	{
		this->listaValoraciones[i] = 0;
	}
	this->listaDeResultadosDeBusqueda = new Multimedia*[this->utilesDeResultadosDeBusqueda];
    if (this->listaDeResultadosDeBusqueda == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
}

Usuario::Usuario(string login, string password, string nombre, string apellido1, string apellido2, int edad, int utilesCV){
	this->login = login;
	this->password = password;
	this->nombre = nombre;
	this->apellido1 = apellido1;
	this->apellido2 = apellido2;
	this->edad = edad;
	this->utilesCV = utilesCV;
	this->utilesDeResultadosDeBusqueda = 0;
	this->listaContenidosUsuario = new Multimedia*[this->utilesCV];
    if (this->listaContenidosUsuario == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
	this->listaValoraciones = new float[this->utilesCV];
    if (this->listaValoraciones == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
	for (int i = 0; i < this->utilesCV; ++i)
	{
		this->listaValoraciones[i] = 0;
	}
	this->listaDeResultadosDeBusqueda = new Multimedia*[this->utilesDeResultadosDeBusqueda];
    if (this->listaDeResultadosDeBusqueda == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
}

Usuario::~Usuario(){
	this->login = " ";
	this->password = " ";
	this->nombre = " ";
	this->apellido1 = " ";
	this->apellido2 = " ";
	this->edad = 0;
	
	for (int i = 0; i < this->getUtilesCV(); ++i)
	{
		this->desasociarContenidoMultimedia(this->listaContenidosUsuario[i]);
	}

	for (int i = 0; i < this->getUtilesCV(); ++i)
	{
		this->listaContenidosUsuario[i] = 0;
		this->listaValoraciones[i] = 0;
	}
	
	for (int j = 0; j < this->getUtilesDeResultadosDeBusqueda(); ++j)
	{
		this->listaDeResultadosDeBusqueda[j] = 0;
	}

	delete [] this->listaContenidosUsuario;
	this->listaContenidosUsuario = 0;
	delete [] this->listaValoraciones;
	this->listaValoraciones = 0;
	delete [] this->listaDeResultadosDeBusqueda;
	this->listaDeResultadosDeBusqueda = 0;

	this->setUtilesCV(0);

	cout << BLUE_COLOR << "Usuario eliminado con éxito" << RESTORE_DEFAULT_COLOR << endl;
}

void Usuario::setListaContenidosUsuario(Multimedia* m){
	int utilesOriginales = this->getUtilesCV();
	int posicion;
	int salida = 0;

	for (posicion = 0; salida != -1; ++posicion)
	{
		if (posicion < this->getUtilesCV() && this->listaContenidosUsuario[posicion] == 0)
		{
			this->listaContenidosUsuario[posicion] = m;
			salida = -1;
		}
		else if (posicion >= this->getUtilesCV())
		{
			this->setUtilesCV(getUtilesCV()+1);
				
			Multimedia** nueva_listaC = new Multimedia*[this->getUtilesCV()];
		    if (nueva_listaC == 0){
        		cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
	       		exit(-1);	
	    	}

	    	for (int i = 0; i < this->getUtilesCV(); ++i)
	    	{
	    		nueva_listaC[i] = 0;
	    	}
	    	for (int j = 0; j < utilesOriginales; ++j)
	    	{
	    		nueva_listaC[j] = this->listaContenidosUsuario[j];
	    	}

			float* nueva_listaV = new float[this->getUtilesCV()];
		    if (nueva_listaV == 0){
        		cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
	        	exit(-1);
	    	}

	    	for (int h = 0; h < this->getUtilesCV(); ++h)
	    	{
	    		nueva_listaV[h] = 0;
	    	}
	    	for (int p = 0; p < utilesOriginales; ++p)
	    	{
	    		nueva_listaV[p] = this->listaValoraciones[p];
	    	}

			for (int k = 0; k < utilesOriginales; ++k)
			{
				this->listaValoraciones[k] = 0;
			}

			delete [] this->listaValoraciones;
			this->listaValoraciones = nueva_listaV;

	    	nueva_listaC[posicion] = m;

			delete [] this->listaContenidosUsuario;
			this->listaContenidosUsuario = nueva_listaC;

			salida = -1;
		}
	}
}

void Usuario::setListaValoraciones(int posicion, float valoracion){
	if(posicion >= 0 && posicion < this->getUtilesCV()) //En el dominio de ambos vectores
	{
		if (this->listaContenidosUsuario[posicion] != 0) //Comprobamos si existe el contenido al que se le va a asociar esa valoración
		{
			this->listaValoraciones[posicion] = valoracion; //Sí existe se iguala la nueva valoración en su lugar correspondiente del vector, equivalente a la posición en el otro vector
		}
		else
			cerr << RED_COLOR << "No se ha encontrado ningún multimedia en la posición introducida" << RESTORE_DEFAULT_COLOR << endl; //Sí no encuentra saltará un mensaje de error
	}
	else
		cerr << RED_COLOR << "No se ha encontrado ningún multimedia en la posición introducida" << RESTORE_DEFAULT_COLOR << endl; //Sí sale del vector saltará el mismo mensaje de error
}

bool Usuario::asociarContenidoMultimedia(Multimedia *m){
	int cuenta = 0;
	for (int i = 0; i < this->getUtilesCV(); ++i)
	{
		if (m != this->listaContenidosUsuario[i])
		{
			cuenta++;
		}
	}
	if (cuenta == this->getUtilesCV())
	{
		this->setListaContenidosUsuario(m);
	}
	else
		cerr << RED_COLOR << "Ese multimedia ya esta asociado en tu lista de contenidos" << RESTORE_DEFAULT_COLOR << endl;

	return true;
}

bool Usuario::desasociarContenidoMultimedia(Multimedia *m){
	int i;
	int salida = 0;

	for (i = 0; i < this->getUtilesCV() && salida != -1; ++i)
	{
		if (this->listaContenidosUsuario[i] == m)
		{
			salida = -1;
		}
	}

	float valoracion = this->listaValoraciones[i];

	m->setPuntuacionTotal(this->listaContenidosUsuario[i]->getPuntuacionTotal()-valoracion);
	m->setTotalUsuariosQueHanValorado(this->listaContenidosUsuario[i]->getTotalUsuariosQueHanValorado()-1);
	m->setValoracionMediaActual((this->listaContenidosUsuario[i]->getPuntuacionTotal()/this->listaContenidosUsuario[i]->getTotalUsuariosQueHanValorado()));

	this->listaContenidosUsuario[i] = 0;
	this->listaValoraciones[i] = 0;
	this->listaContenidosUsuario[i] = this->listaContenidosUsuario[this->getUtilesCV()-1];
	this->listaValoraciones[i] = this->listaValoraciones[this->getUtilesCV()-1];
	this->setUtilesCV(getUtilesCV()-1);

	return false;
}

void Usuario::votarContenidoMultimedia(int posicion, float valoracion){
	this->setListaValoraciones(posicion, valoracion);
	this->getListaContenidosUsuario(posicion)->setPuntuacionTotal(this->listaContenidosUsuario[posicion]->getPuntuacionTotal()+valoracion);
	this->listaContenidosUsuario[posicion]->setTotalUsuariosQueHanValorado(this->listaContenidosUsuario[posicion]->getTotalUsuariosQueHanValorado()+1);
	this->listaContenidosUsuario[posicion]->setValoracionMediaActual((this->listaContenidosUsuario[posicion]->getPuntuacionTotal()/this->listaContenidosUsuario[posicion]->getTotalUsuariosQueHanValorado()));
}

void Usuario::modificarDatosUsuario(string login, string password, string nombre, string apellido1, string apellido2, int edad){
	this->login = login;
	this->password = password;
	this->nombre = nombre;
	this->apellido1 = apellido1;
	this->apellido2 = apellido2;
	this->edad = edad;

	cout << "Usuario modificado con éxito" << endl;
}

void Usuario::print(){
	cout << LIGHT_BLUE_COLOR << "Login: " << this->login << RESTORE_DEFAULT_COLOR << endl;
	cout << LIGHT_BLUE_COLOR << "Nombre: " << this->nombre << RESTORE_DEFAULT_COLOR << endl;
	cout << LIGHT_BLUE_COLOR << "Apellidos: " << this->apellido1 << ", " << this->apellido2 << RESTORE_DEFAULT_COLOR << endl;
	cout << LIGHT_BLUE_COLOR << "Edad: " << this->edad << RESTORE_DEFAULT_COLOR << endl;
}

bool Usuario::buscarContenidoAsociado(string str){
	bool encontrado = false;
	int j = 0;
	
	for (int k = 0; k < this->getUtilesDeResultadosDeBusqueda(); ++k)
	{
		this->listaDeResultadosDeBusqueda[k] = 0;
	}

	this->setUtilesDeResultadosDeBusqueda(0);

	for (int i = 0; i < this->getUtilesDeResultadosDeBusqueda()+1; ++i)
	{
		for (j; j < this->getUtilesCV() && encontrado != true; ++j)
		{
			if (this->listaContenidosUsuario[j]->getTitulo().find(str)!=string::npos || this->listaContenidosUsuario[j]->getCompania().find(str)!=string::npos)
			{
				this->listaDeResultadosDeBusqueda[i] = this->listaContenidosUsuario[j];
				this->setUtilesDeResultadosDeBusqueda(getUtilesDeResultadosDeBusqueda()+1);

				encontrado = true;
			}
		}
		encontrado = false;
	}

	return true;
}

bool Usuario::buscarContenidoAsociado(int n){
	bool encontrado = false;
	int j = 0;
	
	for (int k = 0; k < this->getUtilesDeResultadosDeBusqueda(); ++k)
	{
		this->listaDeResultadosDeBusqueda[k] = 0;
	}

	this->setUtilesDeResultadosDeBusqueda(0);

	for (int i = 0; i < this->getUtilesDeResultadosDeBusqueda()+1; ++i)
	{
		for (j; j < this->getUtilesCV() && encontrado != true; ++j)
		{
			if (n == this->listaContenidosUsuario[j]->getAnio())
			{
				this->listaDeResultadosDeBusqueda[i] = this->listaContenidosUsuario[j];
				this->setUtilesDeResultadosDeBusqueda(getUtilesDeResultadosDeBusqueda()+1);

				encontrado = true;
			}
		}
		encontrado = false;
	}

	return true;
}

void Usuario::imprimirListaContenidosAsociadosYValoraciones(){
	cout << GREEN_COLOR << "Contenidos asociados al Usuario: " << endl;
	for (int i = 0; i < this->getUtilesCV(); ++i)
	{
		cout << i << endl;
		cout << this->listaContenidosUsuario[i] << endl;
		cout << GREEN_COLOR << "	Titulo: " << RESTORE_DEFAULT_COLOR << this->listaContenidosUsuario[i]->getTitulo() << GREEN_COLOR << " Compañia: " << RESTORE_DEFAULT_COLOR << this->listaContenidosUsuario[i]->getCompania() << GREEN_COLOR << " Año: " << RESTORE_DEFAULT_COLOR << this->listaContenidosUsuario[i]->getAnio() << GREEN_COLOR << " Formato: " << RESTORE_DEFAULT_COLOR << this->listaContenidosUsuario[i]->getFormato() << BLACK_COLOR << " - " << RESTORE_DEFAULT_COLOR;
		if (this->listaValoraciones[i] != 0)
		{
			cout << LIGHT_CYAN << "Valoración: " << RESTORE_DEFAULT_COLOR << this->listaValoraciones[i];
		}
		cout << endl;
	}
}

void Usuario::imprimirListaResultadosBusqueda(){
	cout << GREEN_COLOR "Los resultados de busqueda son: " << endl;
	for (int i = 0; i < this->getUtilesDeResultadosDeBusqueda(); ++i)
	{
		cout << GREEN_COLOR << "	Titulo: " << RESTORE_DEFAULT_COLOR << this->listaDeResultadosDeBusqueda[i]->getTitulo() << GREEN_COLOR << " Compañia: " << RESTORE_DEFAULT_COLOR << this->listaDeResultadosDeBusqueda[i]->getCompania() << GREEN_COLOR << " Año: " << RESTORE_DEFAULT_COLOR << this->listaDeResultadosDeBusqueda[i]->getAnio() << endl;
	}
}