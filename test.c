#include "game_of_life.h"
#include <assert.h>
#include <stdio.h>
#include<stdlib.h>

void makeCopy_test(){
    char* array = (char*)malloc(sizeof(char) * 3  * 3);
    if(array == NULL)
    {
        printf("Error allocating memory\n");
        exit(0);
    }
    char** board = (char**)malloc(sizeof(char*) * 3);
    if(board == NULL)
    {
        printf("Error allocating memory\n");
        free(array);
        exit(0);
    }

    for(int i = 0; i < 3; i++){
        board[i] = &array[i*3];
    }


    board[0][0] = '0'; board[0][1] = '1'; board[0][2] = '0';
    board[1][0] = '1'; board[1][1] = '1'; board[1][2] = '0';
    board[2][0] = '0'; board[2][1] = '1'; board[2][2] = '1';

    char** copy = makeCopy(board,3);
    assert(copy[0][0] == '0');
    assert(copy[2][1] == '1');
    assert(copy[1][1] == '1');
    printf("makeCopy() : All tests passed \n");
}

void num_neighbors_test(){
        char* array = (char*)malloc(sizeof(char) * 3  * 3);
    if(array == NULL)
    {
        printf("Error allocating memory\n");
        exit(0);
    }
    char** board = (char**)malloc(sizeof(char*) * 3);
    if(board == NULL)
    {
        printf("Error allocating memory\n");
        free(array);
        exit(0);
    }

    for(int i = 0; i < 3; i++){
        board[i] = &array[i*3];
    }


    board[0][0] = '0'; board[0][1] = '1'; board[0][2] = '0';
    board[1][0] = '1'; board[1][1] = '1'; board[1][2] = '0';
    board[2][0] = '0'; board[2][1] = '1'; board[2][2] = '1';

    assert(num_neighbors(board, 3, 1,1) == 4);
    assert(num_neighbors(board, 3, 1,0) == 3);
    assert(num_neighbors(board, 3, 2,2) == 2);
    printf("num_neighbors() : All tests passed \n");

}

void createNextState_test(){
    char* array = (char*)malloc(sizeof(char) * 3  * 3);
    if(array == NULL)
    {
        printf("Error allocating memory\n");
        exit(0);
    }
    char** board = (char**)malloc(sizeof(char*) * 3);
    if(board == NULL)
    {
        printf("Error allocating memory\n");
        free(array);
        exit(0);
    }

    for(int i = 0; i < 3; i++){
        board[i] = &array[i*3];
    }


    board[0][0] = '0'; board[0][1] = '1'; board[0][2] = '0';
    board[1][0] = '1'; board[1][1] = '1'; board[1][2] = '0';
    board[2][0] = '0'; board[2][1] = '1'; board[2][2] = '1';

    char** testState = createNextState(board,3);

    assert(testState[0][0] == '1');
    assert(testState[2][0] == '1');
    assert(testState[1][1] == '0');
    printf("createNextState() : All tests passed \n");
    


}

void isEqual_test(){
    char* array1 = (char*)malloc(sizeof(char) * 3  * 3);
    if(array1 == NULL)
    {
        printf("Error allocating memory\n");
        exit(0);
    }
    char** board1 = (char**)malloc(sizeof(char*) * 3);
    if(board1 == NULL)
    {
        printf("Error allocating memory\n");
        free(array1);
        exit(0);
    }

    for(int i = 0; i < 3; i++){
        board1[i] = &array1[i*3];
    }


    board1[0][0] = '0'; board1[0][1] = '1'; board1[0][2] = '0';
    board1[1][0] = '1'; board1[1][1] = '1'; board1[1][2] = '0';
    board1[2][0] = '0'; board1[2][1] = '1'; board1[2][2] = '1';

    char* array2 = (char*)malloc(sizeof(char) * 3  * 3);
    if(array2 == NULL)
    {
        printf("Error allocating memory\n");
        exit(0);
    }
    char** board2 = (char**)malloc(sizeof(char*) * 3);
    if(board2 == NULL)
    {
        printf("Error allocating memory\n");
        free(array2);
        exit(0);
    }

    for(int i = 0; i < 3; i++){
        board2[i] = &array2[i*3];
    }


    board2[0][0] = '0'; board2[0][1] = '1'; board2[0][2] = '0';
    board2[1][0] = '1'; board2[1][1] = '1'; board2[1][2] = '0';
    board2[2][0] = '0'; board2[2][1] = '1'; board2[2][2] = '1';

    assert(board1[1][1] == board2[1][1]);
    assert(board1[2][2] == board2[2][2]);
    assert(board1[0][1] == board2[0][1]);
    printf("isEqual() : All tests passed \n");

}

int main(){
    makeCopy_test();
    num_neighbors_test();
    createNextState_test();
    isEqual_test();
    return 0;

}