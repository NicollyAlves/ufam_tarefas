package fumantesCountDownLatch;
import java.util.concurrent.CountDownLatch;

class Fumante implements Runnable {
    private String ingrediente;
    private CountDownLatch agenteLatch;
    private CountDownLatch fumanteLatch;

    public Fumante(String ingrediente, CountDownLatch agenteLatch, CountDownLatch fumanteLatch) {
        this.ingrediente = ingrediente;
        this.agenteLatch = agenteLatch;
        this.fumanteLatch = fumanteLatch;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                System.out.println("Fumante com " + ingrediente + " está esperando os ingredientes.");
                agenteLatch.await();

                System.out.println("Fumante com " + ingrediente + " pegou os ingredientes da mesa e está fumando.");
                Thread.sleep(1000);

                System.out.println("Fumante com " + ingrediente + " terminou de fumar.");
                fumanteLatch.countDown();
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Agente implements Runnable {
    private CountDownLatch agenteLatch;
    private CountDownLatch[] fumanteLatches;

    public Agente(CountDownLatch agenteLatch, CountDownLatch[] fumanteLatches) {
        this.agenteLatch = agenteLatch;
        this.fumanteLatches = fumanteLatches;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                int ingrediente1 = (int) (Math.random() * 3);
                int ingrediente2;
                do {
                    ingrediente2 = (int) (Math.random() * 3);
                } while (ingrediente1 == ingrediente2);

                System.out.println("Agente colocou ingredientes " + ingrediente1 + " e " + ingrediente2 + " na mesa.");
                agenteLatch.countDown();

                for (int j = 0; j < 3; j++) {
                    if (j != ingrediente1 && j != ingrediente2) {
                        fumanteLatches[j].await();
                    }
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class FumantesCountDownLatch {
    public static void main(String[] args) {
        CountDownLatch agenteLatch = new CountDownLatch(1);
        CountDownLatch[] fumanteLatches = { new CountDownLatch(1), new CountDownLatch(1), new CountDownLatch(1) };

        Thread agenteThread = new Thread(new Agente(agenteLatch, fumanteLatches));
        Thread fumante1Thread = new Thread(new Fumante("tabaco", agenteLatch, fumanteLatches[0]));
        Thread fumante2Thread = new Thread(new Fumante("papel", agenteLatch, fumanteLatches[1]));
        Thread fumante3Thread = new Thread(new Fumante("fósforos", agenteLatch, fumanteLatches[2]));

        agenteThread.start();
        fumante1Thread.start();
        fumante2Thread.start();
        fumante3Thread.start();
    }
}
