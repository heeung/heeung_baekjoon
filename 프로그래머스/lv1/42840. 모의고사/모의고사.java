//프로그래머스 모의고사
import java.util.*;

class Solution {
	static int[] cnt1 = new int[3];

	public int[] solution(int[] answers) {
		List<Integer> arr = new ArrayList<>();
		
        int[] arr1 = {1, 2, 3, 4, 5};
        int[] arr2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] arr3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        recur(answers, arr1, 0, 1);
        recur(answers, arr2, 0, 2);
        recur(answers, arr3, 0, 3);
        
		System.out.println(cnt1[0]);
		System.out.println(cnt1[1]);
		System.out.println(cnt1[2]);
		
		int max = 0;
        for (int i = 0; i < 3; i++) {
        	if (max < cnt1[i]) {
        		max = cnt1[i];
        	}
        }
        for (int j = 0; j < 3; j++ ) {
        	if (max == cnt1[j]) {
        		arr.add(j);
        	}
        }
        int[] answer = new int[arr.size()];
        
        for (int k = 0; k < arr.size(); k++) {
        	answer[k] = arr.get(k) + 1;
        }
		return answer;
	}

	public void recur(int[] answers, int[] p, int index, int flag) {
		for (int i = 0; i < p.length; i++) {
            int cnt = 0;
			if (index + i >= answers.length) {
				return ;
            }
			if (p[i] == answers[index + i]) {
				cnt++;
			}
            if (flag == 1)
			    cnt1[0] += cnt;
		    else if (flag == 2)
			    cnt1[1] += cnt;
		    else
			    cnt1[2] += cnt;
		}
		
		recur(answers, p, index + p.length, flag);
	}
}

