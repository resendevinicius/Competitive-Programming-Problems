import java.math.*;
import java.util.*;


public class p10523{
  public static void main(String ...args) {
    Scanner in = new Scanner(System.in);
    int n, a;
    while(in.hasNextInt()){
      n = in.nextInt();
      a = in.nextInt();
      BigInteger A = new BigInteger(a + "");
      BigInteger ans = BigInteger.ZERO;
      for(int i = 1; i <= n; i++){
        ans = ans.add(new BigInteger(i + "").multiply(A.pow(i)));
      }
      System.out.println(ans);
    }
    
  }
}
