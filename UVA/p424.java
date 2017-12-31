import java.math.*;
import java.util.Scanner;
public class Main{
  public static void main(String ...args){
    Scanner s = new Scanner(System.in);
    
    String number;
    BigInteger answer = BigInteger.ZERO;
    while(true){
      number = s.nextLine();
      if(number.equals("0")){
        break;
      }
      BigInteger x = new BigInteger(number);
      answer = answer.add(x);
    }
    System.out.println(answer);
  }
}
