import java.util.Scanner;
public class Main
{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        scan.close();
        
        int prize = 0;
        if(a == b && b == c && c == a) {
            prize = 10000 + a * 1000;
        }
        else if(a == b) {
            prize = 1000 + a * 100;
        }
        else if(b == c) {
            prize = 1000 + b * 100;
        }
        else if(c == a) {
            prize = 1000 + c * 100;
        }
        else {
            int eyes = 0;
            if(a > eyes && a > b && a > c) {
                eyes = a;
            }
            if(b > eyes && b > a && b > c) {
                eyes = b;
            }
            if(c > eyes && c > a && c > b) {
                eyes = c;
            }
            prize = eyes * 100;
        }
        
        System.out.print(prize);
    }
}