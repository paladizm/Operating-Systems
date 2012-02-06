import java.util.concurrent.Semaphore;

class BoundedBuffer implements Buffer {

   static final int BUFFER_SIZE = 5;

   int count, in, out;
   Object[] buffer;
   
   BoundedBuffer() {
      // buffer is initially empty
      count = 0;
      in = out = 0;

      buffer = new Object[BUFFER_SIZE];
   }

/* 
Consider:
   - buffer full
   - no one has lock
   - consumer sleeping
   - producer
      - calls insert()
      - gets monitor lock
      - sees that the buffer is full
      - calls yield (and thus, still owns the monitor lock)
   - consumer awakens
      - calls removes
      - blocks because it cannot get the monitor lock
   - result: deadlock
      - producer blocked waiting for consumer to free up space in the buffer
      - consumer blocked waiting for producer to release the monitor lock
 */

   public synchronized void insert (Object item) {

      while (count == BUFFER_SIZE)
         //; // busy waiting; leads to livelock

         // can lead to deadlock or livelock as well
         // beause yield() does not release the monitor lock
         //try { Thread.yield(); } catch (InterruptedException e) { }
         try { wait() } catch (InterruptedException e) { }
/* when a thread calls wait()
   1) the thread releases the lock
   2) the state of the thread is set to blocked
   3) the thread is placed on the wait set for the object (monitor)
 */

      // add an item to the buffer
      // critical section
      ++count;
      buffer[in] = item;
      in = (in + 1) % BUFFER_SIZE;

      notify();

/* when a thread calls notify()
   1) an 'arbitrary' thread t is chosen from the wait set of the object (monitor)
   2) t is moved from the wait set to the entry set of the object (monitor)
   3) the state of t is set from blocked to runnable (ready)
 */
   }

/* back to example:
   - assume buffer is full and monitor lock is available
   - producer calls insert(), attains monitor lock, and enters method
   - producer determines that the buffer is full and calls wait()
   - the call to wait()
      - releases the monitor lock,
      - sets the state of the producer to blocks, and
      - puts the producer in the wait set for the object (monitor)
   - the consumer
      - calls remove(),
      - attains the monitor lock, 
      - enters method,
      - removes an item
      - calls notify()
   - the call to notify()
      - removes the producer from the wait set of object,
      - sets the producers state to runnable (ready), and
      - moves the producer to the entry set for the object (monitor),

   - the consumer exits the remove() method and therefore, implicitly releases the object lock (monitor)
   - the producer tries to re-acquire the object lock (monitor) and is successful
      - returns from the call to wait()
      - tests the while loop condition
      - determines that space is available in the buffer, and
      - proceeds with the remainder of insert()
      - if no threads are in the wait set for the object (monitor), the call
        to notify has no effect
    - when the producer exits insert(), it releases the object lock (monitor)
 */
   public synchronized Object remove() {
  
      Object item;

      while (count == 0)
         try { wait(); } catch (InterruptedException e) { }

      // remove an item to the buffer
      // critical section
      --count;
      item = buffer[out];
      out = (out + 1) % BUFFER_SIZE;

      notify();

      return item;
   }
}
