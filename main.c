#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Mahasiswa{
    int npm;
    int nilai;
};

struct Mahasiswa mahasiswa[10],sortingMahasiswa[10];
int selectedMenu = -2;
int selectedMenuSorting = -2;
int cariNpm = -2;

void inputNilaiMahasiswa();
void cariNilaiMahasiswa();
void sortingNilaiMahasiswaASC();
void sortingNilaiMahasiswaDESC();
void sortingInsertionASC();
void sortingInsertionDESC();
void sortingSelectionASC();
void sortingSelectionDESC();

int main()
{
    while(selectedMenu!=7){
        system("cls");
        printf("Program data Mahasiswa\n");
        printf("Created by: Muchlish Choeruddin\n");
        printf("NPM: 0619204001\n\n");
        printf("Menu:\n");
        printf("    1. Input nilai mahasiswa\n");
        printf("    2. Searching(linear search)\n");
        printf("    3. Searching(binary search)\n");
        printf("    4. Sorting(bubble sort)\n");
        printf("    5. Sorting(insertion sort)\n");
        printf("    6. Sorting(selection sort)\n");
        printf("    7. Exit\n\n");

        printf("Pilih menu: ");
        scanf("%d",&selectedMenu);

        switch(selectedMenu){
            case 1:
                inputNilaiMahasiswa();
                break;
            case 2:
                cariNilaiMahasiswa();
                break;
            case 3:
                cariNilaiMahasiswaBinary();
                break;
            case 4:
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
            case 5:
                printf("Sorting mahasiswa berdasar:\n");
                printf("    1. Besar ke kecil\n");
                printf("    2. Kecil ke besar\n\n");

                printf("Pilih menu: ");
                scanf("%d",&selectedMenuSorting);
                if(selectedMenuSorting==1){
                    sortingInsertionDESC();
                }else if(selectedMenuSorting==2){
                    sortingInsertionASC();
                }else{
                    puts("Invalid value\nPress <enter> to continue");
                    getch();
                }

                break;
            case 6:
                printf("Sorting mahasiswa berdasar:\n");
                printf("    1. Besar ke kecil\n");
                printf("    2. Kecil ke besar\n\n");

                printf("Pilih menu: ");
                scanf("%d",&selectedMenuSorting);
                if(selectedMenuSorting==1){
                    sortingSelectionDESC();
                }else if(selectedMenuSorting==2){
                    sortingSelectionASC();
                }else{
                    puts("Invalid value\nPress <enter> to continue");
                    getch();
                }

                break;
            case 7:
                break;
            default:
                puts("Invalid value\nPress <enter> to continue");
                getch();
                break;
        }
    }
    return 0;
}
void inputNilaiMahasiswa(){
    for(int i=0; i<10; i++){
        printf("Mahasiswa absen %d\n",i+1);
        printf("NPM: ");
        scanf("%d",&mahasiswa[i].npm);
        printf("Nilai: ");
        scanf("%d",&mahasiswa[i].nilai);
    }
    printf("\nSuccess\n");
    printf("Press enter to continue");
    getch();
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
void cariNilaiMahasiswaBinary(){

    struct Mahasiswa temp;
    for(int i=0; i<10;i++){
        sortingMahasiswa[i]=mahasiswa[i];
    }
    for(int a=0; a<10; a++){
        int indexMin = a;
        for(int j=a; j<10;j++){
            if(sortingMahasiswa[j].npm<sortingMahasiswa[indexMin].npm){
                indexMin=j;
            }
        }
        temp = sortingMahasiswa[a];
        sortingMahasiswa[a] = sortingMahasiswa[indexMin];
        sortingMahasiswa[indexMin] = temp;
    }

    printf("Cari Mahasiswa :");
    scanf("%d",&cariNpm);

    int left = 0;
    int right = 9;
    while(left<=right){
        int mid = left+((right-left)/2);
        if(sortingMahasiswa[mid].npm==cariNpm){
            printf("Mahasiswa dengan npm -- %d --.\n Meraih nilai %d\n",cariNpm,sortingMahasiswa[mid].nilai);
            break;
        }else if(cariNpm<sortingMahasiswa[mid].npm){
            right = mid-1;
        }else{
            left = mid+1;
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
    for(int i=0; i<10;i++){
        sortingMahasiswa[i]=mahasiswa[i];
    }
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

void sortingInsertionASC(){
    struct Mahasiswa temp;
    for(int i=0; i<10;i++){
        sortingMahasiswa[i]=mahasiswa[i];
    }
    for(int a=1; a<=10; a++){
        int j = a;
        while(j>0 && sortingMahasiswa[j-1].nilai>sortingMahasiswa[j].nilai){
            temp=sortingMahasiswa[j];
            sortingMahasiswa[j]=sortingMahasiswa[j-1];
            sortingMahasiswa[j-1]=temp;
            j--;
        }
    }
    printf("NPM        | Nilai\n");
    for(int i=0; i<10; i++){
        printf("%d         | %d\n",sortingMahasiswa[i].npm,sortingMahasiswa[i].nilai);
    }
    puts("\nPress <enter> to continue");
    getch();
}

void sortingInsertionDESC(){
    struct Mahasiswa temp;
    for(int i=0; i<10;i++){
        sortingMahasiswa[i]=mahasiswa[i];
    }
    for(int a=1; a<=10; a++){
        int j = a;
        while(j>0 && sortingMahasiswa[j-1].nilai<sortingMahasiswa[j].nilai){
            temp=sortingMahasiswa[j];
            sortingMahasiswa[j]=sortingMahasiswa[j-1];
            sortingMahasiswa[j-1]=temp;
            j--;
        }
    }
    printf("NPM        | Nilai\n");
    for(int i=0; i<10; i++){
        printf("%d         | %d\n",sortingMahasiswa[i].npm,sortingMahasiswa[i].nilai);
    }
    puts("\nPress <enter> to continue");
    getch();
}
void sortingSelectionASC(){
    struct Mahasiswa temp;
    for(int i=0; i<10;i++){
        sortingMahasiswa[i]=mahasiswa[i];
    }
    for(int a=0; a<10; a++){
        int indexMin = a;
        for(int j=a; j<10;j++){
            if(sortingMahasiswa[j].nilai<sortingMahasiswa[indexMin].nilai){
                indexMin=j;
            }
        }
        temp = sortingMahasiswa[a];
        sortingMahasiswa[a] = sortingMahasiswa[indexMin];
        sortingMahasiswa[indexMin] = temp;
    }
    printf("NPM        | Nilai\n");
    for(int i=0; i<10; i++){
        printf("%d         | %d\n",sortingMahasiswa[i].npm,sortingMahasiswa[i].nilai);
    }
    puts("\nPress <enter> to continue");
    getch();
}
void sortingSelectionDESC(){
    struct Mahasiswa temp;
    for(int i=0; i<10;i++){
        sortingMahasiswa[i]=mahasiswa[i];
    }
    for(int a=0; a<10; a++){
        int indexMin = a;
        for(int j=a; j<10;j++){
            if(sortingMahasiswa[j].nilai>sortingMahasiswa[indexMin].nilai){
                indexMin=j;
            }
        }
        temp = sortingMahasiswa[a];
        sortingMahasiswa[a] = sortingMahasiswa[indexMin];
        sortingMahasiswa[indexMin] = temp;
    }
    printf("NPM        | Nilai\n");
    for(int i=0; i<10; i++){
        printf("%d         | %d\n",sortingMahasiswa[i].npm,sortingMahasiswa[i].nilai);
    }
    puts("\nPress <enter> to continue");
    getch();
}
