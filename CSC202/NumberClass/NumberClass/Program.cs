using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NumberClass {
    class NiftyInteger {
        private int value;
        public NiftyInteger() {
            value = 0;
        }
        public NiftyInteger(int myValue) {
            value = myValue;
        }
        public NiftyInteger(NiftyInteger aNiftyInteger)
        {
            value = aNiftyInteger.value;
        }
        ~NiftyInteger() {
        }
        public NiftyInteger Multiply(NiftyInteger multiplicand) {
            NiftyInteger product = new NiftyInteger(value * multiplicand.value);
            return product;
        }

        public bool Same(NiftyInteger comparee) {
            if (value == comparee.value)
                return true;
            else
                return false;
        }
        public string GetValue()
        {
            string returnThis = value.ToString();
            return returnThis;
        }
    }
    class Program {
        public static void Main() {
            NiftyInteger myNifty = new NiftyInteger(10);
            NiftyInteger yourNifty = new NiftyInteger();
            
            

            Console.WriteLine("I made these: " + myNifty.GetValue() + " " + yourNifty.GetValue() + "\n");
            if (myNifty.Same(yourNifty))
            {
                Console.WriteLine("FAIL\n");
            }
            else
            {
                Console.WriteLine("Same() works.\n");
            }

            NiftyInteger ourNifty = myNifty.Multiply(yourNifty);
            Console.WriteLine("Is this zero?: " + ourNifty.GetValue());
        }
    }

}
