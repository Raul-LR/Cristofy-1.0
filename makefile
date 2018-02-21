all: Cristofy

Cristofy: multimedia.cpp usuario.cpp cristofy.cpp main.cpp
	g++ multimedia.cpp usuario.cpp cristofy.cpp main.cpp -o Cristofy

clean:
	rm Cristofy
