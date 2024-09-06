#include "game_of_life.h"
#include <assert.h>
#include <stdio.h>
#include<stdlib.h>

void makeCopy_test(){

    char** board = allocarray(3,3);


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

    char** board = allocarray(3,3);

    board[0][0] = '0'; board[0][1] = '1'; board[0][2] = '0';
    board[1][0] = '1'; board[1][1] = '1'; board[1][2] = '0';
    board[2][0] = '0'; board[2][1] = '1'; board[2][2] = '1';

    assert(num_neighbors(board, 3, 1,1) == 4);
    assert(num_neighbors(board, 3, 1,0) == 3);
    assert(num_neighbors(board, 3, 2,2) == 2);
    printf("num_neighbors() : All tests passed \n");

}

void createNextState_test(){
    char** board = allocarray(3,3);


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
    char** board1 = allocarray(3,3);
    board1[0][0] = '0'; board1[0][1] = '1'; board1[0][2] = '0';
    board1[1][0] = '1'; board1[1][1] = '1'; board1[1][2] = '0';
    board1[2][0] = '0'; board1[2][1] = '1'; board1[2][2] = '1';


    char** board2 = allocarray(3,3);
    board2[0][0] = '0'; board2[0][1] = '1'; board2[0][2] = '0';
    board2[1][0] = '1'; board2[1][1] = '1'; board2[1][2] = '0';
    board2[2][0] = '0'; board2[2][1] = '1'; board2[2][2] = '1';

    char** board3 = allocarray(3,3);
    board3[0][0] = '0'; board3[0][1] = '1'; board3[0][2] = '1';
    board3[1][0] = '0'; board3[1][1] = '0'; board3[1][2] = '1';
    board3[2][0] = '0'; board3[2][1] = '1'; board3[2][2] = '1';

    assert(isEqual(board1, board2, 3) == true);
    assert(isEqual(board1, board3, 3) == false);
    assert(isEqual(board2, board3, 3) == false);
    printf("isEqual() : All tests passed \n");

}

int main(){
    makeCopy_test();
    num_neighbors_test();
    createNextState_test();
    isEqual_test();
    return 0;

}