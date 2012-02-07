/*******************************************************************************
/
/      filename:  DiningServer.java
/
/   description:  This is Dining Server interface. 
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
interface DiningServer {
    // called by a philosopher when the philosopher gets hungry
    public void pickupForks(int id);

    // called by a philosopher when the philosopher is finished eating
    public void releaseForks(int id);
}
