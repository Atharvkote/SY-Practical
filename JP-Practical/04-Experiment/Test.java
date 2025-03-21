import mypackage.inserationsort;
import mypackage.bubblesort;
import mypackage.selectionsort;

public class Test {
    public static void main(String[] args) {
        
        inserationsort inserationsorter = new inserationsort();
        bubblesort bubblesorter = new bubblesort();
        selectionsort selectionsorter = new selectionsort();
        
        System.out.println("Insertion Sort : ");
        
        int[] arr = {64, 25, 12, 22, 11};
        System.out.println("Original array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        
        inserationsorter.insertionSort(arr);
        
        System.out.println("\nSorted array(Inserations Sort):");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        System.out.println("Bubble Sort : ");
        
        
        // Bubble Sort
        int[] array = {64, 25, 12, 22, 11};
        System.out.println("Original array:");
        for (int num : array) {
            System.out.print(num + " ");
        }
        
        bubblesorter.bubbleSort(array);
        
        System.out.println("\nSorted array(Bubble Sort):");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        System.out.println("Selection Sort : ");
        
        // Selection Sort
        int[] arraytwo = {64, 25, 12, 22, 11};
        System.out.println("Original array:");
        for (int num : arraytwo) {
            System.out.print(num + " ");
        }
        
        selectionsorter.selectionSort(arraytwo);
        
        System.out.println("\nSorted array(Selection Sort):");
        for (int num : arraytwo) {
            System.out.print(num + " ");
        }
    }
}