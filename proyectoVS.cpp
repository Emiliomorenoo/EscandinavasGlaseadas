
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "proyectoC.h"
using namespace std;


int mostrarMenuInicioSesion(vector<Usuario>& usuarios) {
    int opcion = 0;
    while (true) {
        system("cls");
        cout << "Bienvenido a la Red Social Escandinavas Glaseadas" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Sign In" << endl;
        cout << "2. Log In" << endl;
        cout << "3. Ver lista de usuarios existentes" << endl;
        cout << "4. Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Ingrese el numero correspondiente a la opcion que desea: ";

        char tecla = getch();
        if (tecla >= '1' && tecla <= '4') {
            opcion = tecla - '0';
            break;
        }
    }
    return opcion;
}
void mostrarMenuUsuario(Usuario& usuario, vector<Usuario>& usuarios) {
    while (true) {
        system("cls");
        cout << "Bienvenido, " << usuario.nombre << "!" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Mostrar mis publicaciones" << endl;
        cout << "2. Crear una nueva publicacion" << endl;
        cout << "3. Agregar amigo" << endl;
        cout << "4. Ver lista de amigos agregados" << endl;
        cout << "5. Ver publicaciones de amigos" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Ingrese el numero correspondiente a la opcion que desea: ";

        char tecla = getch();
        if (tecla == '1') {
            usuario.mostrarPublicaciones();
        } else if (tecla == '2') {
            string fecha, contenido;
            cout << "Ingrese la fecha de la publicacion (DD/MM/AA): ";
            cin >> fecha;
            cout << "Ingrese el contenido de la publicacion: ";
            cin.ignore();
            getline(cin, contenido);
            usuario.crearPublicacion(fecha, contenido);
            cout << "Publicacion creada exitosamente." << endl;
        } else if (tecla == '3') {
            cout << "Lista de usuarios existentes:" << endl;
            for (Usuario& u : usuarios) {
                cout << "ID: " << u.getId() << ", Nombre: " << u.nombre << ", Edad: " << u.edad << ", Genero: " << u.genero << endl;
            }
            cout << endl;

            cout << "Seleccione el ID del usuario que desea agregar como amigo: ";
            int idAmigo;
            cin >> idAmigo;
            bool encontrado = false;
            for (Usuario& posibleAmigo : usuarios) {
                if (posibleAmigo.getId() == idAmigo) {
                    usuario.agregarAmigo(&posibleAmigo);
                    cout << "Usuario agregado como amigo exitosamente." << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "No se ha encontrado ningun usuario con ese ID." << endl;
            }
        } else if (tecla == '4') {
            usuario.mostrarAmigos();
        } else if (tecla == '5') {
            usuario.mostrarPublicacionesAmigos();
        } else if (tecla == '6') {
            break;
        } else {
            cout << "Opcion no valida. Por favor, ingrese un numero valido." << endl;
            system("pause");
        }
        system("pause");
    }
}
int main() {
    vector<Usuario> usuarios;

    Usuario usuario1("Juan Pablo",13, "Hombre con Sobrepeso que Tiene Senos", "Espaniol");
    usuario1.crearPublicacion("09/04/2024", "¡Hola a todos! Soy Juan Pablo");
    usuarios.push_back(usuario1);

    Usuario usuario2("Emilio", 24, "Odontosexual", "Portugues");
    usuario2.crearPublicacion("11/01/2024", "¡Buenas tardes! Soy Emilio.");
    usuarios.push_back(usuario2);

    Usuario usuario3("Quique", 32, "Hombre con Mala Circuncision", "Mexico");
    usuario3.crearPublicacion("23/03/2024", "¡Hola mundo! Soy Quique.");
    usuarios.push_back(usuario3);


    while (true) {
        int opcionInicioSesion = mostrarMenuInicioSesion(usuarios);
        if (opcionInicioSesion == 1) {
            string nombre, genero, nacionalidad;
            int edad;
            cout << "\nIngrese el nombre del nuevo usuario: ";
            cin >> nombre;
            cout << "Ingrese la edad del nuevo usuario: ";
            cin >> edad;

            cout << "Ingrese el genero del nuevo usuario" << endl;
            cout << "1. Hombre" << endl;
            cout << "2. Mujer" << endl;
            cout << "3. Gay" << endl;
            cout << "4. Hombre Trans" << endl;
            cout << "5. Mujer Trans" << endl;
            cout << "6. Hombre Metrosexual" << endl;
            cout << "7. Mujer Metrosexual" << endl;
            cout << "8. Hombre Curioso de Ser Mujer" << endl;
            cout << "9. Mujer Curiosa de Ser Hombre" << endl;
            cout << "10. Hombre con Sobrepeso que Tiene Senos" << endl;
            cout << "11. Mujer con Manzana de Adan" << endl;
            cout << "12. Hermafrodita con Pene Predominante" << endl;
            cout << "13. Hermafrodita con Vagina Predominante" << endl;
            cout << "14. Hermafrodita sin Organo Dominante" << endl;
            cout << "15. Persona que Nacio sin Genitales e Identifica como Hombre" << endl;
            cout << "16. Persona que Nacio sin Genitales e Identifica como Mujer" << endl;
            cout << "17. Persona que Nacio sin Genitales y se Identifica Orgullosamente" << endl;
            cout << "18. Hombre con Mala Circuncision" << endl;
            cout << "19. Inteligencia Artificial Sensible sin Genero" << endl;
            cout << "20. Inteligencia Artificial Sensible que se Identifica como Mujer" << endl;
            cout << "21. Inteligencia Artificial Sensible que se Identifica como Hombre" << endl;
            cout << "22. Antrosexual" << endl;
            cout << "23. Heterosexual" << endl;
            cout << "24. Autosexual" << endl;
            cout << "25. Androginosexual" << endl;
            cout << "26. Bicurioso" << endl;
            cout << "27. Biflexible" << endl;
            cout << "28. Fluido" << endl;
            cout << "29. Ginosexual" << endl;
            cout << "30. Odontosexual" << endl;
            cout << "31. Grisexual" << endl;
            cout << "32. Lithsexual" << endl;
            cout << "33. Monosexual" << endl;
            cout << "34. Asexual" << endl;
            cout << "35. Pansexual" << endl;
            cout << "36. Homnisexual" << endl;
            cout << "37. Poliamoroso" << endl;
            cout << "38. Biosexual" << endl;
            cout << "39. Hidrosexual" << endl;
            cout << "40. Zoofilico" << endl;
            cout << "41. Polisexual" << endl;
            cout << "42. Gerontofilico" << endl;
            cout << "43. Pornosexual" << endl;
            cout << "44. Sapiosexual" << endl;
            cout << "45. Transerotico" << endl;
            cout << "46. Berdache o Dos Espiritus" << endl;
            cout << "47. T-72B 1989" << endl;
            cout << "48. Boeing 747" << endl;
            cout << "49. Submarino Clase Delta" << endl;
            cout << "50. Helicoptero Apache" << endl;
            cout << "51. Ferrari" << endl;
            cout << "52. Variante Omicron del Coronavirus" << endl;



            int opcionGenero;
            cin >> opcionGenero;
            cin.ignore();
            if (opcionGenero == 1) {
                genero = "Hombre";
            }
            else if (opcionGenero == 2) {
                genero = "Mujer";
            }
            else if (opcionGenero == 3) {
                genero = "gay";
            }
            else if (opcionGenero == 4) {
                genero = "hombre trans";
            }
            else if (opcionGenero == 5) {
                genero = "mujer trans";
            }
           else if (opcionGenero == 6) {
                genero = "hombre metrosexual";
            }
            else if (opcionGenero == 7) {
                genero = "mujer metrosexual";
            }
            else if (opcionGenero == 8) {
                genero = "hombre pero curioso de como es ser mujer";
            }
            else if (opcionGenero == 9) {
                genero = "mujer pero curiosa de como es ser hombre";
            }
            else if (opcionGenero == 10) {
                genero = "hombre con sobrepeso entonces tengo senos";
            }
            else if (opcionGenero == 11) {
                genero = "mujer con Manzana de Adan";
            }
            else if (opcionGenero == 12) {
                genero = "hermafrodita con pene predominante";
            }
            else if (opcionGenero == 13) {
                genero = "hermafrodita con vagina predominante";
            }
            else if (opcionGenero == 14) {
                genero = "hermafrodita sin organo dominante";
            }
            else if (opcionGenero == 15) {
                genero = "naci sin genitales y me identifico como hombre";
            }
            else if (opcionGenero == 16) {
                genero = "naci sin genitales y me identifico como mujer";
            }
            else if (opcionGenero == 17) {
                genero = "naci sin genitales y me identifico orgullosamente";
            }
            else if (opcionGenero == 18) {
                genero = "hombre con mala circuncision";
            }
            else if (opcionGenero == 19) {
                genero = "sensible inteligencia artificial sin genero";
            }
            else if (opcionGenero == 20) {
                genero = "sensible inteligencia artificial y me identifico como mujer";
            }
            else if (opcionGenero == 21) {
                genero = "sensible inteligencia artificial y me identifico como hombre";
            }
            else if (opcionGenero == 22) {
                genero = "antrosexual";
            }
            else if (opcionGenero == 23) {
                genero = "heterosexual";
            }
            else if (opcionGenero == 24) {
                genero = "autosexual";
            }
            else if (opcionGenero == 25) {
                genero = "androginosexual";
            }
            else if (opcionGenero == 26) {
                genero = "bicurioso";
            }
            else if (opcionGenero == 27) {
                genero = "biflexible";
            }
            else if (opcionGenero == 28) {
                genero = "fluido";
            }
            else if (opcionGenero == 29) {
                genero = "ginosexual";
            }
            else if (opcionGenero == 30) {
                genero = "odontosexual";
            }
            else if (opcionGenero == 31) {
                genero = "grisexual";
            }
            else if (opcionGenero == 32) {
                genero = "lithsexual";
            }
            else if (opcionGenero == 33) {
                genero = "monosexual";
            }
            else if (opcionGenero == 34) {
                genero = "asexual";
            }
            else if (opcionGenero == 35) {
                genero = "pansexual";
            }
            else if (opcionGenero == 36) {
                genero = "homnisexual";
            }
            else if (opcionGenero == 37) {
                genero = "poliamoroso";
            }
            else if (opcionGenero == 38) {
                genero = "biosexual";
            }
            else if (opcionGenero == 39) {
                genero = "hidrosexual";
            }
            else if (opcionGenero == 40) {
                genero = "zoofilico";
            }
            else if (opcionGenero == 41) {
                genero = "polisexual";
            }
            else if (opcionGenero == 42) {
                genero = "gerontofilico";
            }
            else if (opcionGenero == 43) {
                genero = "pornosexual";
            }
            else if (opcionGenero == 44) {
                genero = "sapiosexual";
            }
            else if (opcionGenero == 45) {
                genero = "transerotico";
            }
            else if (opcionGenero == 46) {
                genero = "berdache o dos espiritus";
            }
            else if (opcionGenero == 47) {
                genero = "T-72B 1989";
            }
            else if (opcionGenero == 48) {
                genero = "boeing 747";
            }
            else if (opcionGenero == 49) {
                genero = "submarino clase delta";
            }
            else if (opcionGenero == 50) {
                genero = "helicoptero apache";
            }
            else if (opcionGenero == 51) {
                genero = "ferrari";
            }
            else if (opcionGenero == 52) {
                genero = "variante omicron del coronavirus";
            }
            else {
                genero = "genero no especificado";
            }



            cout << "Ingrese la nacionalidad del nuevo usuario: ";
            cin >> nacionalidad;

            Usuario nuevoUsuario(nombre, edad, genero, nacionalidad);
            usuarios.push_back(nuevoUsuario);
            cout << "Usuario registrado exitosamente." << endl;
            system("pause");
        } else if (opcionInicioSesion == 2) {
            int idUsuario;
            cout << "Ingrese el ID de su usuario: ";
            cin >> idUsuario;
            bool encontrado = false;
            for (Usuario& usuario : usuarios) {
                if (usuario.getId() == idUsuario) {
                    mostrarMenuUsuario(usuario, usuarios);
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "No se ha encontrado ningun usuario con ese ID." << endl;
                system("pause");
            }
        } else if (opcionInicioSesion == 3) {
            cout << "Lista de usuarios existentes:" << endl;
            for (Usuario& usuario : usuarios) {
                usuario.mostrar();
            }
            cout << endl;
            system("pause");
        } else if (opcionInicioSesion == 4) {
            break;
        }
    }

    return 0;
}
