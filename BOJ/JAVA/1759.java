import java.util.*;

// 백준 암호 만들기 
// 배열 정렬에서 인덱스 실수해서 틀림
// 자바를 좀더 연습하자 
public class Main {
    static int l,c;
    static Vector <String> v = new Vector<String>();
    static char [] arr = new char[30];
    static int [] select = new int[30];
    public static void func(int idx, int cnt)
    {
        String s = "";
        int c1 = 0, c2 = 0;
        if (idx == c)
        {
            if (cnt != l)
                return;
            for (int i=0; i<c; i++)
            {
                if (select[i] != 0)
                {
                    s += arr[i];
                    if (arr[i] == 'a' || arr[i] == 'e'|| arr[i] == 'i'|| arr[i] == 'o'|| arr[i] == 'u')
                        c1++;
                    else
                        c2++;
                }
            }
            if (c1 >= 1 && c2 >= 2)
            {
                v.add(s);   
            }
            return;
        }
        if (cnt < l)
        {
            select[idx] = 1;
            func(idx + 1, cnt + 1);
            select[idx] = 0;
        }
        func(idx + 1, cnt);
        return;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        l = scan.nextInt();
        c = scan.nextInt();
        for (int i=0; i<c; i++)
        {
            arr[i] = scan.next().charAt(0);
            select[i] = 0;
        }
        Arrays.sort(arr, 0, c);
        func(0, 0);
        Collections.sort(v);
        for (int i=0; i<v.size(); i++)
            System.out.println(v.get(i));
    }

}
