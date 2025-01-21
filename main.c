#include <stdio.h>
#include "funciones.h"

int main() {
    Zona zonas[ZONAS];
    float predicciones[ZONAS];

    leerDatos(zonas);
    calcularPromedios(zonas);
    predecirContaminacion(zonas, predicciones);
    emitirAlertas(zonas, predicciones);
    generarRecomendaciones(zonas, predicciones);
    evaluarCondiciones(zonas);
    exportarDatos(zonas, predicciones);

    mostrarRangosModerados();

    return 0;
}
