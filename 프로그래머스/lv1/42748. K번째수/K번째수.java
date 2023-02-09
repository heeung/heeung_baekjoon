import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for (int i = 0; i < commands.length; i++) {
            int[] arr = array.clone();
        	Arrays.sort(arr, commands[i][0] - 1, commands[i][1]);
        	int index = commands[i][0] - 1 + commands[i][2] - 1;
            answer[i] = arr[index];
        }
        
         return answer;
     }
}