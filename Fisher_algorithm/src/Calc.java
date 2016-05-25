
import java.util.ArrayList;
import java.util.List;


public class Calc {

	int rozmiarC;
	int[][] tabDec;
	
	public int obliczC(int[][] systDec) {
		tabDec = systDec;
	    
		int x;
		int lenX = systDec[0].length;
		List<Integer> listObC = new ArrayList<Integer>();
		List<Integer> posortS = new ArrayList<Integer>();
		for (int i = 0; i < systDec.length; i++) {
			
			
			listObC = new ArrayList<Integer>();
			if(systDec[i][lenX-1]!=-1) {
			x = systDec[i][lenX-1];
			
			for (int j = 0; j < systDec.length; j++) {
				
				if(x==systDec[j][lenX-1]) {
					
					listObC.add(j);
					systDec[j][lenX-1] = -1;
					
					
				}
				
				
			}
			for(int obj:listObC){
				System.out.print(obj);
			}
			System.out.println();
			double[][] tabS = new double[systDec[0].length-1][2];
			for (int j = 0; j < systDec[0].length-1; j++) {
				
			
		
			double C1,C2,Z1,Z2,SC;
			C1 = obliczC1(listObC,j);
			//System.out.println(C1);
			C2 = obliczC2(listObC,j);
			//System.out.println(C2);
			Z1 = obliczZ1(listObC,j,C1);
			//System.out.println(Z1);
			Z2 = obliczZ2(listObC,j,C2);
			//System.out.println(Z2);
			SC = obliczS(C1,C2,Z1,Z2);
			
			System.out.println("S("+j+") to: "+SC);
			tabS[j][0] = SC; 
			tabS[j][1] = j;
			}
			java.util.Arrays.sort(tabS, new java.util.Comparator<double[]>() {
				  public int compare(double[] a, double[] b) {
				    return (a[0] < b[0] ? -1 : (a[0] == b[0] ? 0 : 1));
				  }
				});
			for (int j = 0; j < tabS.length; j++) {
				
					System.out.println(tabS[j][0] +" " + tabS[j][1]);
				
				System.out.println();
				posortS.add((int)tabS[j][1]+1);
			}
			
			
			
			}
		}
		int licz = 1;
	    
		
		int c= (posortS.size()/(tabDec[0].length-1));
		
		
         for (int i = 0; i < (posortS.size()/(tabDec[0].length-1)); i++) {
        	 System.out.println("Dla C("+(i+1)+") obiekty to");
			for (int j = c; j > c-4; j--) {
				System.out.print(" "+ posortS.get(j));
			}
			System.out.println();
	    	c+=4;
		}
		
		
		
		
		return 0;
	}
	
	public double obliczC1(List<Integer> obLis,int numberA) {
		double C1 = 0;
		
		for (int licz:obLis) {
			
			C1 += tabDec[licz][numberA];
			
		}
		
		C1 = C1/obLis.size();
	
		return C1;
	}
	public double obliczC2(List<Integer> obLis,int numberA) {
		double C2=0;
		boolean jest = false;
		for (int i = 0; i < tabDec.length; i++) {
			jest = false;
			for(int licz:obLis) {
				
				if(i==licz) {
					jest = true;
				}
			}
		    if(jest==false) {
			C2 += tabDec[i][numberA];
			
		    }
		}
		C2 = C2/(tabDec.length-obLis.size());
		return C2;
	}
    public double obliczZ1(List<Integer> obLis,int numberA,double C1) {
    	double Z1=0;
    	
    	for (int i = 0; i < obLis.size(); i++) {
			Z1 += Math.pow(tabDec[obLis.get(i)][numberA]-C1,2);
			
		}
    	
    	Z1 = Z1/obLis.size();
    	return Z1;
    }
    public double obliczZ2(List<Integer> obLis,int numberA,double C2) {
    	double Z2=0;
    	boolean jest = false;
    	
    	for (int i = 0; i < tabDec.length; i++) {
			for(int licz:obLis) {
				
				if(i==licz) {
					jest = true;
				}
			}
			 if(jest==false) {
			Z2 += Math.pow(tabDec[i][numberA]-C2,2);
			
			 }
			 jest=false;
		}
    	
    	Z2 = Z2/(tabDec.length-obLis.size());
    	return Z2;
    }
    public double obliczS(double C1,double C2,double Z1,double Z2) {
    	double S = 0;
    	
    	S = (Math.pow(C1-C2, 2)/(Z1+Z2));
    	
    	return S;
    }
}
