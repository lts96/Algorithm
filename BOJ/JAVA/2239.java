import java.io.*;
import java.util.*;


public class Main {
	
	static int n, k, ans;
	static int arr[][] = new int[10][10];
	static boolean flag;
	static void print()
	{
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				System.out.print(arr[i][j]);
			}
			System.out.println();
		}
	}
	
	static void find_num(int cnt[] , int x, int y)
	{
		for (int i=0; i<9; i++)
			cnt[arr[i][y]]++;
		for (int i=0; i<9; i++)
			cnt[arr[x][i]]++;
		
		int sx = x - (x % 3);
		int sy = y - (y % 3);
		int dx = sx + 3;
		int dy = sy + 3;
		
		for (int i=sx; i<dx; i++)
		{
			for (int j=sy; j<dy; j++)
				cnt[arr[i][j]]++;
		}
	}
	static void backtracking(int idx)
	{
		int x = idx / 9;
		int y = idx % 9;
		
		int cnt[] = new int[10];
		if (x == n && y == 0)
		{
            if (!flag)
            {
                print();
                flag = true;
            }
			return;
		}
    // 이거 중요. 이미 정답에 도달했으면 나머지 가지는 더이상 볼 필요가 없음 
        if (flag)
			return;
		if (arr[x][y] != 0)
			backtracking(idx + 1);
		else
		{
			find_num(cnt, x, y);
			for (int i=1; i<=9; i++)
			{
				if (cnt[i] == 0)
				{
					arr[x][y] = i;
					backtracking(idx + 1);
				}
			}
			arr[x][y] = 0;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = 9;
		for (int i=0; i<n; i++)
		{
			String s = scan.next();
			for (int j=0; j<n; j++)
				arr[i][j] = s.charAt(j) - '0';
		}
		backtracking(0);
		
	}
}
