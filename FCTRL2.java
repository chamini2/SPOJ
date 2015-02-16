import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	public static void main (String[] args) {
		BigInteger n = BigInteger.ONE;
		int i, c;
		Scanner in = new Scanner(System.in);
		BigInteger[] dp = new BigInteger[101];

		for (i = 1; i <= 100; i++) {
			n = n.multiply(BigInteger.valueOf(i));
			dp[i] = n;
		}

		for (i = in.nextInt(); i > 0; i--) {

			c = in.nextInt();

			System.out.println(dp[c]);
		}
	}

}