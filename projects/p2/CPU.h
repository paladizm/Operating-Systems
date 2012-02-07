/*******************************************************************************
/
/      filename:  CPU.h
/
/   description:  Implements the CPU for the simulator
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

bool DealCPU (list < Process > &CPU, list < Process > &RQ1,
	 list < Process > &RQ2, vector < Process > &Finished, int &CPURQ1,
	 int &CPURQ2, int &memory, int &time, ofstream & out);
