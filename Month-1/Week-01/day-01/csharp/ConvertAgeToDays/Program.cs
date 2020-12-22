using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("This application convert years into days!");
        int inputYears = Convert.ToInt32(Console.ReadLine());
        int outputDays = AgeConverter.AgeintoDays(inputYears);
        Console.WriteLine($"Result: [{outputDays}] days");
    }
}

public static class AgeConverter
{
    public static int AgeintoDays(int years)
    {
        return 365 * years;
    }
}

