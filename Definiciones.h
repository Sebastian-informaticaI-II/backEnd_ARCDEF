#ifndef DEFINICIONES_H
#define DEFINICIONES_H

enum TipoDeOficial {NAVEGANTE,CANON_MASTER,CARPINTERO};

enum PesoBala {LB_12, LB_18, LB_24, LB_36};

enum TipoBase {BARCO,FORTIN};

enum Bando {ALIADO,ENEMIGO,NEUTRAL};

#define EXPONETE_EXPERIENCIA    3
#define BASE_CALCULO_NIVEL      4
#define NIVEL_BASICO            0
#define EXP_FOR_LEVEL_1         64
#define EXP_INICIAL             0

#define DAMAGE_12_LB            10
#define DAMAGE_18_LB            15
#define DAMAGE_24_LB            20
#define DAMAGE_36_LB            30

#define GRAVEDAD                10
#define PI                      3.14159265
#define ANGULO_PI               180.0

#endif // DEFINICIONES_H
