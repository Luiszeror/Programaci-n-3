package Model;

import java.util.ArrayList;
import java.util.List;

public class Node <T> {

    private T info;
    private List<Node<T>> childrens;


    public Node (T info){
        this.info=info;
        childrens= new ArrayList<>();
    }

    public T getInfo() {
        return info;
    }

    public void setInfo(T info) {
        this.info = info;
    }

    public List<Node<T>> getChildrens(){
     return childrens;
    }

    public void addChildrens(Node<T> node){
        childrens.add(node);
    }
}
