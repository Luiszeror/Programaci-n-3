package Model;

import java.util.Comparator;
import java.util.List;

public class NArioTree <T>{

    private Comparator<T> comparator;
    private Node<T> root;

    public NArioTree (Comparator<T> comparator){

        this.comparator=comparator;
        root=null;

    }

    public boolean isEmpty(){
        return root==null;
    }

    public void addNode(Node<T> father, T info){

        if(isEmpty()){
            root= new Node<>(info);

        }else{
            father.addChildrens( new Node<>(info));

        }
    }

    private Node<T> find(Node<T> root, T node){

        if(node!=null){
            if(comparator.compare(node, root.getInfo())==0){
                return root;
            }else{
                List<Node <T>> childrens = root.getChildrens();

                for(Node<T> children : childrens){

                    if(find(children, node) != null){
                        return find(children, node);
                    }

                }
            }

        }
        return null;
    }

    public Node<T> findNode( T info){
        return find(root, info);

    }

    public List<T> getChildrens(Node<T> node){

        return null;
    }

    public List<T> listChildrens(){

        return null;
    }
}
