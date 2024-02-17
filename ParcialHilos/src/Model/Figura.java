package Model;

import java.awt.*;

public abstract class Figura {
    protected int x;
    protected int y;
    protected Color color;
    protected int dx;
    protected int dy;

    public Figura(int x, int y, Color color, int dx, int dy) {
        this.x = x;
        this.y = y;
        this.color = color;
        this.dx = dx;
        this.dy = dy;
    }

    public abstract void dibujar(Graphics g);

    public abstract void mover();

    public void setDy(int dy) {
        this.dy = dy;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public int getDx() {
        return dx;
    }

    public void setDx(int dx) {
        this.dx = dx;
    }

    public int getDy() {
        return dy;
    }
}
