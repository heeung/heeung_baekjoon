import java.io.*;
import java.util.*;

class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		String[] arr1 = br.readLine().split(" ");
		int[] numArr1 = new int[N];
		for (int i = 0; i < N; i++) {
			numArr1[i] = Integer.parseInt(arr1[i]);
		}
		
		Arrays.sort(numArr1);
		
		int M = Integer.parseInt(br.readLine());
		String[] arr2 = br.readLine().split(" ");
		int[] numArr2 = new int[M];
		for (int i = 0; i < M; i++) {
			numArr2[i] = Integer.parseInt(arr2[i]);
		}

		for (int i = 0; i < M; i++) {
			System.out.println(binarySearch(numArr1, numArr2[i]));
		}
	}

	public static int binarySearch(int[] nums, int target) {

		int end = nums.length - 1;
		int start = 0;
		int mid = 0;

		while (start <= end) {
			mid = (start + end) / 2;

			if (nums[mid] == target)
				return 1;
			else if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
		return 0;
	}
}
