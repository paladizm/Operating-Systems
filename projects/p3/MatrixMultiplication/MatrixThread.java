/*******************************************************************************
/
/      filename:  MatrixThread.java
/
/   description:  This is the thread that does the calculations for the
/                 individual places of the product matrix. 
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
class MatrixThread implements Runnable{

     int row, column, id, size;
     double matrixA[][];
     double matrixB[][];
     double matrixP[][];
     Barrier wall;

     MatrixThread (int r, int c, int s, int si, double matrixa[][], 
                   double matrixb[][], double matrixp[][], Barrier w){
           this.row = r;
           this.column = c;
           this.id = s;
           this.size = si;
           this.matrixA=matrixa;
           this.matrixB=matrixb;
           this.matrixP=matrixp;
           this.wall = w;
     }
     public void run(){
          double sum = 0.0;
          for(int i=0; i<3; i++){
             sum += (matrixA[row][i]*matrixB[i][column]);
           }
          matrixP[row][column] = sum;
          wall.waitForOthers();

          if(id == (size-1)){
            for(int i=0; i<2; i++){
              for(int k=0; k<2; k++){
                System.out.print( matrixP[i][k] + " ");
              }
              System.out.println();
            }
          }
     }
} 
     
