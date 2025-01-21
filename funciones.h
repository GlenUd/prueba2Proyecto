#define ZONAS 5  // Cambiamos de 2 a 5
#define DIAS_HISTORICOS 4
#define LIMITE_PM25 0.0
#define MAX_PM25 35.0
#define LIMITE_CO2 350.0
#define MaxLIMITE_CO2 450.0
#define LIMITE_SO2 0.0
#define MaxLIMITE_SO2 20.0
#define LIMITE_NO2 0.0
#define MaxLIMITE_NO2 50.0
#define MODERADO_CO2_MIN 350.0
#define MODERADO_CO2_MAX 450.0
#define MODERADO_NO2_MIN 0.0
#define MODERADO_NO2_MAX 50.0
#define MODERADO_SO2_MIN 0.0
#define MODERADO_SO2_MAX 20.0
#define MODERADO_PM25_MIN 0.0
#define MODERADO_PM25_MAX 35.0
#define MODERADO_TEMPERATURA_MIN 15.0
#define MODERADO_TEMPERATURA_MAX 25.0
#define MODERADO_HUMEDAD_MIN 40.0
#define MODERADO_HUMEDAD_MAX 70.0
#define MODERADO_VIENTO_MIN 3.0
#define MODERADO_VIENTO_MAX 10.0
#define MODERADO_CONTAMINACION_MIN 10.0
#define MODERADO_CONTAMINACION_MAX 100.0

struct Zona {
    char nombre[50];
    float nivelesActuales;
    float historicos[DIAS_HISTORICOS];
    float temperatura;
    float velocidadViento;
    float humedad;
    float contribucionTrafico;
    float contribucionIndustrias;
    float nivelesCO2;
    float nivelesNO2;
    float nivelesSO2;
    float nivelesPM25;
};

typedef struct Zona Zona;

void leerDatos(Zona zonas[]);
void calcularPromedios(Zona zonas[]);
void predecirContaminacion(Zona zonas[], float predicciones[]);
void emitirAlertas(Zona zonas[], float predicciones[]);
void generarRecomendaciones(Zona zonas[], float predicciones[]);
void evaluarCondiciones(Zona zonas[]);
void exportarDatos(Zona zonas[], float predicciones[]);
void mostrarRangosModerados();