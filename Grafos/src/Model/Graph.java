package Model;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Graph <T>{

    private Comparator<T> comparator;

    private List<Vertex> graph;
    private static final int DIRECT = 0;

    private static final int INDIRECT = 1;

    public Graph(Comparator<T> comparator) {

        this.comparator=comparator;
        this.graph= new ArrayList<>();

    }
    public void addVertex(T info){


    }

    public void addEdge(Vertex<T> inicio, Vertex<T> fin, int associacion){


    }

    public Vertex<T> findVertex(T info){

        return null;
    }

    public List<T> getAdyacents(Vertex<T> inicio){


        return null;

    }

    public List<T> listGraph(Vertex<T> inicio){


        return null;
    }

}
