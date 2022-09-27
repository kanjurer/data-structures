import LinkedList.SinglyLinkedList;

public class Main {
    public static void main(String[] args) {

        SinglyLinkedList<Integer> list = new SinglyLinkedList<>();

        list.add(1);
        list.add(2,0);
        list.add(3);
        list.add(4);
        list.add(5);
        list.add(6);
        list.add(7);
        list.add(8);
        list.add(1, 8);

        //  list.enumerate();

        Integer number = list.remove(-1);

        list.enumerate();
        System.out.println("removed: " + number);

    }
}