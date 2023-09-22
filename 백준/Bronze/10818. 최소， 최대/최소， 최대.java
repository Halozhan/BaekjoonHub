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
        input.close();
        int min = array[0];
        int max = array[0];
        for (int i = 0; i < size; i++)
        {
            if (min > array[i])
                min = array[i];
            if (max < array[i])
                max = array[i];
        }
        System.out.println(min + " " + max);
    }
}