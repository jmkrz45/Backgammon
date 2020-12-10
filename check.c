/*
    Project 1
    ENEE150 Fall 2020
    Joseph M Krzyzek
*/

#include <stdio.h>
#include <stdlib.h>
#include "backgammon.h"

/***************************/
/*** REQUIRED FUNCTIONS ***/
/**************************/
int check_move(int mover, int from, int to, int die)
{
  /*
  The check_move function should call:
  check_basic_move
  check_entry_move
  check_bear_off_move
  */
  if( check_bar(mover) == TRUE )
  {
    return( check_entry_move(mover, from, to, die) );
  }
  else if (check_bear_off(mover) == TRUE)
  {
    return( check_bear_off_move(mover, from, to, die) );
  }
  else
  {
    return( check_basic_move(mover, from, to, die) );
  }
}
int check_basic_move(int mover, int from, int to, int die)
{
  /*
   The check basic move function should call the check_die and check_board_bounds
   functions and evaluate 2 more conditions

   Condition #4*
   The originating point in a move must contain one or more checkers belonging
   to the moving players

   Condition #5*
   The destination point in a move must not contain more than one checker
   belonging to the moving player’s opponent.
   In other words, the destination point can be either empty,
   contain any number of checkers belonging to the moving player,
   or contain exactly one checker belonging to the moving player’s opponent
  */

  /* Call other functions */
  if(check_die(mover, from, to, die) == VALID_MOVE)
  {
    if(check_board_bounds(from) == VALID_MOVE)
    {
      if(check_board_bounds(to) == VALID_MOVE)
      {
        /* Condition #4 */
        if(mover == WHITE)
        {
          if( the_board_white[from] == 0 )
          {
            return(INVALID_MOVE);
          }
          /* Condition #5 */
          else if(the_board_red[to] > 1)
          {
            return(INVALID_MOVE);
          }
          else if(the_board_red[to] == 1)
          {
            the_board_red[to]--;
            the_bar_red++;
            return(VALID_MOVE);
          }
          else
          {
            return(VALID_MOVE);
          }
        }
        /* Condition #4 */
        if(mover == RED)
        {
          if( the_board_red[from] == 0 )
          {
            return(INVALID_MOVE);
          }
          /* Condition #5 */
          else if(the_board_white[to] > 1)
          {
            return(INVALID_MOVE);
          }
          else if(the_board_white[to] == 1)
          {
            the_board_white[to]--;
            the_bar_white++;
            return(VALID_MOVE);
          }
          else
          {
            return(VALID_MOVE);
          }
        }
      }
    }
  }
  return(INVALID_MOVE);
}
int check_entry_move(int mover, int from, int to, int die)
{
  /*
  The check entry move function should call the check_die and check_board_bounds
  functions
  */
  /* Call other functions */
  if( check_die(mover, from, to, die) == VALID_MOVE )
  {
    if( from == 0 )
    {
      if( check_board_bounds(to) == VALID_MOVE )
      {
        if(mover == WHITE)
        {
          // WHITE moves down
          if( ((25 - to) == die) && (the_board_red[to] == 0) )
          {
            the_bar_white--;
            return(VALID_MOVE);
          }
          else if( ((25 - to) == die) && (the_board_red[to] == 1) )
          {
            the_board_red[to]--;
            the_bar_red++;
            the_bar_white--;
            return(VALID_MOVE);
          }
          else
          {
            return(INVALID_MOVE);
          }
        }
        if(mover == RED)
        {
          // RED moves up
          if( ( to == die ) && (the_board_white[to] == 0) )
          {
            the_bar_red--;
            return(VALID_MOVE);
          }
          else if( ( to == die ) && (the_board_white[to] == 1) )
          {
            the_board_white[to]--;
            the_bar_white++;
            the_bar_red--;
            return(VALID_MOVE);
          }
          else
          {
            return(INVALID_MOVE);
          }
        }
      }
    }
  }
  return(INVALID_MOVE);
}
int check_bear_off_move(int mover, int from, int to, int die)
{
  /*
  If the move is a valid bearing off move, the function returns VALID MOVE.
  If the move is not a valid bearing off move, the function returns INVALID MOVE.
  The check_bear_off_move function should call the check_board_bounds function
  */
  if(check_basic_move(mover, from, to, die) == VALID_MOVE)
  {
    return(VALID_MOVE);
  }
  if( check_die(mover, from, to, die) == VALID_MOVE )
  {
    if( check_board_bounds(from) == VALID_MOVE )
    {
      if( to == 0 )
      {
        if( mover == WHITE )
        {
          if( from <= die )
          {
            num_white--;
            return(VALID_MOVE);
          }
          else
          {
            return(INVALID_MOVE);
          }
        }
        else if( mover == RED )
        {
          if( (25 - from) <= die )
          {
            num_red--;
            return(VALID_MOVE);
          }
          else
          {
            return(INVALID_MOVE);
          }
        }
        else
        {
          return(INVALID_MOVE);
        }
      }
    }
  }
  return(INVALID_MOVE);
}
int check_die(int mover, int from, int to, int die)
{
  /*
  This function takes the same 4 input arguments as check move.
  This function checks validity conditions #2 and #3 described in Section 3.2
  If the two conditions are met, it returns VALID MOVE. If the two conditions
  are not met, it returns INVALID MOVE

  Condition #1
  The difference between the 'from' and the 'to' in the move
  must be positive for white checker moves, and negative for red checker moves

  Condition #2
  The absolute value of the difference between the two numbers in a move must
  match one of the rolled dice. In particular, the first move on a turn must
  match one of the die values while the second move must match the other die
  value
  */

  if(mover == WHITE)
  {
    // WHITE moves down
    if( ((from - to) == die) && (from > to) )
    {
      return(VALID_MOVE);
    }
    else if(from == 0 || to == 0)
    {
      return(VALID_MOVE);
    }
    else
    {
      return(INVALID_MOVE);
    }
  }
  if(mover == RED)
  {
    // RED moves up
    if( ((to - from) == die ) && (from < to) )
    {
      return(VALID_MOVE);
    }
    else if(from == 0 || to == 0)
    {
      return(VALID_MOVE);
    }
    else
    {
      return(INVALID_MOVE);
    }
  }
  return(INVALID_MOVE);
}
int check_board_bounds(int index)
{
  /*
  This function takes 1 input argument, “index,” which is a coordinate on
  the backgammon board. This function checks validity condition #1
  If the condition is met, it returns VALID MOVE. If the condition is not met,
  it returns INVALID MOVE

  Condition #1
  Each of the two numbers in the move must be between 1 – 24
  */

  if( (index >= 1) && (index <= 24))
  {
    return(VALID_MOVE);
  }
  else
  {
    return(INVALID_MOVE);
  }
}
