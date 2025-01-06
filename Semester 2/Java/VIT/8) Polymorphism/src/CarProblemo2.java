class car5k 
{ 
int speedlimit = 125; 
} 
class innova2 extends car5k 
{ 
int speedlimit = 135; 
public static void main(String args[]) 
{ 
car5k obj = new innova2(); 
System.out.println(obj.speedlimit);
}}

