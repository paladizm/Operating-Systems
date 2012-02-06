/*******************************************************************************
/
/      filename:  IO.h
/
/   description:  Implements the I/O for the simulator
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

void HandleIO (vector < Process > &IO, list < Process > &CPU,
	  list < Process > &RQ1, vector < string > &tokens, int &time,
	  bool & getcm, list < Process > &RQ2, vector < Process > &Finished,
	  int &CPURQ1, int &CPURQ2, int &memory, ofstream & out, bool & NOGO);
