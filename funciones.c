#include <stdio.h>
#include <string.h>
#include "funciones.h"


void leerDatos(Zona zonas[]) {
    for (int i = 0; i < ZONAS; i++) {
        printf("\nIngrese el Nombre de la Zona %d:\n", i + 1);
        fgets(zonas[i].nombre, sizeof(zonas[i].nombre), stdin);
        size_t len = strlen(zonas[i].nombre);
        if (len > 0 && zonas[i].nombre[len - 1] == '\n') {
        zonas[i].nombre[len - 1] = '\0';
}
        do {
            printf("Nivel actual de contaminacion: ");
            scanf("%f", &zonas[i].nivelesActuales);
            if (zonas[i].nivelesActuales < 0 || zonas[i].nivelesActuales > 100) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].nivelesActuales < 0 || zonas[i].nivelesActuales > 100);

        printf("Datos de contaminacion (ultimos %d dias):\n", DIAS_HISTORICOS);
        for (int j = 0; j < DIAS_HISTORICOS; j++) {
            do {
                printf("Dia %d: ", j + 1);
                scanf("%f", &zonas[i].historicos[j]);
                if (zonas[i].historicos[j] < 0 || zonas[i].historicos[j] > 100) {
                    printf("Error: ingrese un numero entre 0 y 100.\n");
                }
            } while (zonas[i].historicos[j] < 0 || zonas[i].historicos[j] > 100);
        }

        do {
            printf("Temperatura (C): ");
            scanf("%f", &zonas[i].temperatura);
            if (zonas[i].temperatura < -10 || zonas[i].temperatura > 100) {
                printf("Error: ingrese un numero entre -10 y 100.\n");
            }
        } while (zonas[i].temperatura < -10 || zonas[i].temperatura > 100);

        do {
            printf("Velocidad del viento (m/s): ");
            scanf("%f", &zonas[i].velocidadViento);
            if (zonas[i].velocidadViento < 0 || zonas[i].velocidadViento > 100) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].velocidadViento < 0 || zonas[i].velocidadViento > 100);

        do {
            printf("Humedad relativa (%%): ");
            scanf("%f", &zonas[i].humedad);
            if (zonas[i].humedad < 0 || zonas[i].humedad > 100) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].humedad < 0 || zonas[i].humedad > 100);

        do {
            printf("Contribucion del trafico (%%): ");
            scanf("%f", &zonas[i].contribucionTrafico);
            if (zonas[i].contribucionTrafico < 0 || zonas[i].contribucionTrafico > 100) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].contribucionTrafico < 0 || zonas[i].contribucionTrafico > 100);

        do {
            printf("Contribucion de las industrias (%%): ");
            scanf("%f", &zonas[i].contribucionIndustrias);
            if (zonas[i].contribucionIndustrias < 0 || zonas[i].contribucionIndustrias > 100) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].contribucionIndustrias < 0 || zonas[i].contribucionIndustrias > 100);

        do {
            printf("Nivel actual de CO2 (ppm): ");
            scanf("%f", &zonas[i].nivelesCO2);
            if (zonas[i].nivelesCO2 < 0 || zonas[i].nivelesCO2 > 500) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].nivelesCO2 < 0 || zonas[i].nivelesCO2 > 500);

        do {
            printf("Nivel actual de NO2 (ppb): ");
            scanf("%f", &zonas[i].nivelesNO2);
            if (zonas[i].nivelesNO2 < 0 || zonas[i].nivelesNO2 > 100) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].nivelesNO2 < 0 || zonas[i].nivelesNO2 > 100);

        do {
            printf("Nivel actual de SO2 (ppb): ");
            scanf("%f", &zonas[i].nivelesSO2);
            if (zonas[i].nivelesSO2 < 0 || zonas[i].nivelesSO2 > 100) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].nivelesSO2 < 0 || zonas[i].nivelesSO2 > 100);

        do {
            printf("Nivel actual de PM2.5 (ug/m3): ");
            scanf("%f", &zonas[i].nivelesPM25);
            if (zonas[i].nivelesPM25 < 0 || zonas[i].nivelesPM25 > 100) {
                printf("Error: ingrese un numero entre 0 y 100.\n");
            }
        } while (zonas[i].nivelesPM25 < 0 || zonas[i].nivelesPM25 > 100);
    }
}

void mostrarRangosModerados() {
    printf("\nRangos Moderados de Contaminacion y Condiciones Ambientales:\n");
    printf("CO2 (ppm): %.2f - %.2f\n", MODERADO_CO2_MIN, MODERADO_CO2_MAX);
    printf("NO2 (ppb): %.1f - %.1f\n", MODERADO_NO2_MIN, MODERADO_NO2_MAX);
    printf("SO2 (ppb): %.1f - %.1f\n", MODERADO_SO2_MIN, MODERADO_SO2_MAX);
    printf("PM2.5 (ug/m3): %.1f - %.2f\n", MODERADO_PM25_MIN, MODERADO_PM25_MAX);
    printf("Temperatura (C): %.1f - %.2f\n", MODERADO_TEMPERATURA_MIN, MODERADO_TEMPERATURA_MAX);
    printf("Humedad Relativa (%%): %.1f - %.1f\n", MODERADO_HUMEDAD_MIN, MODERADO_HUMEDAD_MAX);
    printf("Velocidad del Viento (m/s): %.1f - %.1f\n", MODERADO_VIENTO_MIN, MODERADO_VIENTO_MAX);
}


void calcularPromedios(Zona zonas[]) {
    for (int i = 0; i < ZONAS; i++) {
        float suma = 0;
        for (int j = 0; j < DIAS_HISTORICOS; j++) {
            suma += zonas[i].historicos[j];
        }
        printf("\nPromedio de contaminacion en la zona '%s': %.2f\n", 
               zonas[i].nombre, suma / DIAS_HISTORICOS);
    }
}

void predecirContaminacion(Zona zonas[], float predicciones[]) {
    for (int i = 0; i < ZONAS; i++) {
        predicciones[i] = zonas[i].nivelesActuales * 1.05; // Prediccion simple: +5% sobre nivel actual
        printf("\nPrediccion de contaminacion para la zona '%s': %.2f\n", 
               zonas[i].nombre, predicciones[i]);
    }
}

void emitirAlertas(Zona zonas[], float predicciones[]) {
    for (int i = 0; i < ZONAS; i++) {
        if (predicciones[i] > MAX_PM25) {
            printf("\n*** Alerta ***: Zona peligrosa '%s' (%.2f)\n", 
                   zonas[i].nombre, predicciones[i]);
        }
    }
}

void generarRecomendaciones(Zona zonas[], float predicciones[]) {
    for (int i = 0; i < ZONAS; i++) {
        if (predicciones[i] > LIMITE_PM25) {
            printf("\nRecomendaciones para la zona '%s':\n", zonas[i].nombre);
            printf("- Reducir el uso de vehiculos motorizados.\n");
            printf("- Promover el trabajo remoto.\n");
            printf("- Evitar actividades al aire libre.\n");
        } else {
            printf("\nZona '%s': Zona dentro de niveles aceptables.\n", zonas[i].nombre);
        }
    }
}

void evaluarCondiciones(Zona zonas[]) {
    for (int i = 0; i < ZONAS; i++) {
        printf("\nEvaluando condiciones en la zona '%s':\n", zonas[i].nombre);

        int bajaPosibilidad = 1;

        // Validación de CO2
        if (zonas[i].nivelesCO2 > MaxLIMITE_CO2) {
            printf("- Niveles de CO2 demasiado altos.\n");
            bajaPosibilidad = 0;
        } else if (zonas[i].nivelesCO2 < MODERADO_CO2_MIN) {
            printf("- Los datos ingresados de CO2 son bajos al rango moderado.\n");
        }

        // Validación de NO2
        if (zonas[i].nivelesNO2 > MaxLIMITE_NO2) {
            printf("- Niveles de NO2 demasiado altos.\n");
            bajaPosibilidad = 0;
        } else if (zonas[i].nivelesNO2 < MODERADO_NO2_MIN) {
            printf("- Los datos ingresados de NO2 son bajos al rango moderado.\n");
        }

        // Validación de SO2
        if (zonas[i].nivelesSO2 > MaxLIMITE_SO2) {
            printf("- Niveles de SO2 demasiado altos.\n");
            bajaPosibilidad = 0;
        } else if (zonas[i].nivelesSO2 < MODERADO_SO2_MIN) {
            printf("- Los datos ingresados de SO2 son bajos al rango moderado.\n");
        }

        // Validación de PM2.5
        if (zonas[i].nivelesPM25 > MAX_PM25) {
            printf("- Niveles de PM2.5 demasiado altos.\n");
            bajaPosibilidad = 0;
        } else if (zonas[i].nivelesPM25 < MODERADO_PM25_MIN) {
            printf("- Los datos ingresados de PM2.5 son bajos al rango moderado.\n");
        }

        // Validación de Humedad
        if (zonas[i].humedad < MODERADO_HUMEDAD_MIN || zonas[i].humedad > MODERADO_HUMEDAD_MAX) {
            printf("- Humedad fuera del rango ideal (40-70%%).\n");
            bajaPosibilidad = 0;
            
        } else if (zonas[i].humedad < MODERADO_HUMEDAD_MIN) {
            printf("- Los datos ingresados de humedad son bajos al rango moderado.\n");
        }

        // Validación de Temperatura
        if (zonas[i].temperatura < MODERADO_TEMPERATURA_MIN || zonas[i].temperatura > MODERADO_TEMPERATURA_MAX) {
            printf("- Temperatura fuera del rango ideal (15-25 C).\n");
            bajaPosibilidad = 0;
        } else if (zonas[i].temperatura < MODERADO_TEMPERATURA_MIN) {
            printf("- Los datos ingresados de temperatura son bajos al rango moderado.\n");
        }

        // Validación de Velocidad del Viento
        if (zonas[i].velocidadViento < MODERADO_VIENTO_MIN || zonas[i].velocidadViento > MODERADO_VIENTO_MAX) {
            printf("- Velocidad del viento fuera del rango ideal (3.0-10.0 nudos).\n");
            bajaPosibilidad = 0;
        } else if (zonas[i].velocidadViento < MODERADO_VIENTO_MIN) {
            printf("- Los datos ingresados de velocidad del viento son bajos al rango moderado.\n");
        }

        // Evaluación final
        if (bajaPosibilidad) {
            printf("-> La zona '%s' esta en un rango moderado.\n", zonas[i].nombre);
        } else {
            printf("-> La zona '%s' presenta condiciones desfavorables.\n", zonas[i].nombre);
        }
    }
}
void exportarDatos(Zona zonas[], float predicciones[]) {
    FILE *archivo = fopen("reporte_contaminacion.txt", "w");
    if (archivo == NULL) {
        printf("\nError al crear el archivo de reporte.\n");
        return;
    }

    fprintf(archivo, "Reporte de Contaminacion Ambiental\n");
    fprintf(archivo, "==============================================================\n\n");
    for (int i = 0; i < ZONAS; i++) {
        fprintf(archivo, "Zona: %s\n", zonas[i].nombre);
        fprintf(archivo, "Nivel actual: %.2f\n", zonas[i].nivelesActuales);
        fprintf(archivo, "Prediccion: %.2f\n\n", predicciones[i]);
        fprintf(archivo, "\nRangos de Contaminacion y Condiciones Ambientales:\n");
        fprintf(archivo,"NO2 (ppb): %.2f\n", zonas[i].nivelesNO2);
        fprintf(archivo,"SO2 (ppb): %.2f\n",zonas[i].nivelesSO2);
        fprintf(archivo,"PM2.5 (ug/m3): %.2f\n",zonas[i].nivelesPM25 );
        fprintf(archivo,"Temperatura (C): %.2f\n",zonas[i].temperatura );
        fprintf(archivo,"Humedad Relativa (%%): %.2f\n",zonas[i].humedad );
        fprintf(archivo,"Velocidad del Viento (m/s): %.2f\n",zonas[i].velocidadViento);
        fprintf(archivo, "================================================================\n");
    }

    fclose(archivo);
    printf("\nReporte exportado exitosamente a 'reporte_contaminacion.txt'.\n");
}