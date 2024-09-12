
class MathMain {
    public static void main(String[] args){
        //Trigo
        Math.sin(0); //returns 0.0
        Math.sin(Math.PI / 6); //returns 0.5
        Math.sin(Math.PI / 2); //returns 1.0
        Math.cos(0); //returns 1.0
        Math.cos(Math.PI / 6); //returns 0.866
        Math.cos(Math.PI / 2);// returns 0
        //Exponents
        Math.exp(1); //returns 2.71
        Math.log(2.71); //returns 1.0
        Math.log10(100); //returns 2.0
        Math.pow(2, 3); //returns 8.0
        Math.pow(3, 2); //returns 9.0
        Math.pow(3.5, 2.5); //returns 22.91765
        Math.sqrt(4); //returns 2.0
        Math.sqrt(10.5); //returns 3.24
        //Rounding
        Math.ceil(2.1);// returns 3.0
        Math.ceil(2.0);// returns 2.0
        Math.ceil(-2.0);// returns –2.0
        Math.ceil(-2.1);// returns -2.0
        Math.floor(2.1);// returns 2.0
        Math.floor(2.0);// returns 2.0
        Math.floor(-2.0);// returns –2.0
        Math.floor(-2.1);// returns -3.0
        Math.rint(2.1);// returns 2.0
        Math.rint(2.0);// returns 2.0
        Math.rint(-2.0);// returns –2.0
        Math.rint(-2.1);// returns -2.0
        Math.rint(2.5);// returns 2.0
        Math.rint(-2.5);// returns -2.0
        Math.round(2.6f);// returns 3
        Math.round(2.0);// returns 2
        Math.round(-2.0f);// returns -2
        Math.round(-2.6);// returns -3 
        //Methods
        Math.max(2, 3);// returns 3
        Math.max(2.5, 3);// returns 3.0
        Math.min(2.5, 3.6);// returns 2.5
        Math.abs(-2);// returns 2
        Math.abs(-2.1);// returns 2.1
    }
}
