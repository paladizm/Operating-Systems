/**
 * Database.java
 *
 * This class contains the methods the readers and writers will use
 * to coordinate access to the database.
 *
 */
import java.util.concurrent.Semaphore;

class Database implements RWLock {
   // the number of active readers
   int readerCount;

   // provides mutex for readerCount
   Semaphore mutex;
   // provides mutex for writers
   // also used by readers to prevent writers to enter a db being read
   Semaphore db;

   public Database() {
      readerCount = 0;
      mutex = new Semaphore(1);
      db = new Semaphore(1);
   }

   // reader will call this when they start reading
   public void acquireReadLock(int readerNum) {
      try { mutex.acquire(); } catch (InterruptedException e) { }
      ++readerCount;


      // if I am the first reader tell all other
      // that the database is being read
      if (readerCount == 1) {
         try { db.acquire(); } catch (InterruptedException e) { }
         System.out.println("Reader " + readerNum + " has acquired db semaphore. Reader count = " + readerCount);
      }

      System.out.println("Reader " + readerNum + " is reading. Reader count = " + readerCount);

      mutex.release();
   }

   public void releaseReadLock(int readerNum) {
      try { mutex.acquire(); } catch (InterruptedException e) { }
      --readerCount;

      // if I am the last reader tell all others
      // that the database is no longer being read
      if (readerCount == 0) {
         db.release();
         System.out.println("Reader " + readerNum + " signaled db semaphore. Reader count = " + readerCount);
 
      }

      System.out.println("Reader " + readerNum + " is done reading. Reader count = " + readerCount);
      mutex.release();
   }

   // writer will call this when they start writing
   public void acquireWriteLock(int writerNum) {

      try { db.acquire(); } catch (InterruptedException e) { }

      System.out.println("writer " + writerNum + " is writing.");
   }

   // writer will call this when they stop writing
   public void releaseWriteLock(int writerNum) {
      db.release();

      System.out.println("writer " + writerNum + " is done writing.");
   }
}
