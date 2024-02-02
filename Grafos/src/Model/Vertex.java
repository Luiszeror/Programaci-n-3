//Made by Luis Robelto 2/02/2024
package Model;

import java.util.ArrayList;
import java.util.List;

public class Vertex <T> {

    private T info;
    private boolean visited;

    private List<Vertex> adyacents;

    public  Vertex (T info){

        this.info= info;
        this.adyacents= new ArrayList<>();

    }

    public T getInfo() {
        return info;
    }

    public void setInfo(T info) {
        this.info = info;
    }

    public boolean isVisited() {
        return visited;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }

    public boolean isAdyacent(Vertex<T> vertex){

        return adyacents.size()!=0;
    }

    public void addVertex(Vertex<T> vertex) {
        if (!adyacents.contains(vertex)) {
            adyacents.add(vertex);
        }
    }

    public List<Vertex> getAdyacents(){

        return adyacents;
    }
}
