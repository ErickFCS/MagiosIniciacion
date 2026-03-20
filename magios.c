#include <stdbool.h>
#include <stdio.h>

#define MAX_VECTOR_RESULTADO 31

/*
 * PRE: -
 * POS: Mensaje de bienvenida mostrado al usuario
 */
void mostrar_mensaje_de_bienvenida() {
  printf("--------------------------------------------------\n");
  printf("\n");
  printf("¡HOLA ASPIRANTE! ¿Listo para rendir tu iniciación?\n");
  printf("\n");
  printf("Responde a las siguientes preguntas y descubre si\n");
  printf("tienes lo necesario para ser un \x1b[97mMAGIO\x1b[0m\n");
  printf("\n");
  printf("--------------------------------------------------\n");
}

/*
 * PRE: Tener una variable en donde se quiera almacenar el puntaje obtenido
 * POS: Puntaje obtenido sumado/restado a la variable pasada
 */
void preguntar_fundador(int *puntaje, bool *rechazado) {
  const int PUNTAJE_SI_ACIERTA = 100;
  const int PUNTAJE_SI_ERRA = -20;
  const int CANTIDAD_MAXIMA_DE_INTENTOS = 3;

  int intentos_restantes = CANTIDAD_MAXIMA_DE_INTENTOS;
  char eleccion = 0;
  bool termino = false;
  while (!termino) {
    if (intentos_restantes > 0) {
      printf("\n");
      printf("\x1b[93mNúmero de intentos restantes: %d\x1b[0m\n", intentos_restantes);
      printf("\n");
      printf("\x1b[93mIngrese solo la letra entre [] de su opción elegida\x1b[0m\n");
      printf("\n");
      printf("¿Quién fundó realmente Springfield?\n");
      printf("\n");
      printf("\t\x1b[94m[J]\x1b[0m Jebediah Springfield\n");
      printf("\t\x1b[94m[A]\x1b[0m Los aliens\n");
      printf("\t\x1b[94m[S]\x1b[0m Los Magios\n");
      printf("\t\x1b[94m[B]\x1b[0m Sr. Burns\n");
      printf("\n");
      printf("Ingrese aquí su elección: ");
      scanf(" %c", &eleccion);
      printf("\n");
      if (eleccion == 'J' || eleccion == 'A' || eleccion == 'S' || eleccion == 'B') {
        if (eleccion == 'J') {
          *puntaje += PUNTAJE_SI_ACIERTA;
          termino = true;
        } else {
          *puntaje += PUNTAJE_SI_ERRA;
          printf("\x1b[91mLa opción %c no es la correcta. Intente nuevamente\x1b[0m\n", eleccion);
          intentos_restantes--;
        }
      } else {
        printf("\x1b[91mLa opción: %c no está entre las válidas. Intente nuevamente\x1b[0m\n", eleccion);
      }
    } else {
      printf("-RECHAZADO-\n");
      *rechazado = true;
      *puntaje = -1;
      termino = true;
    }
  }
}

/*
 * PRE: Tener una variable en donde se quiera almacenar el puntaje obtenido
 * POS: Puntaje obtenido sumado/restado a la variable pasada
 */
void preguntar_voto_de_silencio(int *puntaje) {
  const int PUNTAJE_SI_ACIERTA = 50;
  const int PUNTAJE_SI_ERRA = -300;

  char eleccion = 0;
  bool acepto = false;
  bool termino = false;
  while (!termino) {
    printf("\n");
    printf("\x1b[93mIngrese solo la letra entre [] de su opción elegida\x1b[0m\n");
    printf("\n");
    printf("¿Promete mantener en secreto la existencia de los Magios?\n");
    printf("\n");
    printf("\t\x1b[94m[S]\x1b[0m Sí\n");
    printf("\t\x1b[94m[N]\x1b[0m No\n");
    printf("\n");
    printf("Ingrese aquí su elección: ");
    scanf(" %c", &eleccion);
    printf("\n");
    if (eleccion == 'S') {
      acepto = true;
      *puntaje += PUNTAJE_SI_ACIERTA * acepto; // Solo lo uso para que no me tire la warning
      termino = true;
    } else if (eleccion == 'N') {
      acepto = false;
      *puntaje += PUNTAJE_SI_ERRA;
      termino = true;
    } else {
      printf("\x1b[91mLa opción: %c no está entre las válidas. Intente nuevamente\x1b[0m\n", eleccion);
    }
  }
}

/*
 * PRE: Tener una variable en donde se quiera almacenar el puntaje obtenido
 * POS: Puntaje obtenido sumado/restado a la variable pasada
 */
void preguntar_nacimiento(int *puntaje, bool *rechazado) {
  const int MULTIPLICADOR_PARA_PUNTAJE = 2;

  const int VALOR_YYYY_ACTUAL = 2026;
  const int VALOR_MM_ACTUAL = 3;

  int valor_yyyy = -1;
  int valor_mm = -1;
  int edad = -1;
  bool termino = false;
  while (!termino) {
    printf("\n");
    printf("\x1b[93mIngrese la fecha en formato yyyy/mm\x1b[0m\n");
    printf("\x1b[93mSiendo yyyy el año, y mm, el mes\x1b[0m\n");
    printf("\x1b[93mLa fecha ingresada debe ser:\x1b[0m\n");
    printf("\t\x1b[93mPosterior a 1926/3\x1b[0m\n");
    printf("\t\x1b[93my\x1b[0m\n");
    printf("\t\x1b[93mAnterior a 2026/3\x1b[0m\n");
    printf("\n");
    printf("¿Cuál es su fecha de nacimiento?\n");
    printf("\n");
    printf("Ingrese la fecha \x1b[94m(yyyy/mm)\x1b[0m aquí: ");
    scanf(" %d/%d", &valor_yyyy, &valor_mm);
    printf("\n");
    if (valor_mm >= 1 && valor_mm <= 12 && (valor_yyyy > 1926 || (valor_yyyy == 1926 && valor_mm >= 3)) && (valor_yyyy < 2026 || (valor_yyyy == 2026 && valor_mm <= 3))) {
      edad = VALOR_YYYY_ACTUAL - valor_yyyy - ((VALOR_MM_ACTUAL - valor_mm) < 0);
      if (edad < 18) {
        printf("-RECHAZADO-\n");
        *rechazado = true;
        *puntaje = -1;
      } else {
        *puntaje += edad * MULTIPLICADOR_PARA_PUNTAJE;
      }
      termino = true;
    } else {
      printf("\x1b[91mLa fecha: %d/%d no es válida. Intente nuevamente\x1b[0m\n", valor_yyyy, valor_mm);
    }
  }
}

/*
 * PRE: Tener una variable en donde se quiera almacenar el puntaje obtenido
 * POS: Puntaje obtenido sumado/restado a la variable pasada
 */
void preguntar_sacrificio(int *puntaje) {
  const int MINIMA_ELECCION_VALIDA = 0;
  const int MAXIMA_ELECCION_VALIDA = 12;

  int eleccion = 0;
  bool termino = false;
  while (!termino) {
    printf("\n");
    printf("\x1b[93mIngrese un solo número entero entre %d y %d inclusive\x1b[0m\n", MINIMA_ELECCION_VALIDA, MAXIMA_ELECCION_VALIDA);
    printf("\n");
    printf("¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?\n");
    printf("\n");
    printf("Ingrese aquí su elección \x1b[94m(%d-%d)\x1b[0m: ", MINIMA_ELECCION_VALIDA, MAXIMA_ELECCION_VALIDA);
    scanf(" %d", &eleccion);
    printf("\n");
    if (eleccion < MINIMA_ELECCION_VALIDA || eleccion > MAXIMA_ELECCION_VALIDA) {
      printf("\x1b[91mEl valor: %d no es válido. Intente nuevamente\x1b[0m\n", eleccion);
    } else if (eleccion == 0) {
      *puntaje += -100;
      termino = true;
    } else if (eleccion <= 3) {
      *puntaje += 10;
      termino = true;
    } else if (eleccion <= 6) {
      *puntaje += 40;
      termino = true;
    } else if (eleccion <= 9) {
      *puntaje += 70;
      termino = true;
    } else if (eleccion <= 12) {
      *puntaje += 120;
      termino = true;
    }
  }
}

/*
 * PRE: Tener el puntaje que se quiere evaluar y el array/string/vector en donde se quiere almacenar el resultado
 * POS: El array/string/vector ahora contiene el literal string del resultado
 */
int indice_de_resultado(int puntaje) {
  int indice_de_resultado = 0;
  if (puntaje >= 350) {
    indice_de_resultado = 4;
  } else if (puntaje > 250) {
    indice_de_resultado = 3;
  } else if (puntaje > 150) {
    indice_de_resultado = 2;
  } else if (puntaje > 0) {
    indice_de_resultado = 1;
  } // Si no ha entrado en ningún caso, entonces el puntaje debe ser menor a 0
  return indice_de_resultado;
}

int main() {
  const char RESULTADOS[][MAX_VECTOR_RESULTADO] = {
      "\x1b[91m-RECHAZADO-\x1b[0m",
      "\x1b[93m-ASPIRANTE-\x1b[0m",
      "\x1b[92m-MAGIO NOVATO-\x1b[0m",
      "\x1b[96m-MAGIO-\x1b[0m",
      "\x1b[95m-LIDER SUPREMO-\x1b[0m",
  };

  int puntaje = 0;
  bool rechazado = false;
  mostrar_mensaje_de_bienvenida();
  preguntar_fundador(&puntaje, &rechazado);
  if (!rechazado) {
    preguntar_voto_de_silencio(&puntaje);
    preguntar_nacimiento(&puntaje, &rechazado);
    if (!rechazado) {
      preguntar_sacrificio(&puntaje);
    }
  }
  printf("\n");
  printf("--------------------------------------------------\n");
  printf("\n");
  printf("\x1b[92mLuego de una deliberada discusión...\x1b[0m\n");
  printf("\n");
  printf("\x1b[93mSerás...\x1b[0m\n");
  printf("\n");
  printf("%s\n", RESULTADOS[indice_de_resultado(puntaje)]);
  return 0;
}
