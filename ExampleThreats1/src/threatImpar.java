public class threatImpar implements Runnable{

    int one=0;
    int two=0;
    public threatImpar(int one, int two) {

        this.one=one;
        this.two=two;

    }

    @Override
    public void run() {

        Model md=new Model(one, two);
        md.Primos();

    }
}
