package criacaoThreadComRunnable;

public class Relogio implements Runnable {
	private ContadorTempo contador;
	private int qtdTicks;
	private int inicialTick;
	
	public Relogio(int qtdTicks, int inicialTick) {
	    this.contador = new ContadorTempo(2);
		this.qtdTicks = qtdTicks;
		this.inicialTick = inicialTick;
        Thread t = new Thread(this);
        t.start();
	}
	
	public Relogio(int qtdTicks) {
	    this.contador = new ContadorTempo(2);
		this.qtdTicks = qtdTicks;
		this.inicialTick = 0;
        Thread t = new Thread(this);
        t.start();
	}
	
	public Relogio() {
	    this.contador = new ContadorTempo(2);
		this.qtdTicks = 0;
		this.inicialTick = 0;
        Thread t = new Thread(this);
        t.start();
	}
	
	public void run() {
		try {
			for(int i = 0; i < qtdTicks; i++) {
				System.out.println("Tick: " + (contador.getTick()));
				contador.nextTick();
				Thread.sleep(1000);
			}
		} catch(InterruptedException e) {}
	}
}