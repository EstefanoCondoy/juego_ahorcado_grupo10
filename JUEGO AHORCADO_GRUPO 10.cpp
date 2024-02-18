#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET_COLOR   "\033[0m"
#define RED_COLOR     "\033[31m"
#define GREEN_COLOR   "\033[32m"
#define YELLOW_COLOR  "\033[33m"
#define BLUE_COLOR    "\033[34m"
#define MAGENTA_COLOR "\033[35m"
#define CYAN_COLOR    "\033[36m"

using namespace std;

struct Puntajes {
    int puntaje_jugador1 = 100;
    int puntaje_jugador2 = 100;
    int puntaje_jugador3 = 100;
};

void LimpiarPantalla();
void JugarPartida(Puntajes &puntajes);
void Dibujar(int vida);
void MostrarPuntajes(const Puntajes &puntajes);
void PantallaInicio(Puntajes &puntajes);

char eleccion;
string palabras[] = {"monitor", "microfono", "televisor", "telefono", "elefante", "computador", "teclado", "monitor", "memoria", "graficos", "videojuego", "linterna", "durazno"};
string palabra, fallidas;
size_t nA;
int vida;
bool correcta, completa;

void actualizarPuntaje(bool letraAdivinada, Puntajes &puntajes, int jugadorSeleccionado) {
    int *puntajeJugador;

    switch (jugadorSeleccionado) {
        case 1:
            puntajeJugador = &puntajes.puntaje_jugador1;
            break;
        case 2:
            puntajeJugador = &puntajes.puntaje_jugador2;
            break;
        case 3:
            puntajeJugador = &puntajes.puntaje_jugador3;
            break;
        default:
            cout << "Jugador no valido. Puntaje no actualizado." << endl;
            return;
    }

    if (letraAdivinada) {
        // No sumar puntos por letra correcta
    } else {
        // Restar 10 puntos por cada letra incorrecta
        if (*puntajeJugador >= 10) {
            *puntajeJugador -= 10;
        } else {
            *puntajeJugador = 0;  // Evitar puntajes negativos
        }
    }
}


void JugarPartida(Puntajes &puntajes) {
    srand(static_cast<unsigned int>(time(NULL)));
    nA = rand() % 13;

    cout << "Selecciona el jugador (1, 2, 3): ";
    int jugadorSeleccionado;
    cin >> jugadorSeleccionado;

    for (size_t i = 0; i < palabras[nA].size(); i++) {
        palabra += "-";
    }

    while (vida > 0) {
        LimpiarPantalla();
        cout << YELLOW_COLOR"\t::: A H O R C A D O :::" RESET_COLOR<< endl;
        Dibujar(vida);
        cout << MAGENTA_COLOR"Fallos: " << fallidas;
        cout << "  Progreso: " << palabra << endl;
        cout << BLUE_COLOR"Ingrese una letra (minuscula): ";
        cin >> eleccion;

        correcta = false;
        for (size_t i = 0; i < palabras[nA].size(); i++) {
            if (palabras[nA][i] == eleccion) {
                palabra[i] = eleccion;
                correcta = true;
            }
        }
        if (!correcta) {
            vida--;
            fallidas += eleccion;
        }

        actualizarPuntaje(correcta, puntajes, jugadorSeleccionado);

        completa = true;
        for (size_t i = 0; i < palabra.size(); i++) {
            if (palabra[i] == '-') {
                completa = false;
            }
        }
        if (completa) {
            LimpiarPantalla();
            cout << "\t::: A H O R C A D O :::" << endl;
            Dibujar(vida);
            cout << "Palabra: " << palabras[nA] << endl;
            cout << RED_COLOR"Ganaste."<<RESET_COLOR" Ingresa un caracter para continuar: ";
            cin >> eleccion;
            return;
        }
    }
    LimpiarPantalla();
    cout << "\t::: A H O R C A D O :::" << endl;
    Dibujar(vida);
    cout << "Palabra: " << palabras[nA] << endl;
    cout << RED_COLOR"Perdiste."<<RESET_COLOR" Ingresa un caracter para continuar: ";
    cin >> eleccion;
}

void MostrarPuntajes(const Puntajes &puntajes) {
    cout << RED_COLOR"Puntajes actuales:" << endl;
    cout << RESET_COLOR"Jugador 1: " << puntajes.puntaje_jugador1 << endl;
    cout << "Jugador 2: " << puntajes.puntaje_jugador2 << endl;
    cout << "Jugador 3: " << puntajes.puntaje_jugador3 << endl;
}

void Dibujar(int vida) {
    switch (vida) {
        case 6:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 5:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 4:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |      |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 3:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |     /|" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 2:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |     /|\\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 1:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |     /|\\" << endl;
            cout << "  |     /" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
        case 0:
            cout << "  --------" << endl;
            cout << "  |      |" << endl;
            cout << "  |      O" << endl;
            cout << "  |     /|\\" << endl;
            cout << "  |     / \\" << endl;
            cout << "  |" << endl;
            cout << "  |" << endl;
            cout << " ---" << endl;
            break;
    }
}

void LimpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void PantallaInicio(Puntajes &puntajes) {
    while (true) {
        vida = 6;
        palabra = "";
        fallidas = "";
        LimpiarPantalla();
        cout << CYAN_COLOR "                               ----------------------------------------------------------" << endl;
        cout << RED_COLOR "                                         A H O R C A D O    P O L I T E C N I C O        " << endl;
        cout << CYAN_COLOR "                               ----------------------------------------------------------" << endl;
        cout << endl;
        cout << GREEN_COLOR "                                                      1." << BLUE_COLOR "Puntuacion" << endl;
        cout << GREEN_COLOR "                                                      2." << BLUE_COLOR "Iniciar Juego" << endl;
        cout << GREEN_COLOR "                                                      3." << BLUE_COLOR "Creditos" << endl;
        cout << GREEN_COLOR "                                                      4." << BLUE_COLOR "Salir" << endl;
        cout << endl;
        cout << MAGENTA_COLOR "                                                 Introduzca una opcion: ";
        cin >> eleccion;

        switch (eleccion) {
            case '1':
                // Código para mostrar la puntuación
                MostrarPuntajes(puntajes);
                cin.ignore();  // Para evitar que el enter anterior se tome como la entrada en la siguiente iteración
                cin.get();     // Esperar a que el usuario presione enter
                break;
            case '2':
                JugarPartida(puntajes);
                break;
            case '3':
                // Creditos y autores
                cout << RESET_COLOR "            <No te preocupes por los errores, son simplemente oportunidades para aprender y mejorar tu codigo>" << endl;
                cout << GREEN_COLOR "                                              Facultad de Ingenieria en Sistemas " << endl;
                cout << BLUE_COLOR "                                                -Condoy Caceres Estéfano Damian ";
                cout << BLUE_COLOR "                                                                                             -Lopez Luna Juan David " << endl;
                cin.ignore();  // Para evitar que el enter anterior se tome como la entrada en la siguiente iteración
                cin.get();     // Esperar a que el usuario presione enter
                break;
            case '4':
                cout << RESET_COLOR "                                -------------------- Gracias por jugar --------------------" << endl;
                exit(0);
            default:
                cout << "Opcion no valida. Por favor, selecciona una opcion valida." << endl;
        }
    }
}

int main() {
    srand(time(0));
    Puntajes puntajes;
    PantallaInicio(puntajes);
    return 0;
}


