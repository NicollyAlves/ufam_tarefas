import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.CyclicBarrier;
import java.lang.InterruptedException;

import java.util.concurrent.BrokenBarrierException;

public class MontanhaRussa {
    private static final int N = 12;
    private static final int C = 4;

    public static void main(String[] args) {
        CyclicBarrier barrier = new CyclicBarrier(C, () -> {
            try {
                System.out.println("O carro está iniciando a volta...");
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("A volta foi completada!");
        });

        ExecutorService PassageiroThreadPool = Executors.newFixedThreadPool(N);

        for (int i = 1; i <= N; i++) {
            Runnable Passageiro = new Passageiro(barrier, i);
            PassageiroThreadPool.execute(Passageiro);
        }

        PassageiroThreadPool.shutdown();
    }

    static class Passageiro implements Runnable {
        private final CyclicBarrier barrier;
        private final int PassageiroId;

        public Passageiro(CyclicBarrier barrier, int PassageiroId) {
            this.barrier = barrier;
            this.PassageiroId = PassageiroId;
        }

        @Override
        public void run() {
            System.out.println("Passageiro " + PassageiroId + " chegou na fila da Montanha Russa.");
            try {
                System.out.println("Passageiro " + PassageiroId + " entrou no carro da Montanha Russa.");
                barrier.await();
            } catch (InterruptedException | BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }
}
