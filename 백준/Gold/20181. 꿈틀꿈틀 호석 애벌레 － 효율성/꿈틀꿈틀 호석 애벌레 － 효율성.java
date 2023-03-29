import java.io.*;
import java.util.*;

public class Main {
	
	static int N, K;
	static int[] arr;
	static int[] dp;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new int[N];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        dp = new int[N + 1];
        int sum = arr[0];
        // 투 포인터
        int leftIdx = 0;
        int rightIdx = 1;

        while (rightIdx <= N) {
            if (sum >= K) {
                while (sum >= K) {
                    dp[rightIdx] = Math.max(dp[rightIdx], dp[leftIdx] + sum - K);
                    sum -= arr[leftIdx++];
                }
            } else {
                dp[rightIdx] = Math.max(dp[rightIdx], dp[rightIdx - 1]);
                
                if (rightIdx == N)
                    break;
                
                sum += arr[rightIdx++];
            }
//            System.out.println(Arrays.toString(dp));
        }

        System.out.println(dp[N]);
    }

}