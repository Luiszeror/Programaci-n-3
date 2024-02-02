//Made by Luis Robelto 2/02/2024
package Model;

import java.util.*;

public class Graph <T>{

    private Comparator<T> comparator;

    private List<Vertex<T>> graph;
    public static final int DIRECT = 0;

    public static final int INDIRECT = 1;

    public Graph(Comparator<T> comparator) {

        this.comparator=comparator;
        this.graph= new ArrayList<>();

    }
    public void addVertex(T info){

        graph.add(new Vertex( info));

    }

    public boolean addEdge(Vertex<T> inicio, Vertex<T> fin, int asociacion) {
        if (!graph.contains(inicio) || !graph.contains(fin)) {
            return false;
        }
        if (isAdyacent(inicio, fin)) {
            return false;
        }
        if (asociacion == DIRECT) {
            
            inicio.addVertex(fin);
        } else if (asociacion == INDIRECT) {
            inicio.addVertex(fin);
            fin.addVertex(inicio);

        } else {
            return false;
        }

        return true;
    }


    public Vertex<T> findVertex(T info) {
        for (Vertex<T> vertex : graph) {
            if (vertex.getInfo().equals(info)) {
                return vertex;
            }
        }
        return null;
    }

    public List<T> getAdyacents(Vertex<T> inicio) {
        List<T> adyacentsInfo = new ArrayList<>();

        for (Vertex<T> adyacente : inicio.getAdyacents()) {
            adyacentsInfo.add(adyacente.getInfo());
        }

        return adyacentsInfo;
    }

    public List<T> listGraph(Vertex<T> inicio) {
        List<T> result = new ArrayList<>();
        Queue<Vertex<T>> queue = new LinkedList<>();

        inicio.setVisited(true);
        queue.add(inicio);

        while (!queue.isEmpty()) {
            Vertex<T> currentVertex = queue.poll();
            result.add(currentVertex.getInfo());

            for (Vertex<T> adyacente : currentVertex.getAdyacents()) {
                if (!adyacente.isVisited()) {
                    adyacente.setVisited(true);
                    queue.add(adyacente);
                }
            }
        }

        resetVisitedStatus();

        return result;
    }

    private void resetVisitedStatus() {
        for (Vertex<T> vertex : graph) {
            vertex.setVisited(false);
        }
    }

    public boolean isAdyacent(Vertex<T> g, Vertex<T> i){

        for( Vertex <T> a: g.getAdyacents() ){
            if(a.equals(i)) {
                return true;
            }
        }

        return false;
    }

}
