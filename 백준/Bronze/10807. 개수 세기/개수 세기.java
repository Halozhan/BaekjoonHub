import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int size = input.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = input.nextInt();
        }
        int find = input.nextInt();
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] == find) {
                count++;
            }
        }
        System.out.println(count);
    }
}