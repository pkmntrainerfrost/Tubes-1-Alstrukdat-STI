/* FILE         : word.h */
/* DESKRIPSI    : Header ADT Word (pengganti string) */

#ifndef __WORD__
#define __WORD__

#include "../boolean.h"
#define N_MAX 64
#define BLANK ' '

typedef struct {
    char buffer[N_MAX];
    int length;
} Word;

#define wordLength(w) (w).length

#define INVALID_INT -0xDEADBEEF

/* Membuat kata kosong dengan panjang 0 */
void createWord(Word *w);

/* Menggabung w1 dan w2 dan menyimpannya di w3 */
void concateWord(Word w1, Word w2, Word *w3);

/* Menggabung w1 dan w2 dan menyimpannya di w3 */
void copyWord(Word w1, Word *w2);

/* Merubah sebuah integer menjadi sebuah word */
Word intToWord(int i);

/* Merubah sebuah string menjadi sebuah word */
Word stringToWord(char *s);

/* Merubah sebuah kata menjadi suatu integer, apabila word bukan integer yang valid maka akan mengembalikan INT_INVALID */
int wordToInt(Word w);

/* Merubah sebuah word menjadi suatu string dan menyimpannya di s. PENTING: DEFINISIKAN S TERLEBIH DAHULU DENGAN KAPASITAS WORDLENGTH + 1 */
void wordToString(Word w, char *s);

/* Mengecek apakah dua buah kata merupakan kata yang sama */
boolean isWordEqual(Word w1, Word w2);

/* Mencetak sebuah word ke layar */
void printWord(Word w);

#endif