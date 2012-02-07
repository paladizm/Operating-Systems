/*******************************************************************************
/
/      filename:  Semephore.h
/
/   description:  Implements Semephores for the simulator
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

void HandleSem (vector < string > &tokens, Semephore Semephores[],
	   list < Process > &CPU, list < Process > &RQ1,
	   list < Process > &RQ2, vector < Process > &Finished, int &memory,
	   int &count, int &CPURQ1, int &CPURQ2, bool & getcm, int &time,
	   ofstream & out, bool & ew, bool & es);
