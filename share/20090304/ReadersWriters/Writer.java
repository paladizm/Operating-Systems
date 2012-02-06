/**
 * Writer.java
 *
 * A writer to the database.
 *
 */
class Writer implements Runnable {

   RWLock db;
   int writerNum;

   Writer(int writercount, RWLock db) {
      this.writerNum = writerNum;
      this.db = db;
   }

   public void run() {

      while (true) {
   
         SleepUtilities.nap();

         System.out.println("writer " + writerNum + " wants to write.");

         db.acquireWriteLock(writerNum);

         // you have access to write to the database
         // write for awhile ...
         SleepUtilities.nap();

         db.releaseWriteLock(writerNum);
      }
   }
}
