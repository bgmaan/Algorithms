import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;


public class LoadInfo {
	

	public int[][] wczytanaTablica;
	int  liczbaWierszy;
	int  liczbaKolumn;
	String wiersz = null;
	
	
	
	public int[][] wczytajTablice(String tabName) {
		int licznikWierszy = 0;
		int licznikKolumn = 0;
		int licznik = 0;
      //wczytaj z pliku
		File tekst = new File(tabName+".txt");
		try {
			FileReader czytajPlik = new FileReader(tekst);
			BufferedReader czytajBuffer = new BufferedReader(czytajPlik);
			
			while((wiersz = czytajBuffer.readLine()) != null) {
			String[] wiersze = wiersz.split(" ");
			licznikKolumn ++;
			licznikWierszy = wiersze.length;
			}
		     liczbaWierszy = licznikKolumn;
	         liczbaKolumn = licznikWierszy;
			wczytanaTablica = new int[licznikKolumn][licznikWierszy];
			czytajPlik = new FileReader(tekst);
		    czytajBuffer = new BufferedReader(czytajPlik);
		    int liczk = 0;
			while((wiersz = czytajBuffer.readLine()) != null) {
			
				 String[] wiersze = wiersz.split(" ");
				 for (int i = 0; i < wiersze.length; i++) {
					wczytanaTablica[liczk][i] = Integer.parseInt(wiersze[i]);
				}
				 liczk++;
				 licznik++;
				}
       
			czytajPlik.close();
			
			
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return wczytanaTablica;
		}
	
	public void wypiszTablice(int[][] tab) {
	    System.out.println("________________________");
    	for (int i = 0; i < tab.length; i++) {
			for (int j = 0; j < tab[0].length; j++) {
				System.out.print(tab[i][j]+" ");
			}
			System.out.println();
		}
    	
    }
	
	

}
