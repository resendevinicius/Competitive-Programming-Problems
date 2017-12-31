import java.math.*;
import java.util.*;

public class p10198{
  static int n;
  static boolean memo[] = new boolean [1111];
  static BigInteger pd[] = new BigInteger[1111];
  static int v[] = {1,2,3,1};
  public static void main(String ...args){
    Scanner s = new Scanner(System.in);
    
    while(s.hasNextInt()){
      n = s.nextInt();
      for(int i = 0; i < 1111; i++) memo[i] = false;
      System.out.println(f(0));
    }
  }
  
  static BigInteger f(int sum){
    if(sum == n) return BigInteger.ONE;
    if(sum > n) return BigInteger.ZERO;
    if(memo[sum]){
      return pd[sum];
    }
    BigInteger ans = new BigInteger("0");
    for(int i = 0; i < 4; i++){
      ans = ans.add(f(sum + v[i]));
    }
    memo[sum] = true;
    return pd[sum] = ans;
  }
}
