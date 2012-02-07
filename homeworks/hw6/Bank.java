public interface Bank {

   // adds a customer
   public void addCustomer(int customerNum, int[] maxDemand);

   // output the value of available, maximum, allocation, and need
   public void getState();
 
   // returns true if the request is granted
   // returns false if the request is not granted
   public boolean requestResources(int customerNum, int[] request);

   public void releaseResources(int customerNum, int[] release);
}
