#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <fstream>

void createMatrix(int n, int m, int** mas){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mas[i][j] = ((rand() %200) - 100);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
}

void task_0(int n, int m, int **mas){
    int sred = 0, kolvo = 0;
    std::ofstream out;
    out.open("first_task.txt");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(mas[i][j] > 0){
                sred +=mas[i][j];
                kolvo++;
            }else{
                continue;
                }
        }
        out << "In " << i << " string" << kolvo << "non-negative elements"<< std::endl;
        printf("In %d string %d non-negative elements\n", i, kolvo);
        kolvo = 0;
    }
    out << "Arithmetic mean of the positive elements of the matrix = " << sred << std::endl;
    printf("Arithmetic mean of the positive elements of the matrix = %d\n", sred);
}
void task_1(int n, int m, int** mas){
    int sum = 0; 
    int *ms = new int[m];
    for (int i = 0; i < n; i++){
        int max = mas[i][i];
        for (int j = 0; j < m; j++){
            if(mas[i][j] > max){
                ms[i] = 0;
                break;
            }else{
                ms[i] = 1;
            }
            sum += mas[i][j];
        }
    
        
        }
        for (int i = 0; i < m; i++){
            if(ms[i] == 0 || ms[i] == 1){
                printf("%d ", ms[i]);
            }else{
                break;
            }
        }
        printf("\nsumma = %d\n", sum);
    }


void task_2(int n, int m, int **mas){
    int sum = 0;
    if(n == m){
        //work
        for (int i = 0; i < n; i ++){
            for (int j =0; j < n; j++){
                if(j > i){
                    mas[i][j] = abs((long double)mas[i][j]);
                }
                if(i == j){
                    sum += mas[i][j];
                }
            }
        }
        printf("\n\n\n");
        for (int i = 0; i < n; i ++){
            for (int j =0; j < n; j++){
                printf("%d ", mas[i][j]);
            }
            printf("\n");
        }
        printf("\n SUMM OF GL DIAG = %d\n", sum);
    }else{
        printf("ERROR: matrix is not squre\n");
    }
}
void Inicialization(){
    int task;
    srand(time(NULL));
    int n, m;
    printf("Enter size of the matrix:");
    scanf("%d%d", &n, &m);
    int** mas;
    mas = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        mas[i] = (int*)malloc(m * sizeof(int));
    }
    createMatrix(n, m, mas);
    while(task != -1){
        printf("Choose number of the task:\n0 - first task\n1-second task\n2-third task\n-1 - exit\n");
        scanf("%d", &task);
    if (task == 0){
        task_0(n, m, mas);
    }else if(task == 1){
        task_1(n, m, mas);
    }else if(task == 2){
        task_2(n, m, mas);
    }else if(task == -1){
        printf("Thanks for using");
    }else{
        printf("n/a\n");
    }
}
for (int i = 0; i < n; i++){
    free(mas[i]);
}
free(mas);
mas = NULL;
}