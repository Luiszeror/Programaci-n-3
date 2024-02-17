package Run;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.time.LocalTime;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.util.Random;

public class Main {

    public static void main(String[] args) {
        JFrame frame = new JFrame("Parcial de Programación");

        PanelSuperior panelSuperior = new PanelSuperior();
        Controller.PanelCentro panelCentro = new Controller.PanelCentro();
        PanelInferior panelInferior = new PanelInferior(panelCentro);

        frame.setLayout(new BorderLayout());
        frame.add(panelSuperior, BorderLayout.NORTH);
        frame.add(panelCentro, BorderLayout.CENTER);
        frame.add(panelInferior, BorderLayout.SOUTH);

        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

class PanelSuperior extends JPanel {
    public PanelSuperior() {
        setLayout(new GridLayout(1, 5));
        setBorder(new EmptyBorder(10, 10, 10, 10));

        add(new RelojPanel("Nueva York", ZoneId.of("America/New_York")));

        add(new RelojPanel("Londres", ZoneId.of("Europe/London")));

        add(new RelojPanel("Tokio", ZoneId.of("Asia/Tokyo")));
    }


}

class RelojPanel extends JPanel implements Runnable {
    private JLabel labelHora;
    private JLabel labelPais;
    private ZoneId zoneId;

    public RelojPanel(String nombrePais, ZoneId zoneId) {
        this.zoneId = zoneId;
        setLayout(new BorderLayout());
        setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.GRAY)); // Línea separadora debajo del panel

        labelPais = new JLabel(nombrePais);
        add(labelPais, BorderLayout.NORTH);

        labelHora = new JLabel();
        add(labelHora, BorderLayout.CENTER);

        Thread hiloHora = new Thread(this);
        hiloHora.start();
    }

    @Override
    public void run() {
        while (true) {
            LocalTime horaActual = LocalTime.now(zoneId);
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
            labelHora.setText(formatter.format(horaActual));
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class PanelCentro extends JPanel implements Runnable {
    private volatile boolean enEjecucion = true;

    public PanelCentro() {
        Thread hiloMovimiento = new Thread(this);
        hiloMovimiento.start();
    }

    @Override
    public void run() {
        Random random = new Random();
        while (enEjecucion) {

            try {
                Thread.sleep(random.nextInt(1000)); // Velocidad de movimiento aleatoria
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void detenerMovimiento() {


        enEjecucion = false;
    }
}

class PanelInferior extends JPanel {
    private JButton botonPlay;
    private JButton botonPause;
    private JButton botonStop;
    private PanelCentro panelCentro;



    public PanelInferior(Controller.PanelCentro panelCentro) {


        setBorder(new EmptyBorder(10, 0, 0, 0));

        botonPlay = new JButton("Play");
        botonPlay.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                panelCentro.iniciarMovimiento();
            }
        });



        botonPause = new JButton("Pause");
        botonPause.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                panelCentro.pausarMovimiento();
            }
        });


        botonStop = new JButton("Stop");
        botonStop.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                panelCentro.detenerMovimiento();
            }
        });

        add(botonPlay);
        add(botonPause);
        add(botonStop);
    }
}
