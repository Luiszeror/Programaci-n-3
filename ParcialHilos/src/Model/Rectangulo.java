package Model;

import java.awt.*;

public class Rectangulo extends Figura {
    private int ancho;
    private int alto;

    public Rectangulo(int x, int y, int ancho, int alto, Color color, int dx, int dy) {
        super(x, y, color, dx, dy);
        this.ancho = ancho;
        this.alto = alto;
    }

    @Override
    public void dibujar(Graphics g) {
        g.setColor(color);
        g.fillRect(x, y, ancho, alto);
    }

    @Override
    public void mover() {
        x += dx;
        y += dy;
    }
}

