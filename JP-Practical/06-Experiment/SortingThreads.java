import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class SortingThreads {

    public class BubbleSortThread extends Thread {
        private ArrayList<Integer> array;
        private Integer start;
        private Integer end;

        BubbleSortThread(ArrayList<Integer> array, int start, int end) {
            this.array = new ArrayList<>(array); 
            this.start = start;
            this.end = end;
        }

        private void bubbleSort(ArrayList<Integer> arrayList, int start, int end) {
            for (int i = start; i < end - 1; i++) {
                for (int j = start; j < end - i - 1; j++) {
                    if (arrayList.get(j) > arrayList.get(j + 1)) {
                        // Swap
                        int temp = arrayList.get(j);
                        arrayList.set(j, arrayList.get(j + 1));
                        arrayList.set(j + 1, temp);
                    }
                }
            }
        }

        @Override
        public void run() {
            bubbleSort(array, start, end);
            System.out.println("Bubble Sorted Array: " + array);
        }
    }

    public class SelectionSortThread extends Thread {
        private ArrayList<Integer> array;
        private Integer start;
        private Integer end;

        SelectionSortThread(ArrayList<Integer> array, int start, int end) {
            this.array = new ArrayList<>(array);  
            this.start = start;
            this.end = end;
        }

        private void selectionSort(ArrayList<Integer> arrayList, int start, int end) {
            for (int i = start; i < end - 1; i++) {
                for (int j = i + 1; j < end; j++) {
                    if (arrayList.get(i) > arrayList.get(j)) {
                        // Swap
                        int temp = arrayList.get(j);
                        arrayList.set(j, arrayList.get(i));
                        arrayList.set(i, temp);
                    }
                }
            }
        }

        @Override
        public void run() {
            selectionSort(array, start, end);
            System.out.println("Selection Sorted Array: " + array);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> inputArray = new ArrayList<>();
        
        // Collect input for array
        boolean flagVar = true;
        int index = 0;
        while (flagVar) {
            System.out.print("a[ " + index + " ] :: ");
            try {
                inputArray.add(scanner.nextInt());
                index++;
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter an integer.");
                scanner.next();  
                continue;
            }
            System.out.println("Do you want to add more elements? (y/n)");
            String choice = scanner.next();
            if (choice.equalsIgnoreCase("n")) {
                flagVar = false;
            } else if (!choice.equalsIgnoreCase("y")) {
                System.out.println("Invalid choice. Please enter 'y' or 'n'.");
            }
        }

        System.out.println("Enter Start Index: ");
        int start = scanner.nextInt();
        System.out.println("Enter End Index: ");
        int end = scanner.nextInt();
        scanner.close();

        // Validate indices
        if (start < 0 || end > inputArray.size() || start >= end) {
            System.out.println("Invalid indices. Sorting cannot proceed.");
            return;
        }

        SortingThreads sortingThreads = new SortingThreads();
        BubbleSortThread bubbleSortThread = sortingThreads.new BubbleSortThread(inputArray, start, end);
        SelectionSortThread selectionSortThread = sortingThreads.new SelectionSortThread(inputArray, start, end);

        bubbleSortThread.start();
        selectionSortThread.start();

        try {
            bubbleSortThread.join();
            selectionSortThread.join();
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted: " + e.getMessage());
        }
    }
}
