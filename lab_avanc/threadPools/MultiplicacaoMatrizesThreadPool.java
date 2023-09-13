package threadPools;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MultiplicacaoMatrizesThreadPool {
    public static void main(String[] args) {
        final int tamMatriz = 1000;
        final int numThreads = 8;

        int[][] matrizA = gerarMatrizAleatoria(tamMatriz);
        int[][] matrizB = gerarMatrizAleatoria(tamMatriz);
        int[][] matrizResultado = new int[tamMatriz][tamMatriz];

        System.out.println("Matriz A:");
        imprimirMatriz(matrizA);

        System.out.println("\nMatriz B:");
        imprimirMatriz(matrizB);

        ExecutorService executorService = Executors.newFixedThreadPool(numThreads);

        for (int i = 0; i < tamMatriz; i++) {
            final int linha = i;
            executorService.execute(() -> multiplicarLinha(matrizA, matrizB, matrizResultado, linha));
        }

        executorService.shutdown();

        try {
            executorService.awaitTermination(Long.MAX_VALUE, java.util.concurrent.TimeUnit.NANOSECONDS);
        } catch (InterruptedException e) {
            System.err.println("Erro ao aguardar término das threads.");
        }

        System.out.println("\nMatriz Resultado:");
        imprimirMatriz(matrizResultado);
    }

    public static int[][] gerarMatrizAleatoria(int tamanho) {
        int[][] matriz = new int[tamanho][tamanho];
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                matriz[i][j] = (int) (Math.random() * 100);
            }
        }
        return matriz;
    }

    public static void multiplicarLinha(int[][] matrizA, int[][] matrizB, int[][] matrizResultado, int linha) {
        int tamMatriz = matrizA.length;
        for (int j = 0; j < tamMatriz; j++) {
            int soma = 0;
            for (int k = 0; k < tamMatriz; k++) {
                soma += matrizA[linha][k] * matrizB[k][j];
            }
            matrizResultado[linha][j] = soma;
        }
    }

    public static void imprimirMatriz(int[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[0].length; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }
}
