#set page(paper: "a4", margin: 2cm)
#set text(font: "Georgia", size: 11pt, lang: "es")

#show heading.where(level: 1): it => block(width: 100%, below: 1em)[
  #set align(center)
  #set text(size: 1.5em, weight: "bold", fill: navy)
  #it.body
]

#show heading.where(level: 2): it => block(width: 100%, above: 1.5em, below: 1em)[
  #set text(size: 1.2em, weight: "semibold", fill: rgb("#2a3f5f"))
  #it.body
  #v(-0.5em)
  #line(length: 100%, stroke: 0.5pt + gray)
]

// --- Documento ---

= TP0: Prueba de Iniciación de los Magios

#grid(
  columns: (1fr, 1fr),
  align: (left, right),
  [ *Materia:* Fundamentos de la Programación 1C2026 ],
  [ *Fecha Entrega:* 26 de Marzo, 2026 ]
)

== 1. Introducción y Objetivo
El objetivo de este trabajo práctico es implementar un programa en C (`magios.c`) que evalúe la aptitud de un aspirante para ingresar a la sociedad secreta de los Magios. Se pondrán a prueba los conocimientos básicos de:
- Validación de datos y estructuras de control (bucles y condicionales).
- Modularización (uso de funciones) y buenas prácticas (constantes, nombres descriptivos).
- Manejo de tipos de datos simples y comunicación por consola.

== 2. Especificaciones Técnicas
- *Archivo:* `magios.c`
- *Compilación:* `gcc magios.c -Wall -Werror -Wconversion -std=c99 -o magios`
- *Validación:* Si un dato es inválido, se debe re-preguntar hasta que sea correcto. No es necesario validar tipos de datos (asumir que si se pide un `int`, se ingresará un número).

== 3. El Ritual (Preguntas)

*P1: Fundador de Springfield*
- *Opciones:* [J] Jebediah, [A] Aliens, [S] Magios, [B] Sr. Burns.
- *Regla:* Solo se aceptan mayúsculas. El usuario tiene *3 intentos máximo*. 
- *Puntaje:* +100 si acierta. Cada fallo en una opción válida resta 20 pts. Si agota intentos, finalizar inmediatamente como `-RECHAZADO-`.

*P2: El Secreto*
- *Pregunta:* "¿Promete mantener en secreto la existencia de los Magios?" [S/N].
- *Almacenamiento:* Debe guardarse obligatoriamente en una variable `bool`.
- *Puntaje:* S (+50) / N (-300).

*P3: Fecha de Nacimiento*
- *Formato:* `yyyy/mm` (ej. `1998/4`).
- *Validaciones:* Año de 4 dígitos (mínimo 1926), mes entre 1 y 12. La fecha no puede ser posterior a `2026/03`.
- *Regla:* Calcular edad (Referencia: `2026/03`). Si es menor de 18 años, finalizar como `-RECHAZADO-`.
- *Puntaje:* `edad * 2`.

*P4: Sacrificio de Donas*
- *Rango:* Entero entre 0 y 12.
- *Puntaje:* Según la cantidad (0: -100 | 1-3: +10 | 4-6: +40 | 7-9: +70 | 10-12: +120).

#pagebreak()

== 4. Tabla de Rangos Finales
El puntaje final es la suma de los puntos de cada sección.

#align(center)[
  #table(
    columns: (auto, auto),
    inset: 10pt,
    fill: (x, y) => if y == 0 { silver } else { white },
    [*Puntaje*], [*Resultado*],
    [Menor a 0], [-RECHAZADO-],
    [0 a 150], [-ASPIRANTE-],
    [151 a 250], [-MAGIO NOVATO-],
    [251 a 349], [-MAGIO-],
    [350 o más], [-LIDER SUPREMO-],
  )
]

== 5. Entrega y Evaluación
La entrega se realiza vía *AlgoTrón* en un archivo `.zip` que contenga únicamente `magios.c`. La etiqueta `¡Éxito!` es necesaria para la revisión manual, donde se evaluará la calidad del código, la ausencia de variables globales y el uso correcto de pre/post condiciones.
