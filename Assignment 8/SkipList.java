/*****************************************************
 * Name: Keval Varia
 * Class: Data Structures
 * Assignment #8: Skip List
 * ---------------------------------------------------
 * Program Details:
 * - In this program we will implement a dictionary
 *   using a skip list.
 * - Then we will test all dictionary methods:
 *   a. insert
 *   b. delete
 *   c. search
 *   d. print just the values
 *   e. print level-by-level
 * - The testing will be done using pre-existing data.
 * - Node class stores the keya and value for each node.
 * - insertions will use a coin flip to determine how
 *   many copies will be stored.
 * - deletions will take place based on key.
 *****************************************************/

package skiplist.java;
import java.util.ArrayList;
import java.util.List;
import java.lang.*;

public class SkipList{

    /*
    * The left and right bounds of a skip list are always infinity.
    */
    private Node negativeInfinity;
    private Node positiveInfinity;

    /*
     * Constructor
     */
    public SkipList()
    {

            positiveInfinity = new Node(Integer.MAX_VALUE);
            negativeInfinity = new Node(Integer.MIN_VALUE);

            positiveInfinity.setLeft(negativeInfinity);
            negativeInfinity.setRight(positiveInfinity);

    }


    /*
     * function: search
     * task: searches the dictionary based on key
     * return: Node pointing to all data for found key
     */
    public Node search(int key)
    {

            Node current = negativeInfinity;

            while (current != null)
            {
                while (current.rightPtr != null && current.rightPtr.key <= key ) {
                    current = current.rightPtr;
                }

                if (current.key == key) {
                    break;
                }

                current = current.downPtr;
            }

            return current;

    }




    /*
     * function: insert
     * task: add a value to the data structure
     * return: whether the value was inserted
     */
    public boolean insert(int key, String name) {


        Node current = negativeInfinity;

        List<Node> pointersToUpdate = new ArrayList<Node>();

        while (current != null) {
            while (current.rightPtr != null && current.rightPtr.key < key ) {
                current = current.rightPtr;
            }

            pointersToUpdate.add(current);
            current = current.downPtr;
        }

        // insert after this node.
        int level = 0;
        Node newNode = null;

        while (level == 0 || coinFlip())
        {
            // now move upPtr.
            if (newNode == null)
            {
                newNode = new Node(key, name);
            }
            else
            {
                newNode = new Node(newNode);
            }

            Node nodeToUpdate = null;

            if (pointersToUpdate.size() <= level)
            {
                createNewLevel();
                nodeToUpdate = this.negativeInfinity;
            }
            else
            {
                nodeToUpdate = pointersToUpdate.get(pointersToUpdate.size() - level - 1);
            }

            newNode.rightPtr = nodeToUpdate.rightPtr;
            newNode.leftPtr = nodeToUpdate;

            newNode.rightPtr.leftPtr = newNode;
            nodeToUpdate.rightPtr = newNode;

            level++;
        }

        return true;

    }

    /*
     * function: delete
     * task: remove a value from the data structure
     * return: whether the value was removed
     */
    public boolean delete(int key) {

            Node current = this.negativeInfinity;

            List<Node> pointersToUpdate = new ArrayList<Node>();

            while (current != null) {
                    while (current.rightPtr != null && current.rightPtr.key < key ) {
                            current = current.rightPtr;
                    }

                    if (current.rightPtr.key == key) {
                            pointersToUpdate.add(current);
                    }

                    current = current.downPtr;
            }

            for (int i = 0; i < pointersToUpdate.size(); i++) {

                    Node nodeToUpdate = pointersToUpdate.get(i);

                    Node nodeToDelete = nodeToUpdate.rightPtr;

                    nodeToUpdate.rightPtr = nodeToDelete.rightPtr;
                    nodeToDelete.rightPtr.leftPtr = nodeToUpdate;

                    nodeToDelete.upPtr = null;
                    nodeToDelete.downPtr = null;
            }

            return true;

    }

    /*
     * function: createNewLevel
     * task: add another level
     * return: void
     */
    private void createNewLevel() {

            Node negativeInfinity = new Node(Integer.MIN_VALUE);
            Node positiveInfinity = new Node(Integer.MAX_VALUE);

            negativeInfinity.setRight(positiveInfinity);
            positiveInfinity.setLeft(negativeInfinity);

            this.negativeInfinity.upPtr = negativeInfinity;
            negativeInfinity.downPtr = this.negativeInfinity;
            this.negativeInfinity = negativeInfinity;

            this.positiveInfinity.upPtr = positiveInfinity;
            positiveInfinity.downPtr = this.positiveInfinity;
            this.positiveInfinity = positiveInfinity;

    }

    /*
     * function: coinFlip
     * task: flip coin to determine whether a copy should be added
     * return: boolean
     */
    private boolean coinFlip() {
            return Math.random() >= 0.5;
    }

    /*
     * function: print
     * task: print all keys with their values
     * return: void
     */
    public void print() {

        Node current = this.negativeInfinity;

        while(current.downPtr != null) {
                current = current.downPtr;
        }

        current = current.rightPtr;

        while (current.rightPtr != null) {
                System.out.println(current.key +" "+ current.name);
                current = current.rightPtr;
        }

        System.out.println();
    }

            /*
     * function: printLevelByLevel
     * task: print all keys level by level (keval needs to make spaces)
     * return: void
     */
    public void printLevelByLevel() {

        Node current = this.negativeInfinity;

        while(current != null) {

                Node firstInLevel = current;
                firstInLevel = firstInLevel.rightPtr;

                while (firstInLevel.rightPtr != null) {
                        System.out.print(firstInLevel.key + " ");
                        firstInLevel = firstInLevel.rightPtr;
                }

                current = current.downPtr;
                System.out.println();
        }
    }


    public static void main(String[] args)
    {
        //variable declaration
        SkipList list = new SkipList();

        //insert values, then print the data structure
        System.out.println("Inserting 4 values:");
        list.insert(18, "Laguna Niguel");
        list.insert(41, "Mission Viejo");
        list.insert(22, "San Clemente");
        list.insert(44, "Irvine");
        list.print();
        System.out.println();

        //remove value then print level-by-level
        System.out.println("Removing Mission Viejo");
        list.delete(41);
        System.out.println("Printing level-by-level:");
        list.printLevelByLevel();
        System.out.println();

        //insert values, then print the data structure
        System.out.println("Inserting 3 values:");
        list.insert(58, "Lake Forest");
        list.insert(32, "San Diego");
        list.insert(49, "Anaheim");
        list.print();
        System.out.println();

        //remove value then print level-by-level
        System.out.println("Removing Lake Forest");
        list.delete(58);
        System.out.println("Printing level-by-level:");
        list.printLevelByLevel();
        System.out.println();

        //insert values, then print the data structure
        System.out.println("Inserting 4 values:");
        list.insert(31, "Los Angeles");
        list.insert(17, "Orange");
        list.insert(72, "Palm Springs");
        list.insert(41, "Riverside");
        list.print();
        System.out.println();

        //remove value then print level-by-level
        System.out.println("Removing 73");
        list.delete(73);
        System.out.println("Printing level-by-level:");
        list.printLevelByLevel();
        System.out.println();

        //insert values, then print the data structure
        System.out.println("Inserting 8 values:");
        list.insert(19, "Brea");
        list.insert(60, "Santa Ana");
        list.insert(35, "Tustin");
        list.insert(103, "Oceanside");
        list.insert(11, "La Jolla");
        list.insert(18, "Del Mar");
        list.insert(22, "Aliso Viejo");
        list.insert(49, "Laguna Beach");
        list.print();
        System.out.println();

        //remove value then print level-by-level
        System.out.println("Removing 41");
        list.delete(41);
        System.out.println("Printing level-by-level:");
        list.printLevelByLevel();
        System.out.println();

        //insert values, then print the data structure
        System.out.println("Inserting 7 values:");
        list.insert(42, "Vista");
        list.insert(49, "San Diego");
        list.insert(99, "San Juan");
        list.insert(29, "Dana Point");
        list.insert(88, "El Segundo");
        list.insert(41, "San Celemente");
        list.insert(62, "Laguna Hills");
        list.print();
        System.out.println();
        System.out.println("Printing level-by-level:");
        list.printLevelByLevel();
        System.out.println();       

        //end of program prompt
        System.out.println("End Of Program!");

    }

    //node class will store data and pointers to surrounding nodes
    public static class Node
    {

        //variable declaration
        private int key;
        private String name;
        private Node leftPtr;
        private Node rightPtr;
        private Node upPtr;
        private Node downPtr;


        /*
         * Constructor
         */
        public Node(int key) {
                this.key = key;
                this.name = "";
                this.leftPtr = null;
                this.rightPtr = null;
                this.upPtr = null;
                this.downPtr = null;
        }


        /*
         * Constructor
         */
        public Node(int key, String name) {
                this.key = key;
                this.name = name;
                this.leftPtr = null;
                this.rightPtr = null;
                this.upPtr = null;
                this.downPtr = null;
        }


        /*
         * Constructor
         */
        public Node(Node lowerLevelNode) {
                this.key = lowerLevelNode.key;
                this.name = lowerLevelNode.name;
                this.leftPtr = null;
                this.rightPtr = null;
                this.upPtr = null;
                this.downPtr = lowerLevelNode;
        }


        /*
         * function: getLeft
         * task: return the node to its left
         */
        public Node getLeft() {
                return leftPtr;
        }

        /*
         * function: setLeft
         * task: set the node to its left
         */
        public void setLeft(Node leftPtr) {
                this.leftPtr = leftPtr;
        }

        /*
         * function: getRight
         * task: get the node to its right
         */           
        public Node getRight() {
                return rightPtr;
        }

         /*
         * function: setRight
         * task: set the node to its right
         */     
        public void setRight(Node rightPtr) {
                this.rightPtr = rightPtr;
        }

         /*
         * function: getUp
         * task: get the node above it
         */
        public Node getUp() {
                return upPtr;
        }

        /*
         * function: setUp
         * task: set the node about it
         */     
        public void setUp(Node upPtr) {
                this.upPtr = upPtr;
        }

        /*
         * function: getDown
         * task: get the node under it
         */     
        public Node getDown() {
                return downPtr;
        }

        /*
         * function: setDown
         * task: set the node under it
         */     
        public void setDown(Node downPtr) {
                this.downPtr = downPtr;
        }
    }
}