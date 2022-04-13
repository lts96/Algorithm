import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 백준 트럭
// 큐를 사용해서 트럭을 하나씩 집어넣고 빼는 구현 문제 
// 중요한건 먼저 앞에서 빼고 그 다음에 넣어야 한다는것 

public class Main {
	
	static int n,w,l,ans, pass, curr;
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		w = scan.nextInt();
		l = scan.nextInt();
		int arr[] = new int[n];
		LinkedList<Integer> q = new LinkedList<Integer>();
		for (int i=0; i<n; i++)
			arr[i] = scan.nextInt();
		for (int i=0; i<w; i++)
			q.add(0);
		int idx = 0;
		while(true)
		{
			curr -= q.getFirst();
			ans++;
			if (q.poll() == arr[pass])
			{
				pass++;
				//System.out.println(ans + " " + curr);
			}
			if (idx < n && curr + arr[idx] <= l)
			{
				q.addLast(arr[idx]);
				curr += arr[idx];
				idx++;
			}
			else
				q.addLast(0);
			if (pass == n)
				break;
		}
		System.out.println(ans);
	}
}
