/*
    Project 1
    ENEE150 Fall 2020
    Joseph M Krzyzek
*/

#define NUM_PIECES 15
#define WHITE 1
#define RED 2

#define VALID_MOVE 1
#define INVALID_MOVE 2

#define TRUE 1
#define FALSE 0

/********************/
/* BOARD DEFINITION */
/********************/
#define BOARD_SIZE 24
extern int the_board_white[BOARD_SIZE+1];
extern int the_board_red[BOARD_SIZE+1];
extern int the_bar_white;
extern int the_bar_red;
extern int num_white;
extern int num_red;

/***************************/
/*** REQUIRED FUNCTIONS ***/
/**************************/
void print_board();
int check_move(int mover, int from, int to, int die);
int check_basic_move(int mover, int from, int to, int die);
int check_entry_move(int mover, int from, int to, int die);
int check_bear_off_move(int mover, int from, int to, int die);
int check_die(int mover, int from, int to, int die);
int check_board_bounds(int index);

/************************/
/*** EXTRA FUNCTIONS ***/
/***********************/
int roll_die();
void update_board(int mover, int from, int to);
int check_bar(int mover);
int check_bear_off(int mover);
void make_move(int mover);
int switch_player(int mover);
