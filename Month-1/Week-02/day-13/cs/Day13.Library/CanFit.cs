using System;
using System.Collections.Generic;
using System.Linq;

namespace Day13.Library
{
  public class CanFit
  {
    const int LIMITWEIGHT = 10;
    int[] _items;
    int _bags;

    public CanFit(int[] items, int bags)
    {
      _items = items;
      _bags = bags;
    }

    public bool checkFit()
    {
      int totalBags = 0;
      List<int> extraWeight = new List<int>();
      int accWeight = 0;

      for (int i = 0; i < _items.Length; i++)
      {
        accWeight += _items[i];

        if (accWeight == LIMITWEIGHT)
        {
          totalBags++;
          accWeight = 0;
        } else if (accWeight > LIMITWEIGHT)
        {
          extraWeight.Add(accWeight - LIMITWEIGHT);
          totalBags++;
          accWeight = 0;
        }
      }

      if (extraWeight.Count > 0) totalBags++;

      for (int i = 0; i < extraWeight.Count; i++)
      {
        accWeight += extraWeight[i];
        
        if (accWeight >= LIMITWEIGHT)
        {
          totalBags++;
          accWeight = 0;
        }
      }
      return _bags >= totalBags;
    }
  }
}
