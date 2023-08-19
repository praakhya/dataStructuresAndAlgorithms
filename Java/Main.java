import java.util.Scanner;
//import SinglyLinkedList.SinglyLinkedList;
import DoublyLinkedList.DoublyLinkedList;
public class Main {
    public static void main(String[] args) {
        String optionsStr = new String("1. Append\n2. Insert at position\n3. Remove\n4. Remove from end\n5. Display\nq. Quit\n");
        String appendVal = new String("Enter value to be appended: ");
        String indexVal = new String("Enter index: ");
        String deleteInd = new String("Enter index to delete: ");
        DoublyLinkedList dll = new DoublyLinkedList();
        Scanner scannerObj = new Scanner(System.in);
        System.out.print(optionsStr);
        String opt = scannerObj.nextLine();
        while (opt != "q") {
            switch (opt) {
                case "2": 
                    System.out.print(appendVal);
                    int val = scannerObj.nextInt();
                    System.out.print(indexVal);
                    int ind = scannerObj.nextInt();
                    dll.insert(val,ind);
                    break;
                case "1":
                    System.out.print(appendVal);
                    val = scannerObj.nextInt();
                    dll.insert(val);
                    break;
                case "3":
                    System.out.print(deleteInd);
                    ind = scannerObj.nextInt();
                    ind = dll.delete(ind);
                    if (ind==-1) {
                        System.out.println("Index out of range");
                        break;
                    }
                    System.out.println("Deleted value: "+ind);
                    break;
                case "4":
                    ind = dll.delete();
                    if (ind==-1) {
                        System.out.println("Index out of range");
                        break;
                    }
                    System.out.println("Deleted value: "+ind);
                    break;
                case "5":
                    dll.display();
                    break;
                case "q":
                    scannerObj.close();
                    return;
                default:
                    System.out.println("Error option..");
                    break;
            }
            System.out.print(optionsStr);
            opt = scannerObj.next();
        }
        scannerObj.close();
    }
}
