package Model;

import java.awt.*;

public class Circulo extends Figura {
    private int radio;

    public Circulo(int x, int y, int radio, Color color, int dx, int dy) {
        super(x, y, color, dx, dy);
        this.radio = radio;
    }

    @Override
    public void dibujar(Graphics g) {
        g.setColor(color);
        g.fillOval(x - radio, y - radio, radio * 2, radio * 2);
    }

    @Override
    public void mover() {
        x += dx;
        y += dy;
    }
}
