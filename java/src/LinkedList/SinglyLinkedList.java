package LinkedList;

public class SinglyLinkedList<T> {
    Node<T> head;
    Node<T> tail;
    int size;

    public SinglyLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }


    public void add(T data) {
        this.add(data, size);
    }

    public void add(T data, int index) {
        if (data == null || index < 0 || index > size) return;

        Node<T> node = new Node<>(data);

        if (this.head == null) {
            this.head = this.tail = node;
        } else {
            if (index == 0) {
                node.next = this.head;
                this.head = node;
            } else if (index == size) {
                this.tail.next = node;
                this.tail = node;
            } else {
                Node<T> tmp = this.head;
                for (int i = 0; i < index - 1; i++) {
                    tmp = tmp.next;
                }
                node.next = tmp.next;
                tmp.next = node;
            }
        }

        size++;
    }

    public T remove(int index) {
        if (index < 0 || index >= size) return null;

        Node<T> tmp = this.head;
        if (this.head == null) return null;
        if (size == 1) {
            this.head = this.tail = null;
            size--;
            return tmp.data;
        }

        if (index == 0) {
            this.head = this.head.next;
            size--;

            return tmp.data;
        }

        for (int i = 0; i < index - 1; i++) {
            tmp = tmp.next;
        }

        T data = tmp.next.data;
        tmp.next = tmp.next.next;

        if (index == size - 1) {
            this.tail = tmp.next;
        }

        return data;
    }

    public Node<T> getHead() {
        return head;
    }

    public Node<T> getTail() {
        return tail;
    }

    public int size() {
        return size;
    }

    public void setHead(Node<T> head) {
        this.head = head;
    }

    public void setTail(Node<T> tail) {
        this.tail = tail;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public void enumerate() {
        Node<T> tmp = head;
        System.out.print("{");
        if(tmp != null){
            System.out.print(tmp.data);
            tmp = tmp.next;
        };
        while (tmp != null) {
            System.out.print(", " + tmp.data );
            tmp = tmp.next;
        }
        System.out.println("}");
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int indexOf(T item) {
        if (item == null) return -1;

        Node<T> tmp = head;
        int index = 0;
        while (tmp != null) {
            if (tmp.data.equals(item)) {
                return index;
            }
            tmp = tmp.next;
            index++;
        }

        return -1;
    }

    public boolean contains(T item) {
        return indexOf(item) != -1;
    }

    public void clear() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
}

class Node<T> {
    T data;
    Node<T> next;

    public Node(T data) {
        this.data = data;
    }

    public T getData() {
        return data;
    }

    public Node<T> getNext() {
        return next;
    }

    public void setData(T data) {
        this.data = data;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }
}
