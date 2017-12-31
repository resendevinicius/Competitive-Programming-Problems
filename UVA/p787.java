import java.math.*;
import java.util.*;


public class p787 {
  public static void main(String ... args){
    Scanner in = new Scanner(System.in);
    while(in.hasNextInt()){
      int v[] = new int[111];
      int n = 0;
      int x;
      while((x = in.nextInt()) != -999999){
        v[n++] = x;
      }
      BigInteger ans = new BigInteger("-9999999999999999999999999999999");
      for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
          BigInteger at = BigInteger.ONE;
          for(int k = i; k <= j; k++){
            at = at.multiply(new BigInteger(v[k] + ""));
          }
          ans = ans.max(at);
        }
        
      }
      System.out.println(ans);
    }
    
    
  }
}
