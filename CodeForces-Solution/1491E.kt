/**
 * Description: Kotlin tips for dummies
 * Source:
 * https://codeforces.com/blog/entry/71089
 * Kotlin Reference
 * https://kotlinlang.org/docs/tutorials/competitive-programming.html
 */

/// episode 1: https://codeforces.com/contest/1170
/// episode 2: https://codeforces.com/contest/1211
/// episode 3: https://codeforces.com/contest/1297

import java.io.*
import java.lang.Math.abs
import java.util.*
import kotlin.system.exitProcess

// @JvmField val INPUT = File("input.txt").inputStream()
// @JvmField val OUTPUT = File("output.txt").outputStream()

/// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.jvm/-jvm-field/

class Kattio: PrintWriter {
    @JvmField val r: BufferedReader
    @JvmField var st = StringTokenizer("")
    constructor(): this(System.`in`,System.out) {}
    constructor(i: InputStream, o: OutputStream): super(o,false) { r = i.bufferedReader() }
    fun rLine(): String? = r.readLine()

    fun read(): String { // if no input left returns empty string
        while (st.hasMoreTokens().not()) st =
            StringTokenizer(rLine() ?: return "", " ")
        return st.nextToken()
    }
    fun strs(n: Int) = List(n){read()}
    fun ln() = rLine()!!
    fun lns(n: Int) = List(n){ln()}
    fun int() = read().toInt()
    fun ints(n: Int) = List(n){int()}
    fun db() = read().toDouble()
    fun rDbs(n: Int) = List(n){db()}
    fun long() = read().toLong()
    fun longs(n: Int) = List(n){long()}
}

val io = Kattio()
//const val MOD = 1000000007
const val MOD = 998244353
const val INF = (1e18).toLong()
const val SZ = 1 shl 17

fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }
fun add(a: Int, b: Int) = (a+b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a-b+MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong()*b)%MOD).toInt()
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)

fun example() {
    println(String.format("%.8f", 5.25)) // print to 8 decimals
    val arr2D = Array<IntArray>(5,{IntArray(5,{5})})
    var (x,y) = arrayOf(3,2) // or rInts(2)
    when (x) { //  switch, can be used as expression
        0,1 -> println("x <= 1")
        2 -> println("x == 2") // Note the block
        else -> { println("x is neither 1 nor 2") }
    }
    x = y.also { y = x } // swap x and y
    println("${maxOf(x+2,y)}") // (x,y)=(4,3) -> 4
    val h = HashMap<String,Int>()
    val s = "ababa"
    for (i in 0..s.length-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w,{0})
        h[w] = c+1
    }
    for ((a,b) in h) println("${a} ${b}") // key,value
    val pq = PriorityQueue<Pair<Long,Int>>(){x,y ->
        x.first.compareTo(y.first)} // or compareBy{it.first}
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
        x.first.compareTo(y.first)}) // or sortBy{it.first}
    val list = arrayListOf('a','b','c','d','e')
    println(list.binarySearch('d')) // 3
    list.remove('d')
    val actualInsertPoint = -(list.binarySearch('d')+1) // 3
    list.add(actualInsertPoint, 'd') // [a,b,c,d,e]
    list.removeAt(1) // remove at index -> [a,c,d,e]
}


fun solve() {
    val n = io.int()
    val adj = Array<ArrayList<Int>>(n){ArrayList()}
    val verts = ArrayList<Int>()
    repeat(n-1) {
        var (u,v) = io.ints(2)
        --u
        --v
        adj[u].add(v)
        adj[v].add(u)
    }
    for (i in 0 until n) {
        verts.add(i)
    }
    val fib = arrayListOf(1,1)
    while (fib[fib.size-1] < 200000)
        fib.add(fib[fib.size-2]+fib[fib.size-1])
    val present = BooleanArray(n)
    val par = IntArray(n)
    fun tri(v: ArrayList<Int>): Boolean {
//        println("SOLVING "+v)
        if (v.size == 1) return true
        var fibInd = 0
        while (fib[fibInd] < v.size) ++fibInd
        assert(fib[fibInd] == v.size)

        for (i in v) present[i] = true
        val cand = ArrayList<Int>()
        val rec = ArrayList<Int>()
        fun dfs(x: Int, y: Int): Int {
            if (!present[x]) return 0
            rec.add(x)
            par[x] = y
            var subSize = 1
            for (i in adj[x]) if (i != y) {
                subSize += dfs(i,x)
            }
            if (subSize == fib[fibInd-2] || subSize == fib[fibInd-1])
                cand.add(x)
            return subSize
        }
        dfs(v[0],-1)

        if (cand.size == 0) {
            for (i in v) present[i] = false
            return false
        }
        val aa = cand[0]
        val bb = par[aa]
        rec.clear()
        dfs(aa,bb)
        val rec1 = ArrayList(rec)
//        println("?? ${rec1}")
        rec.clear()
        dfs(bb,aa)
        val rec2 = ArrayList(rec)
        for (i in v) present[i] = false

//        println("AH ${rec1} ${rec2} ${v.size}")
//        assert(rec1.size+rec2.size == v.size)
//        println("ASSERTION PASSED")

        if (!tri(rec1)) return false
        if (!tri(rec2)) return false
        return true
    }
    var ind = 0
    while (fib[ind] < n) ++ind
    if (fib[ind] != n) {
        println("NO")
        return
    }
    if (tri(verts)) {
        println("YES")
    } else {
        println("NO")
    }
}

fun main() {
//    val t = io.int()
    val t = 1
    repeat(t) { solve() }
    io.close()
}