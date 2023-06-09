// chess-master
// Дано число N. Определите, сколькими способами можно расставить
// на доске NxN ферзей, не бьющих друг друга

#include <iostream>
using namespace std;
 

const int SIZE = 5; // размер поля
int queenCount = 0; // количество решений
int board[SIZE][SIZE];
 
int queenExistence(int a, int b) {
// проверяет, нет ли уже установленных ферзей, по вертикали, диагоналям
// 0 - ферзя нет, 1 - ферзь установлен
    for (int i = 0; i <= a; i++) {
        if (board[i][b]) {
            return 0;
        }
    }
 
    for (int i = 0; (i <= a) && ((b - i) >= 0); i++) {
        if (board[a - i][b - i]) {
            return 0;
        }
    }

    for (int i = 0; (i <= a) && ((b + i) < SIZE); i++) {
        if (board[a - i][b + i]) {
            return 0;
        }
    }

    return 1;
}

void findSolutions(int a) {
// a - номер строки в которую нужно поставить очередного ферзя
// функция findSolutions() - пробует найти результаты решений
    if (a == SIZE) {
        queenCount++;
    }

    for (int i = 0; i < SIZE; i++) {
        // проверка на то, если поставить в board[a][i] ферзя (единицу),
        // то он будет единственным в этой строке, столбце и диагоналях
        if (queenExistence(a, i)) {
            board[a][i] = 1;
            findSolutions(a + 1);
            board[a][i] = 0;
        }
    }
}

int main() {
    findSolutions(0);
    cout << "Solutions: " << queenCount << endl;
    return 0;
}