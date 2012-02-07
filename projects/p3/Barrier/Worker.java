/*******************************************************************************
/
/      filename:  Worker.java
/
/   description:  This is the worker thread. 
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
class Worker implements Runnable {

    int id;
    Barrier wall;

    Worker (int id, Barrier wall) {
       this.id = id;
       this.wall = wall;
    }

    public void run() {
       work();
    }

    void work() {
       // do some work for a while
       initialWork();
       System.out.println ("Worker " + id + " has finished its initial work.");

       System.out.println ("Worker " + id + " is waiting for the pack.");

       // now wait for others
       wall.waitForOthers();

       // now do some more work
       remainderWork(); 
    }

    void initialWork() {
       System.out.println ("Worker " + id + " is doing its initial work.");
    }

    void remainderWork() {
       System.out.println ("Worker " + id + " is doing its remainder work.");
    }
}
