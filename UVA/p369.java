import java.util.Scanner;
import java.math.*;


public class Main{
  public static void main(String ...args){
    BigInteger fat[] = new BigInteger[101];
    fat[0] = fat[1] = BigInteger.ONE;
    Scanner s = new Scanner(System.in);
    for(int i = 2; i <= 100; i++){
      BigInteger mult = new BigInteger(i + "");
      fat[i] = mult.multiply(fat[i - 1]);
    }
    int n, m;
    while(true){
      n = s.nextInt();
      m = s.nextInt();
      if(n == 0 && m == 0){
        break;
      }
      BigInteger ans = fat[n].divide(fat[n - m].multiply(fat[m]));
      System.out.println(n + " things taken " + m + " at a time is " + ans + " exactly.");
      
    }
  }
}
