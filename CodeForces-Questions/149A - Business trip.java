import java.util.Arrays;
import java.util.Scanner;

public class program149A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int months[] = new int[12];
		for (int i = 0; i < 12; i++) {
			months[i] = sc.nextInt();
		}
		Arrays.sort(months);
		int count = 0;
		for (int i = 11; i >= 0; i--) {
			if (k <= 0)
				break;
			k -= months[i];
			count++;
		}
		if (k > 0)
			System.out.println(-1);
		else
		System.out.println(count);
		sc.close();
	}
}
