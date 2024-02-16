public class threatPar implements Runnable {

    int one=0;
    int two=0;
    public threatPar(int one, int two) {

        this.one=one;
        this.two=two;

    }

    @Override
    public void run() {

        Model md=new Model(one, two);
        md.Pares();

    }


}

