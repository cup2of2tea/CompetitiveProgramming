import java.util.*
 import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.io.BufferedReader
import java.io.InputStreamReader
fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream = System.out
        val `in` = Main.InputReader(inputStream)
        val out = PrintWriter(outputStream)
 
        var N = `in`.nextInt()
        var K = `in`.nextInt()
        var a = Array<Int>(N){i->i}
        for (i in 0 until N) {
            a[i] = `in`.nextInt()
        }
        a.sort()
        if(K==0) {
            if(a[0] == 1) {
                out.println(-1)
            } else {
                out.println(a[0]-1)
            }
        } else {
            if(K < a.size && a[K] == a[K-1]) {
                out.println(-1)
            }
            else {
                out.println(a[K-1])
            }
        }
        out.close();
    }
object Main {
    @JvmStatic
    fun main(args: Array<String>) {
         val inputStream = System.`in`
        val `in` = Main.InputReader(inputStream)
 
        var N = `in`.nextInt()
        var K = `in`.nextInt()
        val a = IntArray(N)
        for (i in 0 until N) {
            a[i] = `in`.nextInt()
        }
        a.sort()
        if(K==0) {
            if(a[0] == 1) {
                println(-1)
            } else {
                println(a[0]-1)
            }
        } else {
            if(K < a.size && a[K] == a[K-1]) {
                println(-1)
            }
            else {
                println(a[K-1])
            }
        }
    }
 
   
    internal class InputReader(stream: InputStream) {
        var reader: BufferedReader
        var tokenizer: StringTokenizer? = null
 
        init {
            reader = BufferedReader(InputStreamReader(stream), 32768)
            tokenizer = null
        }
 
        operator fun next(): String {
            while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
                try {
                    tokenizer = StringTokenizer(reader.readLine())
                } catch (e: IOException) {
                    throw RuntimeException(e)
                }
 
            }
            return tokenizer!!.nextToken()
        }
 
        fun nextInt(): Int {
            return Integer.parseInt(next())
        }
 
    }
}