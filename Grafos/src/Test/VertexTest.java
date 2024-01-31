package Test;

import Model.Vertex;

import static org.junit.jupiter.api.Assertions.*;

class VertexTest {

    Vertex<Character> A= new Vertex<>('A');
    Vertex<Character> B= new Vertex<>('B');
    Vertex<Character> C= new Vertex<>('C');


    @org.junit.jupiter.api.Test
    void vertex() {

    }

    @org.junit.jupiter.api.Test
    void getInfo() {

        assertEquals('A',A.getInfo());
    }

    @org.junit.jupiter.api.Test
    void setInfo() {
    }

    @org.junit.jupiter.api.Test
    void isVisited() {
    }

    @org.junit.jupiter.api.Test
    void setVisited() {
    }

    @org.junit.jupiter.api.Test
    void isAdyacent() {

       assertFalse(C.isAdyacent(A));

    }

    @org.junit.jupiter.api.Test
    void addVertex() {

        A.addVertex(A);
        A.addVertex(B);
        A.addVertex(C);
        B.addVertex(B);


    }

    @org.junit.jupiter.api.Test
    public void getAdyacents(){

    }
}