package DoublyLinkedList;

public class DoublyLinkedList {
    Node head;
    public DoublyLinkedList() {
        head=null;
    }
    public void insert(int val, int ind) {
        Node newNode = new Node(val);
        if (this.head==null) {
            this.head = newNode;
            return;
        }
        if (ind==0) {
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
            newNode.prev = this.head;
        }
        int i=0;
        Node curr = this.head;
        Node prev = null;
        while (i<ind && curr!=null) {
            ++i;
            prev = curr;
            curr = curr.next;
        }
        prev.next = newNode;
        newNode.prev = prev;
        newNode.next = curr;
        if (curr!=null) {
            curr.prev = newNode;
        }
    }
    public void insert(int val) {
        Node newNode = new Node(val);
        if (this.head==null) {
            this.head = newNode;
            return;
        }
        Node curr = this.head;
        Node prev = null;
        while (curr!=null) {
            prev = curr;
            curr = curr.next;
        }
        prev.next = newNode;
        newNode.prev = prev;
        newNode.next = curr;
    }
    public int delete() {
        if (this.head==null) {
            return -1;
        }
        if (this.head.next==null) {
            int val = this.head.value;
            this.head = null;
            return val;
        }
        Node prev = null;
        Node curr = this.head;
        while (curr.next!=null) {
            prev = curr;
            curr = curr.next;
        }
        prev.next = curr.next;
        return curr.value;
    }
    public int delete(int ind) {
        if (this.head==null) {
            return -1;
        }
        if (ind==0) {
            int val = this.head.value;
            this.head = this.head.next;
            return val;
        }
        Node prev = null;
        Node curr = this.head;
        int i=0;
        while (curr!=null && i<ind) {
            ++i;
            prev = curr;
            curr = curr.next;
        }
        if (curr==null) {
            return -1;
        }
        prev.next = curr.next;
        if (curr.next!=null) {
            curr.next.prev = prev;
        }
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
