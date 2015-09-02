#include <stdio.h>
#include <math.h>
#include "TutorialConfig.h"
#include "Table.h"

double powerOfTen(int num){
   double rst = 1.0;
   if(num >= 0){
       for(int i = 0; i < num ; i++){
           rst *= 10.0;
       }
   }else{
       for(int i = 0; i < (0 - num ); i++){
           rst *= 0.1;
       }
   }
   return rst;
}



double mysqrt(double a)
{
     // if we have both log and exp then use them, otherwise use an iterative approach
#if defined (HAVE_LOG) && defined (HAVE_EXP)
     fprintf(stdout,"Computing with exp and log functions...");
     double result = 0.0;
     result = exp(log(a)*0.5);
     return result;
#else 
     // find more detail of this method on wiki methods_of_computing_square_roots
     // Babylonian method cannot get exact zero but approximately value of the square_root
     fprintf(stdout,"Computing with an iterative approach...");
     double z = a; 
     double rst = 0.0;
     int max = 8;     // to define maximum digit 
     int i;
     double j = 1.0;
     for(i = max ; i > 0 ; i--){
         // value must be bigger then 0
         if(z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
         {
             while( z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
             {
                 j++;
                 if(j >= 10) break;

             }
             j--; //correct the extra value by minus one to j
             z -= (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)); //find value of z
 
             rst += j * powerOfTen(i);     // find sum of a

             j = 1.0;
 
 
           }
 
      }
 
      for(i = 0 ; i >= 0 - max ; i--){
          if(z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
          {
              while( z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
              {
                  j++;

              }
              j--;
              z -= (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)); //find value of z
 
              rst += j * powerOfTen(i);     // find sum of a
              j = 1.0;
           }
      }
      // find the number on each digit
      return rst;
#endif
}
