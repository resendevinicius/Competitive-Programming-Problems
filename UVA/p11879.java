import java.math.*;
import java.io.*;


public class p11879{
    
  public static void main(String ... args){
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line = "";
    try{
      while((line = in.readLine()) != null){
        if(line.equals("0")) break;
        BigInteger lol = new BigInteger(line);
        if(lol.mod(new BigInteger("17")) == BigInteger.ZERO){
          System.out.println(1);
        } else {
          System.out.println(0);
        }
      }
    } catch (Exception e) {
      System.out.println("FODASE");
    }
  }
}
