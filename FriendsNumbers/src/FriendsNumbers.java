import java.util.HashMap;
import java.util.Map;

public class FriendsNumbers {

    private int limiteInferior;
    private int limiteSuperior;
    private Map<Integer, Integer> Friends;

    public FriendsNumbers(int limiteInferior, int limiteSuperior){

    this.limiteInferior=limiteInferior;
    this.limiteSuperior=limiteSuperior;
    this.Friends= new HashMap<Integer, Integer>();

    }

    public int getLimiteInferior() {
        return limiteInferior;
    }

    public void setLimiteInferior(int limiteInferior) {
        this.limiteInferior = limiteInferior;
    }

    public int getLimiteSuperior() {
        return limiteSuperior;
    }

    public void setLimiteSuperior(int limiteSuperior) {
        this.limiteSuperior = limiteSuperior;
    }

    private int getSumDivisors(int numero){
        int sum = 0;
        for (int i = 1; i <= numero / 2; i++) {
            if (numero % i == 0) {
                sum += i;
            }
        }
        return sum;
    }

    public Map<Integer, Integer> getFriends() {
        for (int i = limiteInferior; i <= limiteSuperior; i++) {
            int sum = getSumDivisors(i);
            if (sum > i && sum <= limiteSuperior && getSumDivisors(sum) == i) {
                Friends.put(i, sum);
            }
        }
        return Friends;
    }
}
