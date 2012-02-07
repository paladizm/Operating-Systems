/**
 * An interface for reader-writer locks.
 *
 * In the text we do not have readers and writers
 * pass their number into each method. However we do so
 * here to aid in output messages.
 */

public interface RWLock {
   public abstract void acquireReadLock(int readerNum);
   public abstract void releaseReadLock(int readerNum);

   public abstract void acquireWriteLock(int writerNum);
   public abstract void releaseWriteLock(int writerNum);
}
