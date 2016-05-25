
public class Start {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int [][]systDec;
		Calc newCalc = new Calc();
		LoadInfo loadInfos = new LoadInfo();
		systDec= loadInfos.wczytajTablice("SystemDecyzyjny");
	
		loadInfos.wypiszTablice(systDec);
		newCalc.obliczC(systDec);
		
		

	}

}
