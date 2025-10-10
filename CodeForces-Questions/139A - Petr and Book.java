import java.util.Scanner;

public class problem139A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int arr[] = new int[7];
		for (int i = 0; i < 7; i++) {
			arr[i] = in.nextInt();
		}
		int rem = n;
		int i = 0;
		while (rem != 0) {
			rem -= arr[i];
			if (rem <= 0)
				break;
			i = (i + 1) % 7;
		}
		System.out.println(i + 1);
		in.close();
	}
}
