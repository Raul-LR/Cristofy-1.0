#include "video.h"
#include "musica.h"
#include "imagen.h"
#include "multimedia.h"
#include "usuario.h"
#include "cristofy.h"
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define OCULTO "\033[8;31m"
#define GREEN_COLOR "\033[1;32m"
#define CYAN "\033[36m"
#define RED_COLOR "\033[1;31m"
#define RESTORE_DEFAULT_COLOR "\033[0m"

Cristofy::Cristofy(){
	this->usuariosTotales = 0;
	this->dimUsuarios = 5;
	this->contenidosTotales = 0;
	this->dimMultimedia = 5;

	this->listaUsuarios = new Usuario*[dimUsuarios];
    if (this->listaUsuarios == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
    this->listaContenidoMultimedia = new Multimedia*[dimMultimedia];
    if (this->listaContenidoMultimedia == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
}

Cristofy::Cristofy(int dimUsuarios, int dimMultimedia){
	this->usuariosTotales = 0;
	this->dimUsuarios = dimUsuarios;
	this->contenidosTotales = 0;
	this->dimMultimedia = dimMultimedia;

	this->listaUsuarios = new Usuario*[dimUsuarios];
    if (this->listaUsuarios == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
    this->listaContenidoMultimedia = new Multimedia*[dimMultimedia];
    if (this->listaContenidoMultimedia == 0){
        cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
        exit(-1);
    }
}

Cristofy::~Cristofy(){
	for (int i = 0; i < this->getUsuariosTotales(); ++i)
	{
		delete this->listaUsuarios[i];
		this->listaUsuarios[i] = 0;
	}
	for (int j = 0; j < this->getContenidosTotales(); ++j)
	{
		delete this->listaContenidoMultimedia[j];
		this->listaContenidoMultimedia[j] = 0;
	}

	delete [] this->listaUsuarios;
	delete [] this->listaContenidoMultimedia;
	this->listaUsuarios = 0;
	this->listaContenidoMultimedia = 0;

	this->setUsuariosTotales(0);
	this->setContenidosTotales(0);
	this->setDimUsuarios(0);
	this->setDimMultimedia(0);

	cout << CYAN << "Cristofy eliminado con éxito" << RESTORE_DEFAULT_COLOR << endl;
}

void Cristofy::setListaUsuarios(Usuario *u){
	int posicion;
	int salida = 0;

	for (posicion = 0; salida != -1; ++posicion)
	{
		if (posicion < this->getDimUsuarios() && this->listaUsuarios[posicion] == 0)
		{
			this->listaUsuarios[posicion] = u;
			this->setUsuariosTotales(getUsuariosTotales()+1);
			salida = -1;
		}
		else if (posicion >=getDimUsuarios())
		{
			this->setDimUsuarios(getDimUsuarios()*2);
			Usuario** nueva_listaU = new Usuario*[this->getDimUsuarios()];
		    if (nueva_listaU == 0){
        		cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
      			exit(-1);
   			}
   			for (int i = 0; i < this->getUsuariosTotales(); ++i)
   			{
   				nueva_listaU[i] = 0;
   			}
   			for (int j = 0; j < this->getUsuariosTotales(); ++j)
   			{
   				nueva_listaU[j] = this->listaUsuarios[j];
   			}
   			
   			nueva_listaU[posicion] = u;

   			delete [] this->listaUsuarios;
   			this->listaUsuarios = nueva_listaU;
			this->setUsuariosTotales(getUsuariosTotales()+1);
   			salida = -1;
		}
	}
}

void Cristofy::setListaContenidoMultimedia(Multimedia *m){
	int posicion;
	int salida = 0;

	for (posicion = 0; salida != -1; ++posicion)
	{
		if (posicion < this->getDimMultimedia() && this->listaContenidoMultimedia[posicion] == 0)
		{
			this->listaContenidoMultimedia[posicion] = m;
			this->setContenidosTotales(getContenidosTotales()+1);
			salida = -1;
		}
		else if (posicion >=getDimMultimedia())
		{
			this->setDimMultimedia(getDimMultimedia()*2);
			Multimedia** nueva_listaM = new Multimedia*[this->getDimMultimedia()];
		    if (nueva_listaM == 0){
        		cerr << RED_COLOR << "Error. El sistema operativo no tiene memoria suficiente. Se abortará la ejecución..." << RESTORE_DEFAULT_COLOR << endl;
      			exit(-1);
   			}
   			for (int i = 0; i < this->getContenidosTotales(); ++i)
   			{
   				nueva_listaM[i] = 0;
   			}
   			for (int j = 0; j < this->getContenidosTotales(); ++j)
   			{
   				nueva_listaM[j] = this->listaContenidoMultimedia[j];
   			}
   			
   			nueva_listaM[posicion] = m;

   			delete [] this->listaContenidoMultimedia;
   			this->listaContenidoMultimedia = nueva_listaM;
			this->setContenidosTotales(getContenidosTotales()+1);
   			salida = -1;
		}
	}
}

void Cristofy::bienvenida(){
cout << GREEN_COLOR << " ________  ________  ___  ________   __________  ________  ________  ___    ___ " << endl;
cout << "|\\   ____\\|\\   __  \\|\\  \\|\\  ______\\|\\___   ___\\|\\   __  \\|\\  _____\\|\\  \\  /  /|" << endl;
cout << "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\ \\ \\_____|\\|___|\\ \\__|\\ \\  \\|\\  \\ \\ \\____|\\ \\  \\/  / |" << endl;
cout << " \\ \\  \\    \\ \\   _  _\\ \\  \\ \\_____  \\    \\ \\ \\   \\ \\  \\\\\\  \\ \\  __\\  \\ \\    / /   " << endl;
cout << "  \\ \\  \\____\\ \\  \\\\  \\| \\  \\| ____|\\ \\    \\ \\ \\   \\ \\  \\\\\\  \\ \\ \\_|   \\/  /  /   " << endl;
cout << "   \\ \\_______\\ \\__\\\\ _\\  \\__\\|\\_______\\    \\ \\_\\   \\ \\_______\\ \\_\\  __/  / /           " << endl;
cout << "    \\|_______|\\|__|\\|__|\\|__|\\|_______|     \\|_|    \\|_______|\\|_| |\\___/ /                     " << endl;
cout << "-------------------------------------------------------------------\\|___|/------- " << RESTORE_DEFAULT_COLOR << endl;
}

bool Cristofy::autenticacion(int posicion, string password){
	if (this->listaUsuarios[posicion]->getPassword() == password)
	{
		return true;
	}
	else
		return false;
}

void Cristofy::registrarUsuario(){
	Usuario *user = new Usuario;
	string login;
	string password;
	string nombre;
	string apellido1;
	string apellido2;
	int edad;

	cout << "Por favor, introduzca su email/login: ";
	cin >> login;
	cout << "Por favor, introduzca su contraseña: " << OCULTO;
	cin >> password;
	cout << RESTORE_DEFAULT_COLOR << "Por favor, introduzca su nombre: ";
	cin >> nombre;
	cout << "Por favor, introduzca sus apellidos: ";
	cin >> apellido1;
	cin >> apellido2;
	cout << "Por favor, introduzca su edad: ";
	cin >> edad;

	user->modificarDatosUsuario(login, password, nombre, apellido1, apellido2, edad);
	this->anadirUsuarioASistema(user);

	cout << GREEN_COLOR << "Usuario registrado con éxito" << RESTORE_DEFAULT_COLOR << endl;
}

void Cristofy::registrarMultimedia(){
	Multimedia *multi = new Multimedia;
	Video *v = new Video;
	Musica *m = new Musica;
	Imagen *i = new Imagen;

	string titulo;
	string compania;
	int anio;
	float puntuacionTotal;
	int totalUsuariosQueHanValorado;
	float valoracionMediaActual;
	string rutaFichero;
	string formato;
	string rutaPrograma;
	string resolucion;
	string autor;
	string tematica;
	string estilo;
	int duracion;
	char tecla;

	cout << "Indica que quieres crear:" << endl;
	cout << "	1. Multimedia general" << endl;
	cout << "	2. Video" << endl;
	cout << "	3. Musica" << endl;
	cout << "	4. Inagen" << endl;

	cin >> tecla;

	switch (tecla){
		case '1':

			cout << "Introduza el titulo: ";
			cin.ignore(1024, '\n');
			getline(cin, titulo);
			cout << "Introduzca la compañía: ";
			cin.ignore(1024, '\n');
			getline(cin, compania);
			cout << "Introduzca el año: ";
			cin >> anio;
			cout << "Introduzca la ruta del fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, rutaFichero);
			cout << "Introduzca el formato del fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, formato);
			cout << "Introduzca la ruta del programa que ejecutará el fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, rutaPrograma);

			multi->modificarMultimedia(titulo, compania, anio, 0, 0, 0, rutaFichero, formato, rutaPrograma);
			this->anadirMultimediaASistema(multi);
			delete v;
			delete m;
			delete i;
			break;

		case '2':

			cout << "Introduza el titulo: ";
			cin.ignore(1024, '\n');
			getline(cin, titulo);
			cout << "Introduzca la compañía: ";
			cin.ignore(1024, '\n');
			getline(cin, compania);
			cout << "Introduzca el año: ";
			cin >> anio;
			cout << "Introduzca la ruta del fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, rutaFichero);
			cout << "Introduzca el formato del fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, formato);
			cout << "Introduzca la ruta del programa que ejecutará el fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, rutaPrograma);
			cout << "Introduzca la duracion del vídeo (min): ";
			cin >> duracion;
			cout << "Introduzca la temática del vídeo: ";
			cin.ignore(1024, '\n');
			getline(cin, tematica);
			cout << "Introduzca el autor del vídeo: ";
			cin.ignore(1024, '\n');
			getline(cin, autor);

			v->modificarMultimedia(titulo, compania, anio, 0, 0, 0, rutaFichero, formato, rutaPrograma, duracion, tematica, autor);
			this->anadirMultimediaASistema(v);
			delete multi;
			delete m;
			delete i;
			break;

		case '3':

			cout << "Introduza el titulo: ";
			cin.ignore(1024, '\n');
			getline(cin, titulo);
			cout << "Introduzca la compañía: ";
			cin.ignore(1024, '\n');
			getline(cin, compania);
			cout << "Introduzca el año: ";
			cin >> anio;
			cout << "Introduzca la ruta del fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, rutaFichero);
			cout << "Introduzca el formato del fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, formato);
			cout << "Introduzca la ruta del programa que ejecutará el fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, rutaPrograma);
			cout << "Introduzca la duracion de la cancion (min): ";
			cin >> duracion;
			cout << "Introduzca el estilo de la cancion: ";
			cin.ignore(1024, '\n');
			getline(cin, estilo);
			cout << "Introduzca el autor de la cancion: ";
			cin.ignore(1024, '\n');
			getline(cin, autor);

			m->modificarMultimedia(titulo, compania, anio, 0, 0, 0, rutaFichero, formato, rutaPrograma, duracion, autor, estilo);
			this->anadirMultimediaASistema(m);
			delete multi;
			delete v;
			delete i;
			break;

		case '4':

			cout << "Introduza el titulo: ";
			cin.ignore(1024, '\n');
			getline(cin, titulo);
			cout << "Introduzca la compañía: ";
			cin.ignore(1024, '\n');
			getline(cin, compania);
			cout << "Introduzca el año: ";
			cin >> anio;
			cout << "Introduzca la ruta del fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, rutaFichero);
			cout << "Introduzca el formato del fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, formato);
			cout << "Introduzca la ruta del programa que ejecutará el fichero: ";
			cin.ignore(1024, '\n');
			getline(cin, rutaPrograma);
			cout << "Introduzca la resolución de la imagen: ";
			cin.ignore(1024, '\n');
			getline(cin, resolucion);

			i->modificarMultimedia(titulo, compania, anio, 0, 0, 0, rutaFichero, formato, rutaPrograma, resolucion);
			this->anadirMultimediaASistema(i);
			delete multi;
			delete v;
			delete m;
			break;

		default:
			cerr << RED_COLOR << "Algo ha ido mal, intentalo de nuevo" << RESTORE_DEFAULT_COLOR << endl;					
	}

	cout << GREEN_COLOR << "Multimedia registrado con éxito" << RESTORE_DEFAULT_COLOR << endl;
}

void Cristofy::mostrarMenu(bool admin){
	cout << "Pulse '1', para importar datos desde un fichero *.crfy" << endl;
	cout << "Pulse '2', para exportar datos a un fichero *.crfy" << endl;
	cout << "Pulse '3', para acceder a las opciones de rankings" << endl;
	cout << "	Pulse '1', para acceder al Ranking Top3 General" << endl;
	cout << "	Pulse '2', para acceder al Ranking Top3 por Tipo de Contenido Multimendia (Imágenes, Video ó Música)" << endl;
	cout << "	Pulse '3', para acceder al Ranking Usuarios" << endl;
	cout << "Pulse '4', para acceder a las opciones de contenido multimedia" << endl;
	cout << "	Pulse '1', para agregar Nuevo Contenido Mulimedia al Sistema" << endl;
	cout << "	Pulse '2', para eliminar Contenido Multimedia del Sistema" << endl;
	cout << "	Pulse '3', para buscar Contenido Multimedia en el Sistema" << endl;
	cout << "	Pulse '4', para modificar Datos Contenido Multimedia del Sistema" << endl;
	cout << "	Pulse '5', para consultar Valoración Media Contenido Multimedia" << endl;
	cout << "Pulse '5', para acceder a las opciones de los Usuarios" << endl;
	cout << "	Pulse '1', para agregar Nuevo Usuario al Sistema" << endl;
	cout << "	Pulse '2', para eliminar Usuario del Sistema" << endl;
	cout << "	Pulse '3', para buscar Usuario en el Sistema" << endl;
	cout << "	Pulse '4', para modificar Datos Usuario del Sistema" << endl;
	cout << "Pulse 's', para salir" << endl;
}

void Cristofy::mostrarMenu(){
	cout << "Pulse '1', para modificar datos personales" << endl;
	cout << "Pulse '2', para consultar Lista de Contenidos y Valoraciones del Usuario" << endl;
	cout << "Pulse '3', para dar like (asociar Contenido Multimedia a Usuario)" << endl;
	cout << "Pulse '4', dislike (desasociar Contenido Multimedia de Usuario)" << endl;
	cout << "Pulse '5', para votar Contenido Multimedia " << endl;
	cout << "Pulse '6', para reproducir Contenido Multimedia" << endl;
	cout << "Pulse 's', para salir" << endl;
}

int Cristofy::buscarUsuarioEnSistema(const string login){
	for (int i = 0; i < this->getUsuariosTotales(); ++i)
	{
		if (login == this->listaUsuarios[i]->getLogin())
		{
			return i;
		}
	}

	return -1;
}

void Cristofy::anadirUsuarioASistema(Usuario *user){
	int cuenta = 0;
	for (int i = 0; i < this->getUsuariosTotales(); ++i)
	{
		if (user != this->listaUsuarios[i])
		{
			cuenta++;
		}
	}
	if (cuenta == this->getUsuariosTotales())
	{
		this->setListaUsuarios(user);
	}
	else
		cerr << RED_COLOR << "El Usuario " << user->getLogin() << " ya está registrado en Cristofy" << RESTORE_DEFAULT_COLOR << endl;
}

void Cristofy::modificarUsuarioEnSistema(Usuario *u){
	string login;
	string password;
	string nombre;
	string apellido1;
	string apellido2;
	int edad;

	cout << "Por favor, introduzca el email: ";
	cin >> login;
	cout << "Por favor, introduzca la contraseña: " << OCULTO;
	cin >> password;
	cout << RESTORE_DEFAULT_COLOR << "Por favor, introduzca el nombre: ";
	cin >> nombre;
	cout << "Por favor, introduzca los apellidos: ";
	cin >> apellido1;
	cin >> apellido2;
	cout << "Por favor, introduzca la edad: ";
	cin >> edad;

	u->modificarDatosUsuario(login, password, nombre, apellido1, apellido2, edad);
}

void Cristofy::eliminarUsuarioEnSistema(Usuario *user){
	int i;
	int salida = 0;

	for (i = 0; i < this->getUsuariosTotales() && salida != -1; ++i)
	{
		if (this->listaUsuarios[i] == user)
		{
			salida = -1;
		}
	}

	delete user;
	this->listaUsuarios[i] = 0;
	this->listaUsuarios[i] = this->listaUsuarios[this->getUsuariosTotales()-1];
	this->setUsuariosTotales(getUsuariosTotales()-1);
}

int Cristofy::buscarMultimediaEnSistema(const string str){
	cout << "Hola!!" << endl;
	for (int i = 0; i < this->getContenidosTotales(); ++i)
	{
		if (str == this->listaContenidoMultimedia[i]->getTitulo() || str == this->listaContenidoMultimedia[i]->getCompania())
		{
			cout << "hola??" << endl;
			return i;
		}
	}
	return -1;
}

int Cristofy::buscarMultimediaEnSistema(const int anio){
	for (int i = 0; i < this->getContenidosTotales(); ++i)
	{
		if (anio == this->listaContenidoMultimedia[i]->getAnio())
		{
			return i;
		}
	}
	return -1;
}


void Cristofy::anadirMultimediaASistema(Multimedia *multi){
	int cuenta = 0;
	for (int i = 0; i < this->getContenidosTotales(); ++i)
	{
		if (multi != this->listaContenidoMultimedia[i])
		{
			cuenta++;
		}
	}
	if (cuenta == this->getContenidosTotales())
	{
		this->setListaContenidoMultimedia(multi);
	}
	else
		cerr << RED_COLOR << "Ese multimedia ya esta asociado en la lista de contenidos de Cristofy" << RESTORE_DEFAULT_COLOR << endl;
}

void Cristofy::modificarMultimediaEnSistema(Multimedia *m){
	string titulo;
	string compania;
	int anio;
	float puntuacionTotal;
	int totalUsuariosQueHanValorado;
	float valoracionMediaActual;
	string rutaFichero;
	string formato;
	string rutaPrograma;
	string resolucion;
	string autor;
	string tematica;
	string estilo;
	int duracion;
	char tecla;

	if (Video *m = dynamic_cast<Video *>(m))
	{
		cout << "Introduza el titulo: ";
		cin >> titulo;
		cout << "Introduzca la compañía: ";
		cin >> compania;
		cout << "Introduzca el año: ";
		cin >> anio;
		cout << "Introduzca la ruta del fichero: ";
		cin >> rutaFichero;
		cout << "Introduzca el formato del fichero: ";
		cin >> formato;
		cout << "Introduzca la ruta del programa que ejecutará el fichero: ";
		cin >> rutaPrograma;
		cout << "Introduzca la duracion del vídeo (min): ";
		cin >> duracion;
		cout << "Introduzca la temática del vídeo: ";
		cin >> tematica;
		cout << "Introduzca el autor del vídeo: ";
		cin >> autor;

		m->modificarMultimedia(titulo, compania, anio, 0, 0, 0, rutaFichero, formato, rutaPrograma, duracion, tematica, autor);
	}
	if (Musica *m = dynamic_cast<Musica *>(m))
	{
		cout << "Introduza el titulo: ";
		cin >> titulo;
		cout << "Introduzca la compañía: ";
		cin >> compania;
		cout << "Introduzca el año: ";
		cin >> anio;
		cout << "Introduzca la ruta del fichero: ";
		cin >> rutaFichero;
		cout << "Introduzca el formato del fichero: ";
		cin >> formato;
		cout << "Introduzca la ruta del programa que ejecutará el fichero: ";
		cin >> rutaPrograma;
		cout << "Introduzca la duracion de la cancion (min): ";
		cin >> duracion;
		cout << "Introduzca el estilo de la cancion: ";
		cin >> estilo;
		cout << "Introduzca el autor de la cancion: ";
		cin >> autor;

		m->modificarMultimedia(titulo, compania, anio, 0, 0, 0, rutaFichero, formato, rutaPrograma, duracion, autor, estilo);
	}
	if (Imagen *m = dynamic_cast<Imagen *>(m))
	{
		cout << "Introduza el titulo: ";
		cin >> titulo;
		cout << "Introduzca la compañía: ";
		cin >> compania;
		cout << "Introduzca el año: ";
		cin >> anio;
		cout << "Introduzca la ruta del fichero: ";
		cin >> rutaFichero;
		cout << "Introduzca el formato del fichero: ";
		cin >> formato;
		cout << "Introduzca la ruta del programa que ejecutará el fichero: ";
		cin >> rutaPrograma;
		cout << "Introduzca la resolución de la imagen: ";
		cin >> resolucion;

		m->modificarMultimedia(titulo, compania, anio, 0, 0, 0, rutaFichero, formato, rutaPrograma, resolucion);
	}
	if (Multimedia *m = dynamic_cast<Multimedia *>(m))
	{
		cout << "Introduza el titulo: ";
		cin >> titulo;
		cout << "Introduzca la compañía: ";
		cin >> compania;
		cout << "Introduzca el año: ";
		cin >> anio;
		cout << "Introduzca la ruta del fichero: ";
		cin >> rutaFichero;
		cout << "Introduzca el formato del fichero: ";
		cin >> formato;
		cout << "Introduzca la ruta del programa que ejecutará el fichero: ";
		cin >> rutaPrograma;

		m->modificarMultimedia(titulo, compania, anio, 0, 0, 0, rutaFichero, formato, rutaPrograma);
	}
}

void Cristofy::eliminarMultimediaEnSistema(Multimedia *multi){
	int i;
	int j = 0;
	int salida = 0;

	for (i = 0; i < this->getContenidosTotales() && salida != -1; ++i)
	{
		if (this->listaContenidoMultimedia[i] == multi)
		{
			salida = -1;
		}
	}

	for (j; j < this->getUsuariosTotales(); ++j)
	{
		for (int k = 0; k < this->getUsuario(j)->getUtilesCV(); ++k)
		{
			if (this->getUsuario(j)->getListaContenidosUsuario(k) == this->listaContenidoMultimedia[i])
			{
				this->getUsuario(j)->desasociarContenidoMultimedia(this->getUsuario(j)->getListaContenidosUsuario(k));
			}
		}
	}

	delete this->listaContenidoMultimedia[i];
	this->listaContenidoMultimedia[i] = 0;
	this->listaContenidoMultimedia[i] = this->listaContenidoMultimedia[this->getContenidosTotales()-1];
	this->setContenidosTotales(getContenidosTotales()-1);
}

void Cristofy::valoracionMediaMultimedia(Multimedia* m){
	cout << GREEN_COLOR << "La valoración media de " << RESTORE_DEFAULT_COLOR << m->getTitulo() << GREEN_COLOR << " con un total de " << RESTORE_DEFAULT_COLOR << m->getTotalUsuariosQueHanValorado() << GREEN_COLOR << " usuarios que han valorado es: " << RESTORE_DEFAULT_COLOR << m->getValoracionMediaActual() << endl;
}

void Cristofy::informeTop3General(){
	Multimedia *aux = 0;
	bool cambio = true;

	for (int izda = 0; izda < this->getContenidosTotales() && cambio; ++izda)
	{
		cambio = false;

		for (int i = this->getContenidosTotales()-1; i > izda; --i)
		{
			if (this->listaContenidoMultimedia[i]->getValoracionMediaActual() > this->listaContenidoMultimedia[i-1]->getValoracionMediaActual())
			{
				cambio = true;

				aux = this->listaContenidoMultimedia[i];
				this->listaContenidoMultimedia[i] = this->listaContenidoMultimedia[i-1];
				this->listaContenidoMultimedia[i-1] = aux;
			}
		}
	}

	for (int j = 0; j < 3; ++j)
	{
		cout << GREEN_COLOR << "Top " << j+1 << " : " << endl;
		if (Multimedia *m = dynamic_cast<Multimedia *>(this->listaContenidoMultimedia[j]))
		{
			this->listaContenidoMultimedia[j]->print();
		}
		else if (Video *v = dynamic_cast<Video *>(this->listaContenidoMultimedia[j]))
		{
			this->listaContenidoMultimedia[j]->print();
		}
		else if (Musica *mu = dynamic_cast<Musica *>(this->listaContenidoMultimedia[j]))
		{
			this->listaContenidoMultimedia[j]->print();
		}
		else if (Imagen *i = dynamic_cast<Imagen *>(this->listaContenidoMultimedia[j]))
		{
			this->listaContenidoMultimedia[j]->print();
		}
		cout << "------------------------------------------" << RESTORE_DEFAULT_COLOR << endl;
	}
}

void Cristofy::imprimirUsuarios(){
	for (int i = 0; i < this->getUsuariosTotales(); ++i)
	{
		this->getUsuario(i)->print();
		cout << "--------------------------------------------------------" << endl;
	}
}

void Cristofy::imprimirMulimedias(){
	for (int i = 0; i < this->getContenidosTotales(); ++i)
	{
		this->getMultimedia(i)->print();
		cout << "--------------------------------------------------------" << endl;
	}
}