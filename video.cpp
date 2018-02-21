#include "video.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

#define BLUE_COLOR "\033[34m"
#define LIGHT_BLUE_COLOR "\033[1;34m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define RESTORE_DEFAULT_COLOR "\033[0m"

Video::Video(): Multimedia(){
    this->duracion = 0;
    this->tematica = " ";
    this->autor = " ";
}

Video::Video(int duracion, string tematica, string autor, string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma): Multimedia(titulo, compania, anio, puntuacionTotal, totalUsuariosQueHanValorado, valoracionMediaActual, rutaFichero, formato, rutaPrograma){
	this->duracion = duracion;
	this->tematica = tematica;
	this->autor = autor;
}

Video::~Video(){
    this->duracion = 0;
    this->tematica = " ";
    this->autor = " ";

    cout << BLUE_COLOR << "Vídeo eliminado con éxito" << RESTORE_DEFAULT_COLOR << endl;  
}

void Video::print(){
    cout << LIGHT_BLUE_COLOR << "Título: " << this->getTitulo() << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Compañía: " << this->getCompania() << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Año: " << this->getAnio() << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Formato: " << this->getFormato() << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Duración: " << this->duracion << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Autor: " << this->autor << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Temática: " << this->tematica << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Puntuación Total: " << this->getPuntuacionTotal() << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Total de usuarios que han valorado: " << this->getTotalUsuariosQueHanValorado() << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Valoración media: " << this->getValoracionMediaActual() << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Ruta del fichero: " << this->getRutaFichero() << RESTORE_DEFAULT_COLOR << endl;
    cout << LIGHT_BLUE_COLOR << "Ruta del programa: " << this->getRutaPrograma() << RESTORE_DEFAULT_COLOR << endl;
}

void Video::modificarMultimedia(string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma, int duracion, string tematica, string autor){
    this->setTitulo(titulo);
    this->setCompania(compania);
    this->setAnio(anio);
    this->setPuntuacionTotal(puntuacionTotal);
    this->setTotalUsuariosQueHanValorado(totalUsuariosQueHanValorado);
    this->setValoracionMediaActual(valoracionMediaActual);
    this->setRutaFichero(rutaFichero);
    this->setFormato(formato);
    this->setRutaPrograma(rutaPrograma);
    this->duracion = duracion;
    this->tematica = tematica;
    this->autor = autor;

    cout << "Vídeo modificado con éxito" << endl;
}

void Video::reproducir(){
	pid_t pid = fork(), w;
	int status;
    
    if (this->getRutaPrograma() != " " && this->getRutaFichero() != " ")
    {
        cout << GREEN_COLOR << "Reproduciendo vídeo..." << RESTORE_DEFAULT_COLOR << endl;
        
        if (pid == -1){
            cerr << "No hay memoria..." << endl;
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            cout << "Child process: My process id = " << getpid() << endl;
            cout << "Child process: Value returned by fork() = " << pid << endl;
            execl(this->getRutaPrograma().c_str(), this->getRutaPrograma().c_str(), this->getRutaFichero().c_str(), (char *) 0);
        } 

        do {
            w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
            if (w == -1)  {
                exit(EXIT_FAILURE);
            }

            if (WIFEXITED(status)) {
                cout << "exited, status:" << WEXITSTATUS(status) << endl;
            } else if (WIFSIGNALED(status)) {
                cout << "killed by signal" << WTERMSIG(status) << endl;
            } else if (WIFSTOPPED(status)) {
                cout << "stopped by signal" << WSTOPSIG(status) << endl;
            } else if (WIFCONTINUED(status)) {
                cout << "continua ..." << endl;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else
        cerr << RED_COLOR << "No existe la ruta del programa o el fichero, por favor especifique la ruta del programa o del fichero y vuelva a intentarlo otra vez..." << RESTORE_DEFAULT_COLOR << endl;
}