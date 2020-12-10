/*
    Project 1
    ENEE150 Fall 2020
    Joseph M Krzyzek
*/

#include <stdio.h>
#include <stdlib.h>
#include "backgammon.h"
/************************/
/*** EXTRA FUNCTIONS ***/
/***********************/
int roll_die()
{
  return ( (random() % 6) + 1 );
}
void update_board(int mover, int from, int to)
{
  if(mover == WHITE)
  {
    if(from == 0)
    {
      the_board_white[to]++;
    }
    else if(to == 0)
    {
      the_board_white[from]--;
    }
    else
    {
      the_board_white[from]--;
      the_board_white[to]++;
    }
  }
  if(mover == RED)
  {
    if(from == 0)
    {
      the_board_red[to]++;
    }
    else if(to == 0)
    {
      the_board_red[from]--;
    }
    else
    {
      the_board_red[from]--;
      the_board_red[to]++;
    }
  }
}
int check_bar(int mover)
{
  /*
  Returns TRUE when there is a players piece on the the the bar
  */
  switch(mover)
  {
    case WHITE:
      if( the_bar_white != 0 )
      {
        return(TRUE);
      }
      else
      {
        return(FALSE);
      }
      break;
    case RED:
      if( the_bar_red != 0 )
      {
        return(TRUE);
      }
      else
      {
        return(FALSE);
      }
      break;
  }
  return(FALSE);
}
int check_bear_off(int mover)
{
  /*
  Returns TRUE if is a bear_off_move
  */
  int i;
  int count = 0;

  switch(mover)
  {
    case WHITE:
      for(i = 24; i >= 7; i--)
      {
        count = the_board_white[i] + count;
      }
      if(count == 0)
      {
        return(TRUE);
      }
      else
      {
        return(FALSE);
      }
      break;
    case RED:
      for(i = 1; i <= 18; i++)
      {
        count = the_board_red[i] + count;
      }
      if(count == 0)
      {
        return(TRUE);
      }
      else
      {
        return(FALSE);
      }
      break;
  }
  return(FALSE);
}
int switch_player(int mover)
{
  if(mover == WHITE)
  {
    mover = RED;
  }
  else
  {
    mover = WHITE;
  }
  return(mover);
}
void make_move(int mover)
{
  int from, to, die_one, die_two;
  int correct_inputs = 0;

  die_one = roll_die();
  die_two = roll_die();
  printf("Rolling dice:  %d %d\n", die_one, die_two);

  if(mover == WHITE)
  {
    while(correct_inputs < 2)
    {
      printf("White's move:  ");
      scanf("%d%d", &from, &to);
      if( (from == 0) && (to == 0) )
      {
        exit(0);
      }
      else if(check_move(mover, from, to, die_one) == VALID_MOVE)
      {
        update_board(mover, from, to);
        correct_inputs++;
        print_board();
        while(correct_inputs < 2)
        {
          scanf("%d%d", &from, &to);
          if( (from == 0) && (to == 0) )
          {
            exit(0);
          }
          if(check_move(mover, from, to, die_two) == VALID_MOVE)
          {
            update_board(mover, from, to);
            correct_inputs++;
            printf("White's move:  ");
            print_board();
          }
          else
          {
            printf("White's move:  ");
            printf("Invalid move\n");
          }
        }
      }
      else if(check_move(mover, from, to, die_two) == VALID_MOVE)
      {
        update_board(mover, from, to);
        correct_inputs++;
        print_board();
        while(correct_inputs < 2)
        {
          scanf("%d%d", &from, &to);
          if( (from == 0) && (to == 0) )
          {
            exit(0);
          }
          if(check_move(mover, from, to, die_one) == VALID_MOVE)
          {
            update_board(mover, from, to);
            correct_inputs++;
            printf("White's move:  ");
            print_board();
          }
          else
          {
            printf("White's move:  ");
            printf("Invalid move\n");
          }
        }
      }
      else
      {
        printf("Invalid move\n");
      }
    }
  }
  if(mover == RED)
  {
    while(correct_inputs < 2)
    {
      printf("Red's move:  ");
      scanf("%d%d", &from, &to);
      if( (from == 0) && (to == 0) )
      {
        exit(0);
      }
      else if(check_move(mover, from, to, die_one) == VALID_MOVE)
      {
        update_board(mover, from, to);
        correct_inputs++;
        print_board();
        while(correct_inputs < 2)
        {
          scanf("%d%d", &from, &to);
          if( (from == 0) && (to == 0) )
          {
            exit(0);
          }
          if(check_move(mover, from, to, die_two) == VALID_MOVE)
          {
            update_board(mover, from, to);
            correct_inputs++;
            printf("Red's move:  ");
            print_board();
          }
          else
          {
            printf("Red's move:  ");
            printf("Invalid move\n");
          }
        }
      }
      else if(check_move(mover, from, to, die_two) == VALID_MOVE)
      {
        update_board(mover, from, to);
        correct_inputs++;
        print_board();
        while(correct_inputs < 2)
        {
          scanf("%d%d", &from, &to);
          if( (from == 0) && (to == 0) )
          {
            exit(0);
          }
          if(check_move(mover, from, to, die_one) == VALID_MOVE)
          {
            update_board(mover, from, to);
            correct_inputs++;
            printf("Red's move:  ");
            print_board();
          }
          else
          {
            printf("Red's move:  ");
            printf("Invalid move\n");
          }
        }
      }
      else
      {
        printf("Invalid move\n");
      }
    }
  }
}

/************************/
/******** MAIN *********/
/***********************/
int main()
{
  int mover = WHITE;
  print_board();
  while (TRUE)
  {
    make_move(mover);
    mover = switch_player(mover);
  }
}
