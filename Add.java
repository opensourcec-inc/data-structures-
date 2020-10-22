import java.io.*;
import java.util.*;
public class Add{
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream(new File("in")));
        System.setOut(new PrintStream(new File("out")));
        Scanner sc = new Scanner(System.in);
        int i=sc.nextInt();
        int j=sc.nextInt();
        System.out.println(i+j);
    }
}