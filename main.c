#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* struct itu untuk membuat tipe data, jadi disini kita membuat tipe data Mahasiswa*/
struct Mahasiswa{
    int npm;
    int nilai;
};
/* trus dipake disini,
karena kita akan menginput 10 mahasiswa dalam program kita,
karena mereka punya data yang sama, biar gampang pengolahannya kita buat tipe datanya  */
struct Mahasiswa mahasiswa[10],sortingMahasiswa[10];

/* selected menu dibawa ini untuk menu yang nnti dipilih user */
int selectedMenu = -2;
int selectedMenuSorting = -2;

/* kenapa nilainya semua -2, lupa:v. pokonya kayak buat basenya gitu lah/defaultnya */
int cariNpm = -2;

/* kita buat deklarasi fungsi diatas, nanti isinya di paling bawah */
void inputNilaiMahasiswa();
void cariNilaiMahasiswa();
void sortingNilaiMahasiswaASC();
void sortingNilaiMahasiswaDESC();

/* kenapa dibuat fungsi, biar di int main() nya gk acak acakan banget, walopun disini udh acak acakan sih:v */

int main()
{
    /* pakai while selectedMenu!=4 biar looping terus sampe user input 4 di pilihan menu, yaitu exit*/
    while(selectedMenu!=4){
        system("cls");
        printf("Program data Mahasiswa\n");
        printf("Created by: Muchlish Choeruddin\n");
        printf("NPM: 0619204001\n\n");
        printf("Menu:\n");
        printf("    1. Input nilai mahasiswa\n");
        printf("    2. Searching\n");
        printf("    3. Sorting\n");
        printf("    4. Exit\n\n");

        printf("Pilih menu: ");
        scanf("%d",&selectedMenu);

        /* pake switch buat kondisi user pilih apa nih */
        switch(selectedMenu){
            case 1:
                /* kalo pilih input nilai, runing fungsi input nilai mahasiswa yang ada dibawah dan udh
                di deklarasiin diatas */
                inputNilaiMahasiswa();
                break;
            case 2:
                cariNilaiMahasiswa();
                break;
            case 3:
                printf("Sorting mahasiswa berdasar:\n");
                printf("    1. Besar ke kecil\n");
                printf("    2. Kecil ke besar\n\n");

                printf("Pilih menu: ");
                scanf("%d",&selectedMenuSorting);
                if(selectedMenuSorting==1){
                    sortingNilaiMahasiswaDESC();
                }else if(selectedMenuSorting==2){
                    sortingNilaiMahasiswaASC();
                }else{
                    puts("Invalid value\nPress <enter> to continue");
                    getch();
                }

                break;
            case 4:
                break;
            default:
                puts("Invalid value\nPress <enter> to continue");
                getch();
                break;
        }
    }
    return 0;
}
/* ini nih fungsi input tuh, ngejalanin kek gini */
void inputNilaiMahasiswa(){
    for(int i=0; i<10; i++){
        printf("Mahasiswa absen %d\n",i+1);
        printf("NPM: ");
        /* tuhkan lebih rapih kalo udh bikin tipedata mahasiswa mah
        tinggal masuk ke array mahasiswa index ke berapa, trus masukin ke objek nya.
        klo gk dibikin tipe data pasti bakal biki banyak array kan? hayyoh loh makin bingung dan acak"an
        jadi itu lah fungsi bikin tipedata sendiri
         */
        scanf("%d",&mahasiswa[i].npm);
        printf("Nilai: ");
        scanf("%d",&mahasiswa[i].nilai);
    }
    printf("\nSuccess\n");
    printf("Press enter to continue");
    getch();
    /* getch ini tuh buat nge holding sebentar lah, biar gk langsung nutup trus balik ke menu */
}
void cariNilaiMahasiswa(){
    printf("Cari Mahasiswa :");
    scanf("%d",&cariNpm);
    for(int i=0; i<10; i++){
        if(mahasiswa[i].npm == cariNpm){
            printf("Mahasiswa dengan npm -- %d --.\n Meraih nilai %d\n",cariNpm,mahasiswa[i].nilai);
            break;
        }
    }
    puts("\nPress <enter> to continue");
    getch();
}
void sortingNilaiMahasiswaASC(){
    struct Mahasiswa temp;
    for(int i=0; i<10;i++){
        sortingMahasiswa[i]=mahasiswa[i];
    }
    for(int a=0; a<10-1; a++){
        for(int b=0; b<10-1; b++){
            if(sortingMahasiswa[b].nilai>sortingMahasiswa[b+1].nilai){
                temp=sortingMahasiswa[b+1];
                sortingMahasiswa[b+1]=sortingMahasiswa[b];
                sortingMahasiswa[b]=temp;
            }
        }
    }
    printf("NPM        | Nilai\n");
    for(int i=0; i<10; i++){
        printf("%d         | %d\n",sortingMahasiswa[i].npm,sortingMahasiswa[i].nilai);
    }
    puts("\nPress <enter> to continue");
    getch();
}

void sortingNilaiMahasiswaDESC(){
    struct Mahasiswa temp;
    /*
    ini tuh sebenarnya buat ngalihin data aja si ke sortingmahasiswa, soalnya variable mahasiswa itu adalah ori datanya
    jadi jangan dirubah" harusnya, biar keorian datanya terjaga:v
    */
    for(int i=0; i<10;i++){
        sortingMahasiswa[i]=mahasiswa[i];
    }
    /*
    trus ini fungsi sortingannya
    */
    for(int a=0; a<10-1; a++){
        for(int b=0; b<10-1; b++){
            if(sortingMahasiswa[b].nilai<sortingMahasiswa[b+1].nilai){
                temp=sortingMahasiswa[b+1];
                sortingMahasiswa[b+1]=sortingMahasiswa[b];
                sortingMahasiswa[b]=temp;
            }
        }
    }
    printf("NPM        | Nilai\n");
    for(int i=0; i<10; i++){
        printf("%d         | %d\n",sortingMahasiswa[i].npm,sortingMahasiswa[i].nilai);
    }
    puts("\nPress <enter> to continue");
    getch();
}
