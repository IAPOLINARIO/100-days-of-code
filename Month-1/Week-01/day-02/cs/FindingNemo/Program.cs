using System;

var nemoFinder = new NemoFinder();

Console.WriteLine(nemoFinder.FindNemo("I am finding Nemo !"));
Console.WriteLine(nemoFinder.FindNemo("Nemo is me"));
Console.WriteLine(nemoFinder.FindNemo("I Nemo am"));
Console.WriteLine(nemoFinder.FindNemo("No Nemo's here :P"));

public class NemoFinder
{
    private const string searchValue = "Nemo";
    public string FindNemo(string nemoMessage)
    {
        var searchIndex = nemoMessage.Split(' ');
        var index = Array.IndexOf(searchIndex, searchValue) + 1; // +1 for 0-based index adjustment
        if (index <= 0){
            return "I can't find Nemo :(";
        }

        return $"I found Nemo at {index}!";
    }
}