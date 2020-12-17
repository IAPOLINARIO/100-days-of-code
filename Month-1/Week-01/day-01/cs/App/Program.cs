using System;

Console.WriteLine("Enter your age: ");
try
{
    var result = new AgeCalculator().CalcAge(Console.ReadLine());

    Console.WriteLine($"You are {result} days old");
}
catch (Exception ex)
{
    Console.WriteLine("Something went wrong.");
    Console.WriteLine(ex.Message);
}

public class AgeCalculator
{
    const int yearInDays = 365;
    public int CalcAge(int ageInYears)
    {
        if (ageInYears <= 0 || ageInYears > int.MaxValue) 
        {
            throw new Exception($"Age must be a positive number (Max: {int.MaxValue})");
        }
        return ageInYears * yearInDays;
    }

    public int CalcAge(string ageInYears)
    {
        int.TryParse(ageInYears.Trim(), out int age);
        return CalcAge(age);
    }
}