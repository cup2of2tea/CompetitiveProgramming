import java.util.*;
import java.io.*;
import java.text.*;
 
public class Main {
 
    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    
    
    
    Main() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }
    
    public static void main(String[] args) throws IOException {
        new Main();
    }
    
    void solve() throws IOException {
        String s1=nextString();
        String s2=nextString();
        SimpleDateFormat format = new SimpleDateFormat("yyyy:MM:dd");
        format.setTimeZone(TimeZone.getTimeZone("UTC"));
        Date calendar1=null,calendar2=null;
        try
        {
            calendar1=format.parse(s1);
            calendar2=format.parse(s2);
        } catch (Exception e) {
        e.printStackTrace();
        }
        System.out.println(((Math.abs(calendar2.getTime()-calendar1.getTime()))/(24*60*60*1000)));
    }
    
    
    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }
 
    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
    }
 
    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
 
    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
 
    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}