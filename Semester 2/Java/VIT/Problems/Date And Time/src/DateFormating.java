import java.text.SimpleDateFormat;
import java.util.Date;
 public class DateFormating
{    public static void main(String[] args) 
    {        //Getting today's date
                 Date today = new Date();
                 //Printing today's date in the default format
                 System.out.println("Today is : "+today);
                 //Formatting today's date in dd/MM/yyyy format
                 SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
                 System.out.println("Today in dd/MM/yyyy format : "+formatter.format(today));
    }}

