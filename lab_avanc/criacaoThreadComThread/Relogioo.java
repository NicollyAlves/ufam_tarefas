class ContadorTempo {
	private int tick;
	
	public ContadorTempo() {
		this.tick = 0;
	}
	
	public ContadorTempo(int tick) {
		this.tick = tick;
	}
	
	public void nextTick() {
		tick++;
	}
	
	public int getTick() {
		return tick;
	}
}

public class Relogioo extends Thread {
	private ContadorTempo contador;
	private int qtdTicks;
	private int inicialTick;
	
	public Relogioo(int qtdTicks, int inicialTick) {
	    this.contador = new ContadorTempo(2);
		this.qtdTicks = qtdTicks;
		this.inicialTick = inicialTick;
	}
	
	public Relogioo(int qtdTicks) {
	    this.contador = new ContadorTempo(2);
		this.qtdTicks = qtdTicks;
		this.inicialTick = 0;
	}
	
	public Relogioo() {
	    this.contador = new ContadorTempo(2);
		this.qtdTicks = 0;
		this.inicialTick = 0;
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
	
	public static void main(String[] args) {
		Relogioo relogio = new Relogioo(10, 3);
		relogio.start();
	}
}