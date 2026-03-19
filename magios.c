#include <stdio.h>

#define MAX_VECTOR_RESULTADO 16

void mensaje_bienvenida() {
  printf("Hola aspirante! Preparado para comenzar tu prueba de iniciación?\n");
}

void preguntar_fundador(int *puntaje) {
  char eleccion = 0;
  int intentos = 3;
  char termino = 0;
  while (!termino) {
    if (intentos > 0) {
      printf("¿Quién fundó realmente Springfield?\n");
      printf(
          "Elija una de las opciones ingresando solo una de las letras entre "
          "[].\n");
      printf("Número de intentos restantes: %d\n", intentos);
      printf("[J] Jebediah Springfield\n");
      printf("[A] Los aliens\n");
      printf("[S] Los Magios\n");
      printf("[B] Sr. Burns\n");
      scanf(" %c", &eleccion);
      if (eleccion == 'J' || eleccion == 'A' || eleccion == 'S' ||
          eleccion == 'B') {
        if (eleccion == 'J') {
          *puntaje += 100;
          termino = 1;
        } else {
          *puntaje -= 20;
          printf("La opción %c no es la correcta. Intente nuevamente\n",
                 eleccion);
          intentos--;
        }
      } else {
        printf("La opción: %c no está entre las válidas. Intente nuevamente\n",
               eleccion);
      }
    } else {
      printf("-RECHAZADO-\n");
      termino = 1;
    }
  }
}

void preguntar_voto_de_silencio(int *puntaje) {
  char eleccion = 0;
  char termino = 0;
  while (!termino) {
    printf("¿Promete mantener en secreto la existencia de los Magios?\n");
    printf("Elija una de las opciones ingresando solo una de las letras entre "
           "[].\n");
    printf("[S] Sí\n");
    printf("[N] No\n");
    scanf(" %c", &eleccion);
    if (eleccion == 'S') {
      *puntaje += 50;
      termino = 1;
    } else if (eleccion == 'N') {
      *puntaje += -300;
      termino = 1;
    } else {
      printf("La opción: %c no está entre las válidas. Intente nuevamente\n",
             eleccion);
    }
  }
}

void preguntar_nacimiento(int *puntaje) {
  const int VALOR_YYYY_ACTUAL = 2026;
  const int VALOR_MM_ACTUAL = 3;
  int valor_yyyy = -1;
  int valor_mm = -1;
  int edad = -1;
  char termino = 0;
  while (!termino) {
    printf("¿Cuál es su fecha de nacimiento?\n");
    printf("Ingrese su fecha de nacimiento respetando el siguiente formato:\n");
    printf("yyyy/mm\tSiendo yyyy el año, y mm, el mes. Ej: 2006/3\n");
    printf(
        "La fecha ingresada debe ser posterior al 1926/3 o no sera aceptada\n");
    scanf(" %d/%d", &valor_yyyy, &valor_mm);
    if ((valor_yyyy > 1926 || (valor_yyyy == 1926 && valor_mm > 3)) &&
        valor_mm >= 1 && valor_mm <= 12) {
      edad =
          VALOR_YYYY_ACTUAL - valor_yyyy + ((VALOR_MM_ACTUAL - valor_mm) >= 0);
      if (edad < 18) {
        printf("-RECHAZADO-\n");
      }
      termino = 1;
    } else {
      printf("La fecha %d/%d no es válida. Intente nuevamente\n", valor_yyyy,
             valor_mm);
    }
  }
}

void preguntar_sacrificio(int *puntaje) {
  int eleccion = 0;
  char termino = 0;
  while (!termino) {
    printf(
        "¿Cuántas donas estaría dispuesto a sacrificar para el Número Uno?\n");
    printf("Ingrese un solo número entero entre 0 y 12 inclusive\n");
    scanf(" %d", &eleccion);
    if (eleccion < 0 || eleccion > 12) {
      printf("El valor ingresado no es válido. Intente nuevamente\n");
    } else if (eleccion == 0) {
      *puntaje += -100;
      termino = 1;
    } else if (eleccion <= 3) {
      *puntaje += 10;
      termino = 1;
    } else if (eleccion <= 6) {
      *puntaje += 40;
      termino = 1;
    } else if (eleccion <= 9) {
      *puntaje += 70;
      termino = 1;
    } else if (eleccion <= 12) {
      *puntaje += 120;
      termino = 1;
    }
  }
}

void mi_strcpy(char *destino, const char *origen) {
  int indice_actual = 0;
  while (origen[indice_actual] != '\0') {
    destino[indice_actual] = origen[indice_actual];
    indice_actual++;
  }
}

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
  // preguntar_fundador(&puntaje);
  // preguntar_voto_de_silencio(&puntaje);
  preguntar_nacimiento(&puntaje);
  // preguntar_sacrificio(&puntaje);
  obtener_resultado(puntaje, resultado);
  printf(
      "Luego de una deliberada discusión, hemos decidido que su estado es:\n");
  printf("%s\n", resultado);
  return 0;
}
