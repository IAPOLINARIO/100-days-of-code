using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace PhoneLetterCombinations
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "023";

            if (Letters.IsValidInput(input))
            {
                var letterCombined = Letters.Combiner(input);

                foreach (string line in letterCombined)
                {
                    Console.WriteLine(line);
                }
            }
        }
    }

    public static class Letters
    {
        public static List<string> Combiner(string inputLetters)
        {
            List<string> output = new List<string>();
            int[] inputNumbers = ConvertIntoIntArray(inputLetters);
            var letters = GetLetters(inputNumbers);
            int lastItem;
            string line;

            for (int i = 0; i < letters.Count; i++)
            {
                lastItem = letters.Count - 1;
                foreach (string obj in ConvertIntoStringArray(letters[i]))
                {
                    line = obj;
                    if (!i.Equals(lastItem))
                    {
                        foreach (string obj2 in ConvertIntoStringArray(letters[i + 1]))
                        {
                            output.Add($"{line}{obj2}");
                        }

                    }
                    if (letters.Count == 1)
                    {
                        output.Add(obj);
                    }

                }
            }

            return output;
        }

        public static bool IsValidInput(string input)
        {
            return Regex.IsMatch(input, "^[2-9]*$");
        }

        private static int[] ConvertIntoIntArray(string inputLetters)
        {
            return inputLetters
                .ToCharArray()
                .Select(c => c.ToString()).ToArray()
                .Select(int.Parse).ToArray();
        }

        private static string[] ConvertIntoStringArray(string inputLetters)
        {
            return inputLetters
                .ToCharArray()
                .Select(c => c.ToString()).ToArray();
        }

        private static List<string> GetLetters(int[] inputNumbers)
        {
            var letters = new List<string>();
            var combinations = GetMatrix();

            foreach (int obj in inputNumbers)
            {
                letters.Add(combinations[obj]);
            }
            return letters;
        }

        private static Dictionary<int, string> GetMatrix()
        {
            var phoneKeyboardMatrix = new Dictionary<int, string>()
            {
                { 2, "abc"},
                { 3, "def"},
                { 4, "ghi"},
                { 5, "jkl"},
                { 6, "mno"},
                { 7, "pqrs"},
                { 8, "tuv"},
                { 9, "wxyz"}
             };

            return phoneKeyboardMatrix;
        }
    }
}
