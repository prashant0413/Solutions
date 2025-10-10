import java.util.Scanner;

public class problem320A {

	public static void main(String[] args) {
		// input section
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = String.valueOf(n);

		// output section
		boolean flag = true;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (s.charAt(i) - '0' == 1) {
				if (i + 1 < len && s.charAt(i + 1) - '0' == 4) {
					if (i + 2 < len && s.charAt(i + 2) - '0' == 4) {
						i += 2;
					} else {
						i += 1;
					}
				}
			} else {
				flag = false;
				break;
			}
		}
		if (flag)
			System.out.println("YES");
		else
			System.out.println("NO");
		sc.close();
	}
}
