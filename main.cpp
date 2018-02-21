#include <iostream>
#include <stdlib.h>
#include <string>
#include "multimedia.h"
#include "video.h"
#include "musica.h"
#include "imagen.h"
#include "usuario.h"
#include "cristofy.h"
using namespace std;

#define OCULTO "\033[8;31m"
#define GREEN_COLOR "\033[1;32m"
#define CYAN "\033[36m"
#define RED_COLOR "\033[1;31m"
#define RESTORE_DEFAULT_COLOR "\033[0m"

int main(){
	Cristofy c;
	bool logueado = false;
	bool admin = false;
	int salida = 0;
	int salida1 = 0;
	bool valorado = false;
	string login;
	string password;
	string titulo;
	string str;
	float valoracion = 0;
	int anio = 0;
	int posicion = 0;
	int posicionM = 0;
	char tecla;
	
	//conexionDatos(c);
	/***** INICIALIZACIÓN DE MULTIMEDIAS *****/
	Musica *musica1 = new Musica;
	Video *video2 = new Video;
	Imagen *imagen3 = new Imagen;
	Video *video4 = new Video;
	Musica *musica5 = new Musica;

	musica1->modificarMultimedia("El sueño de Nono", "Nono Music S.L.", 2013, 0, 0, 0, "/crfy/media/music/nonodream.mp3", "mp3", "/bin/vlc", 3, "Nona La Loca", "Regueton");
	video2->modificarMultimedia("The Nono MoonWalker", "Nono Video S.L.", 2016, 0, 0, 0, "/crfy/media/video/nonowalker.mp4", "mp4", "/bin/vlc", 6, "Videoclip", "Nono Iglesias");
	imagen3->modificarMultimedia("Tarek in the Country", "Tarek de Castilla Company S.L.", 2015, 0, 0, 0, "/crfy/media/img/tarek.jpg", "jpeg", "/bin/vlc", "1024X768");
	video4->modificarMultimedia("Star Lolo: The Vegetables Return", "Green Onion S.L.", 2016, 0, 0, 0, "/crfy/media/video/starlolo.avi", "avi", "/bin/vlc", 6, "Película Acción", "J.J. Abrams");
	musica5->modificarMultimedia("Angel Love Song", "Angel Music S.L.", 1975, 0, 0, 0, "/crfy/media/music/angelove.wav", "wav", "/bin/vlc", 4, "Angel Prestley", "Rock");

	c.setListaContenidoMultimedia(musica1);
	c.setListaContenidoMultimedia(video2);
	c.setListaContenidoMultimedia(imagen3);
	c.setListaContenidoMultimedia(video4);
	c.setListaContenidoMultimedia(musica5);

	/****** INICIALIZACIÓN DE USUARIOS ******/
	Usuario *cholo = new Usuario;
	Usuario *zizou = new Usuario;
	Usuario *pep = new Usuario;	

	cholo->modificarDatosUsuario("cholo", "daniestafeliz", "Cholo", "Simeone", "Crack", 50);
	cholo->setListaContenidosUsuario(video2);
	cholo->setListaContenidosUsuario(musica1);
	cholo->setListaContenidosUsuario(musica5);
	cholo->setListaContenidosUsuario(video4);
	cholo->votarContenidoMultimedia(0, 4.3);
	cholo->votarContenidoMultimedia(1, 5.1);
	cholo->votarContenidoMultimedia(2, 10.0);
	cholo->votarContenidoMultimedia(3, 6.0);

	c.setListaUsuarios(cholo);
	
	zizou->modificarDatosUsuario("zizou", "thebest", "Zinedine", "Zidane", "God", 45);
	zizou->setListaContenidosUsuario(imagen3);
	zizou->setListaContenidosUsuario(video4);
	zizou->setListaContenidosUsuario(musica1);
	zizou->setListaContenidosUsuario(musica5);
	zizou->votarContenidoMultimedia(0, 6.0);
	zizou->votarContenidoMultimedia(1, 10.0);
	zizou->votarContenidoMultimedia(2, 5.1);
	zizou->votarContenidoMultimedia(3, 10.0);

	c.setListaUsuarios(zizou);
	
	pep->modificarDatosUsuario("pep", "soyunperdedor", "Josep", "Guardiola", "Perdedor", 47);
	pep->setListaContenidosUsuario(video4);
	pep->setListaContenidosUsuario(video2);
	pep->setListaContenidosUsuario(imagen3);
	pep->setListaContenidosUsuario(musica1);
	pep->votarContenidoMultimedia(0, 10.0);
	pep->votarContenidoMultimedia(1, 4.3);
	pep->votarContenidoMultimedia(2, 6.0);
	pep->votarContenidoMultimedia(3, 5.1);

	c.setListaUsuarios(pep);

	system("clear");

	while(salida != -1)
	{
		salida1 = 0;
		posicion = 0;
		/****LOGIN****/
		while(logueado != true){
			c.bienvenida();
			cout << "Por favor inicie sesion para continuar (si no esta registrado porfavor registrese antes de continuar, para ello pulse 'R', o bien 'C' para continuar)" << endl;
			cin >> tecla;
			switch (tecla){
				case 'r':
				case 'R':
					c.registrarUsuario();
					system("clear");
					break;
				case 'c':
				case 'C':
					cout << "Login: ";
					cin >> login;

					posicion = c.buscarUsuarioEnSistema(login);

					if (posicion != -1)
					{
						cout << "Contraseña: " << OCULTO;
						cin >> password;
						cout << RESTORE_DEFAULT_COLOR << endl;
					}
					else{
						system("clear");
						cerr << RED_COLOR << "Ese usuario no está registrado en el sistema, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;
						break;
					}

					if (password != "admin")
					{
						logueado = c.autenticacion(posicion, password);

						system("clear");
						break;
					}
					else
						admin = true;
						logueado = true;
						system("clear");
						break;
				default:
					cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;
			}
		}

		while(salida1 != -2){
			if (admin == true)//MENU ADMIN
			{	
				cout << "Has iniciado sesion como administrador, ¿que desea hacer?" << endl;
				c.mostrarMenu(admin);
				
				cin >> tecla;

				switch (tecla){
					case '1':
						system("clear");
						cout << RED_COLOR << "Próximamente" << RESTORE_DEFAULT_COLOR << endl;
						break;
					case '2':
						system("clear");
						cout << RED_COLOR << "Próximamente" << RESTORE_DEFAULT_COLOR << endl;
						break;
					case '3':
						cin >> tecla;
						switch (tecla){
							case '1':
								system("clear");
								c.informeTop3General();
								break;
							case '2':
								system("clear");
								cout << RED_COLOR << "Próximamente" << RESTORE_DEFAULT_COLOR << endl;
								break;
							case '3':
								system("clear");
								cout << RED_COLOR << "Próximamente" << RESTORE_DEFAULT_COLOR << endl;
								break;
							default:
								cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;												
						}
						break;
					case '4':
						cin >> tecla;
						switch (tecla){
							case '1':
								c.registrarMultimedia();
								break;
							case '2':
								system("clear");
								cout << "Introduzca el título del multimedia que desea eliminar" << endl;
								cin.ignore(1024, '\n');
								getline(cin, titulo);
								posicionM = c.buscarMultimediaEnSistema(titulo);
								if (posicionM != -1)
								{
									c.eliminarMultimediaEnSistema(c.getMultimedia(posicionM));
									cout << "Multimedia eliminado con éxito" << endl;
								}
								else
									cerr << RED_COLOR << "No se encuentra ningún multimedia con las carecterísticas introducidas" << RESTORE_DEFAULT_COLOR << endl;

								posicionM = 0;
								break;
							case '3':
								system("clear");
								cout << "Por favor, indique si quiere buscar por titulo o compañia o por año: " << endl;
								cout << "	1. Título/Compañía" << endl;
								cout << "	2. Año" << endl;
								cin >> tecla;
								switch (tecla){
									case '1':
										cin.ignore(1024, '\n');
										getline(cin, str);
										posicionM = c.buscarMultimediaEnSistema(str);
										if (posicionM != -1)
										{
											c.getMultimedia(posicionM)->print();
										}
										else
											cerr << RED_COLOR << "No se encuentra ningún multimedia con las carecterísticas introducidas" << RESTORE_DEFAULT_COLOR << endl;
												
										posicionM = 0;
										break;

									case '2':
										cin >> anio;
										posicionM = c.buscarMultimediaEnSistema(anio);
										if (posicionM != -1)
										{
											c.getMultimedia(posicionM)->print();
										}
										else
											cerr << RED_COLOR << "No se encuentra ningún multimedia con las carecterísticas introducidas" << RESTORE_DEFAULT_COLOR << endl;
												
										posicionM = 0;
										break;

									default:
										cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;	
								}
								break;
							case '4':
								system("clear");
								cout << "Estos son los multimedias del sistema: " << endl;
								c.imprimirMulimedias();
								cout << "Introduzca el titulo del multimedia que quiere modificar: ";
								cin.ignore(1024, '\n');
								getline(cin, titulo);
								posicionM = c.buscarMultimediaEnSistema(titulo);
								if (posicionM != -1)
								{
									c.modificarMultimediaEnSistema(c.getMultimedia(posicionM));
								}
								else
									cerr << RED_COLOR << "No se encuentra ningún multimedia con las carecterísticas introducidas" << RESTORE_DEFAULT_COLOR << endl;

								posicionM = 0;
								break;
							case '5':
								system("clear");
								cout << "Estos son los multimedias del sistema: " << endl;
								c.imprimirMulimedias();
								cout << "Introduzca el titulo del multimedia del que quiere consultar su valoración media actual: ";
								cin.ignore(1024, '\n');
								getline(cin, titulo);
								posicionM = c.buscarMultimediaEnSistema(titulo);
								if (posicionM != -1)
								{
									c.valoracionMediaMultimedia(c.getMultimedia(posicionM));
								}
								else
									cerr << RED_COLOR << "No se encuentra ningún multimedia con las carecterísticas introducidas" << RESTORE_DEFAULT_COLOR << endl;

								posicionM = 0;
								break;

							default:
								cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;

						}
						break;
					case '5':
						cin >> tecla;
						switch (tecla){
							case '1':
								system("clear");
								c.registrarUsuario();
								break;
							case '2':
								system("clear");
								cout << "Estos son los usuarios registrados en el sistema: " << endl;
								c.imprimirUsuarios();
								cout << "Por favor, introduzca el login del usuario al que desea eliminar: ";
								cin >> login;
								posicion = c.buscarUsuarioEnSistema(login);
								if (posicion != -1)
								{
									c.eliminarUsuarioEnSistema(c.getUsuario(posicion));
								}
								else
									cerr << RED_COLOR << "No existe ningún usuario registrado con ese login" << RESTORE_DEFAULT_COLOR << endl;

								posicion = 0;
								break;
							case '3':
								system("clear");
								cout << "Por favor, introduzca el login del usuario al que desea buscar: ";
								cin >> login;
								posicion = c.buscarUsuarioEnSistema(login);
								if (posicion != -1)
								{
									c.getUsuario(posicion)->print();
								}
								else
									cerr << RED_COLOR << "No existe ningún usuario registrado con ese login" << RESTORE_DEFAULT_COLOR << endl;

								posicion = 0;
								break;
							case '4':
								system("clear");
								cout << "Por favor, introduzca el login del usuario al que desea modificar: ";
								cin >> login;
								posicion = c.buscarUsuarioEnSistema(login);
								if (posicion != -1)
								{
									c.modificarUsuarioEnSistema(c.getUsuario(posicion));
								}
								else
									cerr << RED_COLOR << "No existe ningún usuario registrado con ese login" << RESTORE_DEFAULT_COLOR << endl;

								posicion = 0;
								break;

							default:
								cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;
						}
						break;
					case 's':
						system("clear");
						cout << GREEN_COLOR "¿Desea salir o volver a la pantalla de login? '1' Salir, '2' Volver" << RESTORE_DEFAULT_COLOR << endl;
						cin >> tecla;
						switch(tecla){
							case '1':
								cout << GREEN_COLOR << "Muchas gracias ¡Hasta pronto!" << RESTORE_DEFAULT_COLOR << endl;
								salida = -1;
								salida1 = -2;
								break;
							case '2':
								logueado = false;
								admin = false;
								salida1 = -2;
								break;

							default:
								cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;
						}

					default:
						cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;
				}
			}
			else //MENU USUARIO
			{
				cout << "Has iniciado sesion como " << c.getUsuario(posicion)->getLogin() <<  ", ¿que dese hacer?" << endl;
				c.mostrarMenu();
				cin >> tecla;
				switch (tecla){
					case '1':
						system("clear");
						cout << "Modifique sus datos en los siguientes apartados: " << endl;
						c.modificarUsuarioEnSistema(c.getUsuario(posicion));
						break;
					case '2':
						system("clear");
						c.getUsuario(posicion)->imprimirListaContenidosAsociadosYValoraciones();
						break;
					case '3':
						system("clear");
						cout << "Estos son los multimedias del sistema: " << endl;
						c.imprimirMulimedias();
						cout << "Introduzca el titulo del contenido Multimedia que le gusta: ";
						cin.ignore(1024, '\n');
						getline(cin, titulo);
						posicionM = c.buscarMultimediaEnSistema(titulo);
						if (posicionM != -1)
						{
							c.getUsuario(posicion)->asociarContenidoMultimedia(c.getMultimedia(posicionM));
						}
						else
							cerr << RED_COLOR << "No existe ningún multimedia con ese titulo" << RESTORE_DEFAULT_COLOR << endl;

						posicionM = 0;
						break;
					case '4':
						system("clear");
						cout << "Estos son los multimedias asociados a tu cuenta: " << endl;
						c.getUsuario(posicion)->imprimirListaContenidosAsociadosYValoraciones();
						cout << "Introduzca el titulo del contenido Multimedia que ya no le gusta: ";
						cin.ignore(1024, '\n');
						getline(cin, titulo);
						posicionM = c.buscarMultimediaEnSistema(titulo);
						if (posicionM != -1)
						{
							c.getUsuario(posicion)->desasociarContenidoMultimedia(c.getMultimedia(posicionM));
						}
						else
							cerr << RED_COLOR << "No existe ningún multimedia registrado con ese titulo" << RESTORE_DEFAULT_COLOR << endl;

						posicionM = 0;
						break;
					case '5':
						system("clear");
						cout << "Estos son los multimedias asociados a tu cuenta: " << endl;
						c.getUsuario(posicion)->imprimirListaContenidosAsociadosYValoraciones();
						cout << "Introduzca el titulo del contenido Multimedia que quiere votar, y la valoracion: ";
						cin.ignore(1024, '\n');
						getline(cin, titulo);
						cin >> valoracion;
						posicionM = c.buscarMultimediaEnSistema(titulo);
						if (posicionM != -1)
						{
							for (int i = 0; i < c.getUsuario(posicion)->getUtilesCV() && valorado != true; ++i)
							{
								if(c.getUsuario(posicion)->getListaContenidosUsuario(i) == c.getMultimedia(posicionM)){
									c.getUsuario(posicion)->votarContenidoMultimedia(i, valoracion);
									valorado = true;
								}
							};
						}
						else
							cerr << RED_COLOR << "No existe ningún multimedia registrado con ese titulo" << RESTORE_DEFAULT_COLOR << endl;

						posicionM = 0;
						break;
					case '6':
						system("clear");
						cout << "Estos son los multimedias del sistema: " << endl;
						c.imprimirMulimedias();
						cout << "Introduzca el titulo del contenido Multimedia que quieres reproducir: ";
						cin.ignore(1024, '\n');
						getline(cin, titulo);
						posicionM = c.buscarMultimediaEnSistema(titulo);
						cout << posicionM << endl;
						if (posicionM != -1)
						{
							cout << "hola??" << endl;
							c.getMultimedia(posicionM)->reproducir();
						}
						else
							cerr << RED_COLOR << "No existe ningún multimedia registrado con ese titulo" << RESTORE_DEFAULT_COLOR << endl;

						posicionM = 0;
						break;
					case 's':
						system("clear");
						cout << GREEN_COLOR "¿Desea salir o volver a la pantalla de login? '1' Salir, '2' Volver" << RESTORE_DEFAULT_COLOR << endl;
						cin >> tecla;
						switch(tecla){
							case '1':
								cout << GREEN_COLOR << "Muchas gracias ¡Hasta pronto!" << RESTORE_DEFAULT_COLOR << endl;
								salida = -1;
								salida1 = -2;
								break;
							case '2':
								logueado = false;
								salida1 = -2;
								break;
							default:
								cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;
						}
						break;

					default:
						cerr << RED_COLOR << "Ups, parece que ha habido un error, intentelo de nuevo" << RESTORE_DEFAULT_COLOR << endl;
				}
			}
		}
	}
}