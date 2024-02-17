package Controller;

import Model.Circulo;
import Model.Figura;
import Model.Rectangulo;
import Model.Triangulo;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class PanelCentro extends JPanel implements Runnable {
    private volatile boolean enEjecucion = false;
    private volatile boolean enPausa = false;
    private final int ANCHO_PANEL = 800;
    private final int ALTO_PANEL = 600;

    private List<Figura> figuras = new ArrayList<>();
    private Thread hiloMovimiento;

    public PanelCentro() {
        Random random = new Random();
        for (int i = 0; i < 3; i++) {
            int x = random.nextInt(ANCHO_PANEL);
            int y = random.nextInt(ALTO_PANEL);
            Color color = new Color(random.nextInt(256), random.nextInt(256), random.nextInt(256)); // Color aleatorio
            int dx = random.nextInt(5) + 1;
            int dy = random.nextInt(5) + 1;

            int tipoFigura = random.nextInt(3);
            switch (tipoFigura) {
                case 0:
                    figuras.add(new Circulo(x, y, 20, color, dx, dy));
                    break;
                case 1:
                    figuras.add(new Rectangulo(x, y, 40, 30, color, dx, dy));
                    break;
                case 2:
                    figuras.add(new Triangulo(x, y, 50, 50, 50, color, dx, dy));
                    break;
            }
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (Figura figura : figuras) {
            figura.dibujar(g);
        }
    }


    @Override
    public void run() {
        while (enEjecucion) {
            if (!enPausa) {
                for (Figura figura : figuras) {
                    figura.mover();

                    if (figura.getX() < 0) {
                        figura.setX(0);
                        figura.setDx(-figura.getDx());
                    } else if (figura.getX() > ANCHO_PANEL) {
                        figura.setX(ANCHO_PANEL);
                        figura.setDx(-figura.getDx());
                    }

                    if (figura.getY() < 0) {
                        figura.setY(0);
                        figura.setDy(-figura.getDy());
                    } else if (figura.getY() > ALTO_PANEL) {
                        figura.setY(ALTO_PANEL);
                        figura.setDy(-figura.getDy());
                    }
                }

                repaint();
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {

                    e.printStackTrace();
                }
            }
        }
    }


    public void detenerMovimiento() {
        enEjecucion = false;
        enPausa = false;
        if (hiloMovimiento != null) {
            hiloMovimiento.interrupt();
        }
        figuras.clear();
    }

    public void iniciarMovimiento() {
        enEjecucion = true;
        if (enPausa) {
            enPausa = false;
        } else {
            hiloMovimiento = new Thread(this);
            hiloMovimiento.start();
        }
    }

    public void pausarMovimiento() {
        enPausa = true;
    }
}
