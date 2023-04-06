#include <iostream>
#include <time.h>
using namespace std;
// 1 - ый номер вариант №13
// 2 - ой номер вариант №9
void createMatrix(int n, int m, int **mas);
void task_0(int n, int m, int **mas);
void task_1(int n, int m, int ** mas);

int main(){
srand(time(NULL));
    int n, m;
    cout << "Enter size of the matrix: ";
    cin >> n >> m;
    int** mas;
    mas = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        mas[i] = (int*)malloc(m * sizeof(int));
    }
    createMatrix(n, m, mas);
    int num = 0;
    while (num != -1)
    {
    cout << "choose number of the task:" << endl;
    if (scanf("%d", &num) == 1){
        if(num == 1) task_0(n,m,mas);
        else if (num == 2)task_1(n,m,mas);
        else if(num == -1) cout << "See you later";
        else cout << "ERROR: choose another task";
        }else {
            cout << "ERROR: incorrect input";
            break;
            }
    }
}

void createMatrix(int n, int m, int** mas){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mas[i][j] = ((rand() % 10) - 5);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}



void task_0(int n, int m, int **mas){
    int min_summa = 99999999, summa = 0;
    // нахождение  минимальной суммы
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            summa += mas[i][j];
        }
        if(summa < min_summa) min_summa = summa;
        summa = 0;
    }
    cout << "Min_summa = " << min_summa << endl;
    // нахождение строки с минимальной суммой
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            summa += mas[i][j];
        }
        if(min_summa == summa) {
            summa = i;
            break;
        }
        summa = 0;
    }
    cout << "number of line whith min summ = " << summa << endl;
    double sred = 0;

    int kolvo = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(i < j){
                sred += mas[i][j];
                kolvo ++;
                }
        }
    }
    sred = sred / kolvo;// так как среднее арифметическое зачастую меньше единицы по модулю,
    // а работаем мы с int матрицей, то в таком случае она меняться не будет
    cout << "arithmetic mean == " << sred << endl;
    // Изменение матрицы
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (i == summa) mas[i][j] += sred;
        }
    }
    //вывод матрицы
    cout << "changed matrix:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}





void task_1(int n, int m, int **mas){
    int counter = 0, id = 0;
    int max_count = 0, id_of_max;
    //Нахождение id столбца с макс кол-вом нулей
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j ++){
            if(mas [j][i] == 0){
                counter ++;
            }
        }
        if (counter > max_count){
            max_count = counter;
            id_of_max = id;
        }
        id ++;
        counter = 0;
    }
    cout << "MAX = " << max_count << " ID of max= " << id_of_max << endl;

    //Вывод матрицы без нужного столбца
    if (max_count != 0){
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j++){
                if(id_of_max != j){
                    cout << mas[i][j] << " ";
                }
            }
             cout << endl;
        }
    }
}