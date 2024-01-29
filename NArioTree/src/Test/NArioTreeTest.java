package Test;

import Model.NArioTree;
import Model.Node;

public class NArioTreeTest {

    private NArioTree<Character> tree;

    void setup(){
        tree = new NArioTree<>((c1,c2)-> Character.compare(c1,c2));
        tree.addNode(null, 'T');
        Node<Character> node= tree.findNode('T');
        tree.addNode(node, 'S');
        tree.addNode(node, 'R');
        tree.addNode(node, 'G');
        tree.addNode(node, 'H');



    }

    void findNode(){

        setup();
        assertNotNull(tree.findNode(('T')));
        assertEquals('T', tree.findNode('T').getInfo());



    }






}
