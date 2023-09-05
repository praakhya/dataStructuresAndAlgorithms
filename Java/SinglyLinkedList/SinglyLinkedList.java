package SinglyLinkedList;

public class SinglyLinkedList {
    Node head;
    public SinglyLinkedList() {
        head=null;
    }
    private void init(int val) {
        this.head = new Node(val);
    }
    public void append(int val) {
        if (this.head == null) {
            init(val);
            return;
        }
        Node temp = this.head;
        while (temp.next != null) {
            temp=temp.next;
        }
        temp.next = new Node(val);
    }
    public Integer pop(int val) {
        if (this.head==null) {
            return null;
        }
        if (val == 0) {
            int v = this.head.value;
            this.head = this.head.next;
            return v;
        }
        Node prev = null;
        Node curr = this.head;
        for (int i=0; i<val && curr!=null; ++i) {
            prev=curr;
            curr=curr.next;
        }
        Node toDel = curr;
        if (toDel==null) {
            return -1;
        }
        else {
            prev.next = curr.next;
            return toDel.value;
        }
    }
    public Integer pop() {
        if (this.head==null) {
            return -1;
        }
        Node prev = null;
        Node curr = this.head;
        while (curr.next != null) {
            prev = curr;
            curr = curr.next;
        }
        prev.next = null;
        return curr.value;
    }
    public void display() {
        Node temp = this.head;
        while (temp!=null) {
            System.out.print(temp.value+" ");
            temp = temp.next;
        }
        System.out.println();
    }
}