import java.util.ArrayList;

public class Model {

    private int one;
    private int two;

    private ArrayList<Integer> pares;
    private ArrayList<Integer> primos;


    public Model(){

    }
    public Model(int one, int two){

        this.one= one;
        this.two= two;
        this.primos= new ArrayList<>();
        this.pares=new ArrayList<>();


    }



    public ArrayList<Integer> Primos() {
        for (int i = Math.min(one, two); i <= Math.max(one, two); i++) {
            if (esPrimo(i)) {
                primos.add(i);
                System.out.println(i);
            }
        }
        return primos;
    }

    private boolean esPrimo(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public ArrayList<Integer> Pares(){

        for(int i= Math.min(one, two);i<Math.max(one, two);i++){

        if(i%2==0){
            pares.add(i);
            System.out.println(i);

        }

        }
        return pares;
    }



    @Override
    public String toString() {

        String prim="" ;
        String par="" ;

        for(Integer a:primos){

            prim+="-"+a+"\n";

        }
        for(Integer a:pares){

            par+="-"+a+"\n";

        }

        return "Resultado{" +
                "pares=" + par +
                ", primos=" + prim +
                '}';
    }
}
