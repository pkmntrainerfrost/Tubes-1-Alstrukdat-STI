# **BNMO**

Tugas Besar Alstrukdat IF2110

Game console kesayangan Indra dan Doni, BNMO, setelah rusak dan diperbaiki oleh teknisi, memunculkan banyak bug dalam game mereka. Tugas kamu adalah memperbaiki program BNMO mereka agar mereka bisa kembali memainkan game kesayangan mereka.

BNMO merupakan suatu robot game console yang diprogram menggunakan bahasa C, dengan game-game didalamnya merupakan permainan berbasis CLI (Command Line Interface). Program ini memanfaatkan berbagai struktur data, diantaranya adalah list/array, mesin karakter, mesin kata, queue, point, dan juga grid. Program pada BNMO dapat digunakan untuk memainkan game, menambahkan game, menghapus game, dan juga mengurutkan game yang akan dimainkan.  

### Anggota Kelompok
| Nama | NIM |
| :----------- |  :----------: |
| Agnes Tamara Putri | 18220010 |
| Salman Ma'arif Achsien | 18221102 |
| Reswara Trista Aulia C. | 18221122 |
| Erensi Ratu Chelsia | 18221166 |
| Rania Sasi Kirana | 18221168 |

### Kompilasi Program

```
│   .gitignore
│   README.md
|   main.c
│
├───.vscode
|       Makefile
│       settings.json
│
├───config
│       config.txt
│
├───Doc
│
└───src
        ├───ADT
        |   │   boolean.h
        |   │
        |   ├───list
        |   │       driverArray.c
        |   │       array.c
        |   │       array.h
        |   │
        |   ├───point
        |   │       driverPoint.c
        |   │       point.c
        |   │       point.h
        |   │
        |   ├───queue
        |   |       driverPrioqueue.c
        |   │       driverQueue2.c
        |   │       prioqueue.c
        |   |       prioqueue.h
        |   │       queue2.c
        |   │       queue2.h
        |   │
        |   └───word
        |         |   driverWord.c
        |         |   driverWord.exe
        |         |   word.c
        |         |   word.h
        |         |
        |         ├───mesinkarakter
        |         |       driver.c
        |         |       driver.exe
        |         |       mesinkarakter.c
        |         |       mesinkarakter.h
        |         |       test.txt
        |         |
        |         └───mesinkata
        |                 driver.c
        |                 driver.exe
        |                 mesinkata.c
        |                 mesinkata.h
        |                 test.txt
        |       
        ├───Games
        |   │   random.c
        |   |   random.exe
        |   |   random.h
        |   │
        |   ├───battleship
        |   │       battleship.c
        |   │       battleship.h
        |   │
        |   ├───dinerdash
        |   │       dinerdash.c
        |   │       dinerdash.h
        |   │
        |   └───rng
        |           rng.c
        |           rng.h
        |
        ├───Misc
        |   │   .DS_Store
        |   │
        |   ├───ascii
        |   │       ascii.c
        |   │       ascii.h
        |   │
        |   └───io
        |           colors.h
        |           io.c
        |           io.h
        |
        └───Utility
            │   splash.c
            |   splash.h
            │
            ├───commandlain
            │       commandlain.c
            │       commandlain.h
            │
            ├───creategame
            │       createGame.c
            │       createGame.h
            │
            ├───deleteGame
            │       deleteGame.c
            │       deleteGame.h
            │
            ├───help
            │       help.c
            │       help.h
            │
            ├───listGame
            │       listGame.c
            │       listGame.h
            │
            ├───load
            │       load.c
            │       load.h
            │
            ├───playGame
            │       playGame.c
            │       playGame.h
            │
            ├───creategame
            │       createGame.c
            │       createGame.h
            │
            ├───queuegame
            │       queueGame.c
            │       queueGame.h
            │
            ├───quit
            │       quit.c
            │       quit.h
            │
            ├───save
            │       save.c
            │       save.h
            │
            ├───skipGame
            │       skipGame.c
            │       skipGame.h
            │
            └───start
                    start.c
                    start.h     
          
```

### Struktur Program

