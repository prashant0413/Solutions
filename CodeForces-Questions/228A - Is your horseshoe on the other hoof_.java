import java.util.Arrays;
import java.util.Scanner;

public class problem228A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] arr = new int[4];
		for (int i = 0; i < 4; i++) {
			arr[i] = sc.nextInt();
		}

		Arrays.sort(arr);
		int cnt = 1;
		int last = arr[0];
		for (int i = 1; i < 4; i++) {
			if (last != arr[i]) {
				cnt++;
				last = arr[i];
			}
		}

		System.out.println(4 - cnt);
	}
}
