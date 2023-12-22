#include <stdio.h>
#include <stdbool.h>

#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // Base case: jika kita telah mencapai tujuan
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Periksa apakah x, y valid
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        // tandai cell sebagai bagian dari solusi
        sol[x][y] = 1;

        // gerakkan ke kanan
        if (solveMazeUtil(maze, x, y + 1, sol)) {
            return true;
        }

        // gerakkan ke bawah
        if (solveMazeUtil(maze, x + 1, y, sol)) {
            return true;
        }

        // jika tidak ada jalur keluar, unmark cell dan kembali
        sol[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(int maze[N][N]) {
    int sol[N][N] = { {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0} };

    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        printf("Solution doesn't exist\n");
        return;
    }

    // print solusi
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[N][N] = { {1, 0, 0, 0},
                       {1, 1, 0, 1},
                       {0, 1, 0, 0},
                       {1, 1, 1, 1} };

    solveMaze(maze);

    return 0;
}
