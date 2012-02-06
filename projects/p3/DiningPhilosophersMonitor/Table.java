/*******************************************************************************
/
/      filename:  Table.java
/
/   description:  This creates the Monitor and the Philosopher threads. 
/
/        author:  Paladino, Zac
/      login id:  cps346-n1.16
/
/         class:  CPS 346
/    instructor:  Perugini
/    assignment:  PJ #3
/
/      assigned:  March 11, 2009
/           due:  April 15, 2009
/
/******************************************************************************/
class Table{
   static final int NUM_PHILOS = 5;
   
   public static void main(String args[]){
        DiningPhilosophersMonitor M = new DiningPhilosophersMonitor(NUM_PHILOS);
        for(int i=0; i<NUM_PHILOS; i++){

           (new Thread(new Philosophers(i, M))).start();
        }
   }
}
