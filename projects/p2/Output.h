/*******************************************************************************
/
/      filename:  Output.cpp
/
/   description:  Implements Event D for the simulator
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

void EventD (vector < string > tokens, list < Process > JobQ, list < Process > RQ1,
	list < Process > RQ2, list < Process > CPU,
	vector < Process > Finished, vector < Process > IO, int memory,
	Semephore Semephores[], bool & getcm, int time, ofstream & out,
	int CPURQ1, int CPURQ2);
