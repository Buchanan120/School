using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BowlingKata
{
    class Frame
    {
        public int firstRoll;
        public int secondRoll;
        public int thirdRoll;
    }
    class Game
    {
        private Frame[] scoreBoard;
        private int currentFrame;
        private bool isFirstRoll;
        public Game() {
            currentFrame = 0;
            isFirstRoll = true;
            scoreBoard = new Frame[10];
        }
        public void roll(int pins)
        {
            if (currentFrame < 10)
            {
                if (pins == 10)
                {
                    isFirstRoll = false;
                }
                //else if (!isFirstRoll && scoreBoard[currentFrame].firstRoll + pins == 10)
                //{

                //}
            }
            if (isFirstRoll)
            {
               scoreBoard[currentFrame].firstRoll = pins;
               isFirstRoll = false;
            }
            else
            {
               scoreBoard[currentFrame].secondRoll = pins;
               isFirstRoll = true;
               currentFrame++;
            }
        }
        public int score()
        {
            int thisScore = 0;
            for (int i = 0; i < 10; i++)
            {
                thisScore += scoreBoard[i].firstRoll;
                thisScore += scoreBoard[i].secondRoll;
            }
            return thisScore;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Game myGame = new Game();
            // Frame 1
            myGame.roll(6);
            myGame.roll(1);
            // Frame 2
            myGame.roll(9);
            myGame.roll(0);
            // Frame 3
            myGame.roll(8);
            myGame.roll(2);
            // Frame 4
            myGame.roll(5);
            myGame.roll(5);
            // Frame 5
            myGame.roll(8);
            myGame.roll(0);
            // Frame 6
            myGame.roll(6);
            myGame.roll(2);
            // Frame 7
            myGame.roll(9);
            myGame.roll(1);
            // Frame 8
            myGame.roll(7);
            myGame.roll(2);
            // Frame 9
            myGame.roll(8);
            myGame.roll(2);
            // Frame 10
            myGame.roll(9);
            myGame.roll(1);
            myGame.roll(7);

            if (myGame.score() == 127)
                Console.WriteLine("Winnrar");
            else
                Console.WriteLine("Loser.");

        }
    }
}
