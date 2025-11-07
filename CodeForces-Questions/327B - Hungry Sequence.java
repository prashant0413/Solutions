import java.util.Scanner;

public class Problem327B {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int cnt = 0;
		for (int i = 1; cnt < n; i++) {
			System.out.print(n + i + " ");
			cnt++;
		}
	}
}
