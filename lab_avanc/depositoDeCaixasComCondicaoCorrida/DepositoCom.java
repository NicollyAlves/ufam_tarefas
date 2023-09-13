package depositoDeCaixasComCondicaoCorrida;

class Deposito {
    private int qtdCaixas = 0;
    private int capacidade;

    Deposito(int capacidade) {
        this.capacidade = capacidade;
    }

    void armazenar() {
        if (qtdCaixas < capacidade) {
            qtdCaixas++;
            System.out.println("Armazenado - Caixas no deposito: " + qtdCaixas);
        }
    }

    void retirar() {
        if (qtdCaixas > 0) {
            qtdCaixas--;
            System.out.println("Retirado - Caixas no deposito: " + qtdCaixas);
        }
    }

    int getQtdCaixas() {
        return qtdCaixas;
    }
}


public class DepositoCom {
    static class Produtor implements Runnable {
        private Deposito dep;
        private int tempoProducao;

        Produtor (Deposito dep, int tempoProducao) {
            this.dep = dep;
            this.tempoProducao = tempoProducao;
        }

        public void run() {
            int MAX = 10;

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
            int MAX = 10;

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
        Thread prod = new Thread(new Produtor (dep, 100));
        Consumidor cons = new Consumidor(dep, 200);

        prod.start();
        cons.start();

    }
}
