import java.util.*;
import java.text.*;
public class CurrentDateAndTime {
    public static void main(String[] args) {
        Date date = new Date();
        System.out.println(date);
        java.util.Date date2 = new java.util.Date();  
        System.out.println(date2); 
        Date d=new Date(2018,9,21);  
        Date d1=new Date(1997,3,10); 
        Date d2=new Date(1998,0,10);  
        System.out.println("Date 'd' is after Date 'd2' : "+d.after(d1)); 
        System.out.println("Clone of your Date 'd' : "+d2.clone()); 
        int comparison=d.compareTo(d1);  
        System.out.println("Your comparison value is : "+comparison);
        Date dNow = new Date( );
        SimpleDateFormat ft =  new SimpleDateFormat ("E yyyy.MM.dd 'at' hh:mm:ss a zzz");
        System.out.println("Current Date: " + ft.format(dNow));
        }
    }
