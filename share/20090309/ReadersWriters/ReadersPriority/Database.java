/**
 * Database.java
 *
 * This class contains the methods the readers and writers will use
 * to coordinate access to the database.
 *
 */

class Database implements RWLock {
   // the number of active readers
   int readerCount;
 
   // is the db currently being written
   boolean dbWriting;

   Database() {
      readerCount = 0;
      dbWriting = false;
   }

   // reader will call this when they start reading
   public synchronized void acquireReadLock(int readerNum) {

      while (dbWriting == true)
         try { wait(); } catch (InterruptedException e) { }

      ++readerCount;

      System.out.println("Reader " + readerNum + " is reading. Reader count = " + readerCount);
   }

   public synchronized void releaseReadLock(int readerNum) {
      --readerCount;

      System.out.println("Reader " + readerNum + " is done reading. Reader count = " + readerCount);

      // if I am the last reader tell _a_ waiting writer
      // that the database is no longer being read
      if (readerCount == 0)
         notify();
   }

   // writer will call this when they start writing
   public synchronized void acquireWriteLock(int writerNum) {

      while (readerCount > 0 || dbWriting == true)
         try { wait(); } catch (InterruptedException e) { }
 
      // once there are either no readers or writers
      // indicate that the database is being written
      dbWriting = true;

      System.out.println("writer " + writerNum + " is writing.");
   }

   // writer will call this when they stop writing
   public synchronized void releaseWriteLock(int writerNum) {
      dbWriting = false;

      System.out.println("writer " + writerNum + " is done writing.");

      // want to notify All readers
      notifyAll();
   }
}
