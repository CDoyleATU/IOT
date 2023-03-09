namespace CodeDemo2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Coins are entered into device
            // Reads size of coin

            Console.WriteLine("Coin entered: ");
            double[] coinArray = {0.20, 0.10, 1, 2, 0.50, 0.05, 0.02, 0.01, 1, 1 , 2, 2, 0.05, 0.02 };

            double total = 0;

            for (int i = 0; i < coinArray.Length; i++)
            {
                switch (coinArray[i])
                {
                    case 0.01:
                        Console.WriteLine("1 cent");
                        total += 0.01;
                        break;

                    case 0.02:
                        Console.WriteLine("2 cent");
                        total += 0.02;
                        break;

                    case 0.05:
                        Console.WriteLine("5 cent");
                        total += 0.05;
                        break;

                    case 0.10:
                        Console.WriteLine("10 cent");
                        total += 0.10;
                        break;

                    case 0.20:
                        Console.WriteLine("20 cent");
                        total += 0.20;
                        break;

                    case 0.50:
                        Console.WriteLine("50 cent");
                        total += 0.50;
                        break;

                    case 1.00:
                        Console.WriteLine("€1");
                        total += 0.20;
                        break;

                    case 2.00:
                        Console.WriteLine("€2");
                        total += 0.50;
                        break;
                }
            }
            Console.WriteLine($"Total = {total:C}");
        }
    }
}