import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int size = input.nextInt();
        int lower_than = input.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = input.nextInt();
        }
        for (int i = 0; i < size; i++)
        {
            if (array[i] < lower_than) {
                System.out.print(array[i] + " ");
            }
        }
    }
}