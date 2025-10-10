import java.util.Arrays;
import java.util.Scanner;

public class problem218A {
	public static void main(String[] args) {
		// input section
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] arr = new int[m];
		for (int i = 0; i < m; i++)
			arr[i] = sc.nextInt();

		// output section
		Arrays.sort(arr);
		int min = 0;
		int max = 0;
		int k = 0;
		int num = arr[k];
		// finding min
		for (int i = 1; i <= n; i++) {
			min += num;
			num--;
			if (num == 0 && k + 1 < m)
				num = arr[++k];
		}
		
		// finding max
		Arrays.sort(arr);
		while (n != 0) {
			max += arr[m -1];
			arr[m - 1]--;
			for (int i = m - 2; i >= 0; i--) {
				if (arr[i] <= arr[i + 1])
					break;
				arr[i] = arr[i] ^ arr[i + 1];
				arr[i + 1] = arr[i] ^ arr[i + 1];
				arr[i] = arr[i] ^ arr[i + 1];
			}
			n--;
		}
		System.out.println(max + " " + min);
		sc.close();
	}
}
