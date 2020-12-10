/*
    Project 1
    ENEE150 Fall 2020
    Joseph M Krzyzek
*/

#include <stdio.h>
#include "backgammon.h"

int the_board_white[BOARD_SIZE+1] =
  {0, 0, 0, 0, 0, 0, 5, 0, 3, 0, 0, 0, 0,
      5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2};

int the_board_red[BOARD_SIZE+1] =
  {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5,
      0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 0};

int the_bar_white = 0;
int the_bar_red = 0;

int num_white = NUM_PIECES;
int num_red = NUM_PIECES;

/******************** board print routines ********************/

void print_board()
{
  /************************/
  /*** CREATE NEW BOARD ***/
  /************************/
  char the_board[BOARD_SIZE][BOARD_SIZE/4 - 1];
  int i, j, k, temp;

  /* fill in the board with '|' */
  for(i = 0; i < BOARD_SIZE; i++)
  {
    for(j = 0; j < 5; j++)
    {
      the_board[i][j] = '|';
    }
  }

  /* fill in the board with the white pieces */
  for(i = 0; i < BOARD_SIZE; i++)
  {
    for(j = 0; j < 5; j++)
    {
      /* if the first column is not zero print W up to 5 times */
      if( the_board_white[i + 1] != 0 )
      {
        while( (j < the_board_white[i + 1]) && (j < 5) )
        {
          the_board[i][j] = 'W';
          j++;
        }
      }
    }
  }

  /* fill in the board with the red pieces */
  for(i = 0; i < BOARD_SIZE; i++)
  {
    for(j = 0; j < 5; j++)
    {
      /* if the first column is not zero print R up to 5 times */
      if( the_board_red[i + 1] != 0 )
      {
        while( (j < the_board_red[i + 1]) && (j < 5))
        {
          the_board[i][j] = 'R';
          j++;
        }
      }
    }
  }

  /***************************/
  /*** BREAK BOARD IN HALF ***/
  /***************************/
  char top_half[BOARD_SIZE/4 - 1][BOARD_SIZE/2];
  char bottom_half[BOARD_SIZE/4 - 1][BOARD_SIZE/2];

  /* fill the halfs */
  for(i = 0; i < 5; i++)
  {
    for(j = 0; j < 12; j++)
    {
      bottom_half[i][j] = the_board[j][i];
    }
  }
  for(i = 0; i < 5; i++)
  {
    for(j = 12; j < 24; j++)
    {
      top_half[i][j - 12] = the_board[j][i];
    }
  }

  /*********************/
  /*** ORIENT BOTTOM ***/
  /*********************/
  /* flip along vertical axis */
  for(k = 0; k < 5; k++)
  {
    j = 11;   // Assigning j to Last array element
    i = 0;    // Assigning i to first array element
    while (i < j)
    {
      temp = bottom_half[k][i];
      bottom_half[k][i] = bottom_half[k][j];
      bottom_half[k][j] = temp;
      i++;
      j--;
     }
   }
   /* flip along horizontal axis */
   for(k = 0; k < 12; k++)
   {
     j = 4;   // Assigning j to Last array element
     i = 0;   // Assigning i to first array element
     while (i < j)
     {
       temp = bottom_half[i][k];
       bottom_half[i][k] = bottom_half[j][k];
       bottom_half[j][k] = temp;
       i++;
       j--;
      }
    }

  /*******************/
  /*** PRINT BOARD ***/
  /*******************/
  /* prints the first line */
  for(i = 13; i <= 24; i++)
  {
    printf("%d ", i);
    if(i == 18)
    {
      printf("   ");
    }
  }
  /* prints the top half */
  for(i = 0; i < 5; i++)
  {
    printf("\n");
    for(j = 0; j < 12; j++)
    {
      printf("%c  ", top_half[i][j]);
      if(j == 5)
      {
        printf("   ");
      }
    }
  }
  printf("\n");
  /* prints the bottom half */
  for(i = 0; i < 5; i++)
  {
    printf("\n");
    for(j = 0; j < 12; j++)
    {
      printf("%c  ", bottom_half[i][j]);
      if(j == 5)
      {
        printf("   ");
      }
    }
  }
  printf("\n");
  /* prints the last line */
  for(i = 12; i >= 1; i--)
  {
    if(i > 9)
    {
      printf("%d ", i);
    }
    else
    {
      printf("%d  ", i);
      if(i == 7)
      {
        printf("   ");
      }
    }
  }
  /* Prints the last line */
  printf("\n  Bar:  White-%d  Red-%d\n", the_bar_white, the_bar_red);
}
