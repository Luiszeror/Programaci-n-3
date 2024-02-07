// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) throws InterruptedException {

        FriendsNumbers fn1= new FriendsNumbers(1000,80000);
        FriendsNumbers fn2= new FriendsNumbers(100,1000);
        FriendsNumbers fn3= new FriendsNumbers(1, 1000000);

        ThreadFriends th1= new ThreadFriends(fn1);
        ThreadFriends th2= new ThreadFriends(fn2);
        ThreadFriends th3= new ThreadFriends(fn3);

        Thread thr1= new Thread(th1);
        Thread thr2= new Thread(th2);
        Thread thr3= new Thread(th3);

        thr1.start();
        thr2.start();
        thr3.start();

        thr1.join();
        thr2.join();
        thr3.join();

        System.out.println(fn1.getFriends());
        System.out.println(fn2.getFriends());
        System.out.println(fn3.getFriends());


    }
    }
