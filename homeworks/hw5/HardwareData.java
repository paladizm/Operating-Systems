/*******************************************************************************
/
/      filename:  HardwareData.java
/
/   description: This program takes care of syncronizing and making the class
/                thread safe. 
/
/        author:  Paladino, Zac
/      login id:  cps346-01.16
/
/         class:  CPS 346
/    instructor:  Perugini
/    assignment:  Homework #5
/
/      assigned:  March 10, 2009
/           due:  March 17, 2009
/
/******************************************************************************/

class HardwareData {
   private boolean value = false;

   HardwareData (boolean value) {
      this.value = value;
   }

   synchronized boolean get() {
      return value;
   }

   synchronized void set (boolean newValue) {
      value = newValue;
   }
 
   // must be atomic
   synchronized boolean getAndSet (boolean newValue) {
      boolean oldValue = this.get();
      this.set (newValue);

      return oldValue;
   }

   // must be atomic
   synchronized void swap (HardwareData other) {
      boolean temp = this.get();

      this.set (other.get());
      other.set(temp);
   }
}

