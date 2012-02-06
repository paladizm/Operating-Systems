/**
 * Reader.java
 *
 * A reader to the database.
 *
 */

class Reader implements Runnable {

   RWLock db;
   int readerNum;

   Reader (int readerNum, RWLock db) {
      this.readerNum = readerNum;
      this.db = db;
   }

   public void run() {

      while (true) {
         SleepUtilities.nap();

         System.out.println("reader " + readerNum + " wants to read.");
         db.acquireReadLock(readerNum);

         // you have access to read from the database
         // let's read for awhile .....
         SleepUtilities.nap();

         db.releaseReadLock(readerNum);
      }
   }
}
