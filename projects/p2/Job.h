/*******************************************************************************
/
/      filename:  Job.h
/
/   description:  Implements the Job Scheduler for the simulator
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

void HandleJob (list < Process > &JobQ, list < Process > &RQ1,
	   vector < string > &tokens, int &time, bool & ev, bool & eve,
	   bool & getcm, int &memory, int &count, int &tot_proc);
