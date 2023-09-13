package threadPools;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


class Deposito {
    private int qtdCaixas = 0;
    private int capacidade;

    private final Object lock1 = new Object();
    private final Object lock2 = new Object();
    private final Object lock3 = new Object();

    Deposito(int capacidade) {
        this.capacidade = capacidade;
    }

    void armazenar() {
        synchronized (lock1) {
            if (qtdCaixas < capacidade) {
                qtdCaixas++;
                System.out.println("Armazenado - Caixas no deposito: " + qtdCaixas);
            }
        }
    }

    void retirar() {
        synchronized (lock2) {
            if (qtdCaixas > 0) {
                qtdCaixas--;
                System.out.println("Retirado - Caixas no deposito: " + qtdCaixas);
            }
        }
    }

    int getQtdCaixas() {
        synchronized (lock3) {
            return qtdCaixas;
        }
    }
}


public class DepósitodeCaixascomThreadPools {
    static class Produtor implements Runnable {
        private Deposito dep;
        private int tempoProducao;

        Produtor (Deposito dep, int tempoProducao) {
            this.dep = dep;
            this.tempoProducao = tempoProducao;
        }

        public void run() {
            int MAX = 1;

            for (int i = 0; i < MAX; i++) {
                dep.armazenar();

                try {
                    Thread.sleep(tempoProducao);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class Consumidor extends Thread {
        private Deposito dep;
        private int tempoConsumo;

        Consumidor (Deposito dep, int tempoConsumo) {
            this.dep = dep;
            this.tempoConsumo = tempoConsumo;
        }

        public void run() {
            int MAX = 1;

            for (int i = 0; i < MAX; i++) {
                dep.retirar();

                try {
                    Thread.sleep(tempoConsumo);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        Deposito dep = new Deposito(3);


        ExecutorService executor = Executors.newFixedThreadPool(5);
        
        for(int i = 0; i < 20; i++){
            executor.submit(new Produtor(dep, (int)(Math.random() * 201)));
            executor.submit(new Consumidor(dep, (int)(Math.random() * 201)));
        }

        executor.shutdown();
    }
}

