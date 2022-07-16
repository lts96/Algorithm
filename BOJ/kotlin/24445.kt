import java.io.*
import java.util.*
import kotlin.collections.ArrayList


val max = 100001
var visit = Array(max) {0}
var arr : Array<ArrayList<Int>> = Array(max + 1) {ArrayList(0)}

fun bfs(s : Int){
    var seq = 1
    var q : Queue<Int> = LinkedList()
    visit[s] = seq
    q.add(s)
    var x : Int
    while(!q.isEmpty()){
        x = q.poll()
        for (next in arr[x]){
            if (visit[next] == 0){
                visit[next] = ++seq
                q.add(next)
            }
        }
    }
}

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m, s) = br.readLine().split(" ").map { it.toInt() }
    for (i in 1..m){
        val (a, b) = br.readLine().split(" ").map{ it.toInt() }
        arr[a].add(b)
        arr[b].add(a)
    }
    for (i in 1..n)
        arr[i].sortDescending()
    bfs(s)
    for (i in 1..n)
        bw.write(visit[i].toString() + "\n")
    bw.flush()
    bw.close()
}
