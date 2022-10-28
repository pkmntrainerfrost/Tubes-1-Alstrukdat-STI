/* File         : mesinkar.h */
/* Deskripsi    : Header ADT Mesin Karakter */

#ifndef __MESIN_KAR__
#define __MESIN_KAR__

#include "../boolean.h"

#define MARK '.'

extern char cc; // Current Character
extern boolean eof; // End of File

void start();

void adv();

#endif