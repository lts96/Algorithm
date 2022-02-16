import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Solution {
	static int win, loss;
	static int enemy[] = new int[9];
	static int data[] = new int[9];
	static ArrayList <Integer> me = new ArrayList<Integer>();
	static boolean select[] = new boolean[9];
  
  // 브루트 포스로 9! 돌면서 모든 경우의 수 탐색하고 조건 체크하는 
	public static void brute(int idx) {
		if (idx == 9) 
		{
			int sum1 = 0;
			int sum2 = 0;
			for (int i=0; i<9; i++)
			{
				if (enemy[i] > data[i])
					sum2 += (enemy[i] + data[i]);
				else
					sum1 += (data[i] + enemy[i]);
			}
			if (sum1 > sum2)
				win++;
			else
				loss++;
		}
		int d = 0;
		for (int i= 0; i < 9; i++)
		{
			if (select[i])
				continue;
			select[i] = true;
			data[idx] = me.get(i);
			brute(idx + 1);
			select[i] = false;
		}
	}
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		for (int t = 1; t <= test; t++)
		{
			win = 0; 
			loss = 0;
			boolean choose[] = new boolean[20];
			for (int i=0; i<9; i++)
			{
				enemy[i] = scan.nextInt();
				choose[enemy[i]] = true;
				me.add(0);
			}
			int d = 0;
			for (int i=1; i<= 18; i++)
			{
				if (choose[i] == false)
					me.set(d++, i);
			}
			brute(0);
			System.out.println("#" + t + " " + loss + " " + win);
			for (int i=0; i<9; i++)
			{
				enemy[i] = 0;
				me.set(i, 0);
				data[i] = 0;
				select[i] = false;
			}
		}
	}
}
