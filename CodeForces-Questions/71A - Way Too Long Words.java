import java.util.Scanner;

public class problem71A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		StringBuilder[] s = new StringBuilder[n];
		for (int i = 0; i < n; i++) {
			String str = sc.nextLine();
			s[i] = new StringBuilder(str);
		}
		for (int i = 0; i < n; i++) {
			if (s[i].length() > 10) {
				String str = s[i].charAt(0) + String.valueOf(s[i].length() - 2) + s[i].charAt(s[i].length() - 1);
				s[i] = new StringBuilder(str);
			}
		}
		for (int i = 0; i < n; i++) {
			System.out.println(s[i].toString());
		}
		sc.close();
	}
}
