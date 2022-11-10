/* File         : mesinkar.h */
/* Deskripsi    : Header ADT Mesin Karakter */

#ifndef __MESINKAR__
#define __MESINKAR__

#include "../utility/boolean.h"

#define MARK '.'

extern char cc; // Current Character
extern boolean eof; // End of File

void start();

void adv();

#endif