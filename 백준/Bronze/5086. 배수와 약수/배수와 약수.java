import java.io.*;
import java.util.*;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
		int num1 = 0;
		int num2 = 0;
        
		StringTokenizer st;
        
		while(true){
			st = new StringTokenizer(br.readLine(), " ");
            
			num1 = Integer.parseInt(st.nextToken());
			num2 = Integer.parseInt(st.nextToken());
            
			if(num1 == 0 && num2 == 0)
                break;
            
			if(num2 % num1 == 0)
				System.out.println("factor");
			else if(num1 % num2 == 0)
				System.out.println("multiple");
			else
				System.out.println("neither"); 
		}
	}
}