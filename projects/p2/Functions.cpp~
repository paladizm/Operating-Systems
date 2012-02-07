/*******************************************************************************
/
/      filename:  Functions.cpp
/
/   description:  Usefull functions to convert strings to ints and 
/                 to make tokens.
/
/        author:  Paladino, Zac
/      login id:  cps346-n1.16
/
/         class:  CPS 346
/    instructor:  Perugini
/    assignment:  PJ #2 
/
/      assigned:  February 18, 2009
/           due:  March 11, 2009
/
/******************************************************************************/

#include <iostream>
#include <iomanip>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*********************** Function: MakeTokens ********************/
//This function makes tokens out of the numbers/letters given in the
//input file and places them into a vector for ease of use.
//Pre: The numbers/letters must be the ones that you want to be in
//         the vector. It takes care of all the whitespace.
//Post: Return the vector with tokens in it.
vector < string > MakeTokens (const string & str, const string & delim)
{
  vector < string > tokens;
  size_t p = 0, p1 = string::npos;
  while (p != string::npos) {
    p1 = str.find_first_of (delim, p);
    if (p1 != p) {
      string token = str.substr (p, p1 - p);
      tokens.push_back (token);
    }
    p = str.find_first_not_of (delim, p1);
  }
  return tokens;
}

/*********************** Function: StringToInt ********************/
//This function makes strings into ints.
//Pre: The string must be an integer before placing in function.
//Post: Returns the int from the conversion of the string.
int
StringToInt (string strconvert)
{
  int conversion;
  conversion = atoi (strconvert.c_str ());
  return (conversion);
}
