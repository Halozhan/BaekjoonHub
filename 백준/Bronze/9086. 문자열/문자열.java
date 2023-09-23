import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testcase = scanner.nextInt();
        scanner.nextLine();
        String[] lines = new String[testcase];
        for (int i = 0; i < testcase; i++) {
            lines[i] = scanner.nextLine();
        }
        scanner.close();
        for (String line : lines) {
            System.out.println(line.charAt(0) + "" + line.charAt(line.length() - 1));
        }
    }
}