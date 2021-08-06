//option to append
//option to sort data according to stream
//option to sort according to name
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct student{
    char stream[10];
    int roll;
    char name[30];
    int sem;
}student;
 
 //function to display data
void show(){
    int size,i;
    student *s_display;

    FILE *fp;
    fp = fopen("students_data.txt", "r");
    if(fp != NULL){
        fseek(fp, 0, SEEK_END);
        size = ftell(fp)/sizeof(student);
        rewind(fp);
        s_display = (student*)malloc(size * sizeof(student));

        for(i = 0; i < size; i++){
            fread(&s_display[i], sizeof(student), 1, fp);
            printf("%-10s", s_display[i].stream);
            printf("%-5d", s_display[i].roll);
            printf("%-15s", s_display[i].name);
            printf("%-5d", s_display[i].sem);
            printf("\n");
        }
    }
    else{
        printf("No data found in the file!");
        exit(0);
    }
    fclose(fp);
    free(s_display);
}

 //function to create new file deleting the previous data
void create(){
    FILE *fp;
    student s[SIZE];
    int i;
    printf("Enter new record to store in file:\n");
    fp = fopen("students_data.txt", "w");
    if(fp == NULL){
        printf("Can't open file!");
        return;
    }
    for(i = 0; i < SIZE; i++){
        fflush(stdin);
        printf("Record %d: \n", i+1);
        printf("Stream: "); gets(s[i].stream);
        printf("Roll: "); scanf("%d", &s[i].roll); fflush(stdin);
        printf("Name: "); gets(s[i].name);
        printf("Semester: "); scanf("%d", &s[i].sem);
        // fflush(stdin);
        fwrite(&s[i], sizeof(student), 1, fp);
    }

    fclose(fp);
}


//function to append to the existing data
void append(){
    FILE *fp;
    int n,i,size;
    student *sappend, *s_display; //declaring it as a pointer to allocate user defined size of memory

    printf("How many number of records you want to feed?: ");
    scanf("%d", &n);
    sappend = (student*)malloc(n * sizeof(student)); //allocating memory dynamically for the struct

    fp = fopen("students_data.txt", "a");

    if(fp == NULL){
        printf("Can't open file!");
        return;
    }
    printf("Enter records to append: \n");
    for(i = 0; i < n; i++){
        fflush(stdin);
        printf("Stream: "); gets(sappend[i].stream);
        printf("Roll: "); scanf("%d", &sappend[i].roll); fflush(stdin);
        printf("Name: "); gets(sappend[i].name);
        printf("Semester: "); scanf("%d", &sappend[i].sem);
        // fflush(stdin);
        fwrite(&sappend[i], sizeof(student), 1, fp);
    }
    fclose(fp);

    fp = fopen("students_data.txt", "r");

    if(fp == NULL){
        printf("Can't open file!");
        return;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp)/sizeof(student);
    rewind(fp);
    s_display = (student*)malloc(size * sizeof(student));

    for(i = 0; i < size; i++){
        fread(&s_display[i], sizeof(student), 1, fp);
        printf("%-10s", s_display[i].stream);
        printf("%-3d", s_display[i].roll);
        printf("%-15s", s_display[i].name);
        printf("%-2d", s_display[i].sem);
        printf("\n");
    }
    fclose(fp);
    free(s_display);
    free(sappend);
}

//function to sort file according to stream
void stream_sort(){
    student *store_data, *sorted_data, temp;
    int n,i,j;
    FILE *fp;
    fp = fopen("students_data.txt", "r");

    if(fp == NULL){
        printf("Can't open file!");
        return;
    }

    fseek(fp, 0, SEEK_END);
    n = ftell(fp)/sizeof(student);
    rewind(fp);
    store_data = (student*)calloc(n , sizeof(student));
    sorted_data = (student*)calloc(n,sizeof(student));
    for(i = 0; i < n; i++){
        fread(&store_data[i], sizeof(student), 1, fp);
        // printf("%10s", store_data[i].stream);
        // printf("%3d", store_data[i].roll);
        // printf("%15s", store_data[i].name);
        // printf("%2d", store_data[i].sem);
        // printf("\n");
    }
    
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(strcmp(store_data[i].stream, store_data[j].stream)>0){
                temp = store_data[i];
                store_data[i] = store_data[j];
                store_data[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++){
        sorted_data[i] = store_data[i];
    }
    fclose(fp); 

    fp = fopen("students_data.txt", "w");

    if(fp == NULL){
        printf("Can't open file!");
        return;
    }

    for(i = 0; i < n; i++){
        fwrite(&sorted_data[i], sizeof(student), 1, fp);
        printf("%-10s", sorted_data[i].stream);
        printf("%-3d", sorted_data[i].roll);
        printf("%-15s", sorted_data[i].name);
        printf("%-2d", sorted_data[i].sem);
        printf("\n");
    }
    fclose(fp);
    free(sorted_data);
    free(store_data);
}


//function to sort data according to the names
void name_sort(){
    student *store_data, *sorted_data, temp;
    int n,i,j;
    FILE *fp;
    fp = fopen("students_data.txt", "r");

    if(fp == NULL){
        printf("Can't open file!");
        return;
    }

    fseek(fp, 0, SEEK_END);
    n = ftell(fp)/sizeof(student);
    rewind(fp);
    store_data = (student*)calloc(n , sizeof(student));
    sorted_data = (student*)calloc(n,sizeof(student));

    for(i = 0; i < n; i++){
        fread(&store_data[i], sizeof(student), 1, fp);
    }
    fclose(fp);
    
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(strcmp(store_data[i].name, store_data[j].name)>0){
                temp = store_data[i];
                store_data[i] = store_data[j];
                store_data[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++){
        sorted_data[i] = store_data[i];
    }

    fp = fopen("students_data.txt", "w");

    if(fp == NULL){
        printf("Can't open file!");
        return;
    }

    for(i = 0; i < n; i++){
        fwrite(&sorted_data[i], sizeof(student), 1, fp);
        printf("%-10s", sorted_data[i].stream);
        printf("%-3d", sorted_data[i].roll);
        printf("%-15s", sorted_data[i].name);
        printf("%-2d", sorted_data[i].sem);
        printf("\n");
    }
    fclose(fp);
    free(store_data);
    free(sorted_data);
}


int main(){
    int choice;
    // FILE *fp;
    system("cls");

    do{
        printf("\n1.READ DATA.\n");
        printf("2.CREATE NEW DATA. (will erase previously written data) \n");
        printf("3.APPEND NEW DATA\n");
        printf("4.SORT DATA ACCORDING TO STREAM (in file)\n");
        printf("5.SORT DATA ACCORDING TO NAME (in file)\n");
        printf("0.EXIT\n");

        printf("\nYour choice: "); scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 0:
                printf("Exiting...."); exit(0); break;
            case 1:
                show(); break;
            case 2:
                create(); break;
            case 3: 
                append(); break;
            case 4:
                stream_sort(); break;
            case 5:
                name_sort(); break;
        }
    }while(choice != 0);
    return 0;
}