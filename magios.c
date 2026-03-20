#include <stdbool.h>
#include <stdio.h>

#define MAX_VECTOR_RESULTADO 16

/*
 * PRE: -
 * POS: Mensaje de bienvenida mostrado al usuario
 */
void mensaje_bienvenida() {
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
void preguntar_fundador(int *puntaje) {
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
          *puntaje -= PUNTAJE_SI_ERRA;
          printf("\x1b[91mLa opción %c no es la correcta. Intente nuevamente\x1b[0m\n", eleccion);
          intentos_restantes--;
        }
      } else {
        printf("\x1b[91mLa opción: %c no está entre las válidas. Intente nuevamente\x1b[0m\n", eleccion);
      }
    } else {
      printf("-RECHAZADO-\n");
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
void preguntar_nacimiento(int *puntaje) {
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
    printf("Ïngrese la fecha \x1b[94m(yyyy/mm)\x1b[0m aquí: ");
    scanf(" %d/%d", &valor_yyyy, &valor_mm);
    printf("\n");
    if (valor_mm >= 1 && valor_mm <= 12 && (valor_yyyy > 1926 || (valor_yyyy == 1926 && valor_mm > 3)) && (valor_yyyy < 2026 || (valor_yyyy == 2026 && valor_mm <= 3))) {
      edad = VALOR_YYYY_ACTUAL - valor_yyyy + ((VALOR_MM_ACTUAL - valor_mm) >= 0);
      if (edad < 18) {
        printf("-RECHAZADO-\n");
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
  int eleccion = 0;
  bool termino = false;
  while (!termino) {
    printf("\n");
    printf("\x1b[93mIngrese un solo número entero entre 0 y 12 inclusive\x1b[0m\n");
    printf("\n");
    printf("¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?\n");
    printf("\n");
    printf("Ingrese aquí su elección \x1b[94m(0-12)\x1b[0m: ");
    scanf(" %d", &eleccion);
    printf("\n");
    if (eleccion < 0 || eleccion > 12) {
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
 * PRE: Tener un array/string/vector en donde se quiera mover un literal string
 * POS: El array/string/vector ahora contiene el literal string + un \0 (null) al final
 */
void mi_strcpy(char *destino, const char *origen) {
  int indice_actual = 0;
  while (origen[indice_actual] != '\0') {
    destino[indice_actual] = origen[indice_actual];
    indice_actual++;
  }
}

/*
 * PRE: Tener el puntaje que se quiere evaluar y el array/string/vector en donde se quiere almacenar el resultado
 * POS: El array/string/vector ahora contiene el literal string del resultado
 */
void obtener_resultado(int puntaje, char *resultado) {
  if (puntaje < 0) {
    mi_strcpy(resultado, "-RECHAZADO-");
  } else if (puntaje <= 150) {
    mi_strcpy(resultado, "-ASPIRANTE-");
  } else if (puntaje <= 250) {
    mi_strcpy(resultado, "-MAGIO NOVATO-");
  } else if (puntaje <= 349) {
    mi_strcpy(resultado, "-MAGIO-");
  } else {
    mi_strcpy(resultado, "-LIDER SUPREMO-");
  }
}

int main() {
  int puntaje = 0;
  char resultado[MAX_VECTOR_RESULTADO] = {0};
  mensaje_bienvenida();
  preguntar_fundador(&puntaje);
  preguntar_voto_de_silencio(&puntaje);
  preguntar_nacimiento(&puntaje);
  preguntar_sacrificio(&puntaje);
  obtener_resultado(puntaje, resultado);
  printf("\n");
  printf("--------------------------------------------------\n");
  printf("\n");
  printf("\x1b[92mLuego de una deliberada discusión...\x1b[0m\n");
  printf("\n");
  printf("\x1b[93mSeras...\x1b[0m\n");
  printf("\n");
  printf("%s\n", resultado);
  return 0;
}
