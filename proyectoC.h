#ifndef proyectoC_h
#define proyectoC_h

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;
class Usuario;
class Publicacion {
private:
    int id;
public:
    string fecha;
    string contenido;
    Usuario* usuario;

    Publicacion(Usuario* usuario, string fecha, string contenido) : usuario(usuario), fecha(fecha), contenido(contenido) {
        static int nextId = 1;
        id = nextId++;
    }

    void mostrarPublicacion();
};
class Usuario {
private:
    int id;
public:
    string nombre;
    int edad;
    string genero;
    string nacionalidad;
    vector<Usuario*> amigos;
    vector<Publicacion*> publicaciones;

    Usuario(string nombre, int edad, string genero, string nacionalidad) : nombre(nombre), edad(edad), genero(genero), nacionalidad(nacionalidad) {
        static int nextId = 1;
        id = nextId++;
    }

    int getId() {
        return id;
    }

    void mostrar() {
        cout << "ID: " << id << ", Nombre: " << nombre << ", Edad: " << edad << ", Genero: " << genero << ", Nacionalidad: " << nacionalidad << endl;
    }

    void mostrarAmigos() {
        cout << "Amigos de " << nombre << ":" << endl;
        for (Usuario* amigo : amigos) {
            amigo->mostrar();
        }
    }

    void mostrarPublicaciones() {
        cout << "Publicaciones de " << nombre << ":" << endl;
        for (Publicacion* publicacion : publicaciones) {
            publicacion->mostrarPublicacion();
        }
    }

    void mostrarPublicacionesAmigos();

    void agregarAmigo(Usuario* nuevoAmigo) {
        amigos.push_back(nuevoAmigo);
        nuevoAmigo->amigos.push_back(this);
    }

    void crearPublicacion(string fecha, string contenido);

    Usuario* getAmigo(int id);
};
void Publicacion::mostrarPublicacion() {
    cout << "Fecha: " << fecha << ", Contenido: " << contenido << ", Usuario: " << usuario->nombre << endl;
}
void Usuario::mostrarPublicacionesAmigos() {
    cout << "Publicaciones de amigos de " << nombre << ":" << endl;
    for (Usuario* amigo : amigos) {
        cout << "Publicaciones de " << amigo->nombre << ":" << endl;
        for (Publicacion* publicacion : amigo->publicaciones) {
            publicacion->mostrarPublicacion();
        }
    }
}
void Usuario::crearPublicacion(string fecha, string contenido) {
    Publicacion* nuevaPublicacion = new Publicacion(this, fecha, contenido);
    publicaciones.push_back(nuevaPublicacion);
}
Usuario* Usuario::getAmigo(int id) {
    for (Usuario* amigo : amigos) {
        if (amigo->getId() == id) {
            return amigo;
        }
    }
    return nullptr;
}

#endif