import javax.swing.*;
import java.awt.*;

public class Formulario extends JFrame {

    public Formulario() {
        setTitle("Formulario");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 300);
        setLayout(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        JLabel lblNombre = new JLabel("Nombre*:");
        gbc.gridx = 0;
        gbc.gridy = 0;
        add(lblNombre, gbc);

        JTextField txtNombre = new JTextField(20);
        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        add(txtNombre, gbc);

        JButton btnNombre = new JButton("Enviar");
        gbc.gridx = 3;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        add(btnNombre, gbc);

        JLabel lblTelefono = new JLabel("Teléfono:*");
        gbc.gridx = 0;
        gbc.gridy = 1;
        add(lblTelefono, gbc);

        JTextField txtTelefono = new JTextField(20);
        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.gridwidth = 2;
        add(txtTelefono, gbc);

        JButton btnTelefono = new JButton("Enviar");
        gbc.gridx = 3;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        add(btnTelefono, gbc);

        JLabel lblCorreo = new JLabel("Correo*:");
        gbc.gridx = 0;
        gbc.gridy = 2;
        add(lblCorreo, gbc);

        JTextField txtCorreo = new JTextField(20);
        gbc.gridx = 1;
        gbc.gridy = 2;
        gbc.gridwidth = 2;
        add(txtCorreo, gbc);

        JButton btnCorreo = new JButton("Enviar");
        gbc.gridx = 3;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        add(btnCorreo, gbc);

        setVisible(true);
    }

    public static void main(String[] args) {
        new Formulario();
    }
}
