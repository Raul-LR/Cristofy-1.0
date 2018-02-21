#include "multimedia.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

#define BLUE_COLOR "\033[34m"
#define RED_COLOR "\033[1;31m"
#define RESTORE_DEFAULT_COLOR "\033[0m"

Multimedia::Multimedia(){
    this->titulo = " "; 
    this->compania = " "; 
    this->anio = 0; 
    this->puntuacionTotal = 0; 
    this->totalUsuariosQueHanValorado = 0; 
    this->valoracionMediaActual = 0; 
    this->rutaFichero = " "; 
    this->formato = " "; 
    this->rutaPrograma = " ";
}

Multimedia::Multimedia(string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma){
    this->titulo = titulo;
    this->compania = compania;
    this->anio = anio;
    this->puntuacionTotal = puntuacionTotal;
    this->totalUsuariosQueHanValorado = totalUsuariosQueHanValorado;
    this->valoracionMediaActual = valoracionMediaActual;
    this->rutaFichero = rutaFichero;
    this->formato = formato;
    this->rutaPrograma = rutaPrograma;
}

Multimedia::~Multimedia(){
    this->titulo = " "; 
    this->compania = " "; 
    this->anio = 0; 
    this->puntuacionTotal = 0; 
    this->totalUsuariosQueHanValorado = 0; 
    this->valoracionMediaActual = 0; 
    this->rutaFichero = " "; 
    this->formato = " "; 
    this->rutaPrograma = " ";

    cout << BLUE_COLOR << "Multimedia eliminado con éxito" << RESTORE_DEFAULT_COLOR << endl;
}

void Multimedia::print(){
    cout << "Título: " << this->titulo << endl;
    cout << "Compañía: " << this->compania << endl;
    cout << "Año: " << this->anio << endl;
    cout << "Formato: " << this->formato << endl;
    cout << "Puntuación Total: " << this->puntuacionTotal << endl;
    cout << "Total de usuarios que han valorado: " << this->totalUsuariosQueHanValorado << endl;
    cout << "Valoración media: " << this->valoracionMediaActual << endl;
    cout << "Ruta del fichero: " << this->rutaFichero << endl;
    cout << "Ruta del programa: " << this->rutaPrograma << endl;
}

void Multimedia::modificarMultimedia(string titulo, string compania, int anio, float puntuacionTotal, int totalUsuariosQueHanValorado, float valoracionMediaActual, string rutaFichero, string formato, string rutaPrograma){
    this->titulo = titulo;
    this->compania = compania;
    this->anio = anio;
    this->puntuacionTotal = puntuacionTotal;
    this->totalUsuariosQueHanValorado = totalUsuariosQueHanValorado;
    this->valoracionMediaActual = valoracionMediaActual;
    this->rutaFichero = rutaFichero;
    this->formato = formato;
    this->rutaPrograma = rutaPrograma;

    cout << "Multimedia modificado con éxito" << endl;
}

void Multimedia::reproducir(){
	pid_t pid = fork(), w;
	int status;
    
    if (this->getRutaPrograma() != " " && this->getRutaFichero() != " ")
    {       
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