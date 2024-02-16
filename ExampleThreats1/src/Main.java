import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        int one=0;
        int two=0;
        Scanner sc= new Scanner(System.in);

        System.out.println("Escriba dos limites para hallar los numero pares y primos que existan entre estos dos numeros: ");
        System.out.println("Limite 1:");
        one=sc.nextInt();
        System.out.println("Limite 2:");
        two=sc.nextInt();

        threatPar tP= new threatPar(one, two);

        threatImpar tIP= new threatImpar(one, two);

        Thread pares= new Thread(tP);
        Thread primos= new Thread(tIP);

        primos.start();

        pares.start();




    }
}