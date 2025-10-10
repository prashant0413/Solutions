import java.util.Scanner;

public class problem80A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();

		int cnt = 0;
		int x = -1;
		for (int i = n + 1; i <= m; i++) {
			if (isPrime(i)) {
				x = i;
				break;
			}
		}
		System.out.println((x == m) ? "Yes" : "NO");
	}

	public static boolean isPrime(int n) {
		int cnt = 0;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				cnt++;
			}
		}
		return (cnt == 0) ? true : false;
	}
}
