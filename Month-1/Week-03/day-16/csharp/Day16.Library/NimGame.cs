using System;

namespace Day16.Library
{
    public class NimGame
    {
        Int32 _input;

        public NimGame(String input)
        {
            _input = Int32.Parse(input);
        }

        public bool IWin()
        {
            return _input % 4 != 0;
        }
    }
}
