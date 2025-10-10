import java.util.Scanner;

public class problem58A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String str = "hello";
		int j = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == str.charAt(j)) {
				j++;
				if (j >= 5)
					break;
			}
		}
		System.out.println((j == 5) ? "YES" : "NO");
		sc.close();
	}
}
