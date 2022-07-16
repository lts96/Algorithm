import java.io.*
import java.util.*
import kotlin.collections.ArrayList


val max = 100
var visit = Array(max + 1) {0}
var arr = Array(101, {0})
var ans = 0
fun bfs(s : Int){
    var q : Queue<Pair<Int, Int>> = LinkedList()
    visit[s] = 1
    q.add(s to 0)
    var x : Int
    var d : Int
    var next : Int
    while(!q.isEmpty()){
        x = q.peek().first
        d = q.peek().second
        q.poll()
        if (x == 100){
            ans = d
            return
        }
        for (i in 1..6){
            next = i + x
            if (next < 1 || next > 100)
                continue
            if (arr[next] != 0)
                next = arr[next]
            //println(next)
            if (visit[next] == 0){
                visit[next] = 1
                q.add(next to d + 1)
            }
        }
    }
}

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    for (i in 1..n + m){
        val (a, b) = br.readLine().split(" ").map{ it.toInt() }
        arr[a] = b
    }
    bfs(1)
    bw.write(ans.toString())
    bw.flush()
    bw.close()
}
