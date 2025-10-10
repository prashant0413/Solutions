import java.util.Scanner;

public class problem272A {

	public static void main(String[] args) {
		// input section
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}

		// output section
		int sum = 0;
		for (int i : arr)
			sum += i;
		int cnt = 0;
		for (int i = 1; i <= 5; i++) {
			if ((sum + i) % (n + 1) != 1)
				cnt++;
		}
		System.out.println(cnt);
		sc.close();
	}
}
