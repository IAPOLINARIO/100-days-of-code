using System;

namespace NextPrime
{
    class Program
    {
        static void Main(string[] args)
        {
            int number = 200;
            int primeNumber = Numbers.GetPrimeNumberOrNext(number);
            Console.WriteLine($"Prime Number is: {primeNumber}");
        }
    }

    public static class Numbers
    {
        public static int GetPrimeNumberOrNext(int number)
        {
            bool isPrimeNumber;

            do
            {
                isPrimeNumber = IsPrime(number);
                if (!isPrimeNumber)
                    number++;
            } while (!isPrimeNumber);

            return number;
        }

        private static bool IsPrime(int number)
        {
            if (number == 1) return false;
            if (number == 2) return true;

            var limit = Math.Ceiling(Math.Sqrt(number));

            for (int i = 2; i <= limit; ++i)
                if (number % i == 0)
                    return false;
            return true;
        }
    }
}
