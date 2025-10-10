import java.util.Scanner;

public class problem450A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = sc.nextInt();
		double maxRounds = 0;
		int pos = n;
		for (int i = 0; i < n; i++) {
			double rounds = Math.ceil((double) arr[i] / m);
			if (rounds >= maxRounds) {
				maxRounds = rounds;
				pos = i + 1;
			}
		}
		System.out.println(pos);
	}
}
