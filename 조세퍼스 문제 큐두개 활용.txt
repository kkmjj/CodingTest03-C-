import java.util.*;

public class zo {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int n = input.nextInt();
		Queue<Integer> jo = new LinkedList<Integer>();
		Queue<Integer> jos = new LinkedList<Integer>();
		int m = input.nextInt();
		for(int i=1; i<=n; i++){
			jo.offer(i);
		} // 순서대로 넣어두고 
		
		
		int count =1;
		while(!jo.isEmpty()){
			
			if(count%m==0){
				jos.offer(jo.poll()); // 번째수에 값을 찾으면 jos라는 곳에 넣어둔다 
			}
			if(count%m!=0){
				jo.offer(jo.poll()); // 뺏다가 다시 넣으면 순서가 원래대로 돌아감.
			}
			count++;
		}
		System.out.print("<"+jos.poll());
		while(!jos.isEmpty()){
			System.out.print(", "+jos.poll()); // jos라는 것을 앞에서 부터 출력하면 된다 .
		}
		System.out.print(">");
	}

}
