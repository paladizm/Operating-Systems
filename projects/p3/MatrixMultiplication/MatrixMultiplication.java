/*******************************************************************************
/
/      filename:  MatrixMultiplication.java
/
/   description:  This is the class that implements main that calls the 
/                 individual matrix threads that create the product matrix. 
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
import java.lang.Object;
class MatrixMultiplication{
     static final int NUM_THREAD = 4;

     public static void main(String args[]){
            double matrixA[][] = {{1.0,0.0,2.0},{-1.0,3.0,1.0}};
            double matrixB[][] = {{3.0,1.0},{2.0,1.0},{1.0,0.0}};
            double[][] matrixP = new double[2][2];
            Barrier wall = new Barrier(NUM_THREAD);
           
            int count = 0; 
            for(int i=0;i<2;i++){
              for(int k=0;k<2;k++){ 
                 (new Thread(new MatrixThread(i,k,count,NUM_THREAD,matrixA,matrixB,matrixP,wall))).start();
                  count++;
              }
          }
    }
}
