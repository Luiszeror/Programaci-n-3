package Model;

import java.awt.*;
import java.util.Random;

public class Triangulo extends Figura {
    private int lado1;
    private int lado2;
    private int lado3;

    public Triangulo(int x, int y, int lado1, int lado2, int lado3, Color color, int dx, int dy) {
        super(x, y, color, dx, dy);
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    @Override
    public void dibujar(Graphics g) {
        g.setColor(color);
        int[] xPoints = {x, x + lado1, x + lado2};
        int[] yPoints = {y, y - lado3, y};
        g.fillPolygon(xPoints, yPoints, 3);
    }

    @Override
    public void mover() {
        x += dx;
        y += dy;
    }
}

