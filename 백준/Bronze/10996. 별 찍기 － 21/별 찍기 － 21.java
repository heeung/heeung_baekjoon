import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		if (n == 1) {
			System.out.println('*');
		} else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j % 2 == 0) {
						System.out.print('*');
					} else {
						System.out.print(' ');
					}
				}
				System.out.println();
				for (int k = 0; k < n; k++) {
					if (k % 2 == 0) {
						System.out.print(' ');
					} else {
						System.out.print('*');
					}
				}
				System.out.println();
			}
		}
	}

}