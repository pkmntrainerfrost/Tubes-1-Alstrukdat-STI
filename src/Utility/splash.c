#include <stdio.h> 
#include "../ADT/boolean.h" 
#include "splash.h"

void splash(int tries, boolean invalidFile) {

    printf("            *#%%(                :::::::::  ::::    ::: ::::    ::::   :::::::: \n");
    printf("/((******/#%%&@@@&%%##((((#       :+:    :+: :+:+:   :+: +:+:+: :+:+:+ :+:    :+:\n");
    printf("*(@(/(((((..............(,      +:+    +:+ :+:+:+  +:+ +:+ +:+:+ +:+ +:+    +:+\n");
    printf("*(/((((((%%...@.......@..(,      +#++:++#+  +#+ +:+ +#+ +#+  +:+  +#+ +#+    +:+\n");
    printf("/(&#&%%#((%%......@#@.....(       +#+    +#+ +#+  +#+#+# +#+       +#+ +#+    +#+\n");
    printf("/(&&&/(((&..............(       #+#    #+# #+#   #+#+# #+#       #+# #+#    #+#\n");
    printf("/(@&&&((((@@&%%(((((((&&((       #########  ###    #### ###       ###  ######## \n");
    printf("/(((%%&(/(((((((((((((((((                                                      \n");
    printf("%%((%%&&/((((&***((((%%,((((       18220010 - Agnes Tamara Putri\n");
    printf("&(&/*&/(((((((((((((&##@(&      18221102 - Salman Ma'arif Achsien\n");
    printf("(((**#(((((((((#((&((&(( **@    18221122 - Reswara Trista Aulia C\n");
    printf("    &&**(((((((((&(((#&( &(.&   18221166 - Erensi Ratu Chelsia\n");
    printf("         *& /#(((((             18221168 - Rania Sasi Kirana\n");
    printf("\n");
    printf("- Tugas Besar 1 IF2111 Algoritma dan Struktur Data STI - Kelompok 06 Kelas 02 -\n");
    printf("\n");
    selamatDatang(tries, invalidFile);
    printf("INPUT [START] ATAU [LOAD <FILENAME>]...\n");
    printf("root@BNMO:~$ ");
    
}

void selamatDatang(int tries, boolean invalidFile) {

    if (tries == 0) {
        printf("Selamat Datang di BNMO!\n");
    } else if (tries < 10) {
        printf("Command tidak valid! Mohon ulangi input...\n");
    } else if (invalidFile) {
        printf("File tidak ditemukan di folder data! Mohon ulangi input...\n");
    } else {
        printf("Melihatmu sudah gagal menginput perintah sebanyak ini, BNMO tertawa kecil.\n");
    }
    

}

//             *#%(                :::::::::  ::::    ::: ::::    ::::   ::::::::  
// /((******/#%&@@@&%##((((#       :+:    :+: :+:+:   :+: +:+:+: :+:+:+ :+:    :+:
// *(@(/(((((..............(,      +:+    +:+ :+:+:+  +:+ +:+ +:+:+ +:+ +:+    +:+
// *(/((((((%...@.......@..(,      +#++:++#+  +#+ +:+ +#+ +#+  +:+  +#+ +#+    +:+ 
// /(&#&%#((%......@#@.....(       +#+    +#+ +#+  +#+#+# +#+       +#+ +#+    +#+ 
// /(&&&/(((&..............(       #+#    #+# #+#   #+#+# #+#       #+# #+#    #+# 
// /(@&&&((((@@&%(((((((&&((       #########  ###    #### ###       ###  ########
// /(((%&(/(((((((((((((((((      
// %((%&&/((((&***((((%,((((       18220010 - Agnes Tamara Putri
// &(&/*&/(((((((((((((&##@(&      18221102 - Salman Ma'arif Achsien
// (((**#(((((((((#((&((&(( **@    18221122 - Reswara Trista Aulia C
//     &&**(((((((((&(((#&( &(.&   18221166 - Erensi Ratu Chelsia
//          *& /#(((((             18221168 - Rania Sasi Kirana
//
// - Tugas Besar 1 IF2111 Algoritma dan Struktur Data STI - Kelompok 06 Kelas 02 -
// 
// Selamat Datang di BNMO!
// INPUT [START] ATAU [LOAD]...
// root@BNMO:~$ 