import java.io.*

val max = 100001
var visit = Array(max) {0}
var arr : Array<ArrayList<Int>> = Array(max + 1) { ArrayList(0) }
var seq = 0
fun dfs(idx : Int){
    if (visit[idx] != 0)
        return
    seq += 1
    visit[idx] = seq
    for (i in arr[idx]){
        if (visit[i] != 0)
            continue
        dfs(i)
    }
}
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, start) = br.readLine().split(' ').map { it.toInt() }
    for (i in 1..m)
    {
        val (a, b) = br.readLine().split(' ').map { it.toInt() }
        arr[a].add(b)
        arr[b].add(a)
    }
    for (i in 1..n)
        arr[i].sortDescending()
    dfs(start)

    val bw = BufferedWriter(OutputStreamWriter(System.out))

    for (i in 1..n){
        bw.write(visit[i].toString() + "\n")
    }
    bw.flush()
    bw.close()
}
