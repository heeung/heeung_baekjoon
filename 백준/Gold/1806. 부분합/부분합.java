
import java.util.*;
import java.io.*;


public class Main {

	static int N,S;
	static int[] arr;
	static int answer = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws Exception{
		init();
		
		int[] sumArr = prefix();
		
		int startIdx = 0;
		int endIdx = 1;
		
		while(true) {
			
			int partSum = sumArr[endIdx]-sumArr[startIdx];
			
			if(partSum >= S) {
				answer = Math.min(answer, endIdx-startIdx);
				startIdx++;
			}else {
				if(endIdx == N) startIdx++;
				else endIdx++;
			}
			
			if(startIdx == N) break;
			
		}
		
		if(answer == Integer.MAX_VALUE) answer = 0;
		System.out.println(answer);


		
	}
	
	// 누적합 구하기
	static int[] prefix() {
		int[] result = new int[N+1];
		for(int i=1;i<N+1;i++) {
			result[i] = result[i-1]+arr[i-1];
		}
		
		return result;
	}
	
	static void init() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] NS = br.readLine().split(" ");
		N = Integer.parseInt(NS[0]);
		S = Integer.parseInt(NS[1]);
		arr = new int[N];
		String[] input = br.readLine().split(" ");
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(input[i]);
		}
		
	}
}
