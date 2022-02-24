import java.io.*;
import java.util.*;

public class Main {
	
/*
반례 
1
4 10
2 10
4 20
2 20
3 30
1 30
답:700
*/
  // 기하문제고 이거보다 좀더 간단한 방법도 있음
  // 내가 푼 방식은 제일 긴 가로세로 찾고 이것과 연결되지 않은 반대쪽 가로세로를 찾아서 각자의 넓이를 빼준것 
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int ans = 0;
		int arr[][] = new int[6][2];
		int mx = 0,my = 0,nx = Integer.MAX_VALUE,ny = Integer.MAX_VALUE;
		for (int i=0; i<6; i++)
		{
			arr[i][0] = scan.nextInt();
			arr[i][1] = scan.nextInt();
		}
		int mx_idx = 0, my_idx = 0;
		// 단순히 최대 최소를 가지고 했다간 걸리는 반례가 존재 
		for (int i=0; i<6; i++)
		{
			if (arr[i][0] >= 3)
			{
				nx = Math.min(nx, arr[i][1]);
				if (mx < arr[i][1])
				{
					mx = Math.max(mx, arr[i][1]);
					mx_idx = i;
				}
			}
			else
			{
				ny = Math.min(ny, arr[i][1]);
				if (my < arr[i][1])
				{
					my = Math.max(my, arr[i][1]);
					my_idx = i;
				}
			}
		}
		// 가장 긴 가로 세로에 붙은 변의 길이를 -1로 초기화시켜서 반대쪽 변 2개의 길이만 남긴다
		for (int i=0; i<6; i++)
		{
			if (i == mx_idx)
			{
				arr[i][1] = -1;
				if (i - 1 >= 0)
					arr[i-1][1] = -1;
				if (i + 1 < 6)
					arr[i+1][1] = -1;
				if (i == 0)
					arr[5][1] = -1;
				else if (i == 5)
					arr[0][1] = -1;
			}
			else if (i == my_idx)
			{
				arr[i][1] = -1;
				if (i - 1 >= 0)
					arr[i-1][1] = -1;
				if (i + 1 < 6)
					arr[i+1][1] = -1;
				if (i == 0)
					arr[5][1] = -1;
				else if (i == 5)
					arr[0][1] = -1;
			}
		}
		for (int i=0; i<6; i++)
		{
			if (arr[i][0] >= 3)
			{
				if (arr[i][1] != -1)
					nx = arr[i][1];
			}
			else
			{
				if (arr[i][1] != -1)
					ny = arr[i][1];
			}
		}
		ans = (mx * my - nx * ny) * k;
		//System.out.println(mx + " " + my + " " + nx + " " + ny);
		System.out.println(ans);
	}	
}
