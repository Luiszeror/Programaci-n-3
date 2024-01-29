package Test;

import Model.NArioTree;
import Model.Node;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

public class NArioTreeTest {

    private NArioTree<Character> tree;

    @Before
    public void setup(){
        tree = new NArioTree<>((c1,c2)-> Character.compare(c1,c2));
        tree.addNode(null, 'T');
        Node<Character> node= tree.findNode('T');
        tree.addNode(node, 'S');
        tree.addNode(node, 'R');
        tree.addNode(node, 'G');
        tree.addNode(node, 'H');



    }

    @Test
    public void findNode(){

        setup();
        assertNotNull(tree.findNode(('T')));
        assertEquals('T', tree.findNode('T').getInfo().charValue());


    }






}
