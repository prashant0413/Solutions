import java.util.Scanner;

public class problem215A {

	public static void main(String[] args) {
		// input section
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr1 = new int[n];
		for (int i = 0; i < n; i++)
			arr1[i] = sc.nextInt();
		int m = sc.nextInt();
		int[] arr2 = new int[m];
		for (int i = 0; i < m; i++)
			arr2[i] = sc.nextInt();

		// output section
		int count = 0;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int pi = arr2[j] % arr1[i];
				if (pi == 0) {
					int div = arr2[j] / arr1[i];
					if (div > max) {
						max = div;
						count = 1;
					} else if (div == max)
						count++;
				}
			}
		}
		System.out.println(count);
		sc.close();
	}
}
