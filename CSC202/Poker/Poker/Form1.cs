using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Poker
{
	public partial class Form1 : Form
	{
		Card[] hand = new Card[5];  //This is the 5-card hand that the player has
		Stack<Card> deck = new Stack<Card>();//This is the deck used throughout the game
		

		public Form1()
		{
			InitializeComponent();
			//PaintCard(1, 2,'D');
			//On load, initialize deck
			CreateDeck();
		}

		//Use some randomization to shuffle the deck of cards.
		//This always creates a new deck just in case, since it s a stack
		private void btnShuffle_Click(object sender, EventArgs e)
		{
			CreateDeck();
			//Create a temporary array to randomize
			Card[] temp = new Card[52];
			Random randomNumber = new Random();
			int randomIndex;

			//initialize temp array
			for (int i = 0; i < 52; i++)
				temp[i] = new Card();

			for (int i = 0; i < 52; i++)
			{
				randomIndex = randomNumber.Next(0, 51); //Randomize

				//Place into temp array, check if its empty
				if (temp[randomIndex].cardNumber == 0)
					temp[randomIndex] = deck.Pop();
				else // if the array is not empty at that index, re-randomize
				{
					while (temp[randomIndex].cardNumber != 0)
					{
						//decrement until empty space from random #
						if (randomIndex >= 0)
						{
							if (randomIndex != 0)
								randomIndex--;
							else //If below 0, then go back to top
								randomIndex = 51;
						}
					}
					temp[randomIndex] = deck.Pop();
				}
			}
			//Clear deck and push on temporary data
			deck.Clear();
			for (int i = 0; i < 52; i++)
				deck.Push(temp[i]);
		}
		
		
		//btnDeal_Click
		//When Deal is clicked, change the hand of the player
		//Which means updating the labels and group boxes on the form
		private void btnDeal_Click(object sender, EventArgs e)
		{
			//Graphics object
			Graphics g = this.CreateGraphics();
			this.Show();

			lblResults.Text = "---";
			if(deck.Count > 5)
			{
				for (int i = 0; i < 5; i++)
				{
					hand[i] = new Card();
					hand[i] = deck.Pop();
				}

				//Change labels and such
				//Card 1
				lblCard1Num.Text = (hand[0].cardNumber).ToString();
				lblCard1Suit.Text = (hand[0].cardSuit).ToString();
				grbCard1.ForeColor = hand[0].cardColor;
				//Card 2
				lblCard2Num.Text = (hand[1].cardNumber).ToString();
				lblCard2Suit.Text = (hand[1].cardSuit).ToString();
				grbCard2.ForeColor = hand[1].cardColor;
				//Card 3
				lblCard3Num.Text = (hand[2].cardNumber).ToString();
				lblCard3Suit.Text = (hand[2].cardSuit).ToString();
				grbCard3.ForeColor = hand[2].cardColor;
				//Card 4
				lblCard4Num.Text = (hand[3].cardNumber).ToString();
				lblCard4Suit.Text = (hand[3].cardSuit).ToString();
				grbCard4.ForeColor = hand[3].cardColor;
				//Card 5
				lblCard5Num.Text = (hand[4].cardNumber).ToString();
				lblCard5Suit.Text = (hand[4].cardSuit).ToString();
				grbCard5.ForeColor = hand[4].cardColor;
			}
			CheckResults();


			CleanGraphics(ref g);
			for (int i = 0; i < 5; i++)
				PaintCard(ref g, i+1, hand[i].cardNumber, hand[i].cardSuit);
		}

		//CheckResults
		//Checks the dealt hand for any winning hands
		//Displays any wins in results label
		private void CheckResults()
		{
			bool bRoyalFlush = false;
			bool bStraightFlush = false;
			bool bFourOfAKind = false;
			bool bFullHouse = false;
			bool bFlush = false;
			bool bStraight = false;
			bool bThreeOfAKind = false;
			bool bTwoPair = false;
			bool bPair = false;		

			//Place current hand in order, smallest to biggest
			List<int> currentHand = new List<int>();
			currentHand.Add(hand[0].cardNumber);
			currentHand.Add(hand[1].cardNumber);
			currentHand.Add(hand[2].cardNumber);
			currentHand.Add(hand[3].cardNumber);
			currentHand.Add(hand[4].cardNumber);
			currentHand.Sort();
			for (int i = 0; i < 5; i++)
				Console.WriteLine(currentHand[i].ToString());

			//Check for Royal Flush
			bool bFoundTen = false;
			bool bFoundJack = false;
			bool bFoundQueen = false;
			bool bFoundKing = false;
			bool bFoundAce = false;
			//Start by checking for some pair
			if(hand[0].cardSuit == hand[1].cardSuit)
			{
				//If all matching suits, check for numbers
				if(hand[0].cardSuit == hand[2].cardSuit &&
					hand[0].cardSuit == hand[3].cardSuit &&
					hand[0].cardSuit == hand[4].cardSuit)
				{
					for(int i = 0; i < 5; i++)
					{
						if (hand[i].cardNumber == 10 && bFoundTen == false)
							bFoundTen = true;
						else if (hand[i].cardNumber == 11 && bFoundJack == false)
							bFoundJack = true;
						else if (hand[i].cardNumber == 12 && bFoundQueen == false)
							bFoundQueen = true;
						else if (hand[i].cardNumber == 13 && bFoundKing == false)
							bFoundKing = true;
						else if (hand[i].cardNumber == 1 && bFoundAce == false)
							bFoundAce = true;
						else
							break;
					}
				}
				if (bFoundTen == true && bFoundJack == true &&
					bFoundQueen == true && bFoundKing == true &&
					bFoundAce == true)
				{
					bRoyalFlush = true;
					lblResults.Text = "Royal Flush!";
				}
			}

			//Check for Straight Flush
			if (hand[0].cardSuit == hand[1].cardSuit)
			{
				//If all matching suits, check for numbers
				if (hand[0].cardSuit == hand[2].cardSuit &&
					hand[0].cardSuit == hand[3].cardSuit &&
					hand[0].cardSuit == hand[4].cardSuit)
				{
					int contiguousCount = 0;
					for(int i = 0; i < 4; i++)
					{
						if (currentHand[i + 1] - currentHand[i] == 1)
							contiguousCount++;
					}
					if(contiguousCount == 4)
					{
						bStraightFlush = true;
						lblResults.Text = "Straight Flush!";
					}
				}
			}

			//Check Flush
			if(hand[0].cardSuit == hand[1].cardSuit)
			{
				//If all matching suits
				if (hand[0].cardSuit == hand[1].cardSuit &&
					hand[0].cardSuit == hand[2].cardSuit &&
					hand[0].cardSuit == hand[3].cardSuit &&
					hand[0].cardSuit == hand[4].cardSuit)
				{
					bFlush = true;
					lblResults.Text = "Flush";
				}
			}

			//Check Straight
			if(currentHand[1] - currentHand[0] == 1)
			{
				int contiguousCount = 0;
				for (int i = 0; i < 4; i++)
				{
					if (currentHand[i + 1] - currentHand[i] == 1)
						contiguousCount++;
				}
				if (contiguousCount == 4)
				{
					bFlush = true;
					lblResults.Text = "Flush!";
				}
			}
			
			//Check Pair
			if(currentHand[0] == currentHand[1] ||
				currentHand[1] == currentHand[2] ||
				currentHand[2] == currentHand[3] ||
				currentHand[3] == currentHand[4])
			{
				bPair = true;
				lblResults.Text = "Pair!";
			}

			//Check Two Pair
			if (currentHand[0] == currentHand[1] ||
				currentHand[1] == currentHand[2] ||
				currentHand[2] == currentHand[3] ||
				currentHand[3] == currentHand[4])
			{
				int numberOfPairs = 0;
				for (int i = 0; i < 4; i++)
				{
					if (currentHand[i] == currentHand[i + 1])
						numberOfPairs++;
				}
				if (numberOfPairs == 2)
				{
					bTwoPair = true;
					lblResults.Text = "Two Pair!";
				}
			}

			//Check Three of a Kind
			if (currentHand[0] == currentHand[1] ||
				currentHand[1] == currentHand[2] ||
				currentHand[2] == currentHand[3])
			{
				int checkNumber = currentHand[0];
				int contiguousCount = 0;
				for (int i = 1; i < 5; i++)
				{
					if (currentHand[i] == checkNumber)
					{
						contiguousCount++;
					}
					else
					{
						if (i < 4 && currentHand[i + 1] != checkNumber)
						{
							if (currentHand[i + 1] == currentHand[i])
							{
								checkNumber = currentHand[i];
								contiguousCount = 0;
							}
							else
								break;
						}
					}
				}
				if (contiguousCount == 2)
				{
					bThreeOfAKind = true;
					lblResults.Text = "Three of a Kind!";
				}
			}

			//Check for Four of a Kind
			if (currentHand[0] == currentHand[1] ||
				currentHand[2] == currentHand[3])
			{
				int checkNumber = currentHand[0];
				int contiguousCount = 0;
				for (int i = 1; i < 5; i++)
				{
					if (currentHand[i] == checkNumber)
					{
						contiguousCount++;
					}
					else
					{
						if (i < 4 && currentHand[i + 1] != checkNumber)
						{
							if (currentHand[i + 1] == currentHand[i])
							{
								checkNumber = currentHand[i];
								contiguousCount = 0;
							}
							else
								break;
						}
					}
				}
				if (contiguousCount == 3)
				{
					bFourOfAKind = true;
					lblResults.Text = "Four of a Kind!";
				}
			}

			//Check Full House
			if (currentHand[0] == currentHand[1] &&
				currentHand[1] == currentHand[2] &&
				currentHand[3] == currentHand[4])
			{
				bFullHouse = true;
				lblResults.Text = "Full House!";
			}
		}

		//CreateDeck
		//Initializes deck on load up
		private void CreateDeck()
		{
			deck.Clear();

			//Create deck for Diamonds
			for (int i = 1; i <= 13; i++)
			{
				Card temp = new Card();
				temp.cardNumber = i;
				temp.cardSuit = 'D';
				temp.cardColor = Color.Red;
				deck.Push(temp);
			}
			//Create deck for Hearts
			for (int i = 1; i <= 13; i++)
			{
				Card temp = new Card();
				temp.cardNumber = i;
				temp.cardSuit = 'H';
				temp.cardColor = Color.Red;
				deck.Push(temp);
			}
			//Create deck for Clubs
			for (int i = 1; i <= 13; i++)
			{
				Card temp = new Card();
				temp.cardNumber = i;
				temp.cardSuit = 'C';
				temp.cardColor = Color.Black;
				deck.Push(temp);
			}
			//Create deck for Spades
			for (int i = 1; i <= 13; i++)
			{
				Card temp = new Card();
				temp.cardNumber = i;
				temp.cardSuit = 'S';
				temp.cardColor = Color.Black;
				deck.Push(temp);
			}
		}

		//PaintCard
		//Draws the cards on the screen with the help of other functions
		//ref g			= reference to this programs graphics object
		//whichCard		= which card at hand is it (1-5)
		//cardNumber	= what card from the deck is it (1-13)
		//cardSuit		= what suit is the card (D, H, C, S)
		private void PaintCard(ref Graphics g, int whichCard, int cardNumber, char cardSuit)
		{
			//Positions for card
			Point cardPositionStart = new Point(0,0);
			Size cardPositionEnd = new Size(75,100);
			//Positions for card number/face
			Point numberPositionStart = new Point(0, 0);
			Size numberPositionEnd = new Size(10, 10);
			//Positions for card suit
			Point suitPositionStart = new Point(0, 0);
			Size suitPositionEnd = new Size(10, 10);

			//Set card color based on suit
			Color cardColor = SetCardColor(cardSuit);

			//g.DrawRectangle(new Pen(Color.Red), new Rectangle(new Point(30, 30), new Size(60, 60)));
			//g.FillRectangle(new SolidBrush(Color.Red), 30,30,60,60);

			//Set positions with modifiers for card, number, and suit images
			SetCardPosition(whichCard, ref cardPositionStart, ref numberPositionStart, ref suitPositionStart);
			//SetCardPosition(whichCard, ref numberPositionStart);
			//SetCardPosition(whichCard, ref suitPositionStart);

			DrawCards(ref g, ref cardColor, ref cardPositionStart, ref cardPositionEnd);
			DrawNumbers(ref g, cardNumber, ref cardColor, ref numberPositionStart, ref numberPositionEnd);
			DrawSuits(ref g, cardSuit, ref cardColor, ref suitPositionStart, ref suitPositionEnd);
			
		}

		//SetCardPosition
		//Takes which card at hand is needed and sets Point
		//Takes references to modify positions in PaintCard function
		void SetCardPosition(int whichCard, ref Point cardPoint, ref Point numberPoint, ref Point suitPoint)
		{
			int xCard = 0, yCard = 0, xNumber = 0, yNumber = 0, xSuit = 0, ySuit = 0;
			//region CardPositions
			//Changes coordinate of placement based on which card it is.  
			#region CardPositions
			yCard = 200;
			yNumber = 210;
			ySuit = 240;
			switch (whichCard)
			{
				case (1):
					xCard = 100;
					xNumber = 135;
					xSuit = 135;
					break;
				case (2):
					xCard = 180;
					xNumber = 215;
					xSuit = 215;
					break;
				case (3):
					xCard = 260;
					xNumber = 295;
					xSuit = 295;
					break;
				case (4):
					xCard = 340;
					xNumber = 375;
					xSuit = 375;
					break;
				case (5):
					xCard = 420;
					xNumber = 455;
					xSuit = 455;
					break;
			}
			#endregion

			cardPoint = new Point(xCard, yCard);
			numberPoint = new Point(xNumber, yNumber);
			suitPoint = new Point(xSuit, ySuit);
		}

		//SetCardColor
		//Takes in card suit, and returns the color it should be
		Color SetCardColor(char cardType)
		{
			if (cardType == 'D' || cardType == 'H')
				return (Color.Red);
			else
				return (Color.Black);
		}

		//DrawCards
		//Takes in information from PaintCard and physically paints images to screen
		//Only displays cards
		void DrawCards(ref Graphics g, ref Color cardColor, ref Point cardPositionStart, ref Size cardPositionEnd)
		{
			//g.DrawRectangle(new Pen(cardColor), new Rectangle(cardPositionStart, cardPositionEnd));
			g.FillRectangle(new SolidBrush(Color.White), new Rectangle(cardPositionStart, cardPositionEnd));
		}


		//DrawNumbers
		//Takes in information from PaintCard and physically paints images to screen
		//Only displays numbers
		void DrawNumbers(ref Graphics g, int cardNumber, ref Color cardColor, ref Point numberPositionStart, ref Size numberPositionEnd)
		{
			//region DrawCards
			//Draws the card based on the type
			#region DrawCards
			switch (cardNumber)
			{
				case (1):
					g.DrawString("A", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (2):
					g.DrawString("2", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (3):
					g.DrawString("3", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (4):
					g.DrawString("4", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (5):
					g.DrawString("5", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (6):
					g.DrawString("6", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (7):
					g.DrawString("7", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (8):
					g.DrawString("8", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (9):
					g.DrawString("9", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (10):
					g.DrawString("10", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (11):
					g.DrawString("J", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (12):
					g.DrawString("Q", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
				case (13):
					g.DrawString("K", new Font("Arial", 10.0f), new SolidBrush(cardColor), numberPositionStart);
					break;
			}
			#endregion
		}

		//DrawSuits
		//Takes in information from PaintCard and physically paints images to screen
		//Only displays suit
		void DrawSuits(ref Graphics g, char cardSuit, ref Color cardColor, ref Point suitPositionStart, ref Size suitPositionEnd)
		{
			switch(cardSuit)
			{
				case ('D'):			//Draw Diamonds
					Point[] diamondPoints = new Point[4];
					diamondPoints[0] = new Point(suitPositionStart.X + 5, suitPositionStart.Y - 5);
					diamondPoints[1] = new Point(suitPositionStart.X - 5, suitPositionStart.Y + 5);
					diamondPoints[2] = new Point(suitPositionStart.X + 5, suitPositionStart.Y + 15);
					diamondPoints[3] = new Point(suitPositionStart.X + 15, suitPositionStart.Y + 5);
					g.FillPolygon(new SolidBrush(cardColor), diamondPoints);
					break;
				case ('H'):			//Draw Hearts
					Point heartLeft = new Point(suitPositionStart.X-3, suitPositionStart.Y);
					Point heartRight = new Point(suitPositionStart.X+3, suitPositionStart.Y);
					Point heartBottom = new Point(suitPositionStart.X, suitPositionStart.Y+3);
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(heartLeft, suitPositionEnd));
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(heartRight, suitPositionEnd));
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(heartBottom, suitPositionEnd));
					break;
				case ('C'):			//Draw Clubs
					Point clubLeft = new Point(suitPositionStart.X - 5, suitPositionStart.Y);
					Point clubRight = new Point(suitPositionStart.X + 5, suitPositionStart.Y);
					Point clubTop = new Point(suitPositionStart.X, suitPositionStart.Y - 5);
					Point clubHandle = new Point(suitPositionStart.X + 4, suitPositionStart.Y + 6);
					Size clubHandleSize = new Size(suitPositionEnd.Width - 7, suitPositionEnd.Height - 2);
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(clubLeft, suitPositionEnd));
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(clubRight, suitPositionEnd));
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(clubTop, suitPositionEnd));
					g.FillRectangle(new SolidBrush(cardColor), new Rectangle(clubHandle, clubHandleSize));
					break;
				case ('S'):			//Draw Spades
					Point spadeLeft = new Point(suitPositionStart.X - 3, suitPositionStart.Y);
					Point spadeRight = new Point(suitPositionStart.X + 3, suitPositionStart.Y);
					Point spadeTop = new Point(suitPositionStart.X, suitPositionStart.Y - 3);
					Point spadeHandle = new Point(suitPositionStart.X + 4, suitPositionStart.Y + 9);
					Size spadeHandleSize = new Size(suitPositionEnd.Width - 7, suitPositionEnd.Height-5);
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(spadeLeft, suitPositionEnd));
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(spadeRight, suitPositionEnd));
					g.FillEllipse(new SolidBrush(cardColor), new Rectangle(spadeTop, suitPositionEnd));
					g.FillRectangle(new SolidBrush(cardColor), new Rectangle(spadeHandle, spadeHandleSize));
					break;
			}
		}

		//CleanGraphics
		//Disposes of graphics so there is no over writing
		void CleanGraphics(ref Graphics g)
		{
			//g.Dispose();
			g.Clear(Color.WhiteSmoke);
		}





	}

	//class Card
	//Individual object of each card in the deck of 52 cards
	class Card
	{
		public int cardNumber;		//A number 1-13, for each card in suit
		public char cardSuit;		//D = Diamonds, H = Hearts, C = Clubs, S = Spades 
		public Color cardColor;		//Red for diamonds and hearts, black for clubs and spades
		public Card()
		{
			cardNumber = 0;
			cardSuit = 'D';
			cardColor = Color.Red;
		}

	}
}