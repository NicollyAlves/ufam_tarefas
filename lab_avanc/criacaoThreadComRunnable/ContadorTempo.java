package criacaoThreadComRunnable;

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