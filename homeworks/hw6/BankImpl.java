public class BankImpl implements Bank {

   private int numOfCustomers = Customer.COUNT;
   private int numOfResources;

   private int[] available;
   private int[][] maximum;
   private int[][] allocation;
   private int[][] need;

   public BankImpl(int[] initResourcesAvailable) {
       available = initResourcesAvailable;
       numOfResources = 3;
       maximum = new int[numOfCustomers][numOfResources];  
       allocation = new int[numOfCustomers][numOfResources];  
       need = new int[numOfCustomers][numOfResources];  
  }

   public void addCustomer(int customerNum, int[] maxDemand) {
   	maximum[customerNum][]=maxDemand;
        need[customerNum][]=maxDemand;
   }

   public void getState() {
        System.out.println(available[0] + " " + available[1] + " " + available[2]);
   }
 
   public boolean requestResources(int customerNum, int[] request) {
   	
   }

   public void releaseResources(int customerNum, int[] release) {
   	
   }
}
