using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
///█ ■
////https://www.youtube.com/watch?v=SGZgvMwjq2U
namespace Snake
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WindowHeight = 16;
            Console.WindowWidth = 32;
            int screenwidth = Console.WindowWidth;
            int screenheight = Console.WindowHeight;
            //unwanted code removed
            int score = 5;t evaluate(char b[3][3]) 
{ 
	// Checking for Rows for X or O victory. 
	for (int row = 0; row < 3; row++) { 
		if (b[row][0] == b[row][1] 
			&& b[row][1] == b[row][2]) { 
			if (b[row][0] == player) 
				return +10; 
			else if (b[row][0] == opponent) 
				return -10; 
		} 
	} 

	// Checking for Columns for X or O victory. 
	for (int col = 0; col < 3; col++) { 
		if (b[0][col] == b[1][col] 
			&& b[1][col] == b[2][col]) { 
			if (b[0][col] == player) 
				return +10; 

			else if (b[0][col] == opponent) 
				return -10; 
		} 
	} 

	// Checking for Diagonals for X or O victory. 
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) { 
		if (b[0][0] == player) 
			return +10; 
		else if (b[0][0] == opponent) 
			return -10; 
	} t evaluate(char b[3][3]) 
{ 
	// Checking for Rows for X or O victory. 
	for (int row = 0; row < 3; row++) { 
		if (b[row][0] == b[row][1] 
			&& b[row][1] == b[row][2]) { 
			if (b[row][0] == player) 
				return +10; 
			else if (b[row][0] == opponent) 
				return -10; 
		} 
	} 

	// Checking for Columns for X or O victory. 
	for (int col = 0; col < 3; col++) { 
		if (b[0][col] == b[1][col] 
			&& b[1][col] == b[2][col]) { 
			if (b[0][col] == player) 
				return +10; 

			else if (b[0][col] == opponent) 
				return -10; 
		} 
	} 

	// Checking for Diagonals for X or O victory. 
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) { 
		if (b[0][0] == player) 
			return +10; 
		else if (b[0][0] == opponent) 
			return -10; 
	} 
            int gameover = 0;
            pixel hoofd = new pixel();
            hoofd.xpos = screenwidth/2;
            hoofd.ypos = screenheight/2;
            hoofd.schermkleur = ConsoleColor.Red;
            string movement = "RIGHT";
            List<int> xposlijf = new List<int>();
            List<int> yposlijf = new List<int>();
            int berryx = randomnummer.Next(0, screenwidth);
            int berryy = randomnummer.Next(0, screenheight);
            DateTime tijd = DateTime.Now;
            DateTime tijd2 = DateTime.Now;
            string buttonpressed = "no";
            while (true)
            {
                Console.Clear();
                if (hoofd.xpos == screenwidth-1 || hoofd.xpos == 0 ||hoofd.ypos == screenheight-1 || hoofd.ypos == 0)
                { 
                    gameover = 1;
                }
                for (int i = 0;i< screenwidth; i++)
                {
                    Console.SetCursorPosition(i, 0);
                    Console.Write("■");
                }
                for (int i = 0; i < screenwidth; i++)
                {
                    Console.SetCursorPosition(i, screenheight -1);
                    Console.Write("■");
                }
                for (int i = 0; i < screenheight; i++)
                {
                    Console.SetCursorPosition(0, i);
                    Console.Write("■");
                }
                for (int i = 0; i < screenheight; i++)
                {
                    Console.SetCursorPosition(screenwidth - 1, i);
                    Console.Write("■");
                }
                Console.ForegroundColor = ConsoleColor.Green;
                if (berryx == hoofd.xpos && berryy == hoofd.ypos)
                {
                    score++;
                    berryx = randomnummer.Next(1, screenwidth-2);
                    berryy = randomnummer.Next(1, screenheight-2);
                } 
                for (int i = 0; i < xposlijf.Count(); i++)
                {
                    Console.SetCursorPosition(xposlijf[i], yposlijf[i]);
                    Console.Write("■");
                    if (xposlijf[i] == hoofd.xpos && yposlijf[i] == hoofd.ypos)
                    {
                        gameover = 1;
                    }
                }
                if (gameover == 1)
                {
                    break;
                }
                Console.SetCursorPosition(hoofd.xpos, hoofd.ypos);
                Console.ForegroundColor = hoofd.schermkleur;
                Console.Write("■");
                Console.SetCursorPosition(berryx, berryy);
                Console.ForegroundColor = ConsoleColor.Cyan;
                Console.Write("■");
                tijd = DateTime.Now;
                buttonpressed = "no";
                while (true)
                {
                    tijd2 = DateTime.Now;
                    if (tijd2.Subtract(tijd).TotalMilliseconds > 500) { break; }
                    if (Console.KeyAvailable)
                    {
                        ConsoleKeyInfo toets = Console.ReadKey(true);
                        //Console.WriteLine(toets.Key.ToString());
                        if (toets.Key.Equals(ConsoleKey.UpArrow) && movement != "DOWN" && buttonpressed == "no")
                        {
                            movement = "UP";
                            buttonpressed = "yes";
                        }
                        if (toets.Key.Equals(ConsoleKey.DownArrow) && movement != "UP" && buttonpressed == "no")
                        {
                            movement = "DOWN";
                            buttonpressed = "yes";
                        }
                        if (toets.Key.Equals(ConsoleKey.LeftArrow) && movement != "RIGHT" && buttonpressed == "no")
                        {
                            movement = "LEFT";
                            buttonpressed = "yes";
                        }
                        if (toets.Key.Equals(ConsoleKey.RightArrow) && movement != "LEFT" && buttonpressed == "no")
                        {
                            movement = "RIGHT";
                            buttonpressed = "yes";
                        }
                    }
                }
                xposlijf.Add(hoofd.xpos);
                yposlijf.Add(hoofd.ypos);
                switch (movement)
                {
                    case "UP":
                        hoofd.ypos--;
                        break;
                    case "DOWN":
                        hoofd.ypos++;
                        break;
                    case "LEFT":
                        hoofd.xpos--;
                        break;
                    case "RIGHT":
                        hoofd.xpos++;
                        break;
                }
                if (xposlijf.Count() > score)
                {
                    xposlijf.RemoveAt(0);
                    yposlijf.RemoveAt(0);
                }
            }
            Console.SetCursorPosition(screenwidth / 5, screenheight / 2);
            Console.WriteLine("Game over, Score: "+ score);
            Console.SetCursorPosition(screenwidth / 5, screenheight / 2 +1);
        }
        class pixel
        {
            public int xpos { get; set; }
            public int ypos { get; set; }
            public ConsoleColor schermkleur { get; set; }
        }
    }
}
//¦
