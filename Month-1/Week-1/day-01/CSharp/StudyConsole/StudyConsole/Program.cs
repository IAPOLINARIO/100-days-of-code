using System;
using System.IO.Enumeration;

namespace StudyConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            string Nome = "Ronaldo";
            var bo = true;
            Console.WriteLine("Hello World!");
            Console.WriteLine(Nome);
            if (bo == true) {

                Console.WriteLine("Orelha de elefante");
                bool a = false;
                var teste = Convert.ToInt16(a); //conversão
                Console.WriteLine(teste);
                Console.WriteLine();
                if (a == false) Console.WriteLine("A chuva vai cair"); // exemplo de condicional e output na mesma linha.

            }

            int teste3 = 2;
            switch (teste3) {

                case 1:
                    Console.WriteLine("Salve salve");
                    break;
                case 2:
                    Console.WriteLine("Macaco veio");
                    break;

                case 3:
                    Console.WriteLine("Meu nome é Ronaldo.");
                    break;
            }
            int aa = 2;
            string teste4 = "Ronaldo";
            string testee = (aa == 1 ? "O mano " + teste4 : "O mano Pedro"); // exemplo condicinal ternário.
            Console.WriteLine(testee);

            int loop1 = 1;

            for (loop1 = 1; loop1 < 10; loop1++) {

                Console.WriteLine(loop1);
            
            }


        }
    }
}
