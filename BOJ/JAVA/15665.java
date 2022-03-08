import java.io.*;
import java.util.*;
import java.util.stream.IntStream;
import java.awt.*;

// 사전순으로 나열하기 위해 작은 숫자가 먼저 오도록 소팅해준다
// 중복되는 숫자는 지워버리고 나온것만 추려서 배열에 넣어준다 
// 그리고 백트래킹 돌면서 순차적으로 m개를 뽑아 출력하면 끝
public class Main {
	
	static int arr[] = new int[10];
	static int arr2[];
	static int n, m;
	static int select[] = new int[10];
	
	static void backtracking(int idx)
	{
		if (idx == m)
		{
			StringBuilder s = new StringBuilder();
			for (int i=0; i<m; i++)
				s.append(select[i]).append(" ");
			System.out.println(s);
			return;
		}
		for (int i = 0; i < arr2.length - 1; i++)
		{
			select[idx] = arr2[i];
			backtracking(idx + 1);
		}
		return;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		for (int i=0; i<10; i++)
			arr[i] = Integer.MAX_VALUE;
		for (int i=0; i<n; i++)
			arr[i] = scan.nextInt();
		Arrays.sort(arr);
		arr2 = IntStream.of(arr).distinct().toArray();
		backtracking(0);
	}
}
