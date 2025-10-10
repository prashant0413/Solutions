import java.util.Scanner;

public class problem318A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long k = sc.nextLong();
		long ans = 0L;
		long even = (n % 2 == 0) ? n / 2 : n - (n / 2 + 1);
		long odd = (n % 2 == 0) ? n / 2 : n / 2 + 1;
		if (k > odd) {
			k -= odd;
			ans = 2 * k;
		}
		else {
			ans = 2 * k - 1;
		}
		System.out.println(ans);
		sc.close();

	}
}
